#include <bits/stdc++.h>
using namespace std;

const int limit = 10000000; // 10^7

// set all not prime
bool isPrime[limit + 1] = { 0 };

void sieveOfEratosthenes (int limit) { //works in 10^7
    isPrime[2] = 1;

    // set all odd numbers prime
    for (int i = 3; i <= limit; i += 2) isPrime[i] = true;

    int sqrtOfLimit = sqrt(limit) + 1;
 
    for (int i = 3; i <= sqrtOfLimit; i += 2) { // 3, 5, 7, 9, 11, ...
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i + i) {
                isPrime[j] = false; // not prime
            }
        }
    }
}

int main () {
    int n;
    sieveOfEratosthenes(limit);
    while(1) {
        printf("\nEnter number: (press 0 to exit) ");
        scanf("%d", &n);
        if(n == 0) break;
        else if (n > limit) {
            printf("Number should be less than %d", limit);
            continue;
        }
        else if (isPrime[n] == false) printf("%d is not a prime number.\n", n);
        else printf("%d is a prime number.\n", n);
        printf("\n");
    }
    return 0;
}
