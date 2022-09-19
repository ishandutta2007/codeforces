//nie, 3 cze 2018, 13:38:19 CEST
//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
# include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const bool local = 
#ifdef LOCAL
true;
#else
false;
#endif
#define f first
#define s second
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define bvt(s, f) int s(int x){return f(x);}int s(UI x){return f(x);}int s(LL x){return f##ll(x);}int s(ULL x){return f##ll(x);}
#define FORBITS(i,m)  for(decltype(m)lP6N4Slr=(m),i=lP6N4Slr?ctz(lP6N4Slr):0;lP6N4Slr;lP6N4Slr^=((decltype(m))1<<i),i=ctz(lP6N4Slr))
#define FORDBITS(i,m) for(decltype(m)_6Im=(m),i=_6Im?8*sizeof(m)-clz(_6Im)-1:0;_6Im;_6Im^=((decltype(m))1<<i),i=8*sizeof(m)-clz(_6Im)-1)
#define SUBS(i, mask) for(decltype(mask)i = (mask),NFR9xNQCJZTrYQ=1;NFR9xNQCJZTrYQ;NFR9xNQCJZTrYQ=i,i=(i-1)&(mask))
#define PB push_back
#define MP make_pair
#define MT(a, b, c) MP(MP(a, b), c)
#define MQ(a, b, c, d) MP(MP(a, b), MP(c, d))
#define tri(a, b, c) pair <pair <a, b>, c>
#define quadr(a, b, c, d) pair <pair <a, b>, pair <c, d> >
#define EB emplace_back
#define ymd(t) using P##t=pair<t,t>;using V##t=vector<t>;using S##t=set<t>;using T##t=pair<P##t,t>;using Q##t=pair<P##t,P##t>;
using LL=long long;using LD=long double;using VI=vector<int>;using PII=pair<int,int>;using SI=set<int>;using MII=map<int,int>;ymd(LD)
using TII=pair<PII,int>;using QII=pair<PII,PII>;using ULL=unsigned long long;ymd(ULL)ymd(VI)ymd(LL)ymd(PII)ymd(PLL)ymd(PLD)ymd(PULL)ymd(SI)
ymd(TII)ymd(TLL)ymd(TLD)ymd(QII)ymd(QLL)ymd(QLD)ymd(QULL)ymd(TULL)using UI=unsigned int;ymd(UI)ymd(PUI)ymd(VUI)ymd(TUI)ymd(QUI)ymd(VVI)
bvt(popc,__builtin_popcount)bvt(ctz,__builtin_ctz)bvt(clz,__builtin_clz)bvt(bit_parity,__builtin_parity)ymd(SLL)ymd(VLL)ymd(VULL)ymd(SULL)
#define siz(r) ((int)r.size())
#define ALL(r) r.begin(), r.end()
#define sim template <class T
#define ros return o
sim,class N>bool mini(T&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(T&o,N h){if(o<h)ros=h,1;return 0;}
#define oor >ostream &operator<<(ostream &o,
#define urs(r) typename pta<typename remove_reference<decltype(r)>::type>::t
#define bnt ;}sim> struct
sim,class N oor pair<T,N>u){ros<<"<"<<u.f<<", "<<u.s<<">" bnt pta{using t=T;};sim,int N>struct pta<T[N]>{using t=T*;};
sim,typename=typename enable_if<!is_same<T,string>::value,urs(T().end())>::type oor
T u){int c=0;o<<"{";for(auto e:u)o<<", "+2*!c++<<e;ros<<"}";}
int mpow(int b, int e) {int o = 1; while (e) {if (e & 1)o = o * 1ll * b % MOD;b = b * 1ll * b % MOD;e /= 2;}ros;}
void dor(){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(T x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);} const bool deb =
#define acv(N,O) sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(N o, T x) {ros O N(x);} \
  sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(T o, N x) {return N(o) O x;} \
  sim> typename enable_if<is_arithmetic<T>::value || is_same<T,N>::value, N&>::type operator O##=(N &o, T x) {ros = o O N(x);}
#ifdef DEB
true;
#define debug(c...)cerr<<"\033[1;"<<30+__LINE__%8<<"m["<<__FUNCTION__<<"#"<<__LINE__<<"] \033["<<30+(__LINE__/8+__LINE__*3)%8<<"m",::dor(c)
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
sim>string bte(T u){stringstream o;o<<u;ros.str()bnt nep;sim>T yyo(nep<T>);sim>nep<T>ngy(T v,string c,int m=0);sim>T yyo(T o){ros bnt
nep{T v;string c;int m; nep<T>mask(){return ngy(v,c,1);}
#define g(o) template<zub(o, v o u, N) "(" + bte(*this) + ") " #o " (" + bte(u) + ")", m);}
template<zub([],v[yyo(u)],N)c+"["+bte(u)+"]",rcu};sim>nep<T>ngy(T v,string c,int m){return nep<T>{v,c,m};}
sim>T yyo(nep<T> o){ros.v;}sim>int uhn(T){return 0;}sim>int uhn(nep<T>o){ros.m;}
#define ccy(c, y) sim> class enable_if<c is_arithmetic<T>::value,string>::type ema(T u){return bte(y);}
ccy(,bitset<8*sizeof(T)>(u))ccy(!,u)sim,class N> string ema(pair<T,N> o) {return "<" + ema(o.f) + ", " + ema(o.s) + ">";}
#define g(o) sim, zub(o, yyo(p) o u.v, T p, nep<N>) "(" + bte(p) + ") " #o " (" + bte(u) + ")", uhn(p) + u.m);}
sim>string bte(nep<T>o){ros.c+" = "+(o.m?ema(o.v):bte(o.v));}sim oor nep<T>m){ros<<bte(rcu sim>nep<T>ngy(nep<T>o,string c="",int m=0){ros;}
#undef g
#define imie(a...) ngy(a, #a)
#define imask(a...) ngy(a, #a, 1)
#define range(u, g, c) ngy(list<urs(u[0])>(&u[yyo(g)], &u[yyo(c)] + 1), #u "[" + bte(g) + "..." + bte(c) + "]")
#define arr(a, i) imie(a)[imie(i)]
#define arr2(a, i, j) imie(a)[imie(i)][imie(j)]
#define arr3(a, i, j, k) imie(a)[imie(i)][imie(j)][imie(k)]
#define arr4(a, i, j, k, q) imie(a)[imie(i)][imie(j)][imie(k)][imie(q)]
vector <stringstream> lif;struct prux {prux() {lif.EB();}~prux() {lif.pop_back();}};
#define mark_stack(c...) udz(__LINE__,c)
#define udz(a,b...) erf(a, b)
#define erf(l,c...) prux _4IJ1MYUxZy2p_Q##l;lif.back()<<"\033[1;"<<30+l%8<<"m["<<__FUNCTION__<<\
  "#"<<l<<"] \033["<<30+(l/8+l*3)%8<<"m";siw(c)
void siw(){};sim, class...N> void siw(T x, N...y) {lif.back() << x << "; ";siw(y...);}
#define print_stack() cerr << "STACK_TRACE_FROM:" << __FUNCTION__ << "#" << __LINE__<<endl,nfl()
#define ckx(o) template<zub(o, o yyo(u), nep<N>) #o "(" + bte(u) + ")", u.m);}
sim> struct tqaz{T a;int u,d,l,r;};sim> tqaz<T> zaqt(T a,int u,int d,int l,int r){return tqaz<T>{a,u,d,l,r};}
#define matr(a,u,d,l,r) ngy(zaqt(a,yyo(u),yyo(d),yyo(l),yyo(r)), #a"["+bte(u)+"..."+bte(d)+"]["+bte(l)+"..."+bte(r)+"]")
#define avc(f) sim>string f(tqaz<T> x){vector<vector<string>> t;FOR(i,x.u,x.d){t.EB();FOR(j,x.l,x.r)t.back().PB(f(x.a[i][j]));}\
stringstream o;VI M;FOR(j,x.l,x.r){int m=0;FOR(i,x.u,x.d)maxi(m, siz(t[i][j]));M.PB(m);}FOR(i,x.u,x.d){o<<"\n\t["<<i<<"] ";\
FOR(j,x.l,x.r){REP(_, M[j-x.l]-siz(t[i][j]))o<<" ";o<<t[i][j]<<((j+1)%5?", ":"; ");}}ros.str() + "\n";}
void nfl() {for (auto &s : lif)cerr << "  " << s.str() << "\033[m" << endl;} ckx(+) ckx(-) ckx(!) ckx(~) avc(bte) avc(ema)
struct zet_p {int o;LD v;zet_p(LL x):o(x%MOD),v(x){} zet_p(LL x, LD y):o(x%MOD),v(y){} int get(){ros>=0?o:o+MOD;}
  zet_p operator+(zet_p a) {return zet_p(o+a.o,v+a.v);}
  zet_p operator-(zet_p a) {return zet_p(o-a.o,v-a.v);}
  zet_p operator*(zet_p a) {return zet_p(o*1ll*a.o,v*a.v);}
  zet_p operator/(zet_p a) {assert(a.o != 0); return zet_p(o*1ll*mpow(a.o, MOD-2),v/a.v);}
  bool operator==(zet_p a) {return (o-a.o)%MOD == 0;}};
ostream&operator<<(ostream &o, zet_p u) {ros<<"["<<u.o<<" @ "<<u.v<<"]";}using frac_mod = zet_p;
#else
false;
struct zet_p {int o;int get(){ros>=0?o:o+MOD;}zet_p(LL x):o(x%MOD){}zet_p(int x):o(x%MOD){}
  zet_p operator+(zet_p a) {return zet_p(o+a.o);}
  zet_p operator-(zet_p a) {return zet_p(o-a.o);}
  zet_p operator*(zet_p a) {return zet_p(o*1ll*a.o);}
  zet_p operator/(zet_p a) {return zet_p(o*1ll*mpow(a.o, MOD - 2));}
  bool operator==(zet_p a) {return (o-a.o)%MOD == 0;}};
struct frac_mod {int o,m;int get(){return (o*1ll*mpow(m,MOD-2)%MOD+MOD)%MOD;}frac_mod(int x):o(x%MOD),m(1){}frac_mod(LL x):o(x%MOD),m(1){}
  frac_mod(LL a,LL b):o(a),m(b){}
  frac_mod operator+(frac_mod a){return frac_mod(o*1ll*a.m+m*1ll*a.o,m*a.m);}
  frac_mod operator-(frac_mod a){return frac_mod(o*1ll*a.m-m*1ll*a.o,m*a.m);}
  frac_mod operator*(frac_mod a){return frac_mod(o*1ll*a.o,m*1ll*a.m);}
  frac_mod operator/(frac_mod a){return frac_mod(o*1ll*a.m,m*1ll*a.o);}
  bool operator==(frac_mod a) {return (o * 1ll * a.m - m * 1ll * a.o) % MOD == 0;}};
acv(frac_mod, +) acv(frac_mod, -) acv(frac_mod, *) acv(frac_mod, /)
#define debug(...)
#define mark_stack(...)
#define print_stack(...)
#endif
acv(zet_p, +) acv(zet_p, -) acv(zet_p, *) acv(zet_p, /)
#define nok(o,c,r,l...) auto operator o(c p, r y)-> decltype(MP(l)) {return MP(l);}
#define pcg(o) sim, class S, class N, class H> nok(o, pair<S u T>, pair<H u N>, p.first o y.first, p.second o y.second)\
sim,class S,class N,class=typename enable_if<!is_base_of<ios_base,typename remove_reference<T>::type>::value>::type>nok\
(o,T,pair<S u N>, p o y.first, p o y.second) sim, class S, class N> nok(o, pair<S u N>, T, p.first o y, p.second o y)
#define clp(r) pcg(r) sim, class S, class N, class H> \
	pair <T,S> & operator r##=(pair <T,S> &p, pair<N,H> y) {p.first r##= y.first; p.second r##= y.second; return p;}\
	sim, class S, class N> pair <T,S> &operator r##=(pair<T,S> &p, N y) {p.first r##= y; p.second r##= y; return p;}
#define u ,
#define syd(o) sim, class N> auto operator o(pair<T,N> e) -> decltype(MP(o e.f, o e.s)) {return MP(o e.f, o e.s);}
clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)
#undef u
sim, class N> using gyv = T;
namespace std {sim, class N> struct hash<pair<T,N>>{size_t operator()(const pair<T,N>&u)const {
      return hash<T>()(u.f) * 440624741ULL ^ hash<N>()(u.s);}};
  sim> struct hash<gyv<T, decltype(((T*)0)->end())>> {size_t operator()(const T& u) const {size_t o = 505347433;
for (auto e : u)o = hash<urs(e)>()(e) ^ o * 277953755ULL;ros;}};}

const int MN = 3e5 + 44;
void PdAYB7V() {
	print_stack();
	debug(imie(MN) * 1ll * imie(MOD), "make sure it is right!!!!");
	debug("make sure m, n aren't misused");
	debug("long longs!!!!!!!!!!!!!!!!!!!");
	debug("run with m, n = 1");
	debug("make sure bounds on values aren't misused");
	debug("Check time/memory limit");
	while (getchar() != EOF);
	exit(0);
}
VI graf[MN];
int low[MN];
int pre[MN];
int dep[MN];
VI tree[MN];
void dfs(int x, int y = -1, int d = 0) {
	static int timer = 0;
	pre[x] = low[x] = ++timer;
	dep[x] = d;
	debug("enter ", imie(x), imie(y), imie(d));
	for (auto v : graf[x]) {
		if (pre[v] == 0) {
			debug("tree path ", imie(x), "->", imie(v));
			dfs(v, x, d + 1);
			mini(low[x], low[v]);
		}
		else if (dep[v] < dep[x] && v != y) {
			debug("return path", imie(x), "->", imie(v));
			mini(low[x], pre[v]);
		}
	}
}
PII furthest(int x, int y = -1) {
	debug(imie(x), imie(y));
	PII ans = MP(0, x);
	for (auto v : tree[x])
		if (v != y)
			maxi(ans, MP(1, 0) + furthest(v, x));
	return ans;
}
int u[MN];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
void Union(int a, int b) {
	u[find(a)] = find(b);
}
int main() {
	#ifdef DEB
	atexit(PdAYB7V);
	#endif
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].PB(b);
		graf[b].PB(a);
		debug(imie(a), imie(b));
	}
	dfs(1);
	debug(range(low, 1, n));
	debug(range(pre, 1, n));
	VPII edges;
	REP(i, n + 1)
		u[i] = i;
	FOR(i, 1, n)
		for (int v : graf[i])
			if (low[v] > pre[i] || low[i] > pre[v]) {
				if (i < v)
					edges.EB(v, i);
				debug(arr(low, i), arr(low, v));
			}
			else
				Union(v, i);
	int e = -1;
	for (auto x : edges) {
		int a = find(x.f), b = find(x.s);
		tree[a].EB(b);
		tree[b].EB(a);
		e = a;
	}
	int dia = furthest(furthest(e).s).f;
	printf("%d\n", dia);
}