#include <cstdio>
#include <algorithm>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

typedef long long llong;

llong MOD = 1000*1000*1000 + 7;

llong powmod(llong x, int p)
{
    llong ans = 1;
    ans %= MOD;
    while (p)
    {
        if (p & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }
    return ans;
}

const int N = 100500;

int A[N];
llong D[N];

int dv[N];
int dv2[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    sort(A, A + n);
    int pt, pt2;
    llong ans = 0;
    int mx = A[n - 1];
    for (int v = 1; v <= mx; v++)
    {
        pt = pt2 = 0;
        for (int x = 1; x * x <= v; x++)
        {
            if (v % x == 0)
            {
                dv[pt++] = x;
                if (x * x != v)
                    dv2[pt2++] = v / x;
            }
        }
        while (pt2 != 0)
            dv[pt++] = dv2[--pt2];
        //eprintf("%d\n", v);
        //for (int i = 0; i < pt; i++)
        //    eprintf("%d ", dv[i]);
        //eprintf("\n");
        dv[pt] = 1e9;
        //for (int i = 0; i < pt - 1; i++)
        //    D[v] = (D[v] + MOD - D[dv[i]]) % MOD;
        llong cur = 1;
        llong neg = 1;
        for (int i = 0; i < pt; i++)
        {
            int cnt = lower_bound(A, A + n, dv[i + 1]) - lower_bound(A, A + n, dv[i]);
            cur = (cur * powmod(i + 1, cnt)) % MOD;
            neg = (neg * powmod(i + 1 - (i == pt - 1), cnt)) % MOD;
        }
        D[v] = (D[v] + cur) % MOD;
        D[v] = (D[v] - neg + MOD) % MOD;
        //eprintf("D[%d] = %d\n", v, (int)D[v]);
        ans = (ans + D[v]) % MOD;
    }
    printf("%d\n", (int)ans);
    return 0;
}