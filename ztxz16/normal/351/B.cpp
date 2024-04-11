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

int a[100005], n, Ans, i, j;
double ans = 0;

int main()
{
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++)
            if (a[i] > a[j])
                Ans++;
    if (Ans % 2 == 0)
        printf("%.6f\n", 2.0 * Ans);
    else
        printf("%.6f\n", 2.0 * Ans - 1);
    return 0;
}