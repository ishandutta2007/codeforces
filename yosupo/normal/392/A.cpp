#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    if (!n) {
        cout << 1 << endl;
        return 0;
    }
    ll m = n;
    ll res = n;
    for (ll i = 1; i <= n; i++) {
        ll u = m;
        while (u*u + i*i > n*n) u--;
        res += max(0LL, m-u-1);
        m = u;
    }
    cout << res * 4 << endl;
    return 0;
}