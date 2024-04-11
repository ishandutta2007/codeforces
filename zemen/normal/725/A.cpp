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
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    reverse(t.begin(), t.end());
    int l = 0, r = 0;
    while (l < n && s[l] == '<')
        ++l;
    while (r < n && t[r] == '>')
        ++r;
    if (l == n)
        cout << n << '\n';
    else
        cout << l + r << '\n';
}