#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, k, i, j, l, r, s1[1000005], s[1000005];
int Now, Min;

int main()
{
    scanf("%d %d", &n, &k);
    Min = 1000005;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &r);
        if (r - k > 0)
            l = r - k;
        else
            l = 1;
        s1[l]++, s1[r + 1]--;
        if (r < Min)
            Min = r;
    }
    
    for (i = 1; i <= 1000000; i++)
        s[i] = s[i - 1] + s1[i];
    for (i = Min; i >= 1; i--)
    {
        int Now = 0;
        for (j = i; j <= 1000000; j += i)
            Now += s[j];
        if (Now >= n)
            break;
    }
    
    printf("%d\n", i);
    return 0;
}