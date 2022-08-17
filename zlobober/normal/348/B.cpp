#include <cstdio>
#include <memory.h>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long llong;

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

const int N = 100500;

llong sum = 0;

llong A[N];

void die()
{
    printf(LLD "\n", sum);
    exit(0);
}


inline llong gcd(llong a, llong b)
{
    while (b)
        a %= b, swap(a, b);
    return a;
}

llong inf = N * 1e8;


inline llong lcm(llong a, llong b)
{
    a /= gcd(a, b);
    if (a > inf / b)
        die();
    return (a * b);
}


vector<int> E[N];



llong Q[N];

llong g = 1;

void DFS(int x, int p = -1, llong c = 1)
{
    if (c > inf)
        die();
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] == p)
            E[x].erase(E[x].begin() + i), --i;
    int d = E[x].size();
    if (d == 0)
        Q[x] = c, g = lcm(g, c);
    else
    {
        assert(!A[x]);
        for (int i = 0; i < E[x].size(); i++)
            DFS(E[x][i], x, c * d);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf(LLD, &A[i]), sum += A[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    memset(Q, -1, sizeof(Q));
    DFS(1);
    llong mn = 1e18;
    for (int i = 1; i <= n; i++)
        if (Q[i] != -1)
        {
            assert(g % Q[i] == 0);
            Q[i] = g / Q[i];
            mn = min(mn, A[i] / Q[i]);
        }
    llong ans = 0;
    for (int i = 1; i <= n; i++)
        if (Q[i] != -1)
        {
            assert(A[i] >= Q[i] * mn);
            ans += A[i] - Q[i] * mn;
        }
    printf(LLD "\n", ans);
    return 0;
}