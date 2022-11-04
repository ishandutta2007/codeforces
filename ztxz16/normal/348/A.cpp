#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

long long n, i, a[100005], l, r, mid, s;

int main()
{
    scanf("%I64d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%I64d", &a[i]);
        if (a[i] > l)
            l = a[i];
    }
    
    r = (1LL << 60);
    while (l < r)
    {
        mid = ((l + r) >> 1);
        s = 0;
        for (i = 1; i <= n; i++)
        {
            s += (mid - a[i]);
            if (s >= mid)
                break;
        }
        
        if (s >= mid)
            r = mid;
        else
            l = mid + 1;
    }
    
    printf("%I64d\n", l);
    return 0;
}