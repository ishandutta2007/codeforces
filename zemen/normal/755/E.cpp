#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

void ass(bool x) {
    if (!x) {
        cout << -1 << '\n';
        exit(0);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    ass(n >= 4);
    ass(k == 2 || k == 3);
    ass(n != 4 || k != 2);
    if (k == 2) {
        cout << n - 1 << '\n';
        forn (i, n - 1)
            cout << i + 1 << ' ' << i + 2 << '\n';
        return 0;
    }
    cout << n - 1 << '\n';
    forn (i, n - 2)
        cout << 1 << ' ' << i + 2 << '\n';
    cout << 2 << ' ' << n << '\n';
}