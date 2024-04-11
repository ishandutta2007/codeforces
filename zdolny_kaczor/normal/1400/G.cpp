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
#define mask_set(...)
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
const int nax = 3e5 + 44, mod = 119 << 23 | 1;
ll powe(ll b, ll e) {
	ll r = 1;
	while (e) {
		if (e & 1) r = r * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return r;
}
int u[nax];
int l[nax], r[nax];
vi coms[nax];
int find(int x) {
	if (u[x] == x) return x;
	return u[x] = find(u[x]);
}
void onion(int a, int b) {
	if (rand() % 2) swap(a, b);
	u[find(a)] = find(b);
}
void reset() {
	iota(u, u + nax, 0);
}
ll fac[nax], fin[nax];
void fac_init() {
	fac[0] = 1;
	for (int i = 1; i < nax; ++i) fac[i] = fac[i - 1] * i % mod;
	fin[nax - 1] = powe(fac[nax - 1], mod - 2);
	for (int i = nax - 2; i >= 0; --i) fin[i] = fin[i + 1] * (i + 1) % mod;
	assert(fin[3] * fac[3] % mod == 1);
	assert(fac[5] == 120);
}
vi by_l[nax], by_r[nax];
vi graf[nax];
int num_in_com[nax];
ll choose(int a, int b) {
	if (b < 0 || b > a) return 0;
	return fac[a] * fin[b] % mod * fin[a - b] % mod;
}
vector <uint8_t> is_good[nax];
int com_id[nax];
bool marked[nax];
vi mul(const vi &a, const vi &b) {
	vi ans(a.size() + b.size() - 1);
	REP(i, a.size()) REP(j, b.size()) ans[i + j] = (ans[i + j] + a[i] * 1ll * b[j]) % mod;
	rans;
}
void solve() {
	fac_init();
	reset();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", l + i, r + i);
		by_l[l[i]].push_back(i);
		by_r[r[i]].push_back(i);
	}
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		onion(a, b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		coms[find(i)].push_back(i);
	}
	int com_cou = 0;
	for (int i = 1; i <= n; ++i) if (coms[i].size() >= 2u) {
		com_id[i] = com_cou++;
		int s = coms[i].size();
		REP(j, s) num_in_com[coms[i][j]] = j;
		is_good[i].resize(1 << s);
		is_good[i][0] = true;
		for (int m = 1; m < 1 << s; ++m) {
			int b = ctz(m);
			if (is_good[i][m ^ (1 << b)]) {
				bool err = false;
				for (int v : graf[coms[i][b]]) {
					int nu = num_in_com[v];
					if (m >> nu & 1) {
						err = true;
						break;
					}
				}
				is_good[i][m] = !err;
			}
			else
				is_good[i][m] = false;
		}
	}
	int free = 0;
	vector <vi> by_cou(com_cou, vi(1, 1));
	vi all_pro = {1};
	auto redo_com = [&](int i) {
		i = find(i);
		int curr_mask = 0;
		int s = coms[i].size();
		REP(j, s) {
			int v = coms[i][j];
			if (marked[v]) {
				curr_mask |= (1 << j);
			}
		}
		int com_num = com_id[i];
		vi now(1 + popc(curr_mask));
		for (int sub = curr_mask; sub >= 0; sub = sub ? (sub - 1) & curr_mask : -1) {
			if (is_good[i][sub]) now[popc(sub)]++;
		}
		debug(imie(by_cou));
		by_cou[com_num] = now;
		all_pro = {1};
		for (auto &x : by_cou) all_pro = mul(all_pro, x);
	};
	auto inc = [&](int i) {
		debug("include", imie(i), arr(graf, i), arr(l, i), arr(r, i));
		assert(!marked[i]);
		marked[i] = true;
		if (coms[i].size() == 1u) {
			free++;
			return;
		}
		redo_com(i);
	};
	auto rem = [&](int i) {
		debug("remove", imie(i), arr(graf, i), arr(l, i), arr(r, i));
		assert(marked[i]);
		marked[i] = false;
		if (coms[i].size() == 1u) {
			free--;
			return;
		}
		redo_com(i);
	};
	ll ans = 0;
	for (int s = 1; s <= n; ++s) {
		for (int x : by_l[s]) inc(x);
		debug("query", imie(s));
		debug(imie(all_pro), imie(free));
		int can_take = all_pro.size() - 1;
		for (int take = 0; take <= can_take; ++take) {
			ll here = all_pro[take] * choose(free, s - take);
			debug(imie(take), imie(here));
			(ans += here) %= mod;
		}
		for (int x : by_r[s]) rem(x);
	}
	printf("%lld\n", fix(ans, mod));
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME