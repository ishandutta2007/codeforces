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
#define UNTIL(t)while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define ALL(r)(r).begin(),(r).end()
#define RALL(r)(r).rbegin(),(r).rend()
#define FS(r)r.first,r.second
#define SF(r)r.second,r.first
#define M0(r) memset(r, 0, sizeof(r))
#define sim template<class c
#define ros return o
#define rans return ans
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=ctz(i##nvj))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=8*sizeof(m)-clz(i##nxd)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << (k)) - 1); m < ((t)1 << (n)); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
#define pwq(t,i) int clz(t x){return clz<int>(x)-i;}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using vll=vector<ll>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using spii=set<pii>;using mii=map<int,int>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class b,class cmp=less<c> >using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim, class cmp=less<c>>using ordered_set = ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#if defined(LOCAL) // || defined(LOCAL2)
#include </home/kjp/headers/debuglib.hpp>
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#define reg_it(...)
#define def_op(...) struct _{};
#if !defined(LOCAL) && !defined(LOCAL2)
#define exit my_exit
void my_exit(int x) {fflush(stdout);_Exit(x);}
#endif
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
#define pow do not use cmath pow unless you know what you are doing
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;ros;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=(ll)(a*(ld)b/m);ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
#pragma GCC diagnostic pop
#if ((ULONG_MAX) != (UINT_MAX))
namespace std {template <> struct is_signed<__int128> : public true_type {};}
#endif
sim, class d> typename common_type<c,d>::type floor_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using floor_div with different signedness");if (b < 0) b = -b, a = -a;return a / b - (a % b < 0);}
sim, class d> typename common_type<c,d>::type ceil_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using ceil_div with different signedness");if (b < 0) b = -b, a = -a;return a / b + (a % b > 0);}
sim> struct REV {using value_type=typename c::value_type;c &x;using it=typename c::reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> struct CREV {using value_type=typename c::value_type;const c&x;using it=typename c::const_reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> REV<c> reversed(c&x) {return REV<c>{x};}sim> CREV<c> reversed(const c&x) {return CREV<c>{x};}
#define done(r...) exit(0 * printf(r))
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << setprecision(6) << fixed << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
//#STAY AT HOME
#define vsv sim,class d,class e
#define nop(o,c,r,l...)>auto operator o(const c&a,const r&b)->decltype(make_pair(l)){return{l};}
#define pcg(o) vsv,class f nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second)vsv,class=typename enable_if<!is_base_of<ios_base,c>::value>::type nop(o,c,pair<d u e>,a o b.first,a o b.second)vsv nop(o,pair<c u d>,e,a.first o b,a.second o b)
#define clp(o) pcg(o)vsv>void operator o##=(pair<c,d>&a,const e&b){a.first o##=b;a.second o##=b;}vsv,class f>void operator o##=(pair<c,d>&a,const pair<e,f>&b){a.first o##=b.first;a.second o##=b.second;}
#define syd(o) sim,class d>auto operator o(pair<c, d> e)->decltype(make_pair(o e.first,o e.second)){return{o e.first,o e.second};}
#define u ,
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)
#undef u
using P = array<ll, 3>;
const P zero = {0, 0, 0};
ll sca(P a, P b) {
	ll ans = 0;
	REP(i, 3) ans += a[i] * b[i];
	rans;
}
P vec(P a, P b) {
	P ans = {};
	int s = 0;
	REP(i, 3) REP(j, 3) if (i != j) {
		int k = i ^ j ^ 3;
		int c = 1 - ((++s) & 2);
		ans[k] += a[i] * b[j] * c;
	}
	assert(sca(ans, a) == 0);
	assert(sca(ans, b) == 0);
	debug(imie(a), imie(b), imie(ans));
	rans;
}
pair <P, P> find(P tar) {
	REP(i, 2) REP(j, 2) REP(k, 2) {
		P s = {i, j, k};
		P q = vec(s, tar);
		if (q != zero)
			return {q, vec(q, tar)};
	}
	debug(imie(tar));
	abort();
}
using P2 = pair <ll, ll>;
int zeros = 0, pairs = 0, reflex = 0;
int cou = 0;
const P2 zero2 = {0, 0};
int vec_sign(P2 a, P2 b) {
	__int128 r = a.first * __int128(b.second) - a.second * __int128(b.first);
	if (r > 0) return 1;
	if (r == 0) return 0;
	if (r < 0) return -1;
	abort();
}
struct ang_cmp {
	bool operator()(P2 a, P2 b) const {
		assert(a != zero2);
		assert(b != zero2);
		bool al = a < zero2;
		bool bl = b < zero2;
		if (al != bl) return al < bl;
		return vec_sign(a, b) > 0;
	};
};
map <P2, int, ang_cmp> rou;
using it_t = map<P2, int, ang_cmp>::iterator;
it_t ne(it_t a) {
	a++;
	if (a == rou.end()) return rou.begin();
	return a;
}
it_t pr(it_t a) {
	if (a == rou.begin()) a = rou.end();
	a--;
	return a;
}
void put(P2 x) {
	debug(imie(x));
	cou++;
	if (x == P2{0, 0}) {
		zeros++;
		return;
	}
	if (rou[x]++ == 0) {
		debug("new point", imie(x));
		if (rou.count(-x)) pairs++;
		auto it = rou.find(x);
		auto p = pr(it);
		auto n = ne(it);
		if (vec_sign(p->first, it->first) <= 0) reflex++;
		if (vec_sign(it->first, n->first) <= 0) reflex++;
		if (vec_sign(p->first, n->first) <= 0) reflex--;
	}
}
void rem(P2 x) {
	debug(imie(x));
	cou--;
	if (x == P2{0, 0}) {
		zeros--;
		return;
	}
	auto it = rou.find(x);
	assert(it != rou.end());
	it->second--;
	if (it->second == 0) {
		debug("bye bye", imie(x));
		if (rou.count(-x)) pairs--;
		auto p = pr(it);
		auto n = ne(it);
		if (vec_sign(p->first, it->first) <= 0) reflex--;
		if (vec_sign(it->first, n->first) <= 0) reflex--;
		if (vec_sign(p->first, n->first) <= 0) reflex++;
		rou.erase(it);
	}
}
int get_ans() {
	debug(imie(rou), imie(reflex), imie(cou), imie(zeros), imie(pairs));
	if (zeros) return 1;
	if (cou < 2) return 0;
	if (pairs) return 2;
	if (reflex) return 0;
	return 3;
}
void solve() {
	P tar;
	REP(i, 3) scanf("%lld", &tar[i]);
	auto [q, r] = find(tar);
	debug(imie(tar), imie(q), imie(r));
	vector <P2> si(1);
	int n;
	scanf("%d", &n);
	REP(_, n) {
		char t;
		scanf(" %c", &t);
		if (t == 'A') {
			P cu;
			REP(i, 3) scanf("%lld", &cu[i]);
			debug("A", cu);
			P2 p = {sca(cu, q), sca(cu, r)};
			ll g = abs(gcd(FS(p)));
			if (g) p /= g;
			si.push_back(p);
			put(p);
		}
		else {
			int x;
			scanf("%d", &x);
			debug("R", x);
			rem(si[x]);
		}
		int ans = get_ans();
		printf("%d\n", ans);
		assert(ans <= cou);
	}
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME