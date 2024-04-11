#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
int p[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    set<int> vals;
    int ans = 0;
    forn (i, n) {
        cin >> p[i];
        --p[i];
        if (i == p[i])
            ++ans;
        else
            vals.insert(p[i]);
    }
    assert(sz(vals) % 2 == 0);
    ans += sz(vals) / 2;
    cout << ans << '\n';
}