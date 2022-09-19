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
struct suffix_automaton;
#ifdef LOCAL
muu &operator<<(muu &d, const suffix_automaton &x);
#endif
struct suffix_automaton {
	vector<map<char,int>> edges; // edges[i]  : the labeled edges from node i
	vector<int> link;            // link[i]   : the parent of i
	vector<int> length;          // length[i] : the length of the longest string in the ith class
	int last;                    // the index of the equivalence class of the whole string
	suffix_automaton(string s) {
		edges.push_back(map<char,int>());
		link.push_back(-1);
		length.push_back(0);
		last = 0;
		for (int i=0; i<(int)s.size(); i++) {
			edges.push_back(map<char,int>());
			length.push_back(i+1);
			link.push_back(0);
			int r = edges.size() - 1;
			int p = last;
			while (p >= 0 && !edges[p].count(s[i])) {
				edges[p][s[i]] = r;
				p = link[p];
			}
			if (p != -1) {
				int q = edges[p][s[i]];
				if (length[p] + 1 == length[q]) {
					link[r] = q;
				}
				else {
					edges.push_back(edges[q]);
					length.push_back(length[p] + 1);
					link.push_back(link[q]);
					int qq = edges.size()-1;
					link[q] = link[r] = qq;
					while (p >= 0 && edges[p][s[i]] == q) {
						edges[p][s[i]] = qq;
						p = link[p];
					}
				}
			}
			last = r;
			// debug << *this;
		}
	}
	suffix_automaton(){}
};
#ifdef LOCAL
muu & operator<<(muu &d, const suffix_automaton &x) {
	return d << "[\n\t" << x.edges << "\n\tlink: " << x.link << "\n\tlength: " << x.length
		<< "\n\tlast: " << x.last << "]\n";
}
#endif
const int nax = 2e5 + 44;
char a[nax], b[nax];
bool seen[nax];
int kmp[nax];
int cou[nax];
int occs[nax];
suffix_automaton aut;
void dfs(int x) {
	if (seen[x]) return;
	seen[x] = 1;
	for (auto p : aut.edges[x]) {
		dfs(p.second);
		cou[x] += cou[p.second];
	}
}
int main() {
	scanf("%s%s", a, b);
	int n = strlen(a), m = strlen(b);
	aut = suffix_automaton(a + 1);
	debug << imie(aut);
	int y = aut.last;
	while (y != -1) {
		int prev = aut.link[y];
		cou[y] = 1;
		y = prev;
	}
	dfs(0);
	debug << range(cou, cou + aut.edges.size());
	int wh = 0;
	occs[0] = cou[0];
	REP(i, m) {
		if (aut.edges[wh].count(b[i])) {
			wh = aut.edges[wh][b[i]];
			occs[i + 1] = cou[wh];
		}
		else
			break;
	}
	debug << range(occs, occs + m + 1);
	FOR(i, 1, m - 1) {
		int x = kmp[i];
		while (x && b[x] != b[i])
			x = kmp[x];
		kmp[i + 1] = x;
		if (b[i] == b[kmp[i + 1]]) kmp[i + 1]++;
		debug << arr(kmp, i + 1);
	}
	debug << range(kmp, kmp + m + 1);
	ll ans = n;
	FOR(i, 2, m) {
		if (kmp[i]) {
			debug << arr(kmp, i) arr(occs, i - kmp[i]);
			ans += n - occs[i - kmp[i]];
		}
		else
			ans += n;
	}
	printf("%lld\n", ans);
}