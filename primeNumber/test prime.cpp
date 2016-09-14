#include <stdio.h>
#include <math.h>
int test_prime (int n)
{
    int i;
    int root;
    root = sqrt(n);
    if (n == 1) return 0; //not prime
    if (n <= 3) return 1; //prime..
    if (n % 2 == 0) return 0; //not prime..
    for (i = 3; i <= root; i += 2) {
        if (n %i == 0) return 0;
    }
    return 1;
}
int main ()
{
    int m;
    while (1) {
    printf("Enter a number (Enter 0 to exit) ");
    scanf("%d", &m);
        if (m == 0) break;
        if (1 == test_prime(m)) {
            printf("%d is a prime number\n", m);
        }
        else {
            printf("%d is not a prime number\n", m);
        }
    }
    getch();
    return 0;
}
