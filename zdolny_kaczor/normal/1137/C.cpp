//nie, 3 cze 2018, 13:38:19 CEST
//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
# include <bits/stdc++.h>
using namespace std;
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); ++i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); --i)
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
int f(ll a) {return g##ll(a);} int f(ull a) {return g##ll(a);}
using ll = long long; using ld = long double; using ull = unsigned long long;
using pii = pair <int, int>; using vpii = vector <pii>; using unt = unsigned int;
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
template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};
sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}
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
void fre(string c) {
#if !defined(LOCAL) && !defined(LOCAL2)
	freopen((c+".in").c_str(), "r", stdin);
	freopen((c+".out").c_str(), "w", stdout);
#endif
}
int n, m, d;
const int nax = 1e5 + 44, dax = 53;
vpii order;
bool touched[nax][dax];
int c_num[nax][dax];
vector <int> graf[nax], graft[nax];
void dfs(int x, int t) {
	int tp = t + 1;
	if (tp == d) tp = 0;
	if (touched[x][t]) return;
	touched[x][t] = 1;
	for (int v : graf[x])
		dfs(v, tp);
	order.emplace_back(x, t);
}
void dfs2(int x, int t, int num) {
	if (c_num[x][t] != -1) return;
	c_num[x][t] = num;
	debug(arr2(c_num, x, t));
	int tp = t - 1;
	if (tp == -1) tp += d;
	for (int v : graft[x])
		dfs2(v, tp, num);
}
char open[nax][dax];
vector <int> ccgraf[nax * dax];
bool done[nax * dax];
int dp[nax * dax];
int local[nax * dax];
void dfs3(int x) {
	if (done[x]) return;
	for (int v : ccgraf[x]) {
		if (v == x) continue;
		dfs3(v);
		maxi(dp[x], dp[v]);
	}
	dp[x] += local[x];
	done[x] = true;
}
int main() {
	scanf("%d%d%d", &n, &m, &d);
	assert(d != 48);
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graft[b].push_back(a);
	}
	FOR(i, 1, n) scanf("%s", open[i]);
	FOR(i, 1, n) REP(t, d) dfs(i, t);
	debug(imie(order));
	reverse(ALL(order));
	memset(c_num, 0xff, sizeof(c_num));
	int num = 0;
	for (pii x : order) {
		if (c_num[x.first][x.second] == -1)
			dfs2(FS(x), num++);
	}
	FOR(i, 1, n) REP(t, d) for (int v : graf[i]) {
		int tp = t + 1;
		if (tp == d) tp = 0;
		debug("add_edge ", arr2(c_num, i, t), arr2(c_num, v, tp));
		ccgraf[c_num[i][t]].push_back(c_num[v][tp]);
	}
	FOR(i, 1, n) {
		set <int> which;
		REP(t, d) if (open[i][t] == '1')
			which.insert(c_num[i][t]);
		debug(imie(i), imie(which));
		for (int v : which)
			local[v]++;
	}
	int start = c_num[1][0];
	dfs3(start);
	printf("%d\n", dp[start]);
}