#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1000100;
char s[maxn];

const int mod = 1e9 + 7;
void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    scanf("%s", s);
    int n = strlen(s);
    reverse(s, s + n);
    int c = 0;
    int res = 0;
    forn (i, n) {
        if (s[i] == 'a') {
            udd(res, c);
            udd(c, c);
        } else {
            udd(c, 1);
        }
    }
    cout << res << '\n';
}