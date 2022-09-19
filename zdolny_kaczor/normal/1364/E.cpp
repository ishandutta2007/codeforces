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
const int nax = 1 << 11, query_limit = 4269;
int p[nax];
int query_cou;
int n;
int query(int i, int j) {
	assert(i >= 0 && i < n && j >= 0 && j < n);
	assert(i != j);
	query_cou++;
	assert(query_cou <= query_limit);
#if defined(LOCAL)
	return p[i] | p[j];
#else
	printf("? %d %d\n", i + 1, j + 1);
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	rans;
#endif
}
void answer(const vi &guess) {
	assert((int) guess.size() == n);
	loc(REP(i, n) assert(p[i] == guess[i]));
	printf("!");
	for (int v : guess) printf(" %d", v);
	printf("\n");
	debug(imie(query_cou));
	exit(0);
}
map <pii, int> cache;
int query_memo(int i, int j) {
	if (i > j) swap(i, j);
	assert(i != j);
	auto [it, added] = cache.insert(make_pair(make_pair(i, j), 0));
	if (added) it->second = query(i, j);
	return it->second;
}
int try_query(int i, int j) {
	assert(i != j);
	if (i > j) swap(i, j);
	auto it = cache.find(make_pair(i, j));
	if (it == cache.end()) return -1;
	return it->second;
}
bool is_submask(int a, int b) {
	return !(a & ~b);
}
int main() {
	unt seed = TIME;
	debug(imie(seed));
	srand(seed);
	scanf("%d", &n);
	loc(iota(p, p + n, 0); random_shuffle(p, p + n));
	// debug(range(p, p + n));
	vi candidates(n);
	iota(ALL(candidates), 0);
	while ((int) candidates.size() >= 3) {
		debug(fun(candidates.size));
		random_shuffle(ALL(candidates));
		int len = candidates.size();
		vi ands(len);
		REP(i, len) ands[i] = query_memo(candidates[i], candidates[(i + 1) % len]);
		vi left;
		// debug(imie(candidates), imie(ands));
		REP(i, len) {
			bool can = is_submask(ands[i], ands[(i + 1) % len]) && is_submask(ands[(i + len - 1) % len], ands[(i + len - 2) % len]);
			if (can) left.push_back(candidates[i]);
		}
		candidates = move(left);
	}
	debug(imie(candidates), imie(query_cou));
	assert(!candidates.empty());
	loc({
		bool found = false;
		for (int x : candidates) if (p[x] == 0) found = true;
		for (int x : candidates) debug(arr(p, x));
		assert(found);
	})
	vi ans(n);
	int zero_pos = -1;
	if (candidates.size() == 1u) zero_pos = candidates[0];
	else {
		assert(candidates.size() == 2u);
		int a = candidates[0], b = candidates[1];
		vi ord(n);
		iota(ALL(ord), 0);
		random_shuffle(ALL(ord));
		for (int c = 0; c <= 2 && zero_pos == -1; ++c) {
			for (int i : ord) if (a != i && b != i) {
				int qa = try_query(a, i), qb = try_query(b, i);
				int cou = (qa != -1) + (qb != -1);
				if (cou == c) {
					qa = query_memo(a, i);
					qb = query_memo(b, i);
					assert(is_submask(qa, qb) || is_submask(qb, qa));
					if (qa < qb) {
						zero_pos = a;
						break;
					}
					if (qa > qb) {
						zero_pos = b;
						break;
					}
				}
			}
		}
		assert(zero_pos != -1);
	}
	debug(imie(query_cou));
	loc(assert(p[zero_pos] == 0));
	REP(i, n) if (i != zero_pos) ans[i] = query_memo(i, zero_pos);
	answer(ans);
	exit(0);
}
//#STAY AT HOME