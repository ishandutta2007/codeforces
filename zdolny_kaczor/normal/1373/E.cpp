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
const int nax = 1e7 + 1;
int d_sum_arr[nax];
int dsum(int x) {
	int ans = 0;
	while (x >= nax) {
		ans += x % 10;
		x /= 10;
	}
	rans + d_sum_arr[x];
}
// const int qax = 151;
// int ans[qax];
// void bru(int k) {
	// memset(ans, -1, sizeof(ans));
	// int su = 0;
	// for (int i = 0; i <= k; ++i) su += dsum(i);
	// if (su < qax && ans[su] == -1) ans[su] = 0;
	// const int bou = 1e9;
	// for (int i = 1; i <= bou; ++i) {
		// su -= dsum(i - 1);
		// su += dsum(i + k);
		// if (su < qax && ans[su] == -1) ans[su] = i;
	// }
	// printf("ans[%d] = {", k);
	// for (int i = 0; i < qax; ++i) printf("%d, ", ans[i]);
	// printf("};\n");
// }
vi ans[20];
void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	if (!ans[k].empty()) {
		printf("%d\n", ans[k][n]);
	}
	else if (k == 0) {
		string a;
		while (n) {
			int d = min(n, 9);
			a.push_back('0' + d);
			n -= d;
		}
		reverse(ALL(a));
		puts(a.c_str());
	}
	else {
		int su = 0;
		for (int i = 0; i <= k; ++i) su += dsum(i);
		if (su == n) {
			printf("%d\n", 0);
			return;
		}
		const int bou = 1e6;
		for (int i = 1; i < bou; ++i) {
			su -= dsum(i - 1);
			su += dsum(i + k);
			if (su == n) {
				printf("%d\n", i);
				return;
			}
		}
		printf("-1\n");
	}
}
int main() {
	ans[1] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4, 9, 5, 19, 6, 29, 7, 39, 8, 49, 18, 59, 28, 69, 38, 79, 48, 89, 58, 189, 68, 289, 78, 389, 88, 489, 98, 589, 198, 689, 298, 789, 398, 889, 498, 989, 598, 1989, 698, 2989, 798, 3989, 898, 4989, 998, 5989, 1998, 6989, 2998, 7989, 3998, 8989, 4998, 9989, 5998, 19989, 6998, 29989, 7998, 39989, 8998, 49989, 9998, 59989, 19998, 69989, 29998, 79989, 39998, 89989, 49998, 99989, 59998, 199989, 69998, 299989, 79998, 399989, 89998, 499989, 99998, 599989, 199998, 699989, 299998, 799989, 399998, 899989, 499998, 999989, 599998, 1999989, 699998, 2999989, 799998, 3999989, 899998, 4999989, 999998, 5999989, 1999998, 6999989, 2999998, 7999989, 3999998, 8999989, 4999998, 9999989, 5999998, 19999989, 6999998, 29999989, 7999998, 39999989, 8999998, 49999989, 9999998, 59999989, 19999998, 69999989, 29999998, 79999989, 39999998, 89999989, 49999998, 99999989, 59999998, 199999989, 69999998, 299999989, 79999998, 399999989, 89999998, 499999989, 99999998, 599999989, 199999998, 699999989, 299999998, 799999989, 399999998, 899999989, };
	ans[2] = {-1, -1, -1, 0, -1, -1, 1, -1, -1, 2, -1, -1, 3, -1, -1, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, -1, -1, 17, -1, -1, 27, -1, -1, 37, -1, -1, 47, -1, -1, 57, -1, -1, 67, -1, -1, 77, -1, -1, 87, -1, -1, 97, -1, -1, 197, -1, -1, 297, -1, -1, 397, -1, -1, 497, -1, -1, 597, -1, -1, 697, -1, -1, 797, -1, -1, 897, -1, -1, 997, -1, -1, 1997, -1, -1, 2997, -1, -1, 3997, -1, -1, 4997, -1, -1, 5997, -1, -1, 6997, -1, -1, 7997, -1, -1, 8997, -1, -1, 9997, -1, -1, 19997, -1, -1, 29997, -1, -1, 39997, -1, -1, 49997, -1, -1, 59997, -1, -1, 69997, -1, -1, 79997, -1, -1, 89997, -1, -1, 99997, -1, -1, 199997, -1, -1, 299997, -1, -1, 399997, -1, -1, 499997, -1, -1, 599997, -1, -1, 699997, };

	for (int i = 1; i < nax; ++i) {
		d_sum_arr[i] = i % 10 + d_sum_arr[i / 10];
	}
	// bru(1);
	// bru(2);
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME