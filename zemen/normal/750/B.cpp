#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

void ass(bool ex) {
    if (!ex) {
        cout << "NO\n";
        exit(0);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    const int X = 20000;
    int n;
    cin >> n;
    int x = 0;
    forn (i, n) {
        int t;
        string dir;
        cin >> t >> dir;
        if (x == 0)
            ass(dir == "South");
        if (x == X)
            ass(dir == "North");

        if (dir == "North") {
            x -= t;
        } else if (dir == "South") {
            x += t;
        }
        ass(x >= 0 && x <= X);
    }
    ass(x == 0);
    cout << "YES\n";
}