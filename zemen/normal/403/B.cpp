#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "b"

namespace my {




	
	struct calculator {
		ll mod;
		bool big_mod;
		
		calculator() {}
		
		calculator(ll _mod) {
			mod = _mod;
			big_mod = (ll(mod) * 2ll > ll(__INT_MAX__));
		}
		
		inline ll mul(ll a, ll b) {
			if (!big_mod) {
				return (a * b) % mod;
			} else {
				ll res = a * b - (ll((ld(a) * ld(b)) / ld(mod)) * mod);
				while (res < 0)
					res += mod;
				while (res >= mod)
					res -= mod;
				return res;
			}
		}
		
		inline ll sum(ll a, ll b) {
			ll res = a + b;
			if (res >= mod)
				res -= mod;
			return res;
		}
		
		inline ll diff(ll a, ll b) {
			ll res = a + mod - b;
			if (res >= mod)
				res -= mod;
			return res;
		}
		
		inline ll binpow(ll a, ll x) {
			ll c = a;
			ll res = 1;
			while (x) {
				if (x & 1)
					res = mul(res, c);
				c = mul(c, c);
				x >>= 1;
			}
			return res;
		}
		
		inline ll rev(ll a) {
			return binpow(a, mod - 2);
		}
		
	};
	




	
	inline ll gcd(ll a, ll b) {
		while (a && b)
			if (a >= b)
				a %= b;
			else
				b %= a;
		return a ? a : b;
	}
	
	inline ll lcm(ll a, ll b) {
		return (a / gcd(a, b)) * b;
	}
	
	inline ll extended_gcd(ll a, ll b, ll &x, ll &y) {
		if (!a) {
			x = 0; 
			y = 1;
			return b;
		}
		ll x1, y1;
		ll d = extended_gcd(b % a, a, x1, y1);
		x = y1 - (b / a) * x1;
		y = x1;
		return d;
	}
	





	
	template <typename T>
	struct vector {
		
		T *a;
		int sz;
		int mem;
		
		inline void resize(int n, T val) {
			if (sz >= n) {
				sz = n;
				return;
			}
			int new_mem = mem;
			if (!mem)
				new_mem = 1;
			while (new_mem < n)
				new_mem <<= 1;
			if (new_mem > mem)
				a = (T *) realloc(a, sizeof(T) * new_mem);
			mem = new_mem;
			for (int i = sz; i < n; ++i)
				a[i] = val;
			sz = n;
		}
		
		inline void resize(int n) {
			if (sz >= n) {
				sz = n;
				return;
			}
			int new_mem = mem;
			if (!mem)
				new_mem = 1;
			while (new_mem < n)
				new_mem <<= 1;
			if (new_mem > mem)
				a = (T *) realloc(a, sizeof(T) * new_mem);
			mem = new_mem;
			sz = n;
		}
		
		vector <T>() {
			mem = sz = 0;
			a = 0;
		}
		
		vector <T>(int n) {
			mem = sz = 0;
			a = 0;
			resize(n);
		}
		
		vector <T>(int n, T val) {
			mem = sz = 0;
			a = 0;
			resize(n, val);
		}
		
		inline void push_back(T v) {
			if (mem <= sz) {
				if (!mem)
					mem = 1;
				else
					mem <<= 1;
				a = (T *) realloc(a, mem * sizeof(T));
			}
			a[sz++] = v;
		}
		
		inline void pop_back() {
			--sz;
		}
		
		inline T & operator[](int id) {
			return a[id];
		}
		
		inline int size() {
			return sz;
		}
		
		inline void clear() {
			free(a);
			a = 0;
			sz = mem = 0;
		}
		
		inline T * begin() {
			return a;
		}
		
		inline T * end() {
			return a + sz;
		}
		
	};



	
	struct sieve {
		my::vector <bool> np;
		my::vector <int> p;
		my::vector <int> minp;
		int n;
		bool linear;
		
		sieve() { }
		
		inline void work_linear() {
			for (int i = 2; i <= n; ++i) {
				if (!minp[i]) {
					minp[i] = i;
					p.push_back(i);
				}
				for (int j = 0; j < (int) p.size() && p[j] <= minp[i] && i * p[j] <= n; ++j)
					minp[i * p[j]] = p[j];
			}
		}
		
		inline void work() {
			if (linear) {
				work_linear();
				return;
			}
			for (int i = 2; i * i <= n; ++i)
				if (!np[i])
					for (int j = i * i; j <= n; j += i)
						np[j] = 1;
		}
				
		sieve(int _n, bool _linear = false) {
			n = _n;
			linear = _linear;
			if (!linear)
				np.resize(n + 1, 0);
			else
				minp.resize(n + 1, 0);
			work();
		}
		
		inline void get_primes() {
			p.clear();
			for (int i = 2; i <= n; ++i)
				if (!np[i])
					p.push_back(i);
		}
		
	};




	
	struct random_generator {
		
		random_generator() {
			ll seed;
			asm("rdtsc" : "=A"(seed));
			srand(seed);
		}
		
		int rand() {
			return abs((::rand() << 15) ^ ::rand());
		}
		
		int rand(int n) {
			return rand() % n;
		}
		
