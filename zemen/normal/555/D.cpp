#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

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
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

const int maxn = 300001;

int x[maxn];
pair<int, int> xx[maxn];
int revp[maxn];
int n;

int calc(int a, int l)
{
    int b = upper_bound(x, x + n, x[a] + l) - x - 1;
    l -= x[b] - x[a];
    int c = lower_bound(x, x + n, x[b] - l) - x;
    l -= x[b] - x[c];
    if (a == b && b == c)
        return a;
    if (a == c)
    {
        int len = abs(x[b] - x[a]);
        int q = l / len;
        l %= len;
        if (q % 2)
        {
            c = lower_bound(x, x + n, x[b] - l) - x;
            l -= x[b] - x[c];
        }
    }
    return calc(c, l);
}

int solve()
{
    int m;
    cin >> n >> m;
    forn (i, n)
    {
        cin >> xx[i].first;
        xx[i].second = i;
    }
    sort(xx, xx + n);
    forn (i, n)
        x[i] = xx[i].first;
    forn (i, n)
        revp[xx[i].second] = i;
    forn (i, m)
    {
        int a, l;
        cin >> a >> l;
        --a;
        a = revp[a];
        cout << xx[calc(a, l)].second + 1 << '\n';
    }
    return 0;
}