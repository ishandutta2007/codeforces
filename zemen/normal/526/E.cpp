#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("e.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 1000010;

int a[maxn];
int dk[maxn];
ll ds[maxn];
ll pr[maxn];

int solve()
{
    int n, q;
    scanf("%d%d", &n, &q);
    forn (i, n)
    {
        scanf("%d", a + i);
        pr[i + 1] = pr[i] + a[i];
    }
    ll all = pr[n];
    forn (qw, q)
    {
        ll b;
        cin >> b;
        ll sum = 0;
        int l = 0;
        int r = 0;
        while (r < n && a[r] + sum <= b)
        {
            sum += a[r];
            dk[r] = 0;
            ds[r] = sum;
            ++r;
        }
        int res = n;
        if (all <= b)
            res = 1;
        while (r < n)
        {
            sum += a[r];
            while (sum > b)
                sum -= a[l++];
            dk[r] = dk[l - 1] + 1;
            ds[r] = ds[l - 1];
            ll rem = all - pr[r + 1];
            if (rem <= b)
                res = min(res, dk[r] + 1 + (rem + ds[r] > b));
            ++r;
        }
        cout << res << '\n';
    }
    return 0;
}