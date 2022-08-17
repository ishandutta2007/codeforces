#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 1050;
int S[N];
int A[N];

typedef long long llong;

const int mod = 1000 * 1000 * 1000 + 7;
const llong mod2 = (llong)mod * mod;
const int M = 10500;
int D[N][2 * M];

inline int sum(int l, int r)
{
    return S[r] - S[l - 1];
}

int ans = 0;

#ifdef LOCAL42
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

void go(int l, int r)
{
    if (l == r)
        return;
    go(l, (l + r) / 2);
    go((l + r) / 2 + 1, r);

    int q = (l + r) / 2;
    D[l - 1][M] = 1;

    for (int i = l - 1; i <= q - 1; i++)
    {
        for (int v = -sum(l, i + 1); v <= sum(l, i + 1); v++)
            D[i + 1][M + v] = 0;
        if (i + 1 != q)
            D[i + 1][M] += 1;
        for (int v = -sum(l, i); v <= sum(l, i); v++)
        {
            D[i + 1][M + v + A[i + 1]] += D[i][M + v];
            D[i + 1][M + v - A[i + 1]] += D[i][M + v];
            if (D[i + 1][M + v + A[i + 1]] >= mod)
                D[i + 1][M + v + A[i + 1]] -= mod;
            if (D[i + 1][M + v - A[i + 1]] >= mod)
                D[i + 1][M + v - A[i + 1]] -= mod;
        }
    }
    D[r + 1][M] = 1;
    for (int i = r + 1; i >= q + 2; i--)
    {
        for (int v = -sum(i - 1, r); v <= sum(i - 1, r); v++)
            D[i - 1][M + v] = 0;
        if (i - 1 != q + 1)
            D[i - 1][M] += 1;
        for (int v = -sum(i, r); v <= sum(i, r); v++)
        {
            D[i - 1][M + v + A[i - 1]] += D[i][M + v];
            D[i - 1][M + v - A[i - 1]] += D[i][M + v];
            if (D[i - 1][M + v + A[i - 1]] >= mod)
                D[i - 1][M + v + A[i - 1]] -= mod;
            if (D[i - 1][M + v - A[i - 1]] >= mod)
                D[i - 1][M + v - A[i - 1]] -= mod;
        }
    }
    llong cur = 0;
    for (int u = -min(sum(l, q), sum(q + 1, r)); u <= min(sum(l, q), sum(q + 1, r)); u++)
    {
        cur = cur + (llong)D[q][M + u] * D[q + 1][M - u];
        if (cur >= mod2)
            cur -= mod2;
    }
    cur = cur % mod;
    eprintf("[%d,%d]|[%d,%d] -> %d\n", l, q, q + 1, r, (int)cur);
    ans = ans + cur;
    if (ans >= mod)
        ans -= mod;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]), S[i] = S[i - 1] + A[i];
    go(1, n);
    printf("%d\n", ans);
    return 0;
}