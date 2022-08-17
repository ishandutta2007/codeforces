#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;

typedef long long llong;

llong pw10[20];

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

int len(llong x)
{
    assert(x != 0);
    int ans = 0;
    while (x != 0)
    {
        x /= 10;
        ans++;
    }
    return ans;
}

llong get(llong x)
{
    if (x == 0)
        return 0;
    int l = len(x);
    llong ans = 0;
    if (l == 1)
        return x;
    ans = 9;
    for (int i = 2; i < l; i++)
        ans += 9 * pw10[i - 2];
    char buf[20];
    sprintf(buf, "%I64d\n", x);
    int f = buf[0] - '0';
    int g = buf[l - 1] - '0';
    for (int i = 1; i < f; i++)
        ans += pw10[l - 2];
    llong quof = (x - f * pw10[l - 1] - g) / 10;
    if (g >= f)
        ans += quof + 1;
    else
        ans += quof;
    return ans;
}

int main()
{
    pw10[0] = 1;
    for (int i = 1; i < 20; i++)
        pw10[i] = pw10[i - 1] * 10;
    llong a, b;
    #ifdef LOCAL
        scanf("%lld %lld", &a, &b);
    #else
        scanf("%I64d %I64d", &a, &b);
    #endif
    llong p = get(b);
    llong q = get(a - 1);
    eprintf("%lld %lld\n", p, q);
    llong ans = get(b) - get(a - 1);
    cout << ans << endl;
}