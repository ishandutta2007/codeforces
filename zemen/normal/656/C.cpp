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

int ind(char c) {
    if (islower(c))
        return c - 'a' + 1;
    else
        return c - 'A' + 1;
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    string s;
    cin >> s;
    int res = 0;
    for (auto c: s) {
        if ('@' < c && '[' > c) {
            res += ind(c);
        }
        if ('`' < c && '{' > c)
            res -= ind(c);
    }
    cout << res << '\n';

    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}