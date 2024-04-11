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
    int n, t;
    string s;
    cin >> n >> t >> s;
    int p = 0;
    while (s[p] != '.')
        ++p;
    string A = s.substr(0, p);
    string B = s.substr(p + 1);
    int c = 0;
    while (c < sz(B) && B[c] <= '4')
        ++c;
    if (c == sz(B)) {
        cout << s << '\n';
        return 0;
    }
    --c;
    --t;
    while (t > 0 && c >= 0 && B[c] == '4')
        --c, --t;
    if (c >= 0) {
        B.resize(c + 1);
        B.back()++;
        cout << A << "." << B << '\n';
        return 0;
    }
    A.back()++;
    c = sz(A) - 1;
    while (c > 0 && A[c] > '9') {
        A[c - 1]++;
        A[c] = '0';
        --c;
    }
    if (A[0] > '9') {
        A[0] = '0';
        A.insert(A.begin(), '1');
    }
    cout << A << '\n';
}