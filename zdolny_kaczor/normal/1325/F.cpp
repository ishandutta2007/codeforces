//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
//it's nice to stick a fork into an open socket
//clock says it's time to sleep
//our getppid() in heaven, hallowed by ttyname
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
#define sim template<class c
#define ros return o
#define rans return ans
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=ctz(i##nvj))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=8*sizeof(m)-clz(i##nxd)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << (k)) - 1); m < ((t)1 << (n)); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
#define pwq(t,i) int clz(t x){return clz<int>(x)-i;}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using spii=set<pii>;using mii=map<int,int>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class b,class cmp=less<c> >using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim, class cmp=less<c>>using ordered_set = ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#if defined(LOCAL) // || defined(LOCAL2)
namespace std {
#include </home/kjp/headers/debuglib.hpp>
}
#else
#define loc(...)
#define onl(r...)r
#define debug(...)
#define print_stack(...)
#define mark_stack(...)
#define set_pre(...)
#define reg_it(...)
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
#if ((ULONG_MAX) != (UINT_MAX))
namespace std {template <> struct is_signed<__int128> : public true_type {};}
#endif
#define q31 (8 * sizeof(c) - 1)
sim, class d> typename common_type<c,d>::type floor_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using floor_div with different signedness");if (b < 0) b = -b, a = -a;return a / b - (a % b < 0);}
sim, class d> typename common_type<c,d>::type ceil_div(c a, d b) {static_assert(is_signed<c>::value==is_signed<d>::value,"using ceil_div with different signedness");if (b < 0) b = -b, a = -a;return a / b + (a % b > 0);}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-security"
template <class...c> void done(const c&...x) {printf(x...); exit(0);}
#pragma GCC diagnostic pop
sim> typename enable_if<is_signed<c>::value, c>::type FastMax(c x, c y) { return ((x - y) >> q31 & (x ^ y)) ^ x; }
sim> typename enable_if<is_signed<c>::value, c>::type FastMin(c x, c y) { return ((x - y) >> q31 & (x ^ y)) ^ y; }
sim> typename enable_if<is_signed<c>::value, c>::type FastAbs(c x)        { return (x ^ x >> q31) - (x >> q31); }
sim> typename enable_if<is_signed<c>::value, c>::type gcd(c a, c b) {
	loc(assert(a > 0 && b > 0));
	int aa = ctz(a), bb = ctz(b);
	int r = FastMin(aa, bb);
	a >>= aa;
	while (a && b) {
		b >>= ctz(b);
		c x = FastAbs(a - b);
		a = FastMin(a, b);
		b = x;
	}
	return (a + b) << r;
}
sim> c lcm(c a, c b) {return a / gcd(a, b) * b;}
sim>typename enable_if<is_integral<c>::value,ull>::type my_hash(c x){
	if(sizeof(c)>8) return mix((ull)x^SALT)^mix((ull)(x>>64)^SALT);
	return mix(x^SALT);
}
template<size_t N>ull my_hash(const bitset<N>&x){
	return mix(hash<bitset<N>>()(x)^SALT);
}
sim,class n>ull my_hash(const pair<c,n>&);
sim>gyv<ull,typename c::value_type>my_hash(const c&x){
	ull o=SALT;
	for(auto&d:x)o=mix(o^my_hash(d));
	ros;
}
sim,class n>ull my_hash(const pair<c,n>&x){return mix(my_hash(x.first))^my_hash(x.second);}
sim>struct my_hasher{size_t operator()(const c&o)const{return my_hash(o);}};
sim, class m>
#ifdef LOCAL
using _un0rDer3d_M4P=unordered_map<c,m,my_hasher<c>>;
sim> using _un0rDer3d_5et = unordered_set<c, my_hasher<c>>;
#else
struct _un0rDer3d_M4P : public cc_hash_table<c,m,my_hasher<c>>{bool count(const c&x)const{return this->find(x) != this->end();}};
sim> using _un0rDer3d_5et = _un0rDer3d_M4P<c, null_type>;
#endif
#define unordered_map _un0rDer3d_M4P
#define unordered_set _un0rDer3d_5et
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << setprecision(6) << fixed << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
sim> struct REV {c &x;using it=typename c::reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> struct CREV {const c&x;using it=typename c::const_reverse_iterator;it begin(){return x.rbegin();}it end(){return x.rend();}};
sim> REV<c> reversed(c&x) {return REV<c>{x};}sim> CREV<c> reversed(const c&x) {return CREV<c>{x};}
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;
const int nax = 1e5 + 44;
vi graf[nax];
int dep[nax], par[nax], col[nax], which[nax];
int cycle;
int mex(const set <int> &s) {
	int p = 0;
	for (int x : s) {
		if (x != p) break;
		p++;
	}
	return p;
}
void dfs(int x, int y = 0, int d = 0) {
	assert(col[x] == 0);
	col[x] = 1;
	dep[x] = d;
	par[x] = y;
	vector <int> down, up;
	for (int v : graf[x]) if (v != y) {
		if (col[v] == 0) down.push_back(v);
		if (col[v] == 1) up.push_back(v);
	}
	for (int v : up) {
		if (dep[x] - dep[v] + 1 >= cycle) {
			int at = x;
			vector <int> C = {at};
			while (at != v) {
				at = par[at];
				C.push_back(at);
			}
			printf("2\n%d\n", (int) C.size());
			for (int x : C) printf("%d ", x);
			done("\n");
		}
	}
	set <int> seen;
	for (int v : up) seen.insert(which[v]);
	if (y != 0) seen.insert(which[y]);
	which[x] = mex(seen);
	debug(arr(which, x));
	for (int v : down) if (col[v] == 0) dfs(v, x, d + 1);
	col[x] = 2;
}
vector <int> by_spl[nax];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	cycle = 1;
	while (cycle * cycle < n) cycle++;
	dfs(1);
	for (int i = 1; i <= n; ++i) by_spl[which[i]].push_back(i);
	debug(range(by_spl, 0, n + 1));
	for (int i = 0; i <= n; ++i) if ((int) by_spl[i].size() >= cycle) {
		by_spl[i].resize(cycle);
		printf("1\n");
		for (int x : by_spl[i]) printf("%d ", x);
		done("\n");
	}
	abort();
}