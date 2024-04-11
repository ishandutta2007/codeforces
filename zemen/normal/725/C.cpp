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
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    string s;
    cin >> s;
    forn (i, sz(s) - 1)
        if (s[i] == s[i + 1]) {
            cout << "Impossible\n";
            return 0;
        }
    set<char> S;
    forn (i, sz(s)) {
        if (S.count(s[i])) {
            rotate(s.begin(), s.begin() + i, s.end());
            break;
        }
        S.insert(s[i]);
    }
    //cerr << s << '\n';
    int to = 1;
    while (s[to] != s[0])
        ++to;
    s.erase(s.begin() + to);
    int sh = (to + 1) / 2;
    string A = s.substr(sh + 13) + s.substr(0, sh);
    string B = s.substr(sh, 13);
    reverse(B.begin(), B.end());
    cout << A << '\n' << B << '\n';
}