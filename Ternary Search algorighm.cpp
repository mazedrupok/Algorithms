#include <bits/stdc++.h>
using namespace std;
int tsearch(int *data, int left, int right, int value){
    int i, first, second;
    if(left > right) return -1;

    i = (right - left)/3;
    if(i == 0) i++;

    first = i  + left - 1;
    second = i*2 + left - 1;

    if(data[first] == value) return first;
    else if(data[first] > value)
         return tsearch(data, left, first-1, value);
    else {
        if(data[second] == value) return second;
        else if(data[second] > value)
           return tsearch(data, first+1, second-1, value);
        else
           return tsearch(data, second+1, right, value);
     }
}
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int res, k;
    printf("Enter no to be searched :");
    scanf(" %d", &k);
    res = tsearch(a, 0, 9, k);
    printf("\n%d", res);
    return 0;
}

