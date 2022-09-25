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


int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif

    int n, a, b;
    cin >> n >> a >> b;
    if (n > a * b) {
        cout << -1 << '\n';
        return 0;
    }
    int x = 1, y = 2;
    forn (i, a) {
        forn (j, b) {
            int d = (i + j) % 2;
            if (d == 0) {
                if (x > n)
                    cout << 0 << ' ';
                else
                    cout << x << ' ';
                x += 2;
            } else {
                if (y > n)
                    cout << 0 << ' ';
                else
                    cout << y << ' ';
                y += 2;
            }
        }
        cout << '\n';
    }

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}