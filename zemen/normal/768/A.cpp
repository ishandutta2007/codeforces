#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
int a[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    int mn = *min_element(a, a + n);
    int mx = *max_element(a, a + n);
    int res = 0;
    forn (i, n)
        if (mn < a[i] && a[i] < mx)
            res++;
    cout << res << '\n';
}