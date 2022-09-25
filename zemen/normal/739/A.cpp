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
    int n, m;
    cin >> n >> m;
    int worst = n;
    forn (i, m) {
        int l, r;
        cin >> l >> r;
        --l;
        worst = min(worst, r - l);
    }
    cout << worst << '\n';
    forn (i, n)
        cout << i % worst << ' ';
    cout << '\n';
}