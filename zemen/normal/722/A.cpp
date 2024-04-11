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
    int fmt;
    string s;
    cin >> fmt >> s;
    int hours = (s[0] - '0') * 10 + (s[1] - '0');
    if (fmt == 12 && (hours <= 0 || hours > 12)) {
        if (s[1] == '0')
            s[0] = '1';
        else
            s[0] = '0';
    }
    if (fmt == 24 && hours >= 24)
        s[0] = '0';
    if (s[3] > '5')
        s[3] = '0';
    cout << s << '\n';
}