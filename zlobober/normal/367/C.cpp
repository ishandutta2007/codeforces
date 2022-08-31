#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

typedef long long llong;

llong get(llong k)
{
    if (k == 1)
        return 1;
    else if (k % 2 == 1)
        return k * (k - 1) / 2 + 1;
    else
        return k * k / 2;
}

const int N = 2000500;
int A[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d %d", &t, &A[i]);
    }
    sort(A, A + m);
    reverse(A, A + m);
    int res = -1;
    if (get(m) <= n)
        res = m;
    else
    {
        int a = 1, b = m;
        while (b - a > 1)
        {
            int q = (a + b) / 2;
            if (get(q) <= n)
                a = q;
            else
                b = q;
        }
        res = a;
    }
    assert(res <= m && get(res) <= n);
    fprintf(stderr, "%d -> %d (%d)\n", n, res, (int)get(res));
    llong sum = 0;
    for (int i = 0; i < res; i++)
        sum += A[i];
#ifdef LOCAL42
    printf("%lld\n", sum);
#else
    printf("%I64d\n", sum);
#endif
}