#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        int MaxR = 0, MaxW = 0;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            MaxR = max(MaxR, x);
            MaxW = max(MaxW, y);
        }
        if (MaxR + MaxW > n)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i <= MaxR)
                printf("R");
            else
                printf("W");
        }
        printf("\n");
    }
}