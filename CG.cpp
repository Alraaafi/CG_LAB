#include <bits/stdc++.h>
#include<graphics.h> //ck
using namespace std;
//Md. Tanvir Ahmed Rafi
//-JSTU CSE'4th








///Cohen line cliping Region
const int INSIDE = 0;
const int LEFT   = 1;
const int RIGHT  = 2;
const int BOTTOM = 4;
const int TOP    = 8;
// Clipping window
int xmin = 100, ymin = 100, xmax = 300, ymax = 300;
// Function to find region code
int getCode(int x, int y)
{
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    if (y > ymax) code |= TOP;
    return code;
}




















///Sutherland–Hodgman Polygon Clipping Region
struct Point {
    float x, y;
};

// Clipping window
float xmin = 100, ymin = 100, xmax = 300, ymax = 300;

// Check inside functions
bool insideLeft(Point p)   { return p.x >= xmin; }
bool insideRight(Point p)  { return p.x <= xmax; }
bool insideBottom(Point p) { return p.y >= ymin; }
bool insideTop(Point p)    { return p.y <= ymax; }

// Intersection functions
Point intersect(Point p1, Point p2, int edge)
{
    Point p;

    if (edge == 1) { // left
        p.x = xmin;
        p.y = p1.y + (p2.y - p1.y) * (xmin - p1.x) / (p2.x - p1.x);
    }
    else if (edge == 2) { // right
        p.x = xmax;
        p.y = p1.y + (p2.y - p1.y) * (xmax - p1.x) / (p2.x - p1.x);
    }
    else if (edge == 3) { // bottom
        p.y = ymin;
        p.x = p1.x + (p2.x - p1.x) * (ymin - p1.y) / (p2.y - p1.y);
    }
    else { // top
        p.y = ymax;
        p.x = p1.x + (p2.x - p1.x) * (ymax - p1.y) / (p2.y - p1.y);
    }

    return p;
}

// Clip polygon with one edge
vector<Point> clip(vector<Point> poly, int edge)
{
    vector<Point> output;
    int n = poly.size();

    for (int i = 0; i < n; i++)
    {
        Point curr = poly[i];
        Point prev = poly[(i - 1 + n) % n];

        bool currIn, prevIn;

        if (edge == 1) {
            currIn = insideLeft(curr);
            prevIn = insideLeft(prev);
        }
        else if (edge == 2) {
            currIn = insideRight(curr);
            prevIn = insideRight(prev);
        }
        else if (edge == 3) {
            currIn = insideBottom(curr);
            prevIn = insideBottom(prev);
        }
        else {
            currIn = insideTop(curr);
            prevIn = insideTop(prev);
        }

        // Case 1: inside-inside
        if (currIn && prevIn)
            output.push_back(curr);

        // Case 2: outside-inside
        else if (!currIn && prevIn)
        {
            output.push_back(intersect(prev, curr, edge));
        }

        // Case 3: inside-outside
        else if (currIn && !prevIn)
        {
            output.push_back(intersect(prev, curr, edge));
            output.push_back(curr);
        }
    }

    return output;
}




