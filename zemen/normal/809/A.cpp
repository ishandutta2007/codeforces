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

const int mod = 1e9 + 7;
void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
int mul(ll a, ll b) {
    return a * b % mod;
}

const int maxn = 300300;
int x[maxn];
int p2[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    p2[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p2[i] = p2[i - 1];
        udd(p2[i], p2[i - 1]);
    }
    int n;
    cin >> n;
    forn (i, n)
        cin >> x[i];
    sort(x, x + n);
    int s = 0;
    forn (i, n) {
        int coef = p2[i];
        udd(coef, mod - p2[n - i - 1]);
        udd(s, mul(coef, x[i]));
    }
    cout << s << '\n';
}