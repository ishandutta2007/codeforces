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
struct Solver {
	vector <vi> graf;
	int n, e1, e2, d;
	vi dep1, deepest1, dep2, deepest2;
	vi par1, par2;
	vi down, up;
	void run(int x, int y, int d, vi &dep, vi &deepest, vi &par) {
		dep[x] = d;
		deepest[x] = d;
		par[x] = y;
		for (int v : graf[x]) if (v != y) {
			run(v, x, d + 1, dep, deepest, par);
			maxi(deepest[x], deepest[v]);
		}
	}
	vi par_glo;
	void dfs1(int x, int y = 0) {
		par_glo[x] = y;
		down[x] = 0;
		for (int v : graf[x]) if (v != y) {
			dfs1(v, x);
			maxi(down[x], down[v] + 1);
		}
	}
	void dfs2(int x, int y = 0) {
		for (int v : graf[x]) if (v != y) maxi(up[v], up[x] + 1);
		vpii best;
		for (int v : graf[x]) if (v != y) best.emplace_back(down[v], v);
		sort(RALL(best));
		for (int v : graf[x]) if (v != y) {
			for (auto [val, wh] : best) {
				if (wh != v) {
					maxi(up[v], val + 1);
					break;
				}
			}
		}
		for (int v : graf[x]) if (v != y) dfs2(v, x);
	}
	Solver() {
		scanf("%d%d%d", &n, &e1, &e2);
		graf.resize(n + 1);
		dep1.resize(n + 1);
		deepest1.resize(n + 1);
		par1.resize(n + 1);
		dep2.resize(n + 1);
		deepest2.resize(n + 1);
		par2.resize(n + 1);
		REP(_, n - 1) {
			int a, b;
			scanf("%d%d", &a, &b);
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		run(e1, 0, 0, dep1, deepest1, par1);
		run(e2, 0, 0, dep2, deepest2, par2);
		debug(imie(par1), imie(par2));
		vi path;
		for (int at = e1; at != e2; at = par2[at]) path.push_back(at);
		path.push_back(e2);
		debug(imie(path));
		int tail1 = 0, tail2 = 0;
		bool moved = true;
		d = path.size() - 1;
		while(moved) {
			moved = false;
			int v1 = path[max(0, d - tail1)];
			int d1 = deepest1[v1];
			int new_tail2 = d1 - d;
			debug(imie(v1), imie(d1), imie(new_tail2));
			assert(new_tail2 >= tail2);
			if (new_tail2 > tail2) {
				moved = true;
				tail2 = new_tail2;
			}
			int v2 = path[min(d, tail2)];
			int d2 = deepest2[v2];
			int new_tail1 = d2 - d;
			debug(imie(v2), imie(d2), imie(new_tail1));
			assert(new_tail1 >= tail1);
			if (new_tail1 > tail1) {
				moved = true;
				tail1 = new_tail1;
			}
		}
		bool can_free = tail1 + tail2 >= d;
		debug(imie(can_free));
		down.resize(n + 1, -1);
		up.resize(n + 1, -1);
		par_glo.resize(n + 1);
		dfs1(1, -1);
		dfs2(1, -1);
		bool found_star = false;
		for (int i = 1; i <= n; ++i) {
			int big = 0;
			debug(arr(par_glo, i));
			for (int v : graf[i]) {
				int test;
				if (v == par_glo[i]) test = up[i];
				else test = down[v];
				debug(imie(i), imie(v), imie(test));
				if (test + 1 >= d) big++;
			}
			debug(imie(i), imie(big));
			if (big >= 3) found_star = true;
		}
		debug(imie(found_star));
		puts(found_star && can_free ? "YES" : "NO");
		debug(draw_tree(1, graf));
		debug(draw_tree(1, graf, [&](int x){stringstream o; o << "{" << x << "; u = " << up[x] << "; d = " << down[x] << "}"; ros.str();}));
	}
};
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	scanf("%d", &t);
	REP(_, t) Solver();
	exit(0);
}
//#STAY AT HOME