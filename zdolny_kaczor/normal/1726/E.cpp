//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
//#STAY AT HOME
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#define TIME (chrono::steady_clock::now().time_since_epoch().count())
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define xfm(a,b)a##b
#define xwb(a,b)xfm(a,b)
#define _ xwb(nvj,__LINE__)
#define __ xwb(kjy,__LINE__)
#define ___ xwb(cjm,__LINE__)
#define REP(i,n)for(urs(n)i=0;i<(n);++i)
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define FS(r)r.first,r.second
#define ALL(r)(r).begin(),(r).end()
#define M0(r) memset(r,0,sizeof(r))
#define sim template<class c
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=i##nvj?ctz(i##nvj):0)
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=i##nxd?8*sizeof(m)-clz(i##nxd)-1:0)
#define ksets(t, m, k, n)for(t m=(((t)1<<(k))-1);m<((t)1<<(n));m=nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g)sim>int f(c a){if(sizeof(c)==8)return g##ll(a);return g(a);}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using vll=vector<ll>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<>>;sim,class b,class cmp=less<c>>using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim,class cmp=less<c>>using ordered_set=ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount)hur(ctz,__builtin_ctz)hur(clz,__builtin_clz)sim,class N>bool mini(c&o,const N&h){if(o>h)return o=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)return o=h,1;return 0;}
#ifdef LOCAL
#include </home/konrad/cp/headers/debuglib.hpp>
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#define reg_it(...)
#define def_op(...) struct _{};
#define mask_set(...)
#define exit my_exit
void __resources();
void my_exit(int x) {fflush(stdout);
#ifdef LOCAL2
__resources();
#endif
_Exit(x);}
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
#define pow don't'
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;return o^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf=1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;return o;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
//#STAY AT HOME
#define rer(o,f) zet_p operator o(zet_p y)const{return zet_p(v f loc(,w o y.w));}zet_p&operator o##=(zet_p y){return*this=*this o y;}
#define ycc(o) sim>typename enable_if<is_integral<c>::value,zet_p>::type operator o(c a, zet_p b){return zet_p(a) o b;}
const int mod = 119 << 23 | 1;
ll inv(ll b){assert(b);int e=mod-2;ll o=1;while(e){if(e&1)o=o*b%mod;b=b*b%mod;e>>=1;}return o;}struct zet_p{int v;loc(ld w;)sim=int,typename=typename enable_if<is_integral<c>::value>::type>zet_p(c r=0):v(r%mod)loc(,w(r)){}loc(sim>zet_p(c a, ld b):v(a%mod),w(b){})rer(+,+y.v)rer(-,-y.v)rer(*,*1ll*y.v)rer(/,*inv(y.v))int get()const{return ((unt)v+mod)%mod;}zet_p operator-()const{return zet_p(-v loc(,-w));}bool operator==(zet_p y)const{return(v-y.v)%mod==0;}};ycc(+)ycc(-)ycc(*)ycc(/)sim>bool operator==(c a, zet_p b){return zet_p(a)==b;}loc(ostream&operator<<(ostream &o,zet_p y){return o<<"["<<y.get()<<"~"<<y.w<<"]";})
const int nax = 3e5 + 44;
zet_p factorial[nax];
zet_p double_factorial[nax];
zet_p involutions[nax];
zet_p pow2[nax];
zet_p choose(int a, int b) {
	if (b > a || b < 0) {
		debug("WARNING", imie(a), imie(b));
		return 0;
	}
	return factorial[a] / (factorial[b] * factorial[a - b]);
}
void solve() {
	int n;
	scanf("%d", &n);
	zet_p ans = 0;
	for (int pairs = 0; pairs <= n / 2; pairs += 2) {
		ans += involutions[n - 2 * pairs]
				* choose(n - pairs, pairs)
				* (pairs == 0 ? 1 : double_factorial[pairs - 1])
				* pow2[pairs / 2];

		debug(imie(involutions)[imie(n) - 2 * imie(pairs)]
				* imie(choose)(imie(n) - imie(pairs), imie(pairs))
				* (pairs == 0 ? imie(zet_p(1)) : imie(double_factorial)[imie(pairs) - 1])
				* imie(pow2)[imie(pairs / 2)]);
	}
	debug(imie(ans));
	printf("%d\n", ans.get());
}
void init() {
	factorial[0] = double_factorial[0] = 1;
	for (int i = 1; i < nax; ++i) {
		factorial[i] = factorial[i - 1] * i;
	}
	double_factorial[1] = 1;
	for (int i = 2; i < nax; ++i)
		double_factorial[i] = double_factorial[i - 2] * i;
	involutions[0] = involutions[1] = 1;
	for (int i = 2; i < nax; ++i)
		involutions[i] = involutions[i - 1] + involutions[i - 2] * (i - 1);
	pow2[0] = 1;
	for (int i = 1; i < nax; ++i) pow2[i] = 2 * pow2[i - 1];
	debug(range(involutions, 0, 10));
}
int main() {
	static_assert(mod == 998244353);
	init();
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME