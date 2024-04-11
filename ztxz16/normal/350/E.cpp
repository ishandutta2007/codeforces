#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k, i, j, sel, x, y, a[305], Hash[305];
int Ans1[100005], Ans2[100005], tot;
int ok[305][305];

void add(int a, int b);

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    if (k == n)
    {
        printf("-1\n");
        return 0;
    }
    
    for (i = 1; i <= k; i++)
        scanf("%d", &a[i]), Hash[a[i]] = 1;
    x = a[1], y = a[2];
    for (i = 1; i <= n; i++)
        if (Hash[i] == 0)
            break;
    sel = i;
    for (i = 1; i <= n; i++)
        if (i != sel)
            add(i, sel);
    for (i = 1; i < n; i++)
        for (j = i + 1; j <= n; j++)
        {
            if (m == 0)
                break;
            if ((i == x && Hash[j] == 1) || (Hash[i] == 1 && j == x))
                continue;
            add(i, j);
        }
    
    if (m > 0)
        printf("-1\n");
    else
        for (i = 1; i <= tot; i++)
            printf("%d %d\n", Ans1[i], Ans2[i]);
        
    return 0;
}

void add(int a, int b)
{
    if (ok[a][b] == 1)
        return;
    ok[a][b] = ok[b][a] = 1;
    Ans1[++tot] = a, Ans2[tot] = b;
    m--;
    return;
}