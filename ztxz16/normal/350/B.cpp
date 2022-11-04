#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int a[100005], b[100005], du[100005], Ans, i, j, s, sel, n;
int List[100005], tot;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &b[i]), du[b[i]]++;
    Ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            continue;
        for (j = i, s = 0; (j != 0 && du[j] == 1) || j == i; j = b[j], s++);
        if (s > Ans)
            Ans = s, sel = i;
    }
    
    printf("%d\n", Ans);
    for (j = sel; (j != 0 && du[j] == 1) || j == sel; j = b[j])
        List[++tot] = j;
    for (i = tot; i >= 1; i--)
        printf("%d ", List[i]);
    printf("\n");
    return 0;
}