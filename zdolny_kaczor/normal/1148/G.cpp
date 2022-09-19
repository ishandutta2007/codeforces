//Konrad Paluszek, University of Warsaw (former XIV LO Warsaw)
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<< (
#define ris return *this
#define urs(r) typename remove_cv<typename remove_reference<decltype(r)>::type>::type
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)), muu&>::type operator<<(c g) {
#define forbits(i, m) if (m) for (urs(m) i = ctz(m), quq = m; quq; quq ^= ((decltype(m))1 << i), i = ctz(quq)) 
#define fordbits(i, m) if (m) for (urs(m) i = 8 * sizeof(m) - clz(m) - 1, quq = m; quq; quq ^= ((decltype(m))1 << i), i = 8 * sizeof(m) - clz(quq) - 1)
#define FOR(i, b, e) for (auto i = b; i <= e; ++i)
#define FORD(i, b, e) for (auto i = b; i >= e; --i)
#define REP(i, n) for (urs(n) i = 0; i < n; ++i)
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
#define ALL(r) (r).begin(), (r).end()
#define FS(r) r.first, r.second
#define MAKE(b, e) <urs(*(b))>(b, e)
sim> struct rge {c h, n;};sim> rge<c> range(c h, c n) {return rge<c>{h, n};}
sim, class F> struct rgm {c h, n; F f;};
sim, class F> rgm<c, F> map_range(c b, c e, F f) {return rgm<c, F>{b, e, f};}
sim, class F> rgm<typename c::const_iterator, F> map_range(const c &x, F f) {return map_range(x.begin(), x.end(), f);}
sim, class F> struct umm {c m; F f; bool r;};
sim, class F> umm<c, F> mask_iter(c a, F f, bool r = false) {return umm<c, F>{a, f, r};}
sim> auto dud(c *r) -> decltype(cerr << *r);sim> char dud(...);
using ll = long long; using ld = long double; using ull = unsigned long long;
using pii = pair <int, int>; using vpii = vector <pii>; using unt = unsigned int;
#define hur(f, g) int f(unt a) {return g(a);} int f(int a) {return g(a);} \
int f(ll a) {return g##ll(a);} int f(ull a) {return g##ll(a);}
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)struct muu {
#ifdef LOCAL
stringstream a;muu & operator<<(string c) {ris << '\"' << c.c_str() << '\"';}
~muu() {cerr << a.str() << "\033[0m" << endl;}R22(<) a << boolalpha << g; ris;}R22(==) ris << range(begin(g), end(g));}
sim mor rge<c> u) {int q = 0;a << '{';for (c s = u.h; s != u.n; ++s)*this << ", " + 2 * !q++ << *s;ris << "}_" << q;}
sim, class n mor pair <c,n> r) {ris << "(" << r.first << ", " << r.second << ")";}
sim, class F mor rgm<c, F> u) {int q = 0;a << "[";for (c s = u.h; s != u.n; ++s)u.f(*this << ", " + 2 * !q++, *s);ris << "]_" << q;}
sim, class F mor umm<c, F> u) {a << "[";int q = 0;if (!u.r) {forbits(i, u.m)u.f(*this << ", " + 2 * !q++, i);} else {fordbits(i, u.m)u.f(*this << ", " + 2 * !q++, i);}ris << "]";}
#else
sim mor const c&) {ris;}
#endif
};
sim>void factor(muu &d,c x){if(x<=1&&x+1>=0){d<<x;return;}d<<x<<"=";if(x<0){d<<"-";x=-x;}int q=0;for(c p=2;p*p<x;++p){int e=0;while(x%p==0){e++;x/=p;}if(e)d<<"*"+!q++<<p;if (e > 1)d<<"^"<<e;}if(x>1)d<<"*"+!q++<<x;}
sim> void mini(c &a, c b) { if (a > b) a = b; }sim> void maxi(c &a, c b) { if (a < b) a = b; }
#ifdef LOCAL
muu & operator<<(muu &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
muu & operator<<(muu &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
#endif
#define debug (muu() << "\033[1;"<<30+__LINE__%8<<"m"<< __FUNCTION__ << "#" << __LINE__ << ": \033[" << 30+(int)(__LINE__*3.125)%8<<"m")
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << mask_iter(r, [](muu &d, int x){d << x;}) << "] "
#define arr(a, i) "[" #a imie(i) ": " << a[i] << "] "
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] "
#define vsv sim, class d, class e
#define nop(o,c,r,l...) auto operator o(c a, r b)-> decltype(make_pair(l)) {return {l};}
#define pcg(o) vsv, class f> nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second) \
vsv,class = typename enable_if<!is_same<c, muu>::value>::type> nop(o, c, pair<d u e>, a o b.first, a o b.second) \
vsv> nop(o, pair<c u d>, e, a.first o b, a.second o b)
#define clp(o) pcg(o) \
vsv> void operator o##= (pair <c,d> & a, e b) {a.first o##= b; a.second o##= b;} \
vsv, class f> void operator o##= (pair <c,d> & a, pair <e,f> b) {a.first o##= b.first; a.second o##= b.second;}
#define syd(o) sim, class d> auto operator o(pair<c, d> e) -> decltype(make_pair(o e.first, o e.second)) {return {o e.first, o e.second};}
#define u ,
clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)
#undef u
#define rans return ans
#define div __div__
const int nax = 1e7 + 1;
int div[nax];
vector <int> where[nax];
int sq_free(int x) {
	int ans = 1;
	while (x > 1) {
		int p = div[x];
		while (x % p == 0) x /= p;
		ans *= p;
	}
	rans;
}
inline unt ros(unt m) {
	unt a = m & -m;
	unt b = ~((a - 1) ^ m);
	unt c = b & -b;
	unt d = (c >> (1 + __builtin_ctz(a))) - 1;
	return c | (m & ~(c - 1)) | d;
}
int a[nax];
int occs[nax], muls[nax];
void redo_muls() {
	memset(muls, 0, sizeof(muls));
	for (int i = 1; i < nax; ++i)
		for (int j = i; j < nax; j += i)
			muls[i] += occs[j];
}
int cop(int x) {
	debug << imie(x);
	int primes[8] = {};
	int pro[1 << 8];
	pro[0] = 1;
	int cou = 0;
	while (x > 1) {
		primes[cou] = div[x];
		x /= div[x];
		cou++;
	}
	int ans = 0;
	FOR(m, 1, (1 << cou) - 1) {
		int b = ctz(m);
		pro[m] = pro[m ^ (1 << b)] * primes[b];
	}
	REP(m, (1 << cou))
		ans += (popc(m) & 1 ? -1 : 1) * muls[pro[m]];
	debug << imie(ans);
	rans;
}
void dec(int x, int v) {
	int primes[8] = {};
	int pro[1 << 8];
	pro[0] = 1;
	int cou = 0;
	while (x > 1) {
		primes[cou] = div[x];
		x /= div[x];
		cou++;
	}
	int ans = 0;
	FOR(m, 1, (1 << cou) - 1) {
		int b = ctz(m);
		pro[m] = pro[m ^ (1 << b)] * primes[b];
	}
	REP(m, (1 << cou))
		ans += muls[m] -= v;
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
#if !defined(LOCAL) && !defined(LOCAL2)
	if (n <= 20) {
		REP(i, n)
			scanf("%d", a + i);
		for (unt m = ((1u << k) - 1); m < (1u << n); m = ros(m)) {
			int deg[n] = {};
			forbits(i, m)
				forbits(j, m) {
					if (i == j) break;
					if (__gcd(a[i], a[j]) > 1) {
						deg[i]++;
						deg[j]++;
					}
				}
			int fair = 0;
			forbits(i, m)
				if (deg[i] == k - 1)
					fair++;
			if (fair == 0 || fair == k) {
				forbits(i, m)
					printf("%d ", i + 1);
				printf("\n");
				return 0;
			}
		}		
	}
#endif
	for (int i = 2; i < nax; ++i)
		if (div[i] == 0) {
			div[i] = i;
			if (i < nax / i - 1)
				for (int j = i * i; j < nax; j += i)
					div[j] = i;
		}
	debug << range(div + 1, div + 100);
	vector <int> opts, ans;
	REP(i, n) {
		int x;
		scanf("%d", &x);
		x = sq_free(x);
		if (where[x].empty())
			opts.push_back(x);
		where[x].push_back(i + 1);
		occs[x]++;
	}
	int take_away = -1;
	int last = -1;
	srand(69);
	random_shuffle(ALL(opts));
	redo_muls();
	for (int i = 2; i < nax; ++i) {
		if (muls[i] >= k) {
			for (int j = i; j < nax; j += i)
				for (int v : where[j]) {
					printf("%d ", v);
					k--;
					if (k == 0) return 0 * printf("\n");
				}
			return 0 * printf("\n");
		}
	}
	while ((int)ans.size() < k) {
		if (clock() > 1.9 * CLOCKS_PER_SEC) {
			int c = 0;
			for (int x : opts) {
				for (int y : where[x]) {
					printf("%d ", y);
					c++;
					if (c == k) {
						printf("\n");
						return 0;
					}
				}
			}
		}
		pii largest = {-1, -1};
		int turns = opts.size() / 2 + 3;
		for (int x : opts) {
			maxi(largest, {cop(x), x});
			if (turns-- == 0) break;
		}
		debug << imie(largest);
		int curr = largest.second;
		if (largest.first == 0) {
			debug << "found clique";
			for (int x : opts) {
				for (int y : where[x]) {
					printf("%d ", y);
					k--;
					if (k == 0)
						return 0 * printf("\n");
				}
			}
		}
		int take_now = where[curr].size();
		vector <int> del, left;
		for (int x : opts) {
			if (x != curr) {
				if (__gcd(x, curr) == 1) {
					del.push_back(x);
					take_now += where[x].size();
				}
				else {
					left.push_back(x);
				}
			}
		}
		debug << imie(del) imie(left);
		if (take_now > 2 && take_away == -1) {
			if (where[curr].size() > 1u)
				take_away = where[curr][0];
			else
				take_away = where[del.back()][0];
		}
		int missing = k - ans.size();
		last = missing;
		debug << imie(missing);
		debug << arr(where, curr);
		for (int x : where[curr]) {
			if (missing == 0)
				break;
			ans.push_back(x);
			missing--;
		}
		dec(curr, where[curr].size());
		if (missing == 0) {
			if (last > 1)
				ans.back() = where[del.back()][0];
			else
				ans.push_back(where[del.back()][0]);
		}
		else {
			for (int x : del) {
				dec(x, where[x].size());
				for (int y : where[x]) {
					if (missing) {
						missing--;
						ans.push_back(y);
					}
				}
			}
		}
		swap(opts, left);
	}
	if ((int)ans.size() > k) {
		assert(take_away != -1);
		assert((int)ans.size() == k + 1);
	}
	else
		take_away = -1;
	debug << imie(ans) imie(take_away);
	for (int x : ans)
		if (x != take_away)
			printf("%d ", x);
	printf("\n");
}