int main()
{
    //int gd,gm;
    //detectgraph(&gd, &gm);
    //initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");









    ///DDA line Drawing:
    //double x0,y0,xn,yn;
    //cout<<"for DDA Enter x0,y0,xn,yn : ";
    //cin>>x0>>y0>>xn>>yn;
    //double dx,dy,m,step;
    //dx = x0-xn;
    //dy = y0-yn;
    //step = max( abs(dy),  abs(dx) );
    //m  = dy/dx;
    //vector< pair<double, double> > pline;
    //pline.push_back( {x0, y0} );
    //double x = x0,y=y0;
    //if(m<1)
    //{
    //    for(int i=1; i<=step; i++)
    //    {
    //        x = (x+1);
    //        y = (y+m);
    //        pline.push_back( {round(x), round(y)} );
    //    }
    //}
    //else if(m>1)
    //{
    //    for(int i=1; i<=step; i++)
    //    {
    //        x = ( x + (1/m));
    //        y = (y+1);
    //        pline.push_back( {round(x), round(y)} );
    //
    //    }
    //}
    //else
    //{
    //    for(int i=1; i<=step; i++)
    //    {
    //        x = (x+1);
    //        y = (y+1);
    //        pline.push_back( {round(x), round(y)} );
    //
    //    }
    //}
    //cout<<"line points: "<<endl;
    //for(auto p: pline)
    //{
    //    cout<<p.first<<" "<<p.second<<endl;
    //}













    ///Bresenham Line Drawing... algo
    // double x0,y0,xn,yn;
    // cout<<"for BLDA Enter x0,y0,xn,yn : ";
    // cin>>x0>>y0>>xn>>yn;
    // double dx,dy,m,step,i;
    // dx = xn-x0;
    // dy = yn-y0;
    // step = abs(dx);
    // m  = 2*dy - dx;
    // vector< pair<double, double> > pline;
    // pline.push_back( {x0, y0} );
    // double x = x0,y=y0;

    // for(i=1; i<=step; i++)
    // {
    //     if( m < 0 )
    //     {
    //         m = m + 2*dy;
    //         x++;
    //     }
    //     else
    //     {
    //         m = m+(2*dy) - (2*dx);
    //         x++;
    //         y++;
    //     }
    //     pline.push_back( {x,y} );
    // }

    // cout<<"line points: "<<endl;
    // for(auto p: pline)
    // {
    //     cout<<p.first<<" "<<p.second<<endl;
    // }


















    ///mid point Circle Drawing algo
    // double i,r,x0,y0,p,x,y;
    // cout<<"ENTER POINT AND RADIOUS: ";
    // cin>>x0>>y0>>r;
    // p = 1 - r;
    // x = 0;
    // y = r;
    // vector< pair<double,double> > oct1,oct2,q1;
    // while( x<y )
    // {
    //     oct1.push_back( { x,y } );
    //     oct2.push_back( { y,x } );
    //     if( p < 0 )
    //     {
    //         x++;
    //         p = p + (2*x) + 1;
    //     }
    //     else
    //     {
    //         x++;
    //         y--;
    //         p = p + (2*x) + 1 - (2*y);
    //     }
    // }
    // reverse(oct2.begin(), oct2.end());
    // q1 = oct1;
    // for(auto o: oct2) q1.push_back(o);
    // for(auto o : q1)
    // {
    //     cout<<o.first<< " "<<o.second<<endl; //q1
    // }

























    ///Bresenham Circle Drawing Algo:
    // double i,r,x0,y0,p,x,y;
    // cout<<"ENTER POINT AND RADIOUS: ";
    // cin>>x0>>y0>>r;
    // p = 3 - 2*r;
    // x = 0;
    // y = r;
    // vector< pair<double,double> > oct1,oct2,q1;
    // while( x<y )
    // {
    //     oct1.push_back( { x+x0,y+y0 } );
    //     oct2.push_back( { y+y0,x+x0 } );
    //     if( p < 0 )
    //     {
    //         x++;
    //         p = p + (4*x) + 6;
    //     }
    //     else
    //     {
    //         x++;
    //         y--;
    //         p = p + (2*x) + 10 - (4*y);
    //     }
    // }
    // reverse(oct2.begin(), oct2.end());
    // q1 = oct1;
    // for(auto o: oct2) q1.push_back(o);
    // for(auto o : q1)
    // {
    //     cout<<o.first<< " "<<o.second<<endl; //q1
    // }














    ///2D Translation
    //int x1,y1,x2,y2,xt,yt;
    //cout<<"Enter line point x1,y1,x2,y2: ";
    //cin>>x1>>y1>>x2>>y2;
    //line(x1,y1,x2,y2);
    //cout<<"Give Translation Factor xt,yt: ";
    //cin>>xt>>yt;
    //x1+=xt;
    //x2+=xt;
    //y1+=yt;
    //y2+=yt;
    //line(x1,y1,x2,y2);














    ///2D Rotation
    //int x1,y1,x2,y2,a;
    //cout<<"Enter line point x1,y1,x2,y2: ";
    //cin>>x1>>y1>>x2>>y2;
    //line(x1,y1,x2,y2);
    //cout<<"Enter Rotation Angle: ";
    //cin>>a;
    //double r = (a*acos(-1))/180; //radian covert
    //x1 = x1*cos(r) - y1*sin(r);
    //y1 = y1*cos(r) + x1*sin(r);
    //x2 = x2*cos(r) - y2*sin(r);
    //y2 = y2*cos(r) + x2*sin(r);
    //line(x1,y1,x2,y2);



















    ///2D Scalling
    //int x1,y1,x2,y2,sx,sy;
    //cout<<"Enter line point x1,y1,x2,y2: ";
    //cin>>x1>>y1>>x2>>y2;
    //line(x1,y1,x2,y2);
    //cout<<"Enter Scaling Factor sx,sy: ";
    //cin>>sx>>sy;
    //x1 = x1*sx;
    //y1 = y1*sy;
    //x2 = x2*sx;
    //y2 = y2*sy;
    //line(x1,y1,x2,y2);

















    ///2D Reflection
    //int x1,y1,x2,y2,sx,sy;
    //cout<<"Enter line point x1,y1,x2,y2: ";
    //cin>>x1>>y1>>x2>>y2;
    //line(x1,y1,x2,y2); //orginal
    //line(x1,-y1,x2,-y2); //Reflection on x ; not support in g.c
    //line(-x1,y1,-x2,y2); //Reflection on y ;not auppport in g.c




















    ///2D Shering
    //int x1,y1,x2,y2,sx,sy;
    //cout<<"Enter line point x1,y1,x2,y2: ";
    //cin>>x1>>y1>>x2>>y2;
    //rectangle(x1,y1,x2,y2); //orginal
    //cin>>sx>>sy;
    //rectangle( x1+(y1*sx),y1, x2 , (x2+y2*sx) );
















    ///Cohen Sutherland Line Clipping
    // int x1, y1, x2, y2;
    // cout << "Enter x1 y1 x2 y2: ";
    // cin >> x1 >> y1 >> x2 >> y2;
    // // PRE-CALCULATED SLOPE
    // double m = (x2 - x1) / (double)(y2 - y1);
    // int code1 = getCode(x1, y1);
    // int code2 = getCode(x2, y2);
    // bool accept = false;
    // while (true)
    // {
    //     if (code1 == 0 && code2 == 0)
    //     {
    //         accept = true;
    //         break;
    //     }
    //     else if (code1 & code2)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         int codeOut;
    //         double x, y;

    //         if (code1 != 0)
    //             codeOut = code1;
    //         else
    //             codeOut = code2;

    //         // Top
    //         if (codeOut & TOP)
    //         {
    //             x = x1 + (ymax - y1) / m;
    //             y = ymax;
    //         }

    //         // Bottom
    //         else if (codeOut & BOTTOM)
    //         {
    //             x = x1 + (ymin - y1) / m;
    //             y = ymin;
    //         }
    //         // Right
    //         else if (codeOut & RIGHT)
    //         {
    //             y = y1 + m * (xmax - x1);
    //             x = xmax;
    //         }

    //         // Left
    //         else if (codeOut & LEFT)
    //         {
    //             y = y1 + m * (xmin - x1);
    //             x = xmin;
    //         }
    //         // Replace outside point
    //         if (codeOut == code1)
    //         {
    //             x1 = x;
    //             y1 = y;
    //             code1 = getCode(x1, y1);
    //         }
    //         else
    //         {
    //             x2 = x;
    //             y2 = y;
    //             code2 = getCode(x2, y2);
    //         }
    //     }
    // }
    // if (accept)
    // {
    //     cout << "Clipped Line: ";
    //     cout << "(" << x1 << ", " << y1 << ") to ";
    //     cout << "(" << x2 << ", " << y2 << ")";
    // }
    // else
    // {
    //     cout << "Line is outside the clipping window";
    // }






























    ///Sutherland–Hodgman Polygon Clipping Algorithm:
    //int n;
    //cout << "Enter number of polygon points: ";
    //cin >> n;
    //vector<Point> poly(n);
    //cout << "Enter polygon points (x y):\n";
    //for (int i = 0; i < n; i++)
    //    cin >> poly[i].x >> poly[i].y;

    // Clip against 4 boundaries
    //poly = clip(poly, 1); // left
    //poly = clip(poly, 2); // right
    //poly = clip(poly, 3); // bottom
    //poly = clip(poly, 4); // top

    //cout << "\nClipped Polygon Points:\n";
    //for (auto p : poly)
    //    cout << "(" << p.x << ", " << p.y << ")\n";











    cin.ignore();
    cin.get();
    getchar();
    closegraph();
    return 0;

}
