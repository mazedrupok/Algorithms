/*
    Md. Abdul Mazed
    Noakhali Science & Technology University
    mazed4g@gmail.com
    http://www.facebook.com/mazedrupok/bd
    github.com/mazedrupok
    Program: Coin change
        :) :) :)
*/
#include <bits/stdc++.h>
using namespace std;
int coin[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
vector <int > taka;
int return_coin (int amount, int n) {
    int res = 0, i = 0;
    while (amount > 0) {
        if (i > n) {res = -1; break;}
        if (amount >= coin[i]) {
            taka.push_back(coin[i]);
            amount -= coin[i];
            res++;
        }
        else i++;
    }
    return res;
}
int main ()
{
    int amount;
    scanf (" %d", &amount);
    int x = return_coin (amount, 8);
    if (x == -1) printf ("Coin return not possible\n");
    else {
        printf ("Total coins: %d\nCoins:", x);
        for (int i = 0; i < taka.size(); i++) printf (" %d", taka[i]); printf ("\n");
    }
    taka.clear();
}
