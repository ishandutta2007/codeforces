#include <cstdio>
using namespace std;

typedef long long llong;

#ifdef LOCAL
    #define I64d "%lld"
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define I64d "%I64d"
    #define eprintf(...) 42
#endif

const int N = 60;
llong D[N + 2][N + 2][2];
int R[N + 2];

int main()
{
    llong n, t;
    scanf(I64d" "I64d, &n, &t);
    ++n;
    int q = 0;
    while ((1LL << q) < t)
        q++;
    if ((1LL << q) != t)
    {
        printf("0\n");
        return 0;
    }
    q++;
    eprintf("counting [2..%lld] having %d bits (!without first row!)\n", n, q);
    for (int i = 0; i < N; i++)
        R[i] = (n >> (N - 1 - i)) & 1;
    D[0][0][0] = 1;
    for (int i = 0; i < N - 1; i++)
    {
        for (int v = 0; v <= i + 1; v++)
            for (int ot = 0; ot < 2; ot++)
            {
                for (int u = 0; u < (ot ? 2 : R[i + 1] + 1); u++)
                    D[i + 1][v + (u == 1)][ot || u != R[i + 1]] += D[i][v][ot];
            }
    }
    llong ans = D[N - 1][q][0] + D[N - 1][q][1];
    if (q == 1)
        ans--;
    printf(I64d"\n", ans);
    return 0;
}