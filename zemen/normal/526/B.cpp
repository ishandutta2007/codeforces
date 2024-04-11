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
    freopen("b.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

int a[1 << 15];
int base;
ll ans = 0;

int calc(int u)
{
    if (u >= base)
        return 0;
    int l = calc(u * 2) + a[u * 2];
    int r = calc(u * 2 + 1) + a[u * 2 + 1];
    ans += abs(l - r);
    return max(l, r);
}

int solve()
{
    int n;
    cin >> n;
    base = (1 << n);
    forn (i, (1 << (n + 1)) - 2)
        cin >> a[i + 2];
    calc(1);
    cout << ans << '\n';
    return 0;
}