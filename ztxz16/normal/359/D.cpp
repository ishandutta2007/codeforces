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
int n, i, Now, tot, Ans, s, a[500005], succ[500005], next[500005];

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    succ[1] = 1;
    for (i = 2; i <= n; i++)
    {
        if (a[i - 1] == a[i])
            succ[i] = succ[i - 1];
        else
        {
            Now = i - 1;
            while (Now > 0 && a[Now] % a[i] == 0)
                Now = succ[Now] - 1;
        }
        
        succ[i] = Now + 1;
    }
    
    next[n] = n;
    for (i = n - 1; i >= 1; i--)
    {
        if (a[i + 1] == a[i])
            next[i] = next[i - 1];
        else
        {
            Now = i + 1;
            while (Now <= n && a[Now] % a[i] == 0)
                Now = next[Now] + 1;
        }
        
        next[i] = Now - 1;
    }
    
    for (i = 1; i <= n; i++)
        if (next[i] - succ[i] > Ans)
            Ans = next[i] - succ[i];
    for (i = 1; i <= n; i++)
        if (next[i] - succ[i] == Ans)
            a[++tot] = succ[i];
    sort(a + 1, a + tot + 1);
    for (i = 1; i <= tot; i++)
        if (a[i] != a[i - 1])
            s++;
    printf("%d %d\n", s, Ans);
    for (i = 1; i <= tot; i++)
        if (a[i] != a[i - 1])
            printf("%d ", a[i]);
    printf("\n");
    return 0;
}