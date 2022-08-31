#include <iostream>
#include <map>
using namespace std;

typedef long long llong;

const llong MOD = 1000000007;

inline llong mul(llong x, llong y)
{
    return ((x * y) % MOD + MOD) % MOD;
}

inline llong sum(llong x, llong y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

inline void SUM(llong& x, llong y)
{
    x = sum(x, y);
}

inline void MUL(llong& x, llong y)
{
    x = mul(x, y);
}

int POW(llong x, llong y)
{
    return (y == 0) ? 1 : mul(1 + ((y % 2) * (x - 1)), POW(mul(x, x), y / 2));
}

const int N = 1050;

inline llong div(llong x, llong y)
{
    return mul(x, POW(y, MOD - 2));
}

llong F[N * N];

void count_F()
{
    F[0] = 1;
    for (int i = 1; i < N * N; i++)
        F[i] = mul(F[i - 1], i);
}

const int NN = 2 * N;
llong _C[NN][NN];

void count_C()
{
    _C[0][0] = 1;
    for (int x = 1; x < NN; x++)
        for (int y = 0; y <= NN; y++)
            _C[x][y] = sum((y != 0) * _C[x - 1][y - 1], (y != x) * _C[x - 1][y]);
}

//map<

llong C(llong n, llong k)
{
    if (n < NN)
        return _C[n][k];
    return div(div(F[n], F[k]), F[n - k]);
}

int main()
{
    count_C();
    count_F();
    int n, m, k;
    cin >> n >> m >> k;
    llong ans = 0;
    if (m == 1)
    {
        ans = POW(k, n);
    }
    else
    {
        llong D[N];
        //for (int q = 1; q < N; q++)
        //    for (int p = 0; p <= q; p++)
        //        D[q][p] = sum(mul(p, D[q - 1][p]), mul((q - p + 1), D[q - 1][p - 1]));
        for (int c = 1; c < N; c++)
        {
            D[c] = POW(c, n);
            for (int i = c - 1; i >= 1; i--)
            {
                SUM(D[c], mul(-C(c, i), D[i]));
            }
        }

        for (int tot = 1; tot <= min(k, 2 * n); tot++)
        {
            llong tcans = C(k, tot);
            for (int com = (tot % 2); com <= tot; com += 2)
            {
                llong cans = 1;
                int side = (tot - com) / 2;
                if (side + com > n)
                    continue;
                MUL(cans, mul(tcans, mul(C(tot,com), C(tot - com,side))));
                MUL(cans, POW(com, (n * m) - 2 * n));
                MUL(cans, mul(D[side + com], D[side + com]));
                SUM(ans, cans);
            }
        }
    }
    cout << ans;
}