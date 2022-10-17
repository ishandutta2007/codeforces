#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int n;
ll a[N], b[N], c[N];
ll ans, K;
void f()
{
    for (int i = 0; i < (1 << n); i++)
    {
        int x = -1, y = -1;
        int dx = 0, dy = n;
        ll sx = 0, sy = 0;
        bool ok = 1;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                if (x == -1)
                    x = j;
                else
                    ok &= (dx <= j - x), dx = j - x, x = j;
                sx += a[j];
            }
            else
            {
                if (y == -1)
                    y = j;
                else
                    ok &= (dy >= j - y), dy = j - y, y = j;
                sy += a[j];
            }
        }
        if (!ok)
            continue;
        ans += (sx < sy);
        // ans++;
        // if ((sx < sy))
        // {
        //     for (int j = 0; j < n; j++)
        //         cerr << ((i >> j) & 1);
        //     // cerr << "   " << dx << " " << dy;
        //     cerr << endl;
        // }
    }
}
/*
x < s - x
2x < s

0 111111 010101  0000000 1

0|1||0001
||01|0001

00000000 1111111
*/

ll get(int l, int r)
{
    if (l > r)
        return 0;
    if (l)
        return b[r] - b[l - 1];
    else
        return b[r];
}
ll get2(int l, int r)
{
    if ((l ^ r) & 1)
        r--;
    if (l > r)
        return 0;
    if (l > 1)
        return c[r] - c[l - 2];
    else
        return c[r];
}

void solve()
{
    ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] *= 2;
        c[i] = b[i] = a[i];
        if (i)
            b[i] += b[i - 1];
        if (i > 1)
            c[i] += c[i - 2];
    }
    K = b[n - 1] / 2;
    if (n < 5)
    {
        f();
    }
    else
    {
        // f();
        // cerr << ans << endl;
        ans = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            // cerr << "A: " << i << endl;

            {
                ll s = get(0, i);
                if (s < K)
                {
                    int l = 0, r = n;
                    while (l <= r)
                    {
                        int m = (l + r) / 2;
                        if (i + 2 * m < n && s + get2(i + 2, i + 2 * m) < K)
                            l = m + 1;
                        else
                            r = m - 1;
                    }
                    ans += l;
                }
            }
            // cerr << "#1: ";
            // cerr << ans << endl;
            if (i)
            {
                ll s = get(1, i);
                if (s < K)
                {
                    int l = 0, r = n;
                    while (l <= r)
                    {
                        int m = (l + r) / 2;
                        if (i + 2 * m < n && s + get2(i + 2, i + 2 * m) < K)
                            l = m + 1;
                        else
                            r = m - 1;
                    }
                    ans += l;
                }
            }

            // cerr << "#2: ";
            // cerr << ans << endl;

            if (i + 2 < n)
            {
                ll s = get(0, i) + a[n - 1];
                if (s < K)
                {
                    int l = 0, r = n;
                    while (l <= r)
                    {
                        int m = (l + r) / 2;
                        if (i + 2 * m < n - 2 && s + get2(i + 2, i + 2 * m) < K)
                            l = m + 1;
                        else
                            r = m - 1;
                    }
                    ans += l;
                }
            }

            // cerr << "#3: ";
            // cerr << ans << endl;

            if (i && i + 2 < n)
            {
                ll s = get(1, i) + a[n - 1];
                if (s < K)
                {
                    int l = 0, r = n;
                    while (l <= r)
                    {
                        int m = (l + r) / 2;
                        if (i + 2 * m < n - 2 && s + get2(i + 2, i + 2 * m) < K)
                            l = m + 1;
                        else
                            r = m - 1;
                    }
                    // cerr << "__" << l << " " << s << " " << get2(i + 2, i + 2) << endl;
                    ans += l;
                }
            }

            // cerr << "#4: ";
            // cerr << ans << endl;
            if (i + 2 < n && ((n - i) & 1))
            {
                if (get(0, i) + get2(i + 2, n - 1) < K)
                    ans--;
                if (i && get(1, i) + get2(i + 2, n - 1) < K)
                    ans--;
            }

            // cerr << "#5: ";
            // cerr << ans << endl;
        }
        for (int i = 0; i <= n; i++)
            if (get(i, n - 1) < K)
                ans++;
    }

    printf("%lld\n", ans % mod);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}