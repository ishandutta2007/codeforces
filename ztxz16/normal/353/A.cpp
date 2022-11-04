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

int n, i, a, b, s1, s2, c;

int FASTBUFFER;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &a, &b);
        s1 += a, s2 += b;
        if ((a & 1) != (b & 1))
            c = 1;
    }
    
    if ((s1 & 1) == 0 && (s2 & 1) == 0)
        printf("0\n");
    else if ((s1 & 1) == 1 && (s2 & 1) == 1 && c == 1)
        printf("1\n");
    else
        printf("-1\n");
    return 0;
}