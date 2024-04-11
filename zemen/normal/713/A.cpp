#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

map<ll, int> a;

ll dec(string s) {
    reverse(s.begin(), s.end());
    ll res = 0;
    forn (i, sz(s))
        res |= (((s[i] - '0') % 2) << i);
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int q;
    cin >> q;
    forn (i, q) {
        char op;
        string s;
        cin >> op >> s;
        ll x = dec(s);
        if (op == '+') {
            a[x]++;
        } else if (op == '-') {
            a[x]--;
        } else {
            cout << a[x] << '\n';
        }
    }
}