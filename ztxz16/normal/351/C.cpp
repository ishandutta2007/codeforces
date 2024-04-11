#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = (a - b) >> 31), (b & FASTBUFFER | a & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = (a - b) >> 31), (a & FASTBUFFER | b & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

using namespace std;

int n, m, i, j, k, i2, j2, xx, tot;
int a[30], b[30], Need[30][30], Now[30];
int f[30][30][30];
int g[30][30][30];

void dfs(int i, int s);

int main()
{
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            Need[i][j] = OO;
    dfs(1, 0);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= n; j++)
            f[0][i][j] = Need[i][j];
    for (k = 1; k <= 24; k++)
    {
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                f[k][i][j] = OO;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                for (i2 = 0; i2 <= n; i2++)
                    for (j2 = 0; j2 <= n; j2++)
                    {
                        if (f[k - 1][i][j] == OO || f[k - 1][i2][j2] == OO)
                            continue;
                        if (j < i2)
                        {
                            if (i + i2 - j <= n)
                            {
                                xx = f[k - 1][i][j] + f[k - 1][i2][j2];
                                if (xx < f[k][i + i2 - j][j2])
                                    f[k][i + i2 - j][j2] = xx;
                            }
                        }
                        
                        else
                        {
                            if (j2 + j - i2 <= n)
                            {
                                xx = f[k - 1][i][j] + f[k - 1][i2][j2];
                                if (xx < f[k][i][j2 + j - i2])
                                    f[k][i][j2 + j - i2] = xx;
                            }
                        }
                    }
    }
    
    for (k = 0; k <= 24; k++)
    {
        if ((m & (1 << k)) > 0)
        {
            tot++;
            if (tot == 1)
            {
                for (i = 0; i <= n; i++)
                    for (j = 0; j <= n; j++)
                        g[tot][i][j] = f[k][i][j];
            }
            
            else
            {
                for (i = 0; i <= n; i++)
                    for (j = 0; j <= n; j++)
                        g[tot][i][j] = OO;
                for (i = 0; i <= n; i++)
                    for (j = 0; j <= n; j++)
                        for (i2 = 0; i2 <= n; i2++)
                            for (j2 = 0; j2 <= n; j2++)
                            {
                                if (g[tot - 1][i][j] == OO || f[k][i2][j2] == OO)
                                    continue;
                                if (j < i2)
                                {
                                    if (i + i2 - j <= n)
                                    {
                                        xx = g[tot - 1][i][j] + f[k][i2][j2];
                                        if (xx < g[tot][i + i2 - j][j2])
                                            g[tot][i + i2 - j][j2] = xx;
                                    }
                                }
                        
                                else
                                {
                                    if (j2 + j - i2 <= n)
                                    {
                                        xx = g[tot - 1][i][j] + f[k][i2][j2];
                                        if (xx < g[tot][i][j2 + j - i2])
                                            g[tot][i][j2 + j - i2] = xx;
                                    }
                                }
                            }
            }
        }
    }
    
    printf("%d\n", g[tot][0][0]);
    return 0;
}

void dfs(int i, int s)
{
    int x, s1, s2;
    if (i > n)
    {
        s1 = s2 = 0;
        for (x = 1; x <= n; x++)
        {
            if (Now[x] == 2)
            {
                if (s2 > 0)
                    s2--;
                else
                    s1++;
            }
            
            else
                s2++;
        }
        
        if (s < Need[s1][s2])
            Need[s1][s2] = s;
        return;
    }
    
    Now[i] = 1;
    dfs(i + 1, s + a[i - 1]);
    Now[i] = 2;
    dfs(i + 1, s + b[i - 1]);
    return;
}