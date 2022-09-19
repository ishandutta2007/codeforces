//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
# include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define bvt(s, f) int s(int x){return f(x);}int s(UI x){return f(x);}int s(LL x){return f##ll(x);}int s(ULL x){return f##ll(x);}
#define FORBITS(i,m)  for(decltype(m)lP6N4Slr=(m),i=lP6N4Slr?ctz(lP6N4Slr):0;lP6N4Slr;lP6N4Slr&=~((decltype(m))1<<i),i=ctz(lP6N4Slr))
#define FORDBITS(i,m) for(decltype(m)_6Im=(m),i=_6Im?8*sizeof(m)-clz(_6Im)-1:0;_6Im;_6Im&=~((decltype(m))1<<i),i=8*sizeof(m)-clz(_6Im)-1)
#define SUBS(i, mask) for(decltype(mask)i = (mask),NFR9xNQCJZTrYQ=1;NFR9xNQCJZTrYQ;NFR9xNQCJZTrYQ=i,i=(i-1)&(mask))
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ymd(t) using P##t=pair<t,t>;using V##t=vector<t>;using S##t=set<t>;using T##t=pair<P##t,t>;using Q##t=pair<P##t,P##t>;
using LL=long long;using LD=long double;using VI=vector<int>;using PII=pair<int,int>;using SI=set<int>;using MII=map<int,int>;ymd(LD)
using TII=pair<PII,int>;using QII=pair<PII,PII>;using ULL=unsigned long long;ymd(ULL)ymd(VI)ymd(LL)ymd(PII)ymd(PLL)ymd(PLD)ymd(PULL)ymd(SI)
ymd(TII)ymd(TLL)ymd(TLD)ymd(QII)ymd(QLL)ymd(QLD)ymd(QULL)ymd(TULL)using UI=unsigned int;ymd(UI)ymd(PUI)ymd(VUI)ymd(TUI)ymd(QUI)
bvt(popc,__builtin_popcount)bvt(ctz,__builtin_ctz)bvt(clz,__builtin_clz)bvt(bit_parity,__builtin_parity)
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
const int MOD = 1e9 + 7;
int mpow(int b, int e) {int o = 1; while (e) {if (e & 1)o = o * 1ll * b % MOD;b = b * 1ll * b % MOD;e /= 2;}ros;}
void dor(){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(T x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);} const bool deb =
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
#define mark_stack(c...) erf(__LINE__,c)
#define erf(l,c...) prux _4IJ1MYUxZy2p_Q##l;lif.back()<<__FUNCTION__<<"#"<<l<<": ";siw(c)
void siw(){};sim, class...N> void siw(T x, N...y) {lif.back() << x << "; ";siw(y...);}
#define print_stack() cerr << "STACK_TRACE_FROM:" << __FUNCTION__ << "#" << __LINE__<<endl,nfl()
#define ckx(o) template<zub(o, o yyo(u), nep<N>) #o "(" + bte(u) + ")", u.m);}
sim> struct tqaz{T a;int u,d,l,r;};sim> tqaz<T> zaqt(T a,int u,int d,int l,int r){return tqaz<T>{a,u,d,l,r};}
#define matr(a,u,d,l,r) ngy(zaqt(a,yyo(u),yyo(d),yyo(l),yyo(r)), #a"["+bte(u)+"..."+bte(d)+"]["+bte(l)+"..."+bte(r)+"]")
#define avc(f) sim>string f(tqaz<T>x){string o="";FOR(i,x.u,x.d){o+="\n\t["+bte(i)+"] ";FOR(j,x.l,x.r)o+=f(x.a[i][j])+\
  ((j+1)%5?", ":"; ");}ros+"\n";}
void nfl() {for (auto &s : lif)cerr << "  " << s.str() << endl;} ckx(+) ckx(-) ckx(!) ckx(~) avc(bte) avc(ema)
#define acv(N,O) sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(N o, T x) {ros + N(x);} \
  sim> typename enable_if<is_arithmetic<T>::value, N>::type operator O(T o, N x) {return N(o) + x;} \
  sim> typename enable_if<is_arithmetic<T>::value || is_same<T,N>::value, N>::type 
#else
false;
#define debug(...)
#define mark_stack(...)
#define print_stack(...)
#endif
#define nok(o,c,r,l...) auto operator o(c p, r y)-> decltype(make_pair(l)) {return make_pair(l);}
#define pcg(o) sim, class S, class N, class H> nok(o, pair<S u T>, pair<H u N>, p.first o y.first, p.second o y.second)\
sim,class S,class N,class=typename enable_if<!is_base_of<ios_base,typename remove_reference<T>::type>::value>::type>nok\
(o,T,pair<S u N>, p o y.first, p o y.second) sim, class S, class N> nok(o, pair<S u N>, T, p.first o y, p.second o y)
#define clp(r) pcg(r) sim, class S, class N, class H> \
	pair <T,S> & operator r##=(pair <T,S> &p, pair<N,H> y) {p.first r##= y.first; p.second r##= y.second; return p;}\
	sim, class S, class N> pair <T,S> &operator r##=(pair<T,S> &p, N y) {p.first r##= y; p.second r##= y; return p;}
#define u ,
#define syd(o) sim, class N> auto operator o(pair<T,N> e) -> decltype(make_pair(o e.f, o e.s)) {return make_pair(o e.f, o e.s);}
clp(+) clp(-) clp(*) clp(/) clp(%) clp(^) clp(|) clp(>>) clp(<<) clp(&) pcg(&&) pcg(||) syd(-) syd(+) syd(~) syd(!)
#undef u
sim, class N> using gyv = T;
namespace std {sim, class N> struct hash<pair<T,N> > {size_t operator()(const pair<T,N>&u) const {
      return hash<T>()(u.f) * 440624741ULL ^ hash<N>()(u.s);}};
  sim> struct hash<gyv<T, decltype(((T*)0)->end())>> {size_t operator()(const T& u) const {size_t o = 505347433;
      for (auto e : u)o = hash<urs(e)>()(e) ^ o * 277953755ULL;ros;}};}
const int MN = 1e6 + 44;
int per[MN];
int main() {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", per + i);
    per[i]--;
  }
  int cycles = 0;
  REP(i, n) {
    if (per[i] != -1) {
      cycles++;
      int wh = i;
      do {
        int wh2 = per[wh];
        per[wh] = -1;
        wh = wh2;
      }
      while (wh != i);
    }
  }
  if (cycles % 2 == 0)
    printf("Petr\n");
  else
    printf("Um_nik\n");
}