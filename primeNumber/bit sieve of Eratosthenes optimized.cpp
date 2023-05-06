// Tested with https://www.codechef.com/problems/CHKPRM

#include <bits/stdc++.h>
using namespace std;

const int N = 100000000; // 10^8 needs 1.5 sec to generate

// Dividing with 2, as we are discarding even numbers from boolean storage
// Dividing with 32, the bit size of integer type
unsigned int status[(N/2)/32] = { 0 }; //needs 1562500*4 bytes or 6MB
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){    return N=N | (1<<pos);}

void bitSieveOfEratosthenes(int N) {
     int sqrtN = int( sqrt( N ) ) + 1;
     status[0] = 1;   //for 0 position for number 1. here 1 for not prime.

     for (int i = 3; i <= sqrtN; i += 2 ) {
         if( check(status[i/64], (i/2) %32)==0) {
              for(int j = i*i; j <= N; j += i+i ) {
                 status[j/64] = Set(status[j/64], (j/2) % 32);
              }
         }
     }
}

int main() {
    // your code goes here
    bitSieveOfEratosthenes(N);
    unsigned int n;
    cin >> n;
    // cout << status[n/64] << endl;
    if (n %2 == 0) cout << "NO";
    else if(check(status[n/64], (n/2) %32)==0) cout << "YES";
    else cout << "NO";
    return 0;
}
