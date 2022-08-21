#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>

using namespace std;

typedef long long ll;

template<class T>
struct Pi {
    T x, y;
    Pi() {}
    Pi(T xx, T yy) {
        x = xx; y = yy;
    }
    bool operator<(const Pi &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator>(const Pi &r) const {
        if (x != r.x) return x > r.x;
        return y > r.y;
    }
    bool operator==(const Pi &r) const {
        if (x != r.x) return false;
        return y == r.y;
    }
};

template<class T>
struct Ti {
    T x, y, z;
    Ti() {}
    Ti(T xx, T yy, T zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator<(const Ti &r) const {
        if (x != r.x) return x < r.x;
        if (y != r.y) return y < r.y;
        return z < r.z;
    }
    bool operator>(const Ti &r) const {
        if (x != r.x) return x > r.x;
        if (y != r.y) return y > r.y;
        return z > r.z;
    }
    bool operator==(const Ti &r) const {
        if (x != r.x) return false;
        if (y != r.y) return false;
        return z == r.z;
    }
};

ll pow_mod(ll x, ll n, ll mod) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return r;
}

ll invp(ll r, ll mod) {
    return pow_mod(r, mod-2, mod);
}

const int MN = 101000;
const ll MD = 1e9+7;
vector<int> g[MN];
bool col[MN];

ll dp[MN][2];
ll solve(int i, int b) {
    if (dp[i][b] != -1) return dp[i][b];
    ll res = 0;
    if (col[i] && b) {
        return 0;
    }
    if (!col[i] && !b) {
        ll u = 1;
        for (int d: g[i]) {
            u *= solve(d, 0) + solve(d, 1);
            u %= MD;
        }
        for (int d: g[i]) {
            res += u * invp(solve(d, 0) + solve(d, 1), MD) % MD * solve(d, 0) % MD;
            res %= MD;
        }
    }
    if (col[i] || b) {
        ll u = 1;
        for (int d: g[i]) {
            u *= (solve(d, 0) + solve(d, 1));
            u %= MD;
        }
        res += u;
        res %= MD;
    }
    dp[i][b] = res;
    return res;
}

int main() {
    fill_n(dp[0], MN*2, -1);
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a;
        scanf("%d", &a);
        g[a].push_back(i+1);
    }
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        col[i] = a;
    }
    cout << solve(0, 0) << endl;
    return 0;
}