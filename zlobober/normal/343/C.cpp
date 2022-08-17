#include <cstdio>
#include <algorithm>
using namespace std;

#ifdef LOCAL42
    #define LLD "%lld"
#else
    #define LLD "%I64d"
#endif

typedef long long llong;

const int N = 100500;
llong X[N], P[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf(LLD, &X[i]);
    for (int i = 0; i < m; i++)
        scanf(LLD, &P[i]);
    llong a = -1, b = (llong)3e10;
    while (b - a > 1)
    {
        llong x = (a + b) / 2;
        int pt = 0;
        bool good = false;
        for (int i = 0; i < n; i++)
        {
            if (pt == m)
                break;
            llong q = X[i];
            llong r = P[pt];
            if (abs(q - r) > x)
                continue;
            int u = pt, v = m;
            while (v - u > 1)
            {
                int w = (u + v) / 2;
                if ((q < r) && (P[w] - q) <= x || (q >= r) && (min(abs(P[w] - r) + abs(q - r), abs(P[w] - q) + abs(P[w] - r)) <= x))
                    u = w;
                else
                    v = w;
            }
            pt = v;
        }
        if (pt == m)
            b = x;
        else
            a = x;
    }
    printf(LLD "\n", b);
    return 0;
}