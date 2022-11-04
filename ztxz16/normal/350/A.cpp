#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, Mina, Maxa, Minb, i, j, a[105], b[105];

int main()
{
    scanf("%d %d", &n, &m);
    Mina = 2147483647, Maxa = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        Mina = min(Mina, a[i]);
        Maxa = max(Maxa, a[i]);
    }
    
    Minb = 2147483647;
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
        Minb = min(Minb, b[i]);
    }
    
    for (j = 1; j < Minb; j++)
        if (Maxa <= j && Mina * 2 <= j)
            break;
    if (j < Minb)
        printf("%d\n", j);
    else
        printf("-1\n");
    return 0;
}