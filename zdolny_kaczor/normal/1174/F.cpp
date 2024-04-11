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
#define log __log__
const int nax = 2e5 + 44, log = 18;
vector <int> graf[nax];
int jump[nax][log];
int dep[nax];
bool is[nax];
int myst;
int dfs2(int x, int y = 0) {
	if (is[x]) return x;
	int r = -1;
	for (int v : graf[x])
		if (v != y) {
			int sub = dfs2(v, x);
			if (sub != -1) {
				if (r == -1) r = sub;
				else return x;
			}
		}
	return r;
}
int lca(vector <int> &x) {
	memset(is, 0, sizeof(is));
	for (int c : x) is[c] = 1;
	int ans = dfs2(1);
	for (int c : x) is[c] = 0;
	rans;
}
int move_up(int x, int c) {
	REP(i, log) if (c >> i & 1)
		x = jump[x][i];
	return x;
}
int lca(int a, int b) {
	REP(_, 2) {
		if (dep[a] > dep[b])
			a = move_up(a, dep[a] - dep[b]);
		swap(a, b);
	}
	if (a == b) return a;
	FORD(i, log - 1, 0) {
		int aa = jump[a][i], bb = jump[b][i];
		if (aa != bb) a = aa, b = bb;
	}
	assert(jump[a][0] == jump[b][0] && a && b);
	return jump[a][0];
}
int dist(int a, int b) {
	return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}
int in[nax], out[nax];
void dfs(int x, int y = 0, int d = 0) {
	static int timer = 0;
	in[x] = timer++;
	jump[x][0] = y;
	FOR(i, 1, log - 1)
		jump[x][i] = jump[jump[x][i - 1]][i - 1];
	dep[x] = d;
	for (int v : graf[x]) if (v != y)
		dfs(v, x, d + 1);
	out[x] = timer++;
}
bool under(int a, int b) {
	return in[a] >= in[b] && out[a] <= out[b];
}
int q_cou = 0;
void answer(int c) {
#ifdef LOCAL
	assert(myst == c);
#else
	printf("! %d\n", c);
#endif
	debug << imie(c) imie(q_cou);
	exit(0);
}
int d_query(int x) {
	debug << imie(x);
	q_cou++;
	assert(q_cou <= 36);
#ifdef LOCAL
	return dist(x, myst);
#else
	printf("d %d\n", x);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	rans;
#endif
}
int s_query(int x) {
	debug << imie(x);
	q_cou++;
	assert(q_cou <= 36);
#ifdef LOCAL
	int diff = dep[myst] - dep[x];
	assert(diff > 0);
	int ans = move_up(myst, diff - 1);
	assert(jump[ans][0] == x);
	rans;
#else
	printf("s %d\n", x);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	rans;
#endif
}
static uint64_t splitmix64(uint64_t x) {
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}
int main() {
	ull my_rand = 1234567;
	int n;
	scanf("%d", &n);
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
#ifdef LOCAL
	scanf("%d", &myst);
#endif
	dfs(1);
	debug << "dep " << range(dep + 1, dep + n + 1);
	vector <int> opts;
	FOR(i, 1, n) opts.push_back(i);
	while (opts.size() > 1u) {
		pii best = {nax, nax};
		int LCA = lca(opts);
		REP(_, 4) {
			int c;
			do {
				my_rand = splitmix64(my_rand + opts.size());
				c = 1 + my_rand % n;
			}
			while (!under(c, LCA));
			map <int, int> cou;
			for (int v : opts)
				cou[dist(v, c)]++;
			int l = 0;
			for (pii x : cou)
				maxi(l, x.second);
			mini(best, {l, c});
		}
		debug << imie(opts) imie(LCA);
		bool is_l = false;
		for (int v : opts)
			if (v == LCA) {
				is_l = true;
				break;
			}
		if (is_l) {
			int c = LCA;
			map <int, int> cou;
			for (int v : opts)
				cou[dist(v, c)]++;
			int l = 0;
			for (pii x : cou)
				maxi(l, x.second);
			if (l <= best.first)
				best.second = LCA;
		}
		else {
			map <int, int> cou;
			for (int v : opts) {
				int und = move_up(v, dep[v] - dep[LCA] - 1);
				cou[und]++;
			}
			int l = 0;
			for (pii x : cou)
				maxi(l, x.second);
			if (l <= best.first)
				best.second = -1;
		}
		if (best.second == -1) {
			int s = s_query(LCA);
			vector <int> new_opts;
			for (int v : opts)
				if (under(v, s))
					new_opts.push_back(v);
			swap(opts, new_opts);
		}
		else {
			int d = d_query(best.second);
			vector <int> new_opts;
			for (int v : opts)
				if (dist(v, best.second) == d)
					new_opts.push_back(v);
			swap(opts, new_opts);
		}
	}
	assert(opts.size());
	answer(opts[0]);
}