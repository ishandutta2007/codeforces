#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MD = 1e9+7;

//x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

int main() {
    int n; cin >> n;
    string s; cin >> s;
    ll d[4] = {};
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            d[0]++;
        } else if (s[i] == 'C') {
            d[1]++;
        } else if (s[i] == 'G') {
            d[2]++;
        } else {
            d[3]++;
        }
    }
    sort(d, d+4, greater<ll>());
    ll u = 0;
    for (int i = 0; i < 4; i++) {
        if (d[i] == d[0]) u++;
    }
    cout << pow_mod(u, n, MD) << endl;
}