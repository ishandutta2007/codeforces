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
#define mo 1000000007

using namespace std;

int n, m, i, j;
int f1[3005][3005], f2[3005][3005], f3[3005][3005], f4[3005][3005];
char str[3005][3005];
long long Ans, Ans1, Ans2;

int main()
{
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%s", str[i] + 1);
    for (i = 1; i < n; i++)
        for (j = 2; j <= m; j++)
        {
            if (i == 1 && j == 2)
            {
                if (str[i][j] == '#')
                    f1[i][j] = 0;
                else
                    f1[i][j] = 1;
            }
            
            else
            {
                if (str[i][j] == '#')
                    f1[i][j] = 0;
                else
                    f1[i][j] = (f1[i - 1][j] + f1[i][j - 1]) % mo;
            }
        }
    
    for (i = 2; i <= n; i++)
        for (j = 1; j < m; j++)
        {
            if (i == 2 && j == 1)
            {
                if (str[i][j] == '#')
                    f2[i][j] = 0;
                else
                    f2[i][j] = 1;
            }
            
            else
            {
                if (str[i][j] == '#')
                    f2[i][j] = 0;
                else
                    f2[i][j] = (f2[i - 1][j] + f2[i][j - 1]) % mo;
            }
        }
    
    for (i = 1; i <= n; i++)
        for (j = 2; j < m; j++)
        {
            if (i == 1 && j == 2)
            {
                if (str[i][j] == '#')
                    f3[i][j] = 0;
                else
                    f3[i][j] = 1;
            }
            
            else
            {
                if (str[i][j] == '#')
                    f3[i][j] = 0;
                else
                    f3[i][j] = (f3[i - 1][j] + f3[i][j - 1]) % mo;
            }
        }
    
    for (i = 2; i < n; i++)
        for (j = 1; j <= m; j++)
        {
            if (i == 2 && j == 1)
            {
                if (str[i][j] == '#')
                    f4[i][j] = 0;
                else
                    f4[i][j] = 1;
            }
            
            else
            {
                if (str[i][j] == '#')
                    f4[i][j] = 0;
                else
                    f4[i][j] = (f4[i - 1][j] + f4[i][j - 1]) % mo;
            }
        }
    Ans1 = f1[n - 1][m];
    Ans1 *= f2[n][m - 1];
    Ans2 = f3[n][m - 1];
    Ans2 *= f4[n - 1][m];
    Ans = (Ans1 - Ans2) % mo;
    while (Ans < 0)
        Ans += mo;
    Ans %= mo;
    printf("%d\n", (int)(Ans));
    return 0;
}