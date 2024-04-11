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
const int mod = 1000 * 1000 * 1000 + 7;
void add_self(int & a, int b) { a += b; if(a >= mod) a -= mod; }
void sub_self(int & a, int b) { a -= b; if(a < 0) a += mod; }
int mul(int a, int b) { return (ll) a * b % mod; }
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = mul(r, a);
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) { return my_pow(a, mod - 2); }

struct Massey {
	vector<int> start, coef; // 3 optional lines
	vector<vector<int>> powers;
	int memo_inv;
	
	// Start here and write the next ~25 lines until "STOP"
	
	int L; // L == coef.size() <= start.size()
	Massey(vector<int> in) { // O(N^2)
		L = 0;
		const int N = in.size();
		vector<int> C{1}, B{1};
		for(int n = 0; n < N; ++n) {
			assert(0 <= in[n] && in[n] < mod); // invalid input
			B.insert(B.begin(), 0);
			int d = 0;
			for(int i = 0; i <= L; ++i)
				add_self(d, mul(C[i], in[n-i]));
			if(d == 0) continue;
			vector<int> T = C;
			C.resize(max(B.size(), C.size()));
			for(int i = 0; i < (int) B.size(); ++i)
				sub_self(C[i], mul(d, B[i]));
			if(2 * L <= n) {
				L = n + 1 - L;
				B = T;
				d = my_inv(d);
				for(int & x : B) x = mul(x, d);
			}
		}
		cerr << "L = " << L << "\n";
		assert(2 * L <= N - 2); // NO RELATION FOUND :(
		// === STOP ===
		for(int i = 1; i < (int) C.size(); ++i)
			coef.push_back((mod - C[i]) % mod);
		assert((int) coef.size() == L);
		for(int i = 0; i < L; ++i)
			start.push_back(in[i]);
		while(!coef.empty() && !coef.back()) { coef.pop_back(); --L; }
		if(!coef.empty()) memo_inv = my_inv(coef.back());
		powers.push_back(coef);
		//~ debug() << imie(coef);
	}
	
	vector<int> mul_cut(vector<int> a, vector<int> b) {
		vector<int> r(2 * L - 1);
		for(int i = 0; i < L; ++i)
			for(int j = 0; j < L; ++j)
				add_self(r[i+j], mul(a[i], b[j]));
		while((int) r.size() > L) {
			int value = mul(r.back(), memo_inv); // div(r.back(), coef.back());
			const int X = r.size();
			add_self(r[X-L-1], value);
			for(int i = 0; i < L; ++i)
				sub_self(r[X-L+i], mul(value, coef[i]));
			assert(r.back() == 0);
			r.pop_back();
		}
		return r;
	}
	int get(ll k) { // O(L^2 * log(k))
		if(k < (int) start.size()) return start[k];
		if(L == 0) return 0;
		k -= start.size();
		vector<int> vec = coef;
		for(int i = 0; (1LL << i) <= k; ++i) {
			if(i == (int) powers.size())
				powers.push_back(mul_cut(powers.back(), powers.back()));
			if(k & (1LL << i))
				vec = mul_cut(vec, powers[i]);
		}
		int total = 0;
		for(int i = 0; i < L; ++i)
			add_self(total, mul(vec[i], start[(int)start.size()-1-i]));
		return total;
	}
};
void solve(Massey &m) {
	int k;
	scanf("%d", &k);
	if (k == 1) printf("0\n");
	else printf("%lld\n", 4ll * m.get(k - 2) % mod);
}
void run() {
	const int nax = 1e7 + 44;
	static vi graf[nax];
	int head = 1;
	vi vec;
	while (true) {
		int memo = head;
		REP(i, memo) {
			int add;
			if (graf[i].size() == 0u) add = 1;
			else if (graf[i].size() == 1u) add = 2;
			else add = 0;
			REP(_, add) graf[i].push_back(head++);
		}
		if (head > nax) break;
		vector <bool> used(head);
		int curr = 0;
		for (int i = head - 1; i >= 0; --i) {
			int sub = 0;
			for (int x : graf[i]) if (!used[x]) sub++;
			if (sub >= 3) {
				used[i] = true;
				curr++;
			}
		}
		vec.push_back(curr);
	}
	debug(imie(vec));
	Massey m(vec);
}
int main() {
	// loc(run());
	vector <int> in = {0, 1, 1, 3, 6, 12, 24, 49, 97, 195, 390, 780, 1560, 3121, 6241, 12483, 24966, 49932, 99864, 199729, 399457, 798915};
	Massey m(in);
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	scanf("%d", &t);
	REP(_, t) solve(m);
	exit(0);
}
//#STAY AT HOME