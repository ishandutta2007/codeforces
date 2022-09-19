//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
sim> struct rge {c h, n;};
sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim> auto dud(c *r) -> decltype(cerr << *r);
sim> char dud(...);
struct muu {
#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << '{';
		for (c s = u.h; s != u.n; ++s)
			*this << ", " + 2 * (s == u.h) << *s;
		ris << '}';
	}
	sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
	sim, class F mor rgm<c, F> u) {
		for (c s = u.h; s != u.n; ++s)
			u.f(*this << ", " + 2 * (s == u.h), *s);
		ris;
	}
	#else
	sim mor const c&) {ris;}
	#endif
	muu & operator()() {ris;}
};
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": ")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
using ll = long long;
vector<ll> witness = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

ll __attribute__ ((no_sanitize_undefined)) mnoz(ll a,ll b, ll m) {
	ll q = ((double)a * b / m);
	ll r = (a*b - q*m) % m;  //ma si przekrca
	if (r < 0)
		r += m;
	return r;
}

ll pot(ll a, ll b, ll mod) {
  ll res = 1;
  while (b) {
    if (b&1)
      res = mnoz(res,a,mod);
    a = mnoz(a,a,mod);
    b /= 2;
  }
  return res;
}

bool test(ll n) {
  if (n == 2)
    return true;
  if (n < 2 || n%2 == 0)
    return false;
  
  ll d = n-1;
  ll s = 0;
  while (d%2 == 0) {
    d /= 2;
    ++s;
  }
  
  for (auto i: witness) if (i%n) {
    ll x = pot(i,d,n);
    if (x != 1) {
      bool zlozona = true;
      for (int j = 0; j < s; ++j) {
        if (x == n-1) {
          zlozona = false;
          break;
        }
        x = mnoz(x, x, n);
      }
      if (zlozona)
        return false;
    }
  }
  
  return true;
}

ll nwd(ll a, ll b) {
  return a ? nwd(b%a,a) : b;
}
const int nax = 515, mod = (119 << 23) + 1;
ll a[nax];
ll root(ll x) {
	ll r = sqrt((long double)x);
	for (ll i = max(0ll, r - 1); i <= r + 1; ++i)
		if (i * i == x) return i;
	return -1;
}
ll root3(ll x) {
	ll r = cbrt(x);
	for (ll i = max(0ll, r - 1); i <= r + 1; ++i)
		if (i * i * i == x) return i;
	return -1;
}
int n;
ll ans = 1;
void go(ll x) {
	if (x == 1) return;
	debug << imie(x);
	int e = 0;
	for (int i = 0; i < n; ++i) {
		while (a[i] % x == 0) {
			e++;
			a[i] /= x;
		}
	}
	ans = ans * (e + 1) % mod;
}
int main() {
	debug << imie(mod);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n; ++i) {
		ll r = root(a[i]);
		if (r != -1) {
			ll r2 = root(r);
			if (r2 != -1)
				r = r2;
		}
		if (~r)
			go(r);
		else {
			ll r = root3(a[i]);
			if (r != -1)
				go(r);
		}
	}
	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i] != a[j])
		go(nwd(a[i], a[j]));
	for (int i = 0; i < n; ++i) if (a[i] > 1) {
		bool prime = test(a[i]);
		ll p = a[i];
		int e = 0;
		for (int j = 0; j < n; ++j) {
			while (a[j] % p == 0) {
				a[j] /= p;
				e++;
			}
		}
		debug << imie(p) imie(e) imie(prime);
		ans = ans * (e + 1) % mod;
		if (!prime)
			ans = ans * (e + 1) % mod;
	}
	printf("%lld\n", ans);
}