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
ull mix(ull x) {
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}
#define left __1Eft_
#define log __l0g_
const int nax = 1e5 + 44, log = 17;
vector <int> by_deg[nax], graf[nax];
int jump[nax][log], dep[nax];
void dfs1(int x, int y = 0, int d = 0) {
	dep[x] = d;
	jump[x][0] = y;
	FOR(i, 1, log - 1) jump[x][i] = jump[jump[x][i - 1]][i - 1];
	for (int v : graf[x]) if (v != y) dfs1(v, x, d + 1);
}
void answer(int x) {
	printf("%d\n", x);
	exit(0);
}
int val[nax];
int lca(int a, int b) {
	REP(_, 2) {
		if (dep[a] > dep[b]) {
			int diff = dep[a] - dep[b];
			REP(i, log) if (diff >> i & 1)
				a = jump[a][i];
		}
		swap(a, b);
	}
	if (a == b) return a;
	FORD(i, log - 1, 0) {
		int aa = jump[a][i], bb = jump[b][i];
		if (aa != bb) {
			a = aa;
			b = bb;
		}
	}
	return jump[a][0];
}
bool touched[nax];
vector <int> candidates;
void dfs2(int x, int y = 0, int c = 0) {
	c += val[x];
	if (c == 0 && !touched[x]) candidates.push_back(x);
	for (int v : graf[x]) if (v != y) dfs2(v, x, c);
}
int marked[nax];
int go_up(int x, int d) {
	REP(i, log) if (d >> i & 1) x = jump[x][i];
	return x;
}
int on_path(int a, int b, int l, int d) {
	if (dep[a] - dep[l] >= d)
		return go_up(a, d);
	else
		return go_up(b, (dep[a] + dep[b] - 2 * dep[l]) - d);
}
void block(int x, int y) {
	debug << imie(x) imie(y);
	if (jump[x][0] == y) {
		val[x]++;
		val[1]--;
	}
	else {
		assert(jump[y][0] == x);
		val[y]++;
	}
}
vector <int> left[nax];
int degs[nax];
bool check(int x, int y = 0, int d = 0) {
	if (degs[d] == 0) degs[d] = graf[x].size();
	if (degs[d] != (int) graf[x].size()) return false;
	for (int v : graf[x]) if (v != y && !check(v, x, d + 1)) return false;
	return true;
}
void block_oth(int center, int a1, int a2) {
	if (!touched[center])
		debug << "touch " imie(center);
	touched[center] = 1;
	vector <int> oth;
	for (int x : left[center]) {
		if (x == a1 || x == a2)
			oth.push_back(x);
		else
			block(center, x);
	}
	swap(left[center], oth);
}
ull seed = 12345;
int my_rand() {
	seed = mix(seed);
	return seed % 1000000007;
}
int rand_from(vector <int> &a) {
	return a[my_rand() % a.size()];
}
int main() {
	int n;
	scanf("%d", &n);
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
		left[a].push_back(b);
		left[b].push_back(a);
	}
	FOR(i, 1, n) by_deg[graf[i].size()].push_back(i);
	dfs1(1);
	vector <int> odd, even;
	FOR(i, 1, n) {
		if (dep[i] % 2) odd.push_back(i);
		else even.push_back(i);
	}
	pii largest_odd = {0, 0}, largest_even = {0, 0};
	map <int, int> odd_cou, even_cou;
	vector <int> small_odd, small_even;
	for (int x : odd)
		odd_cou[graf[x].size()]++;
	for (pii c : odd_cou)
		maxi(largest_odd, {c.second, c.first});
	for (int x : odd)
		if ((int)graf[x].size() != largest_odd.second)
			small_odd.push_back(x);
	for (int x : even)
		even_cou[graf[x].size()]++;
	for (pii c : even_cou)
		maxi(largest_even, {c.second, c.first});
	for (int x : even)
		if ((int)graf[x].size() != largest_even.second)
			small_even.push_back(x);
	if (small_odd.size() || small_even.size()) {
		UNTIL(0.7) {
			int a, b;
			if (small_even.empty() || (!small_odd.empty() && my_rand() % 2)) {
				a = rand_from(odd);
				if (graf[a].size() == largest_odd.second)
					b = rand_from(small_odd);
				else
					b = rand_from(odd);
			}
			else {
				a = rand_from(even);
				if (graf[a].size() == largest_even.second)
					b = rand_from(small_even);
				else
					b = rand_from(even);
			}
			if (graf[a].size() == graf[b].size())
				continue;
			int l = lca(a, b);
			int d = dep[a] + dep[b] - 2 * dep[l];
			assert(d % 2 == 0);
			int x = on_path(a, b, l, d / 2 - 1);
			int y = on_path(a, b, l, d / 2);
			int z = on_path(a, b, l, d / 2 + 1);
			block_oth(y, x, z);
		}
	}
	dfs2(1);
	sort(ALL(candidates), [](int x, int y){return graf[x].size() < graf[y].size();});
	FOR(i, 1, n) random_shuffle(ALL(graf[i]));
	int i = 0;
	debug << imie(candidates);
	UNTIL(0.95) {
		if (i == (int) candidates.size()) break;
		memset(degs, 0, sizeof(degs));
		if (check(candidates[i]))
			answer(candidates[i]);
		i++;
	}
	answer(-1);
}