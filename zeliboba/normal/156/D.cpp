#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

vi sz, p;

int getp(int x) {
    if (x == p[x])
        return x;
    return (p[x] = getp(p[x]));
}

void join (int x, int y) {
    int px = getp(x), py = getp(y);
    if (px == py)
        return;
    if (sz[px] < sz[py]) {
        p[px] = py;
        sz[py] += sz[px];
    } else {
        p[py] = px;
        sz[px] += sz[py];
    }
}

ll mpow (ll x, ll n, ll k) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % k;
        x = x * x % k;
        n /= 2;
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    sz.assign(n, 1);
    p.assign(n, 0);
    for (int i = 0; i < n; ++i)
        p[i] = i;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
//        cout << a << " " << b << endl;
        join(a, b);
    }
    vl v;
    ll prod = 1;
    for (int i = 0; i < n; ++i) if (p[i] == i) {
        v.push_back(sz[i]);
        prod = prod * sz[i] % k;
    }
    if (v.size() == 1) {
        cout << 1 % k << endl;
        return 0;
    }
    cout << (prod * mpow(n, v.size() - 2, k)) % k << endl;
    return 0;
}