		ll llrand() {
			return abs((ll(rand()) << 31) ^ rand());
		}
		
		ll llrand(ll n) {
			return llrand() % n;
		}
	};
	
	random_generator rnd;




	
	inline bool miller_rabin(ll n, ll a, calculator &calc) {
		if (gcd(n, a) > 1)
			return true;
		ll x = n;
		--x;
		int l = 0;
		while (!(x & 1ll)) {
			x >>= 1;
			++l;
		}
		ll c = calc.binpow(a, x);
		for (int i = 0; i < l; ++i) {
			ll nx = calc.mul(c, c);
			if (nx == 1) {
				if (c != 1 && c != n - 1)
					return true;
				else
					return false;
			}
			c = nx;
		}
		return c != 1;
	}
	
	inline bool is_prime(ll n) {
		if (!(n & 1ll))
			return n == 2;
		calculator calc(n);
		for (ll a = 2; a < std::min(8ll, n); ++a)
			if (miller_rabin(n, a, calc))
				return false;
		return true;
	}
	
	struct factorization {
		my::vector <ll> p;
		my::vector <ll> div;
		my::vector <std::pair <ll, int> > d;
		ll n;
		
		inline void factor_sieve(ll n, sieve &s) {
			while (n > 1) {
				p.push_back(s.minp[n]);
				n /= s.minp[n];
			}
		}
		
		inline void factor(ll x) {
			if (x == 1)
				return;
			if (is_prime(x)) {
				p.push_back(x);
				return;
			}
			if (!(x & 1ll)) {
				p.push_back(2);
				factor(x >> 1);
				return;
			}
			if (x % 3 == 0) {
				p.push_back(3);
				factor(x / 3);
				return;
			}
			if (x % 5 == 0) {
				p.push_back(5);
				factor(x / 5);
				return;
			}
			calculator calc(x);
			while (true) {
				ll x1 = rnd.rand(x - 1) + 1;
				ll x2 = calc.mul(x1, x1) + 1;
				if (x2 >= x)
					x2 -= x;
				int i1 = 1, i2 = 2;
				while (1) {
					ll c = llabs(x1 - x2) % x;
					if (c == 0)
						break;
					ll g = gcd(c, x);
					if (g > 1) {
						factor(g);
						factor(x / g);
						return;
					}
					if (i1 * 2 == i2) {
						i1 *= 2;
						x1 = x2;
					}
					++i2;
					x2 = calc.mul(x2, x2) + 1;
					if (x2 >= x)
						x2 -= x;
				}
			}
		}
		
		inline void sort() {
			std::sort(p.begin(), p.end());
		}
		
		inline void make_canonical() {
			sort();
			if (!p.size())
				return;
			int lb = 0;
			d.clear();
			for (int i = 0; i < (int) p.size(); ++i)
				if (p[lb] != p[i]) {
					d.push_back(std::make_pair(p[lb], i - lb));
					lb = i;
				}
			d.push_back(std::make_pair(p[lb], (int) p.size() - lb));
		}
		
		factorization(ll _n) {
			n = _n;
			p.clear();
			factor(n);
			make_canonical();
		}
		
		factorization(ll _n, sieve &_s) {
			n = _n;
			p.clear();
			if (n <= _s.n)
				factor_sieve(n, _s);
			else
				factor(n);
			make_canonical();
		}
		
		inline ll phi() {
			ll res = 1;
			for (int i = 0; i < (int) d.size(); ++i) {
				for (int j = 0; j < d[i].second - 1; ++j)
					res *= d[i].first;
				res *= d[i].first - 1;
			}
			return res;
		}		
		
		inline void brute(ll x = 1, int k = 0) {
			if (k == (int) d.size()) {
				div.push_back(x);
				return;
			}
			for (int i = 0; i <= d[k].second; ++i) {
				brute(x, k + 1);
				x *= d[k].first;
			}
		}
		
		inline void sort_divisors() {
			std::sort(div.begin(), div.end());
		}
		
		inline void make_divisors() {
			div.clear();
			brute();
		}
	};
	


}

int a[5001];
int b[5001];
int bonus[5001];
ll d[5001];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i) {
		my::factorization f(a[i]);
		//~ for (int j = 0; j < f.p.size(); ++j)
			//~ cerr << f.p[j] << ' ';
		//~ cerr << '\n';
		for (int j = 0; j < f.p.size(); ++j) {
			if (binary_search(b, b + m, f.p[j]))
				--res;
			else
				++res;
		}
	}
	int g = a[0];
	for (int r = 0; r < n; ++r) {
		g = my::gcd(g, a[r]);
		my::factorization f(g);
		bonus[r] = 0;
		for (int j = 0; j < f.p.size(); ++j) {
			if (binary_search(b, b + m, f.p[j]))
				++bonus[r];
			else
				--bonus[r];
		}
	}
	for (int i = 0; i < n; ++i)
		d[i] = -INF;
	d[n] = res;
	for (int i = n; i > 0; --i)
		for (int j = 0; j < i; ++j)
			d[j] = max(d[j], d[i] + (bonus[j] - bonus[i]) * (j + 1));
	ll ans = res;
	for (int i = 0; i < n; ++i)
		ans = max(ans, d[i]);
	cout << ans << '\n';
}