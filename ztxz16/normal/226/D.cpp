#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, j, tag, s1[105], s2[105], a[105][105];
int Count1[105], Count2[105], Ans1[105], Ans2[105], t1, t2;

void turn(int i, int j);
void turn1(int i);
void turn2(int j);

int main()
{

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            s1[i] += a[i][j], s2[j] += a[i][j];
    while (1)
    {
        tag = 0;
        for (i = 1; i <= n; i++)
            if (s1[i] < 0)
                turn1(i), tag = 1;
        for (i = 1; i <= j; i++)
            if (s2[i] < 0)
                turn2(i), tag = 1;
        if (tag == 0)
            break;
    }
    
    for (i = 1; i <= n; i++)
        if (Count1[i] == 1)
            Ans1[++t1] = i;
    for (i = 1; i <= m; i++)
        if (Count2[i] == 1)
            Ans2[++t2] = i;
    printf("%d ", t1);
    for (i = 1; i <= t1; i++)
        printf("%d ", Ans1[i]);
    printf("\n%d ", t2);
    for (i = 1; i <= t2; i++)
        printf("%d ", Ans2[i]);
    printf("\n");
    return 0;
}

void turn(int i, int j)
{
    int del = (0 - a[i][j]) - a[i][j];
    s1[i] += del, s2[j] += del;
    a[i][j] = 0 - a[i][j];
    return;
}

void turn1(int i)
{
    int j;
    Count1[i] ^= 1;
    for (j = 1; j <= m; j++)
        turn(i, j);
    return;
}

void turn2(int j)
{
    int i;
    Count2[j] ^= 1;
    for (i = 1; i <= n; i++)
        turn(i, j);
    return;
}