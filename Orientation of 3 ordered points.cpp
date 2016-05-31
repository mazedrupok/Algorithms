/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   Category: Computational Geometry (Orientation of 3 ordered points).
   Helpful link: http://www.geeksforgeeks.org/orientation-3-ordered-points/
   Comment:
*/
#include <iostream>
using namespace std;
struct Point {
    int x, y;
};
int orientation(Point p1, Point p2, Point p3) {
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;  // co-linear
   //Val = positive means Clock-wise.
    return (val > 0)? 1: 2; // clock or counter-clock wise
}
int main()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int o = orientation(p1, p2, p3);
    if (o==0)         cout << "Linear";
    else if (o == 1)  cout << "Clockwise";
    else              cout << "CounterClockwise";
    return 0;
}
