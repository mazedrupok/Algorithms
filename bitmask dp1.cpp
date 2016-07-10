/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MMM   MMM AA     AA ZZZZZZZ EEEEEEE DDDDD

 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 Github:   www.github.com/mazedrupok
 Link:     Shafayet Blog
*/
#include <bits//stdc++.h>
using namespace std;

#define MAX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
#define inf        INT_MAX
#define mod        1000000007
#define PI         acos(-1.0)
#define sqr(x)     ((x)*(x))

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N=N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

/****************************** END OF TEMPLATE ******************************/
int n, dp[(1<<15) +2], w[16][16]; //works in n <= 15
int call (int mask ) {
    if (mask == (1<<n)-1) return 0;
    if (dp[mask] != -1) return dp[mask];
    int mn = 1 << 28;
    for (int i = 0; i < n; i++) {
        if (check (mask, i) == 0) {
            int price = w[i][i];
            for (int j = 0; j < n; j++) {
                if (i != j && check(mask, j) == 1) price += w[i][j];
            }
            int ret = price + call (Set(mask, i));
            mn = min (mn, ret);
        }
    }
    return dp[mask] = mn;
}
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    //read("in.txt"); //write ("out.txt");

    cin >> n;
    memset (dp, -1, sizeof (dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> w[i][j];
    }
    cout << call(0) << endl;
    return 0;
}


