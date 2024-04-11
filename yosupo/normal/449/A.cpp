#include <iostream>

using namespace std;
typedef long long ll;
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (n-1+m-1 < k) {
        cout << -1 << endl;
        return 0;
    }
    if (n > m) swap(n, m);
    ll r = 0;
    if (n < 1000) {
        for (int i = 1; i <= n; i++) {
            ll u = n/i-1;
            ll kk = k-u;
            if (kk <= 0) {
                r = max(r, i*m);
            } else if (kk < m) {
                r = max(r, m/(kk+1)*i);
            }
        }
    }
    if (k < n) {
        r = max(r, n/(k+1)*m);
    }
    if (k < m) {
        r = max(r, m/(k+1)*n);
    }
    if (n <= k) {
        ll kk = k-n+1;
        r = max(r, m/(kk+1));
    }
    if (m <= k) {
        ll kk = k-m+1;
        r = max(r, n/(kk+1));
    }
    cout << r << endl;
    return 0;
}