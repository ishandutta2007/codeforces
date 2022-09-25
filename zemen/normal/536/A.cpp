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
    freopen("a.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

ll c2(ll x)
{
    return x * (x + 1) / 2;
}

int solve()
{
    ll a, b, n;
    cin >> a >> b >> n;
    forn (i, n)
    {
        int l, t, m;
        scanf("%d%d%d", &l, &t, &m);
        --l;
        if (a + l * b > t)
        {
            cout << -1 << '\n';
            continue;
        }
        ll L = l, R = 1e9;
        while (L + 1 < R)
        {
            ll r = (L + R) / 2;
            ll moves = a + r * b;
            ll sum = (r - l + 1) * a;
            sum += (c2(r) - c2(l - 1)) * b;
            moves = max(moves, (sum + m - 1) / m);
            if (moves > t)
                R = r;
            else
                L = r;
        }
        cout << L + 1 << '\n';
    }
    return 0;
}