#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int gcd(int a, int b) {
    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    int m = 1;
    forn (i, n) {
        int c;
        scanf("%d", &c);
        m = lcm(m, gcd(c, k));
    }
    cout << (m == k ? "Yes\n" : "No\n");

}