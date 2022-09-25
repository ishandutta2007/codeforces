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
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, k;
    int a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;
    set<int> bad;
    bad.insert(a);
    bad.insert(b);
    bad.insert(c);
    bad.insert(d);
    if (n == 4) {
        cout << -1 << '\n';
        return 0;
    }
    if (k <= n) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> path;
    for (int i = 1; i <= n; ++i) {
        if (bad.count(i))
            continue;
        path.push_back(i);
    }
    cout << a << ' ' << c;
    for (auto x: path)
        cout << ' ' << x;
    cout << ' ' << d << ' ' << b << '\n';
    cout << c << ' ' << a;
    for (auto x: path)
        cout << ' ' << x;
    cout << ' ' << b << ' ' << d << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}