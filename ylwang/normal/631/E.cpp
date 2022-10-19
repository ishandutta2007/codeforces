#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 200005
#define K(x, y) ((1.0 * w[x] - w[y]) / (1.0 * (x) - (y)))
#define Calc1(x, y) (sum[(x) - 1] - sum[(y) - 1] - a[x] * ((x) - (y)))
#define Calc2(x, y) (a[x] * ((y) - (x)) - (sum[(y)] - sum[(x)]))

using namespace std;
#define LL long long

int n, stk[maxn], top = 0;
LL a[maxn], sum[maxn], ans = 0, w[maxn], res = 0;

inline int read()
{
    char ch = getchar();
    int ret = 0, f = 1;
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        ret = ret * 10 + ch - '0', ch = getchar();
    return ret * f;
}

int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
        ans += 1ll * i * a[i];
    }
    stk[1] = 1, stk[2] = 2, top = 2;
    w[1] = sum[0], w[2] = sum[1];
    res = max(0ll, Calc1(2, 1));
    for (int i = 3; i <= n; ++i)
    {
        int l = 1, r = top - 1, j = stk[top];
        while (l <= r)
        {
            int mid = (r - l >> 1) + l;
            if (K(stk[mid + 1], stk[mid]) > a[i])
                r = mid - 1, j = stk[mid];
            else
                l = mid + 1;
        }
        res = max(res, Calc1(i, j));
        w[i] = sum[i - 1];
        while (top > 1)
        {
            if (K(i, stk[top]) > K(stk[top], stk[top - 1]))
                break;
            --top;
        }
        stk[++top] = i;
    }
    stk[1] = n, stk[2] = n - 1, top = 2;
    w[n] = sum[n], w[n - 1] = sum[n - 1];
    res = max(res, Calc2(n - 1, n));
    for (int i = n - 3; i > 0; --i)
    {
        int l = 1, r = top - 1, j = stk[top];
        while (l <= r)
        {
            int mid = (r - l >> 1) + l;
            if (K(stk[mid + 1], stk[mid]) < a[i])
                r = mid - 1, j = stk[mid];
            else
                l = mid + 1;
        }
        res = max(res, Calc2(i, j));
        w[i] = sum[i];
        while (top > 1)
        {
            if (K(i, stk[top]) < K(stk[top], stk[top - 1]))
                break;
            --top;
        }
        stk[++top] = i;
    }
    printf("%I64d\n", ans + res);
    return 0;
}