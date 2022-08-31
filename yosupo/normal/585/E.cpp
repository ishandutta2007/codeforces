#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

/// , x^nO(logn)
ll pow(ll x, ll n) {
    ll r = 1;
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}

/// x^n % md
ll pow_mod(ll x, ll n, ll md) {
	ll r = 1;
	while (n) {
		if (n & 1) r = (r * x) % md;
		x = (x * x) % md;
		n >>= 1;
	}
	return r;
}

/// x, mdxmd
ll invp(ll x, ll md) {
	return pow_mod(x, md-2, md);
}


const ll MD = 1e9+7;
const int MN = 500100;
const int MA = 10100100;

ll inv2;
ll dp1[MA];

int n;
ll pow_2_n1;
ll a[MN];
vector<int> fac[MN];

ll solve1() {
	ll gcd1 = 0;
	fill_n(dp1, MA, 1);
	for (int i = 0; i < n; i++) {
		int m = (int)fac[i].size();
		ll res = 0;
		for (int j = 0; j < (1<<m); j++) {
			int u = 1;
			for (int k = 0; k < m; k++) {
				if (!((j>>k) & 1)) continue;
				u *= fac[i][k];
			}
			if (__builtin_popcount(j) % 2 == 1) {
				res += MD-dp1[u];
			} else {
				res += dp1[u];
			}
			if (res >= MD) res -= MD;
			dp1[u] *= 2;
			if (dp1[u] >= MD) dp1[u] -= MD;
		}
		gcd1 += res;
		if (gcd1 >= MD) gcd1 -= MD;
	}
	gcd1 = (gcd1+MD) % MD;

	ll sm = 0;
	for (int i = 0; i < n; i++) {
		int m = (int)fac[i].size();
		ll res = 0;
		for (int j = 0; j < (1<<m); j++) {
			int u = 1;
			for (int k = 0; k < m; k++) {
				if (!((j>>k) & 1)) continue;
				u *= fac[i][k];
			}
			if (__builtin_popcount(j) % 2 == 1) {
				res -= dp1[u]*inv2;
			} else {
				res += dp1[u]*inv2;
			}
			res %= MD;
		}
		sm += res*2 - gcd1;
		sm %= MD;
	}
	sm = (sm+MD) % MD;
	return sm;
}

template <int N>
struct Primes {
    bool used[N];
    vector<int> p;
    Primes() {
        used[0] = used[1] = true;
        for (int i = 2; i < N; i++) {
            if (!used[i]) {
                p.push_back(i);
            }
            for (int j = 2*i; j < N; j += i) {
                used[j] = true;
            }
        }
    }
};
Primes<100000> pr;

int main() {
	inv2 = invp(2, MD);
	scanf("%d", &n);
	pow_2_n1 = pow_mod(2, n-1, MD);
	for (int i = 0; i < n; i++) {
		int a2;
		scanf("%d", &a2);
		a[i] = a2;
		ll aa = a2;
		for (ll j: pr.p) {
			if (j*j > aa) break;
			if (aa % j == 0) {
				fac[i].push_back(j);
				while (aa % j == 0) {
					aa /= j;
				}
			}
		}
		if (aa > 1) {
			fac[i].push_back(aa);
		}
	}
	ll sm = solve1();
	cout << sm << endl;
    return 0;
}