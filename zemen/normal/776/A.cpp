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
    string a, b;
    int n;
    cin >> a >> b >> n;
    cout << a << ' ' << b << '\n';
    forn (i, n) {
        string old, nw;
        cin >> old >> nw;
        if (a == old)
            a = nw;
        else
            b = nw;
        cout << a << ' ' << b << '\n';
    }
}