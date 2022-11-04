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

int n, l, r, ql, qr, a[100005], s[100005], Now, Ans, i, j;
int FASTBUFFER;

int main()
{
    scanf("%d %d %d %d %d", &n, &l, &r, &ql, &qr);
    Ans = 2147483647;
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    for (i = 0; i <= n; i++)
    {
        j = n - i;
        Now = s[i] * l + (s[n] - s[i]) * r;
        if (i > j)
            Now += (i - 1 - j) * ql;
        if (j > i)
            Now += (j - 1 - i) * qr;
        if (Now < Ans)
            Ans = Now;
    }
    
    printf("%d\n", Ans);
    return 0;
}