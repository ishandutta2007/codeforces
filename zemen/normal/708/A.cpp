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
    string s;
    cin >> s;
    int x = 0;
    int n = s.size();
    while (s[x] == 'a')
        ++x;
    if (x == n) {
        s[n - 1] = 'z';
    } else {
        for (int i = x; i < n; ++i) {
            if (s[i] == 'a')
                break;
            s[i]--;
        }
    }
    cout << s << '\n';
}