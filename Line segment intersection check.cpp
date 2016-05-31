/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   Category: Computational Geometry (Check 2 lines Intersection).
   Helpful link: http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
   Comment:
*/
#include <iostream>
using namespace std;
struct point {
   int x, y;
};
bool onSegment (point a, point m, point b) {
 if ((m.x>=min(a.x,b.x) && m.x<=max(a.x,b.x)) && (m.y>=min(a.y,b.y) && m.y<=max(a.y,b.y)))
   return true;
 return false;
}
int orientation(point a, point b, point c) {
   int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
   if (val == 0) return 0;  // co-linear
//Val = positive means Clock-wise.
   return (val > 0)? 1: 2; // clock or counter-clock wise
}
bool lineIntersect (point a, point b, point c, point d) {
   int o1, o2, o3, o4;
   o1 = orientation(a, b, c);
   o2 = orientation(a, b, d);
   o3 = orientation(c, d, a);
   o4 = orientation(c, d, b);
   if (o1 != o2 && o3 != o4) return true; //general case
   //Special case
   //if c lies on ab line
   if (o1 == 0 && onSegment(a, c, b)) return true;
   if (o2 == 0 && onSegment(a, c, b)) return true;
   if (o3 == 0 && onSegment(c, a, d)) return true;
   if (o4 == 0 && onSegment(c, b, d)) return true;
   return false;
}
int main()
{
   struct point p1 = {1, 1}, q1 = {10, 1};
   struct point p2 = {1, 2}, q2 = {10, 2};

   lineIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

   p1 = {10, 0}, q1 = {0, 10};
   p2 = {0, 0}, q2 = {10, 10};
   lineIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

   p1 = {-5, -5}, q1 = {0, 0};
   p2 = {1, 1}, q2 = {10, 10};
   lineIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

   return 0;
}
