#include <bits/stdc++.h>
using namespace std;
int N = 100000000; // 10^8 needs 1.5 sec to generate
int status[100000000/32]; //needs 3125000*4 bytes or 12MB
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

void bitSieveOfEratosthenes(int N) {
     int sqrtN = int( sqrt( N ) );
     status[0] = 3;   //for 0 1 position for number 0 and 1. here 1 for not prime.. :)
     for (int i = 4; i <= N; i += 2) {
         status[i/32] |= (1 << (i %32));
     }
     for (int i = 3; i <= sqrtN; i += 2 ) {
		 if( check(status[i/32],i%32)==0) {
	 		 for(int j = i*i; j <= N; j += 2*i ) {
				 status[j/32]=Set(status[j/32],j % 32);
	 		 }
		 }
	 }
}

int main ()
{
     int n, limit;
     printf ("Enter Limit: "); scanf (" %d", &limit);
     bitSieveOfEratosthenes(limit);
     while (1) {
        printf ("Enter a number(-1 to exit): "); scanf (" %d", &n);
        if (n < 0) break;
        if( check(status[n/32], n%32)==0)
	 	   printf("%d is a prime.\n", n);
        else printf ("%d not a prime\n", n);
     }
}

