#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llong;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#ifdef LOCAL
    #define I64D "%lld"
#else
    #define I64D "%I64d"
#endif

llong n, x, y, c;

llong get(llong d)
{
    llong V[4] = {d - y, d - x, d - (n - 1 - x), d - (n - 1 - y)};
    llong U[4] = {d - (x + y + 1), d - (1 + (n - 1 - 0) - (x - y)), d - (1 + (n - 1 - 0) - (y - x)), d - (1 + (n - 1 + n - 1) - (x + y))};
    //eprintf("%lld\n", d);
    //eprintf("%lld %lld %lld %lld\n", V[0], V[1], V[2], V[3]);
    //eprintf("%lld %lld %lld %lld\n", U[0], U[1], U[2], U[3]);
    llong ans = d * d + (d + 1) * (d + 1);
    for (int i = 0; i < 4; i++)
        V[i] = max(V[i], 0LL), ans -= V[i] * V[i];
    for (int i = 0; i < 4; i++)
        U[i] = max(U[i], 0LL), ans += U[i] * (U[i] + 1) / 2;
    return ans;
}

llong get2(llong d)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cnt += (abs(i - x) + abs(j - y)) <= d;
    return cnt;
}


int main()
{
    scanf(I64D" "I64D" "I64D" "I64D, &n, &x, &y, &c);
    --x, --y;
    llong a = -1, b = 2e9 + 42;

    /*for (n = 1; n <= 100; n++)
        for (x = 0; x < n; x++)
            for (y = 0; y < n; y++)
                for (c = 0; c <= 2 * n; c++)
                    if (get(c) != get2(c))
                    {
                        eprintf("OLOLO %lld %lld %lld %lld\n", n, x, y, c);
                    }*/


    //for (int i = 0; i <= 10; i++)
    //    eprintf("%d "I64D"\n", i, get(i));
    while (b - a > 1)
    {
        int m = (a + b) / 2;
        if (get(m) >= c)
            b = m;
        else
            a = m;
    }
    printf(I64D"\n", b);
}