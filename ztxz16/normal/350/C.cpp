#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct TN
{
    int x, y;
    
    friend bool operator < (TN a, TN b)
    {
        return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
    }
}a[100005];

int n, i, Ans;

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1);
    Ans = 0;
    for (i = 1; i <= n; i++)
    {
        if (a[i].x == 0 || a[i].y == 0)
            Ans += 4;
        else
            Ans += 6;
    }
    
    printf("%d\n", Ans);
    for (i = 1; i <= n; i++)
    {
        if (a[i].x > 0)
            printf("1 %d R\n", a[i].x);
        if (a[i].x < 0)
            printf("1 %d L\n", 0 - a[i].x);
        if (a[i].y > 0)
            printf("1 %d U\n", a[i].y);
        if (a[i].y < 0)
            printf("1 %d D\n", 0 - a[i].y);
        printf("2\n");
        if (a[i].x > 0)
            printf("1 %d L\n", a[i].x);
        if (a[i].x < 0)
            printf("1 %d R\n", 0 - a[i].x);
        if (a[i].y > 0)
            printf("1 %d D\n", a[i].y);
        if (a[i].y < 0)
            printf("1 %d U\n", 0 - a[i].y);
        printf("3\n");
    }
    
    return 0;
}