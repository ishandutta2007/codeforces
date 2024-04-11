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
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int tn = 1;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

set<pair<int, int>> bd[2];

set<pair<int, int>> used;

int cut(int x, int y, int dir)
{
    auto it = bd[!dir].upper_bound(make_pair(-y, INF));
    assert(it != bd[!dir].begin());
    --it;
    int from = it->second;
    int res = x - from;

    it = bd[dir].upper_bound(make_pair(-from, INF));
    assert(it != bd[!dir].begin());
    --it;
    if (it->first <= -x)
        bd[dir].emplace(-from, it->second);
    bd[dir].emplace(-x, y);
    return res;
}

int solve()
{
    int n, q;
    cin >> n >> q;
    bd[0].emplace(-n, -1);
    bd[1].emplace(-n, -1);
    forn (i, q)
    {
        int x, y;
        char c;
        cin >> y >> x >> c;
        --x, --y;
        if (used.count(make_pair(x, y)))
            cout << 0 << '\n';
        else
        {
            used.insert(make_pair(x, y));
            if (c == 'U')
                cout << cut(x, y, 0) << '\n';
            else
                cout << cut(y, x, 1) << '\n';
        }
    }
    return 0;
}