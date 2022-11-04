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

int n, i, Ans, Now, a[100005], s[100005];
char str[100005];

int FASTBUFFER;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
    scanf("%s", str + 1);
    Now = Ans = 0;
    for (i = n; i >= 1; i--)
    {
        if (str[i] == '0')
            continue;
        else
        {
            if (Now + s[i - 1] > Ans)
                Ans = Now + s[i - 1];
            Now += a[i];
        }
    }
    
    if (Now > Ans)
        Ans = Now;
    printf("%d\n", Ans);
    return 0;
}