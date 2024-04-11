#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    vector<int> a(n);
    forn (i, n)
        cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0, best = inf * 2;
    forn (i, n - 1) {
        int c = a[i + 1] - a[i];
        if (c < best)
            best = c, cnt = 0;
        if (c == best)
            ++cnt;
    }
    cout << best << ' ' << cnt << '\n';
}