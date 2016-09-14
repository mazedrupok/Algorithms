//this program can count less than 2^30 or 10^9..
#include <cstdio>
#include <cmath>
#include<iostream>
using namespace std;
unsigned int numbers[3500], len = 0;
inline bool prime(unsigned int x) {
    unsigned int i, last = sqrt(x);
    for (i = 2; i <= last; i++) {
        if (x %i == 0) return 0;
    }
    return 1;
}
void generate() {
    for (unsigned int i = 2; i < 32000; i++) { //squre root of 2^30..
        if (prime(i) == 1) numbers[len++] = i;
    }
}
inline bool process(unsigned long x) {
    unsigned int i, last = sqrt(x);
    for (i = 0; i < len && numbers[i] <= last; i++) {
        if (x %numbers[i] == 0) return 0;
    }
    return 1;
}
int main()
{
    int t;
    unsigned long fno, sno;
    generate();
    cin>>t;
    while (t--) {
        cin>>fno>>sno;
        if (fno == 1) fno++;
        while (fno <= sno) {
            if (process(fno)) cout<<fno<<endl;
            fno++;
        }
        cout<<endl;
    }
    return 0;
}
