#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define ll long long
#include <string.h>

using namespace std;

ll FASTBUFFER;

vector <int> can[20];
vector <int>::iterator it;

ll i, j, k, t, temp, sel[7], ok[1005], a[1005], Ans[105][105], tot;
ll f[105][20], succ[105][20];
long long Now, ans[7];

void dfs(ll i, ll s);

int main()
{
    dfs(1, 0);
    for (i = 0; i <= 42; i++)
        if (ok[i] == 1)
            can[i % 10].push_back(i);
    scanf("%I64d", &t);
    while (t > 0)
    {
        t--;
        scanf("%I64d", &Now);
        tot = 0;
        while (Now > 0)
        {
            a[++tot] = Now % 10;
            Now /= 10;
        }
        
        memset(f, 0, sizeof(f));
        f[1][0] = 1;
        for (i = 1; i <= tot; i++)
        {
            for (j = 0; j <= 9; j++)
            {
                if (f[i][j] == 0)
                    continue;
                k = a[i] - j;
                if (k < 0)
                    k += 10;
                for (it = can[k].begin(); it != can[k].end(); ++it)
                    f[i + 1][(j + (*it)) / 10] = 1, succ[i + 1][(j + (*it)) / 10] = (*it);
            }
        }
        
        if (f[tot + 1][0] == 1)
        {
            for (i = 1; i <= 6; i++)
                ans[i] = 0;
            i = tot + 1, j = 0;
            while (i > 1)
            {
                temp = succ[i][j];
                for (k = 1; k <= 6; k++)
                {
                    ans[k] *= 10;
                    ans[k] += Ans[temp][k];
                }
                
                j = a[i - 1] - (temp % 10);
                if (j < 0)
                    j += 10;
                i--;
            }
            
            for (i = 1; i <= 5; i++)
                printf("%I64d ", ans[i]);
            printf("%I64d\n", ans[i]);
        }
        
        else
            printf("-1\n");
    }
    
    return 0;
}

void dfs(ll i, ll s)
{
    ll x;
    if (i > 6)
    {
        ok[s] = 1;
        for (x = 1; x <= 6; x++)
            Ans[s][x] = sel[x];
        return;
    }
    
    sel[i] = 0, dfs(i + 1, s + 0);
    sel[i] = 4, dfs(i + 1, s + 4);
    sel[i] = 7, dfs(i + 1, s + 7);
    return;
}