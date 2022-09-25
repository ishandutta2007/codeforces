#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
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
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int c1 = 0, c2 = 0;
    int i = 0;
    while (c1 < n) {
        if (i && i % t == 0)
            c1 += k, c2 += k;

        int j = i - d;
        if (j > 0 && j % t == 0)
            c2 += k;

        if (c2 >= n && c1 < n) {
            cout << "YES\n";
            return 0;
        }
        ++i;
    }
    cout << "NO\n";
}