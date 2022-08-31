#include <cstdio>
using namespace std;

const int MOD = 1000*1000*1000 + 7;
typedef long long llong;

inline int powmod(int x, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ((llong)ans * x) % MOD;
        x = ((llong)x * x) % MOD;
        p /= 2;
    }
    return ans;
}

inline int inv(int x)
{
    return powmod(x, MOD - 2);
}

const int N = 2050;
int A[N];
int B[N];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    --k;
    int ans = 0;
    int cur = 1;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
    for (int i = 0; i < n; i++)
    {
        eprintf("%d ", cur);
        for (int j = i; j < n; j++)
            B[j] = (B[j] + (llong)cur * A[j - i]) % MOD;
        cur = (((llong)cur * (k + i + 1)) % MOD) * (llong)inv(i + 1) % MOD;
    }
    eprintf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", B[i]);
    return 0;
}