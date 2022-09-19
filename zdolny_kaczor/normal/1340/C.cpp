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
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using spii=set<pii>;using mii=map<int,int>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class b,class cmp=less<c> >using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim, class cmp=less<c>>using ordered_set = ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
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
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;ros^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf = 1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;ros;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
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
const int vax = 501, nax = 1e4 + 44;
int stop[nax];
vi graf[nax];
int pos[nax];
int g, r;
void add_edge(int a, int b) {
	debug(arr(pos, a), arr(pos, b));
	graf[a].push_back(b);
	graf[b].push_back(a);
}
struct dir1 {
	bitset<vax> b;
	dir1() : b(0) {
		b[0] = 1;
	}
	dir1(const bitset<vax>&x) : b(x) {}
	void insert(int c) {
		for (; c < vax; c *= 2) b |= b << c;
	}
	bool has(int x) const {return b[x];}
	void set(int x) {b[x] = 1;}
	void operator|=(const dir1 &a) {b |= a.b;}
	dir1 shift(int x) const {
		return b << x;
	}
	void set_all() {
		b.set();
	}
};
struct dir2 {
	bitset<vax> b;
	dir2(const bitset<vax>&x) : b(x) {}
	dir2() : b(0) {
		b[vax - 1] = 1;
	}
	void insert(int c) {
		for (; c < vax; c *= 2) b |= b >> c;
	}
	dir2 shift(int x) const {
		return b >> x;
	}
	bool has(int x) const {return b[vax - x - 1];}
	void operator|=(const dir2 &a) {b |= a.b;}
	void set_all() {
		b.set();
	}
};
ostream &operator<<(ostream &o, dir1 a) {
	o << "{";
	int q = 0;
	REP(i, min(g * 2, vax)) if (a.has(i)) o << ", " + 2 * !q++ << i;
	ros << "}";
}
ostream &operator<<(ostream &o, dir2 a) {
	o << "{";
	int q = 0;
	REP(i, min(g * 2, vax)) if (a.has(i)) o << ", " + 2 * !q++ << i;
	ros << "}";
}
bool adds_impl(const dir1 &x, const dir2 &y, int v) {
	assert(v < vax);
	// debug(imie(x.b) << (imie(vax) - 1 - imie(v)) & imie(y.b));
	return ((x.b << (vax - 1 - v)) & y.b).any();
}
bool adds_bru(const dir1&x, const dir2&y, int v) {
	// debug(imie(x), imie(y), imie(v));
	for (int i = 0; i <= v; ++i) if (x.has(i) && y.has(v - i)) {
		// debug(imie(v) - imie(i));
		return true;
	}
	// debug("not found");
	return false;
}
bool adds(const dir1&x, const dir2&y, int v) {
	bool ret = adds_impl(x, y, v);
	loc(assert(ret == adds_bru(x, y, v)));
	return ret;
}
dir1 Lwaste[nax];
dir2 Rwaste[nax];
int dist[nax];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d", pos + i);
	scanf("%d%d", &g, &r);
	sort(pos, pos + m);
	for (int i = 1; i < m; ++i) {
		int d = pos[i] - pos[i - 1];
		Lwaste[i] |= Lwaste[i - 1].shift(d);
		Lwaste[i].insert(d);
	}
	for (int i = m - 2; i >= 0; --i) {
		int d = pos[i + 1] - pos[i];
		Rwaste[i] |= Rwaste[i + 1].shift(d);
		Rwaste[i].insert(d);
	}
	for (int i = 0; i < m; ++i) debug(arr(pos, i), arr(Lwaste, i), arr(Rwaste, i));
	REP(start, m) {
		dir1 curr = Lwaste[start];
		for (int i = start + 1; i < m && pos[i] <= pos[start] + g; ++i) {
			int d = pos[i] - pos[i - 1];
			int went = pos[i] - pos[start];
			debug(imie(d));
			if (d == 1)
				curr.set_all();
			else {
				curr.shift(d);
				if (curr.has(d))
					curr.set(0);
				else
					curr.insert(d);
			}
			curr |= Lwaste[i];
			int left = g - went;
			if (left % 2 == 0 && adds(curr, Rwaste[i], left / 2)) add_edge(start, i);
			debug(imie(start), arr(pos, i), imie(curr));
		}
	}
	memset(dist, 60, sizeof(dist));
	dist[0] = 0;
	queue<int> bfs;
	bfs.push(0);
	while (!bfs.empty()) {
		int x = bfs.front();
		bfs.pop();
		for (int v : graf[x]) if (dist[v] > nax * 10) {
			dist[v] = dist[x] + 1;
			bfs.push(v);
		}
	}
	int ans = numeric_limits<int>::max();
	for (int i = 0; i < m; ++i) {
		if (dist[i] < nax * 10 && pos[i] + g >= pos[m - 1]) {
			mini(ans, dist[i] * (g + r) + (pos[m - 1] - pos[i]));
		}
	}
	if (ans == numeric_limits<int>::max()) printf("-1\n");
	else printf("%d\n", ans);
	exit(0);
}
//#STAY AT HOME