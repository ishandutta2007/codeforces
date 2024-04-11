#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

bool isPr(int n) {
    bool pr = true;
    for (int i = 2; i * i <= n; ++i) {
        if (i < n && n % i == 0)
            pr = false;
    }
    return pr;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    if (isPr(n)) {
        cout << 1 << '\n';
        return 0;
    }
    if (n % 2 == 0)
        cout << 2 << '\n';
    else {
        if (isPr(n - 2))
            cout << 2 << '\n';
        else
            cout << 3 << '\n';
    }
}