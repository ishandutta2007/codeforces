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
#define log l0g
const int nax = 1e6 + 44, log = 20, mod = 1e9 + 7;
vi match(string::iterator a, string::iterator b, int len) {
	vi ans(len);
	REP(i, len) ans[i] = *(a + i) == *(b + i) ? len - 1 : i;
	for (int i = len - 2; i >= 0; --i) mini(ans[i], ans[i + 1]);
	debug(range(a, a + len), range(b, b + len), imie(ans));
	return ans;
}
vector <string> in;
vector <vi> one;
vector <vi> A, B, C;
struct segment {
	int p;
	int b, e;
	string to_str() const {
		return string(in[p].begin() + b, in[p].begin() + e);
	}
};
ostream &operator<<(ostream &o, segment s) {
	ros << "{" << string(in[s.p].begin() + s.b, in[s.p].begin() + s.e) << "}=" << s.p << "[" << s.b << "," << s.e << ")";
}
int cmp_impl(segment a, segment b) {
	debug(imie(a), imie(b));
	assert(a.e - a.b == b.e - b.b);
	assert(abs(a.p - b.p) <= 1);
	assert(abs(a.b - b.b) <= 1);
	bool flip = pii(a.p, a.b) > pii(b.p, b.b);
	int ret = -5;
	if (flip) swap(a, b);
	if (a.p == b.p) {
		if (a.b == b.b) ret = 0;
		else {
			int fir = one[a.p][a.b] - a.b;
			if (fir >= a.e - a.b) 
				ret = 0;
			else {
				char ca = in[a.p][a.b + fir];
				char cb = in[b.p][b.b + fir];
				if (ca < cb) ret = -1;
				else if (ca == cb) ret = 0;
				else ret = 1;
			}
		}
	}
	else {
		int fir = -1;
		if (a.b == b.b) {
			fir = A[a.p][a.b] - a.b;
		}
		else if (a.b == b.b + 1) {
			fir = B[a.p][b.b] - b.b;
		}
		else if (a.b + 1 == b.b) {
			fir = C[a.p][a.b] - a.b;
		}
		else abort();
		assert(fir >= 0);
		// debug(imie(fir));
		if (fir >= a.e - a.b) ret = 0;
		else {
			char ca = in[a.p][a.b + fir];
			char cb = in[b.p][b.b + fir];
			if (ca < cb) ret = -1;
			else if (ca == cb) ret = 0;
			else ret = 1;
		}
	}
	assert(ret >= -1 && ret <= 1);
	if (flip) ret *= -1;
	debug(imie(ret));
	return ret;
}
int cmp(segment a, segment b) {
	int ret = cmp_impl(a, b);
#ifdef LOCAL
	string aa = a.to_str(), bb = b.to_str();
	debug(imie(aa), imie(bb), imie(ret));
	if (aa > bb) assert(ret == 1);
	if (aa == bb) assert(ret == 0);
	if (aa < bb) assert(ret == -1);
#endif
	return ret;
}
using elem = vector <segment>;
int cmp_impl(elem s1, elem s2) {
	debug(imie(s1), imie(s2));
	int i1 = 0, i2 = 0;
	while (i1 < (int) s1.size() && i2 < (int) s2.size()) {
		auto &[p1, b1, e1] = s1[i1];
		auto &[p2, b2, e2] = s2[i2];
		int take = min(e1 - b1, e2 - b2);
		int c = cmp(segment{p1, b1, b1 + take}, segment{p2, b2, b2 + take});
		if (c != 0) return c;
		b1 += take;
		b2 += take;
		if (b1 == e1) i1++;
		if (b2 == e2) i2++;
	}
	bool has1 = i1 != (int) s1.size();
	bool has2 = i2 != (int) s2.size();
	assert(!has1 || !has2);
	if (has1) return -1;
	if (has2) return 1;
	return 0;
}
int cmp(const elem &s1, const elem &s2) {
	debug(imie(s1), imie(s2));
	int ret = cmp_impl(s1, s2);
	#ifdef LOCAL
		string aa, bb;
		for (auto &x : s1) aa += x.to_str();
		for (auto &x : s2) bb += x.to_str();
		debug(imie(aa), imie(bb), imie(ret));
		if (aa > bb) assert(ret == 1);
		if (aa == bb) assert(ret == 0);
		if (aa < bb) assert(ret == -1);
	#endif
	return ret;
}
bool equiv(elem a, elem b) {
	return cmp(a, b) == 0;
}
 bool my_less(elem a, elem b) {
	return cmp(a, b) == -1;
}
void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}
void solve() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		static char word[nax];
		scanf("%s", word);
		in.emplace_back(word);
		in.back().push_back('#');
	}
	debug(imie(in));
	REP(i, n)
		one.push_back(match(in[i].begin(), in[i].begin() + 1, in[i].size() - 1));
	REP(i, n - 1) {
		A.push_back(match(in[i].begin(), in[i + 1].begin(), min(in[i].size(), in[i + 1].size())));
		B.push_back(match(in[i].begin() + 1, in[i + 1].begin(), min(in[i].size() - 1, in[i + 1].size())));
		C.push_back(match(in[i].begin(), in[i + 1].begin() + 1, min(in[i].size(), in[i + 1].size() + 1)));
	}
	vector <vector <elem> > each(n);
	REP(i, n) {
		int l = in[i].size();
		each[i].push_back({segment{i, 0, l}});
		for (int s = 0; s + 1 < l; ++s) {
			each[i].emplace_back();
			if (s) each[i].back().push_back(segment{i, 0, s});
			if (s + 1 != l) each[i].back().push_back(segment{i, s + 1, l});
		}
		sort(ALL(each[i]), my_less);
		// each[i].resize(unique(ALL(each[i]), equiv) - each[i].begin());
		debug(arr(in, i), arr(each, i));
	}
	vector <vi> dp(n);
	dp[0].resize(each[0].size(), 1);
	REP(i, n - 1) {
		int prev = i, curr = i + 1;
		int head = 0;
		int inc = 0;
		dp[curr].resize(each[curr].size());
		REP(j, each[curr].size()) {
			while (head != (int) each[prev].size() && cmp(each[prev][head], each[curr][j]) != 1) {
				add(inc, dp[prev][head]);
				debug(arr(each, prev, head), "<=", arr(each, curr, j));
				head++;
			}
			dp[curr][j] = inc;
		}
		debug(arr(dp, curr));
	}
	int ans = 0;
	for (int x : dp.back()) add(ans, x);
	printf("%d\n", ans);
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME