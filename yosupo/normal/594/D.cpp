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



const ll MD = 1e9+7;

/**
 * Starry Sky Tree
 */
template <int S>
struct StarrySkyTree {
    static const int N = 1<<S;

    using P = pair<int, int>;

    int sz[2*N];
    StarrySkyTree() {
        for (int i = 2*N-1; i >= N; i--) {
            sz[i] = 1;
        }
        for (int i = N-1; i >= 1; i--) {
            sz[i] = sz[i*2]+sz[i*2+1];
        }
    }

    vector<P> v[2*N];
    vector<int> sm[2*N];

    void add(int id, int nexid, int x) {
    	v[id+N].push_back(P(nexid, x));
    }
    void init() {
    	for (int i = 2*N-1; i >= N; i--) {
    		sort(v[i].begin(), v[i].end());
    		sm[i].resize(v[i].size() + 1);
    		sm[i][0] = 1;
    		for (int j = 1; j <= (int)v[i].size(); j++) {
    			sm[i][j] = (ll)sm[i][j-1] * v[i][j-1].second % MD;
    		}
    	}
    	for (int i = N-1; i >= 1; i--) {
    		v[i].resize(v[2*i].size() + v[2*i+1].size());
    		merge(v[2*i].begin(), v[2*i].end(), v[2*i+1].begin(), v[2*i+1].end(), v[i].begin());
    		sm[i].resize((int)v[i].size()+1);
    		sm[i][0] = 1;
    		for (int j = 1; j <= (int)v[i].size(); j++) {
    			sm[i][j] = (ll)sm[i][j-1] * v[i][j-1].second % MD;
    		}
    	}
    }

    /// [a, b)
    ll get(int a, int b, int R, int k = 1) {
        if (sz[k] <= a || b <= 0) return 1;
        if (a <= 0 && sz[k] <= b) {
        	return sm[k][lower_bound(v[k].begin(), v[k].end(), P(R, -1)) - v[k].begin()];
        }
        ll dl = get(a, b, R, k*2);
        ll dr = get(a-sz[k]/2, b-sz[k]/2, R, k*2+1);
        return dl*dr % MD;
    }
};



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




//primes.size -> N=100k:near10k
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


const int B = 1050;

StarrySkyTree<18> st;
Primes<B> pr;
int pc; //C

int n; //C
ll a[200200], sm[200200]; //C
ll b[200200], bsm[200200];

int nexbuf[1100100];

const int C = 25;
vector<int> hasp[C];


void calc() {
	sm[0] = 1;
	for (int i = 1; i <= n; i++) {
		sm[i] = sm[i-1] * a[i-1];
		sm[i] %= MD;
	}

	fill_n(b, 200200, 1);
	fill_n(nexbuf, 1100100, n);
	for (int i = n-1; i >= 0; i--) {
		ll aa = a[i];
		for (ll p: pr.p) {
			if (p*p > aa) break;
			if (aa % p == 0) {
				if (C <= p) {
					b[i] *= (p-1) * invp(p, MD) % MD; b[i] %= MD;
					st.add(i, nexbuf[p], (p-1) * invp(p, MD) % MD);
					nexbuf[p] = i;
				} else {
					hasp[p].push_back(i);
				}
				while (aa % p == 0) aa /= p; 
			}
		}
		if (aa > 1) {
			ll p = aa;
			if (C <= p) {
				b[i] *= (p-1) * invp(p, MD) % MD; b[i] %= MD;
				st.add(i, nexbuf[p], (p-1) * invp(p, MD) % MD);
				nexbuf[p] = i;
			} else {
				hasp[p].push_back(i);
			}
			nexbuf[p] = i;
		}
	}
	for (ll p: pr.p) {
		if (C <= p) break;
		reverse(hasp[p].begin(), hasp[p].end());
	}
	bsm[0] = 1;
	for (int i = 1; i <= n; i++) {
		bsm[i] = bsm[i-1] * b[i-1];
		bsm[i] %= MD;
	}

	st.init();

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r); l--;
		ll fi = sm[r] * invp(sm[l], MD) % MD;

		for (ll p: pr.p) {
			if (C <= p) break;
			if (lower_bound(hasp[p].begin(), hasp[p].end(), l) !=
				lower_bound(hasp[p].begin(), hasp[p].end(), r)) {
				fi *= (p-1) * invp(p, MD) % MD; fi %= MD;
			}
		}
		fi *= bsm[r]; fi %= MD;
		fi *= invp(bsm[l], MD); fi %= MD;

		fi *= invp(st.get(l, r, r), MD); fi %= MD;

		printf("%d\n", (int)fi);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int aa;
		scanf("%d", &aa);
		a[i] = aa;
	}

	calc();
    return 0;
}