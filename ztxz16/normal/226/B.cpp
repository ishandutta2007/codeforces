#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll cmp(ll a, ll b)
{
    return a > b;
}

ll n, i, j, k, Ans, q, x, Now, s, s1, a[100005], sum[100005];

int main()
{
    scanf("%I64d", &n);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    sort(a + 1, a + n + 1, cmp);
    s1 = 0;
    for (i = 1; i <= n; i++)
        s1 += a[i] * (i - 1), sum[i] = sum[i - 1] + a[i];
    scanf("%I64d", &q);
    for (i = 1; i <= q; i++)
    {
        scanf("%I64d", &x), Now = 1, s = 0;
        if (x == 1)
        {
            printf("%I64d ", s1);
            continue;
        }
        
        else
        {
            Ans = 0;
            for (j = 1; j <= n; j++)
            {
                k = min(j + Now - 1, n);
                Ans += s * (sum[k] - sum[j - 1]);
                j = k;
                Now *= x;
                s++;
            }
            
            printf("%I64d ", Ans);
        }
    }
    
    printf("\n");
    return 0;
}