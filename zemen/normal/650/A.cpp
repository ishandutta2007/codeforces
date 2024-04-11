#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

map<int, int> cv, ch;
map<pair<int, int>, int> cc;

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    
    int n;
    cin >> n;
    ll res = 0;
    forn (i, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        res += cv[x];
        res += ch[y];
        res -= cc[make_pair(x, y)];
        cv[x]++, ch[y]++, cc[make_pair(x, y)]++;
    }
    cout << res << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}