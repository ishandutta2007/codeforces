//Konrad Paluszek,University of Warsaw(former XIV LO Staszic)
//it's nice to stick a fork into an open socket
//clock says it's time to sleep
//our getppid() in heaven, hallowed by ttyname
#ifndef LOCAL
#pragma GCC optimize("Ofast")
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
sim, class d> typename common_type<c,d>::type floor_div(c a, d b) {if (b < 0) b = -b, a = -a;return a / b - (a % b < 0);}
sim, class d> typename common_type<c,d>::type ceil_div(c a, d b) {if (b < 0) b = -b, a = -a;return a / b + (a % b > 0);}
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
void __tmi() {cerr << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
const int nax = 1 << 19;
struct val {
	int pref, suf, in, whole;
};
val make(bool good) {
	if (good) return val{1, 1, 1, 1};
	return val{0, 0, 0, -inf};
}
val operator*(val a, val b) {
	return {max(a.pref, a.whole + b.pref), max(b.suf, b.whole + a.suf), max(max(a.in, b.in), a.suf + b.pref), max(-inf, a.whole + b.whole)};
}
val tree[2 * nax];
ostream &operator<<(ostream &o, val v) {
	ros << "[pref=" << v.pref << "; suf=" << v.suf << "; in=" << v.in << "; whole=" << v.whole << "]";
}
void put(val x, int pos) {
	debug(imie(x), imie(pos));
	pos += nax;
	tree[pos] = x;
	pos /= 2;
	while (pos) {
		tree[pos] = tree[pos * 2] * tree[pos * 2 + 1];
		pos /= 2;
	}
}
int8_t seq[nax];
int n;
void set1(int x) {
	seq[x] = 1;
	if (x) put(make(!seq[x - 1]), x - 1);
	if (x + 1 < n) put(make(!seq[x + 1]), x);
}
int ans[nax];
set <int> blocked;
int NE[nax];
int get_next(int i) {
	if (NE[i] == i) return i;
	return NE[i] = get_next(NE[i]);
}
#undef assert
#define assert(...)
void rem(int i) {
	assert(NE[i] == i);
	NE[i]++;
}
void run(int l, int r, int v) {
	for (int i = get_next(l); i < r; rem(i), i = get_next(i)) {
		assert(ans[i] == 0);
		ans[i] = v;
	}
}
void set1_phase2(int x) {
	assert(seq[x] == 0);
	seq[x] = 1;
	if (x) {
		if (seq[x - 1]) blocked.insert(x - 1);
		else blocked.erase(x - 1);
	}
	if (x + 1 < n) {
		if (seq[x + 1]) blocked.insert(x);
		else blocked.erase(x);
	}
}
int main() {
	REP(i, nax) tree[i + nax] = make(false);
	for (int i = nax - 1; i; --i) tree[i] = tree[i * 2] * tree[i * 2 + 1];
	scanf("%d", &n);
	map <int, vi> where;
	REP(i, n) {
		int x;
		scanf("%d", &x);
		where[x].push_back(i);
	}
	int longest = 0;
	vector <int> poses;
	for (auto &[k, v] : where) {
		poses.push_back(k);
		for (int c : v) set1(c);
		int curr = tree[1].in;
		debug(range(seq, 0, n - 1), arr(tree, 1), imie(curr));
		maxi(longest, curr);
	}
	debug(imie(longest));
	int turns = longest / 2;
	printf("%d\n", turns);
	memset(seq, 0, sizeof(seq));
	iota(NE, NE + nax, 0);
	REP(i, n - 1) blocked.insert(i);
	blocked.insert(-1);
	blocked.insert(n - 1);
	for (auto [k, ve] : where) {
		for (int p : ve) {
			set1_phase2(p);
			debug(imie(blocked), range(seq, 0, n));
			int low = p - 1, high = p + 1;
			if (p - 1 && seq[p - 1] != seq[p]) low++;
			if (p + 1 < n && seq[p] != seq[p + 1]) high--;
			for (int v = max(low, 0); v <= min(n - 1, high); ++v) {
				auto it = blocked.lower_bound(v);
				int end = *it;
				it--;
				int beg = *it;
				beg++;
				end++;
				debug(imie(v), range(seq, beg, end));
				int len = end - beg;
				if (len & 1) {
					assert(seq[beg] == seq[end - 1]);
					if (seq[beg]) run(beg, end, k);
				}
				else {
					int half = len / 2;
					assert(seq[beg] != seq[end - 1]);
					if (seq[beg]) run(beg, beg + half, k);
					else run(beg + half, end, k);
				}
			}
		}
		debug(imie(k), "done");
	}
	REP(i, n) printf("%d ", ans[i]);
	printf("\n");
}