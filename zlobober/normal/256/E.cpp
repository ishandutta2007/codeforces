#include <cstdio>
#include <memory.h>
#include <cassert>
using namespace std;

typedef long long llong;

#define LLD "%lld"

llong MOD = 777777777;

const int N = 1 << 17;

struct dyn
{
    llong V[3][3];
    bool fict;
    dyn()
    {
        fict = false;
    }
    inline llong* const operator[](int i)
    {
        return V[i];
    }
};

dyn NONE;

dyn T[2 * N];
int R[N + 42];
int TL[2 * N], TR[2 * N];

int G[3][3];

inline bool match(int x, int y)
{
    return y == -1 || x == y;
}

dyn merge(dyn A, dyn B, int y)
{
    if (A.fict)
        return B;
    if (B.fict)
        return A;
    dyn C;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
        {
            C[a][b] = 0;
            for (int c = 0; c < 3; c++)
                C[a][b] = (C[a][b] + match(c, R[y]) * (A[a][c] * B[c][b])) % MOD;
        }
    return C;
}

dyn get(int l, int r, int L, int R, int v)
{
    if (r < L || l > R)
        return NONE;
    if (l <= L && R <= r)
        return T[v];
    dyn a = get(l, r, L, (L + R) / 2, 2 * v);
    dyn b = get(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
    dyn c = merge(a, b, (L + R) / 2 + 1);
    return c;
}

void set(int x, int v)
{
    R[x] = v;
    x += N - 1;
    for (int a = 0; a < 3; a++)
        for (int b = 0; b < 3; b++)
            T[x][a][b] = G[a][b] * match(a, v);
    while (x >>= 1)
        T[x] = merge(T[2 * x], T[2 * x + 1], TL[2 * x + 1]);
}

int main()
{
    NONE.fict = true;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &G[i][j]);
    memset(R, -1, sizeof(R));
    for (int i = N; i < 2 * N; i++)
    {
        TL[i] = TR[i] = i - N + 1;
        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                T[i][a][b] = G[a][b];
    }

    for (int i = N - 1; i > 0; i--)
        T[i] = merge(T[2 * i], T[2 * i + 1], TL[2 * i + 1]);
    for (int i = 0; i < m; i++)
    {
        int x, v;
        scanf("%d %d", &x, &v);
        --v;
        set(x, v);
        llong ans = 0;
        if (n == 1)
            ans = (R[1] == -1) ? 3 : 1;
        else
        {
            dyn res = get(1, n - 1, 1, N, 1);
            assert(!res.fict);
            for (int a = 0; a < 3; a++)
                for (int b = 0; b < 3; b++)
                    ans = (ans + res[a][b] * match(a, R[1]) * match(b, R[n])) % MOD;
        }
        printf(LLD"\n", ans);
    }
}