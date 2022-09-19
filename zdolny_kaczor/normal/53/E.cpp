//nie, 13 maj 2018, 15:56:16 CEST
# include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define PB push_back
#define MP make_pair
#define EB emplace_back
using LL = long long; using LD = long double; using VI = vector<int>;
using PII = pair<int,int>; using VPII = vector<PII>;
#define siz(r) ((int)r.size())
#define ALL(r) r.begin(), r.end()
#define sim template <class T
#define ros return o
sim, class N> void mini(T &p, N h) {if (p > h) p = h;}
sim, class N> void maxi(T &p, N h) {if (p < h) p = h;}
#define oor >ostream &operator<<(ostream &o,
#define urs(r) typename pta<typename remove_reference<decltype(r)>::type>::t
#define bnt ;}sim> struct
sim,class N oor pair<T,N>u){ros<<"<"<<u.f<<", "<<u.s<<">" bnt pta{using t = T;};sim,int N>struct pta<T[N]>{using t=T*;};
sim,typename=typename enable_if<!is_same<T,string>::value,urs(T().end())>::type oor
T u){int c=0;o<<"{";for(auto e:u)o<<", "+2*!c++<<e;ros<<"}";}
void dor(){cerr<<dec<<"\033[0m"<<endl;}sim,class...N>void dor(T x,N...y){cerr<<boolalpha<<x<<"; ";dor(y...);}
#ifdef DEB
#define debug(c...)cerr<<"\033[1;"<<30+__LINE__%8<<"m["<<__FUNCTION__<<"#"<<__LINE__<<"] \033["<<30+(__LINE__/8+__LINE__*3)%8<<"m",::dor(c)
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
sim>string bte(T u){stringstream o;o<<u;ros.str()bnt nep;
sim>T yyo(nep<T>);sim>nep<T>ngy(T v,string c,int m=0);sim>T yyo(T o){ros bnt
nep{T v;string c;int m; nep<T>mask(){return ngy(v,c,1);}
#define g(o) template <zub(o, v o u, N) "(" + bte(*this) + ") " #o " (" + bte(u) + ")", m);}
template<zub([],v[yyo(u)],N)c+"["+bte(u)+"]",rcu};sim>nep<T>ngy(T v,string c,int m){return nep<T>{v,c,m};}
sim>T yyo(nep<T> o){ros.v;}sim>int uhn(T){return 0;}sim>int uhn(nep<T>o){ros.m;}
#define ccy(c, y) sim> class enable_if<c is_arithmetic<T>::value,string>::type ema(T u){return bte(y);}
ccy(,bitset<8*sizeof(T)>(u))ccy(!,u)sim>string bte(nep<T>o){ros.c+" = "+(o.m?ema(o.v):bte(o.v));}
#define g(o) sim, zub(o, yyo(p) o u.v, T p, nep<N>) "(" + bte(p) + ") " #o " (" + bte(u) + ")", uhn(p) + u.m);}
sim oor nep<T>m){ros<<bte(rcu sim>nep<T>ngy(nep<T>o,string c="",int m=0){ros;}
#undef g
#define imie(a) ngy(a, #a)
#define imask(a) ngy(a, #a, 1)
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
void nfl() {for (auto &s : lif)cerr << "  " << s.str() << endl;}
#else
#define debug(...)
#define mark_stack(...)
#define print_stack(...)
#endif
#define FORBITS(i,m)  for(int a_0X=(m),i=a_0X?__builtin_ctz(a_0X):0;a_0X;a_0X&=~(1<<i),i=__builtin_ctz(a_0X))
#define SUBS(i, m) for (int i = (m); i; i = (i - 1) & m)
const int MN = 10;
unsigned dp[1 << MN][1 << MN];
bool conn[MN][MN];
unsigned binom[MN + 1][MN + 1];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  REP(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    conn[a][b] = conn[b][a] = true;
  }
  REP(i, n)
    FOR(j, i + 1, n - 1)
      if (conn[i][j]) {
        int a = (1 << i), b = (1 << j), c = a | b;
        dp[c][c] = dp[c][a] = dp[c][b] = dp[c][0] = 1;
      }
  debug(1 << imie(n));
  REP(all, 1 << n) {
    if (__builtin_popcount(all) <= 2)
      continue;
    SUBS(leaves, all) {
      if (leaves == all)
        continue;
      int v = __builtin_ctz(leaves);
      debug(imask(all), imask(leaves), imie(v));
      FORBITS(x, all &~ leaves) {
        debug(imie(x));
        if (conn[v][x]) {
          dp[all][leaves] += dp[all &~ (1 << v)][leaves &~ (1 << v)];
        }
      }
      if (dp[all][leaves])
        debug(arr2(dp, imask(all), imask(leaves)));
      dp[all][0] += dp[all][leaves] * (__builtin_parity(leaves) ? 1 : -1);
    }
  }
  debug(imie(n));
  binom[0][0] = 1;
  FOR(i, 1, MN) {
    binom[i][0] = binom[i][i] = 1;
    FOR(j, 1, i - 1)
      binom[i][j] = binom[i - 1][j] + binom[i - 1][j - 1];
  }
  unsigned ans = 0;
  int all = (1 << n) - 1;
  REP(mask, (1 << n)) {
    int j = __builtin_popcount(mask);
    if (j >= k) {
      int s = 1 - ((j - k) & 1) * 2;
      ans += dp[all][mask] * binom[j][k] * s;
    }
  }
  printf("%u\n", ans);
}