//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
# include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FOR(i, b, e) for (auto i = (b); i <= (e); ++i)
#define REP(i, n) for (urs(n) i = 0; i < (n); ++i)
#define FORD(i, b, e) for (auto i = (b); i >= (int)(e); --i)
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
#define ALL(r) (r).begin(), (r).end()
#define FS(r) r.first, r.second
#define MAKE(b, e) <urs(*(b))>(b, e)
#define sim template <class c
#define ros return o
#define rans return ans
#define forbits(i, m) if (m) for (urs(m) i = ctz(m), quq = m; quq; quq ^= ((decltype(m))1 << i), i = ctz(quq)) 
#define fordbits(i, m) if (m) for (urs(m) i = 8 * sizeof(m) - clz(m) - 1, quq = m; quq; quq ^= ((decltype(m))1 << i), i = 8 * sizeof(m) - clz(quq) - 1)
#define hur(f, g) int f(unt a) {return g(a);} int f(int a) {return g(a);} \
int f(ll a) {return g##ll(a);} int f(ull a) {return g##ll(a);} int f(long a){return f((ll)a);}; int f(unsigned long a){return f((ull)a);}
using ll = long long; using ld = long double; using ull = unsigned long long;using pii = pair <short, short>;
using vpii = vector <pii>; using unt = unsigned int;sim> using min_queue = priority_queue<c, vector<c>, greater<c>>;
template <typename T>using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)
sim,class N>bool mini(c&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,N h){if(o<h)ros=h,1;return 0;}
#ifdef LOCAL
ostream & operator<<(ostream &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
ostream & operator<<(ostream &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
#define oor >ostream &operator<<(ostream &o,
#define urs(r) typename pta<typename remove_reference<decltype(r)>::type>::t
#define bnt ;}sim> struct
sim,class N oor pair<c,N>u){ros<<"<"<<u.first<<", "<<u.second<<">" bnt pta{using t=c;}; sim,int N>struct pta<c[N]>{using t=c*;};
sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){
int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<e;ros<<"}";} void dor(){cerr<<dec<<"\033[0m"<<endl;}
sim,class...N>void dor(c x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);}
#define debug(c...)cerr<<"\033[1;"<<30+__LINE__%8<<"m"<<__FUNCTION__<<"#"<<__LINE__<<": \033["<<30+(int)(__LINE__*3.125)%8<<"m",::dor(c)
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
sim>string bte(c u){stringstream o;o<<boolalpha<<u;ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);
sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}
#define g(o) template<zub(o, v o u, N) "(" + bte(*this) + ") " #o " (" + bte(u) + ")", m);}
template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}
sim>c yyo(nep<c> o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
#define ccy(r...) sim> class enable_if<r is_arithmetic<c>::value,string>::type ema(c u){
ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}
#undef g
#define g(o) sim, zub(o, yyo(p) o u.v, c p, nep<N>) "(" + bte(p) + ") " #o " (" + bte(u) + ")", uhn(p) + u.m);}
sim>string bte(nep<c>o){ros.d+" = "+(o.m?ema(o.v):bte(o.v));}
sim oor nep<c>m){ros<<bte(rcu sim> nep<c> ngy(nep<c> o,string d="",int m=0){ros;}
#undef g
#define imie(a...) ngy(a, #a)
#define imask(a...) ngy(a, #a, 1)
#define range_v(u, g, c) ngy(list<urs(u[0])>(&u[yyo(g)], &u[yyo(c)] + 1), #u "[" + bte(g) + "..." + bte(c) + "]")
#define range(i, j) ngy(list<urs(*i)>(i, j), "[" #i "..." #j ")")
#define arr(a, i) imie(a)[imie(i)]
#define arr2(a, i, j) imie(a)[imie(i)][imie(j)]
#define arr3(a, i, j, k) imie(a)[imie(i)][imie(j)][imie(k)]
#define arr4(a, i, j, k, q) imie(a)[imie(i)][imie(j)][imie(k)][imie(q)]
#define ckx(o) template<zub(o, o yyo(u), nep<N>) #o "(" + bte(u) + ")", u.m);}
ckx(+)ckx(-)ckx(!)ckx(~)
#else
#define debug(...)
#define urs(r) typename remove_reference<decltype(r)>::type
#endif
#define vsv sim, class d, class e
#define nop(o,c,r,l...) auto operator o(c a, r b)-> decltype(make_pair(l)) {return {l};}
#define pcg(o) vsv, class f> nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second) \
vsv,class = typename enable_if<!is_base_of<ios_base, c>::value>::type> nop(o, c, pair<d u e>, a o b.first, a o b.second) \
vsv> nop(o, pair<c u d>, e, a.first o b, a.second o b)
#define clp(o) pcg(o) \
vsv> void operator o##= (pair <c,d> & a, e b) {a.first o##= b; a.second o##= b;} \
vsv, class f> void operator o##= (pair <c,d> & a, pair <e,f> b) {a.first o##= b.first; a.second o##= b.second;}
#define syd(o) sim, class d> auto operator o(pair<c, d> e) -> decltype(make_pair(o e.first, o e.second)) {return {o e.first, o e.second};}
#define u ,
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)
#undef u
ull mix(ull x){x += 0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
sim,class n>using gyv=c;namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&x)const{
return mix(hash<c>()(x.first))^hash<n>()(x.second);}};sim>struct hash<gyv<c, typename c::value_type>>
{size_t operator()(const c&x)const{size_t ans = x.size();for (auto &e : x) ans = mix(ans ^ hash<typename c::value_type>()(e));rans;}};};
#ifndef LOCAL
sim, class m> using _un0rDer3d_M4P = cc_hash_table<c, m, hash<c>>;
#define unordered_map _un0rDer3d_M4P
#endif
void fre(string c) {
#if !defined(LOCAL) && !defined(LOCAL2)
	freopen((c+".in").c_str(), "r", stdin);
	freopen((c+".out").c_str(), "w", stdout);
#endif
}
const int nax = 1e3 + 44;
struct bt {
	vector <int> r, c;
	vector <array <int, 4> > ans;
	int counter;
	int n;
	int left_rows, left_cols;
	vector <vector <bool> > blocked;
	vector <vector <int> > what;
	vector <bool> done_row, done_col;
	bool is_possible() {
		counter++;
		FOR(i, 1, n) {
			if (!done_row[i]) {
				pii where = {i, 1};
				bool do_next = true;
				while (true) {
					if (where.second == n + 1) {
						if (where.first != r[i]) {
							return false;
						}
						do_next = false;
						break;
					}
					int num = what[where.first][where.second];
					if (num == -1 && !blocked[where.first][where.second]) break;
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.second++;
				}
				where = {r[i], n};
				if (do_next) {
					while (true) {
						if (where.second == 0) {
							return false;
						}
						int num = what[where.first][where.second];
						if (num == -1 && !blocked[where.first][where.second]) break;
						if (num != -1) {
							auto to = ans[num];
							where.first ^= to[0] ^ to[2];
							where.second ^= to[1] ^ to[3];
						}
						where.second--;
					}
				}
			}
			if (!done_col[i]) {
				pii where = {1, i};
				bool do_next = true;
				while (true) {
					if (where.first == n + 1) {
						if (where.second != c[i]) {
							return false;
						}
						do_next = false;
						break;
					}
					int num = what[where.first][where.second];
					if (num == -1 && !blocked[where.first][where.second]) break;
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.first++;
				}
				where = {n, c[i]};
				if (do_next) {
					while (true) {
						if (where.first == 0) {
							return false;
						}
						int num = what[where.first][where.second];
						if (num == -1 && !blocked[where.first][where.second]) break;
						if (num != -1) {
							auto to = ans[num];
							where.first ^= to[0] ^ to[2];
							where.second ^= to[1] ^ to[3];
						}
						where.first--;
					}
				}
			}
		}
		return true;
	}
	bt(const vector <int> &_r, const vector <int> &_c)
		: r(_r)
		, c(_c)
		, counter(0)
		, n(r.size() - 1)
		, left_rows(n)
		, left_cols(n) 
		, blocked(n + 1, vector<bool>(n + 1))
		, what(n + 1, vector<int>(n + 1, -1))
		, done_row(n + 1), done_col(n + 1)
	{
		while (!go()) {
			debug("try again");
		}
	}
	bool go() {
		if (left_rows == 1 && left_cols == 1) return true;
		if (!is_possible()) return false;
		REP(_, 3) {
			bool do_row = false;
			int i = 0;
			do {
				do_row = rand() % 2;
				if (left_rows == 1) do_row = false;
				if (left_cols == 1) do_row = true;
				i = rand() % n + 1;
			}
			while (do_row ? done_row[i] : done_col[i]);
			if (do_row) {
				vector <pii> path_start, path_end;
				pii where = {i, 1};
				while (where.second != n + 1) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_start.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.second++;
				}
				if (where.first == r[i]) {
					done_row[i] = 1;
					left_rows--;
					for (pii x : path_start) blocked[x.first][x.second] = 1;
					if (go()) return true;
					done_row[i] = 0;
					left_rows++;
					for (pii x : path_start) blocked[x.first][x.second] = 0;
					continue;
				}
				where = {r[i], n};
				while (where.second != 0) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_end.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.second--;
				}
				if (path_start.empty() || path_end.empty()) return false;
				vpii indices = {{0, 0}};
				if (path_start.size() >= 2u)
					indices.emplace_back(1, 0);
				if (path_end.size() >= 2u)
					indices.emplace_back(0, 1);
				if (path_start.size() >= 3u)
					indices.emplace_back(rand() % (path_start.size() - 2) + 2, rand() % path_end.size());
				if (path_end.size() >= 3u)
					indices.emplace_back(rand() % path_start.size(), rand() % (path_end.size() - 2) + 2);
				for (pii x : indices) {
					int i1 = x.first, i2 = x.second;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 1;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 1;
					int num = ans.size();
					ans.push_back({FS(path_start[i1]), FS(path_end[i2])});
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = num;
					if (go()) return true;
					ans.pop_back();
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = -1;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 0;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 0;
				}
			}
			else {
				vector <pii> path_start, path_end;
				pii where = {1, i};
				while (where.first != n + 1) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_start.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.first++;
				}
				if (where.second == c[i]) {
					done_col[i] = 1;
					left_cols--;
					for (pii x : path_start) blocked[x.first][x.second] = 1;
					if (go()) return true;
					done_col[i] = 0;
					left_cols++;
					for (pii x : path_start) blocked[x.first][x.second] = 0;
					continue;
				}
				where = {n, c[i]};
				while (where.first != 0) {
					int num = what[where.first][where.second];
					if (num == -1 && blocked[where.first][where.second] == 0)
						path_end.push_back(where);
					if (num != -1) {
						auto to = ans[num];
						where.first ^= to[0] ^ to[2];
						where.second ^= to[1] ^ to[3];
					}
					where.first--;
				}
				if (path_start.empty() || path_end.empty()) return false;
				vpii indices = {{0, 0}};
				if (path_start.size() >= 2u)
					indices.emplace_back(1, 0);
				if (path_end.size() >= 2u)
					indices.emplace_back(0, 1);
				if (path_start.size() >= 3u)
					indices.emplace_back(rand() % (path_start.size() - 2) + 2, rand() % path_end.size());
				if (path_end.size() >= 3u)
					indices.emplace_back(rand() % path_start.size(), rand() % (path_end.size() - 2) + 2);
				for (pii x : indices) {
					int i1 = x.first, i2 = x.second;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 1;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 1;
					int num = ans.size();
					ans.push_back({FS(path_start[i1]), FS(path_end[i2])});
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = num;
					if (go()) return true;
					ans.pop_back();
					what[path_start[i1].first][path_start[i1].second] = what[path_end[i2].first][path_end[i2].second] = -1;
					REP(a, i1) blocked[path_start[a].first][path_start[a].second] = 0;
					REP(a, i2) blocked[path_end[a].first][path_end[a].second] = 0;
				}
			}
		}
		return false;
	}
};
vector <array <int, 4> > solve(vector <int> r, vector <int> c) {
	debug(imie(r), imie(c));
	bt b(r, c);
	return b.ans;
}
void verify(vector <int> r, vector <int> c, vector <array <int, 4> > answer) {
	int n = r.size() - 1;
	assert(r.size() == c.size());
	for (auto x : answer)
		for (int y : x)
			assert(y >= 1 && y <= n);
	vector <vpii> mapa(n + 1, vpii(n + 1));
	FOR(i, 1, n)
		FOR(j, 1, n)
			mapa[i][j] = {i, j + 1};
	for (auto x : answer) {
		assert(mapa[x[0]][x[1]] == pii(x[0], x[1] + 1));
		assert(mapa[x[2]][x[3]] == pii(x[2], x[3] + 1));
		mapa[x[0]][x[1]] = {x[2], x[3] + 1};
		mapa[x[2]][x[3]] = {x[0], x[1] + 1};
	}
	FOR(i, 1, n) {
		pii where = {i, 1};
		while (where.second <= n)
			where = mapa[where.first][where.second];
		assert(r[i] == where.first);
	}
	FOR(i, 1, n)
		FOR(j, 1, n)
			mapa[i][j] = {i + 1, j};
	for (auto x : answer) {
		assert(mapa[x[0]][x[1]] == pii(x[0] + 1, x[1]));
		assert(mapa[x[2]][x[3]] == pii(x[2] + 1, x[3]));
		mapa[x[0]][x[1]] = {x[2] + 1, x[3]};
		mapa[x[2]][x[3]] = {x[0] + 1, x[1]};
	}
	FOR(i, 1, n) {
		pii where = {1, i};
		while (where.first <= n)
			where = mapa[where.first][where.second];
		assert(c[i] == where.second);
	}
}
void one_test(vector <int> r, vector <int> c) {
	auto ans = solve(r, c);
	verify(r, c, ans);
}
void run_tests() {
	FOR(n, 1, 5) {
		vector <int> r(n + 1), c(n + 1);
		REP(i, n + 1) r[i] = c[i] = i;
		do do one_test(r, c);
		while (next_permutation(1 + ALL(c))); while (next_permutation(1 + ALL(r)));
		debug("passed for ", imie(n));
	}
}
int main() {
#ifdef LOCAL
	run_tests();
#endif
	int n;
	scanf("%d", &n);
	vector <int> r(n + 1), c(n + 1);
	FOR(i, 1, n) scanf("%d", &r[i]);
	FOR(i, 1, n) scanf("%d", &c[i]);
	auto ans = solve(r, c);
	printf("%d\n", (int) ans.size());
	for (auto x : ans) {
		for (int c : x) printf("%d ", c);
		printf("\n");
	}
}