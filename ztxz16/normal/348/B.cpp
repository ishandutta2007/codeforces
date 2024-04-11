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

using namespace std;

long long n, i, a, b, ss, val[100005];
long long e[200005], succ[200005], last[200005], sum;
long long Sum[200005], Del[200005];

long long gcd(long long a, long long b);
void dfs(long long i, long long f);

int main()
{
    scanf("%I64d", &n);
    for (i = 1; i <= n; i++)
        scanf("%I64d", &val[i]), ss += val[i];
    for (i = 1; i < n; i++)
    {
        scanf("%I64d %I64d", &a, &b);
        e[++sum] = b, succ[sum] = last[a], last[a] = sum;
        e[++sum] = a, succ[sum] = last[b], last[b] = sum;
    }
    
    dfs(1, 0);
    printf("%I64d\n", ss - Sum[1]);
    return 0;
}

long long gcd(long long a, long long b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void dfs(long long i, long long f)
{
    long long x, y, tag = 0, Gcd = 0, lcm = 1, Min;
    for (x = last[i]; x != 0; x = succ[x])
    {
        y = e[x];
        if (y == f)
            continue;
        dfs(y, i);
        if (tag == 0)
            Min = Sum[y];
        else
            Min = min(Min, Sum[y]);
        tag++;
    }
    
    if (tag == 0)
        Sum[i] = val[i], Del[i] = 1;
    else
    {
        for (x = last[i]; x != 0; x = succ[x])
        {
            y = e[x];
            if (y == f)
                continue;
            Gcd = gcd(lcm, Del[y]);
            lcm = lcm / Gcd * Del[y];
            if (lcm > Min)
            {
                printf("%I64d\n", ss);
                exit(0);
            }
        }
        
        Min = -1;
        for (x = last[i]; x != 0; x = succ[x])
        {
            y = e[x];
            if (y == f)
                continue;
            Sum[y] = Sum[y] / lcm * lcm;
            if (Min == -1 || Sum[y] < Min)
                Min = Sum[y];
        }
        
        Sum[i] = Min * tag;
        Del[i] = lcm * tag;
    }
    
    if (Sum[i] == 0)
    {
        printf("%I64d\n", ss);
        exit(0);
    }
    
    return;
}