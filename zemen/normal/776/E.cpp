#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

ll phi(ll n) {
    ll res = 1;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i)
            continue;
        res *= i - 1;
        n /= i;
        while (n % i == 0) {
            res *= i;
            n /= i;
        }
    }
    if (n > 1)
        res *= n - 1;
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i <= k; ++i) {
        if (i % 2 == 0)
            continue;
        n = phi(n);
        if (n == 1)
            break;
    }
    cout << n % ll(1000000007) << '\n';
}