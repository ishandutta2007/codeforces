#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        ll d;
        cin >> d;
        v[i] = d;
    }
    sort(v.begin(), v.end());
    ll s = 0, u = 0;
    for (int i = 0; i < n; i++) {
        ll d = v[i];
        s += i*d-u;
        u += d;
    }
    s = 2*s + u;
    u = gcd(s, n);
    cout << s/u << ' ' << n/u << endl;
    return 0;
}