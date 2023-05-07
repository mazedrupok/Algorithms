#include <stdio.h>
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
        // printf("a * x + b * y = gcd\n");
        // printf("%d * %d + %d * %d = %d\n", a, *x, b, *y, b);
        return b;
    }
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
    // printf("%d * %d + %d * %d = %d\n", a, *x, b, *y, (a * *x) + (b * *y));
    return gcd;
}
// Driver Program
int main()
{
    int x, y;
    int a = 38, b = 102;
    int g = gcdExtended(a, b, &x, &y);
    printf("gcd(%d, %d) = %d, x = %d, y = %d\n", a, b, g, x, y);
    return 0;
}
/*
Proof
=> a * x + b * y = a1 * x1 + b1 * y1 = gcd
=> a * x + b * x1 = a1 * x1 + b1 * y1; as y = x1
=> a * x + b * x1 = a1 * x1 + a * y1; as b1 = a
=> x + (b/a) * x1 = (a1 * x1) / a + y1;
=> x + (b/a) * x1 = (b%a * x1) / a + y1; as a1 = b%a
=> x = y1 + (b%a * x1) / a - (b/a) * x1
=> x = y1 + ((b - ⌊b/a⌋ * a) * x1) / a - (b/a) * x1
=> x = y1 + (b/a) * x1 - (⌊b/a⌋ * a) * x1 / a - (b/a) * x1
=> x = y1 - (⌊b/a⌋ * a) * x1 / a
=> x = y1 - ⌊b/a⌋ * x1
*/

/*
Another proof
a.x + b.y = gcd —-(1)
And x1 and y1 are results for inputs b%a and a
(b%a).x1 + a.y1 = gcd
When we put b%a = (b – (⌊b/a⌋).a) in above,
we get following. Note that ⌊b/a⌋ is floor(b/a)
(b – (⌊b/a⌋).a).x1 + a.y1  = gcd
Above equation can also be written as below
b.x1 + a.(y1 – (⌊b/a⌋).x1) = gcd —-(2)
After comparing coefficients of ‘a’ and ‘b’ in (1) and
(2), we get following,
x = y1 – ⌊b/a⌋ * x1
y = x1
*/

/*
 extended coefficients (x, y) can infinite
 For a and b, gcd(a,b) = ax + by
 x = k * b / gcd(a,b)
 y = (-k) * a / gcd(a,b)
 where, k belongs to Z.
 (Z is any positive or negetive interger)
 */
