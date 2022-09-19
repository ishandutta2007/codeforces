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
#define FOR(i,b,e)for(urs((b)+(e))i=(b);i<=(e);++i)
#define REP(i,n)for(urs(n)i=0;i<(n);++i)
#define FORD(i,b,e)for(urs((b)+(e))i=(b);i>=(int)(e);--i)
#define UNTIL(t)while(clock()<(t)*CLOCKS_PER_SEC)
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define ALL(r)(r).begin(),(r).end()
#define FS(r)r.first,r.second
#define sim template<class c
#define ros return o
#define rans return ans
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=ctz(i##nvj))
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=8*sizeof(m)-clz(i##nxd)-1)
#define ksets(t, m, k, n) for (t m = (((t)1 << (k)) - 1); m < ((t)1 << (n)); m = nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g,r)sim>int f(c a){if(sizeof(c)==16)return r;if(sizeof(c)==8)return g##ll(a);return g(a);}
#define pwq(t,i) int clz(t x){return clz<int>(x)-i;}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim,class cmp=less<c> >using ordered_set=tree<c,null_type,cmp,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
#ifdef LOCAL
#include </home/kjp/headers/debuglib.hpp>
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
const int nax = 1010;
const ll m1 = (ll) 1e18 + mix(TIME) % 998244353 * 720 + 1, m2 = (ll) 1e18 + mix(TIME ^ 998244353) % 998244353 * 720 + 1;
char s[nax];
using safe_ll = pair <ll, ll>;
safe_ll operator+(safe_ll a, safe_ll b) {
	return {(a.first + b.first) % m1, (a.second + b.second) % m2};
}
safe_ll operator-(safe_ll a, safe_ll b) {
	return {(a.first - b.first) % m1, (a.second - b.second) % m2};
}
ll get(safe_ll a) {
	a.first %= m1;
	if (a.first < 0) a.first += m1;
	a.second %= m2;
	if (a.second < 0) a.second += m2;
	if (a.first == a.second) return a.first;
	return llinf;
}
safe_ll dp[nax][nax];
#define log __lOg
const int log = 10;
int kmr[nax][log];
bool cmp(pii a, pii b) {
	int la = a.second - a.first, lb = b.second - b.first;
	int common_l = min(la, lb);
	int last = 31 - clz(common_l);
	debug(imie(la), imie(lb), imie(last));
	pii ah = {kmr[a.first][last], kmr[a.first + common_l - (1 << last)][last]};
	pii bh = {kmr[b.first][last], kmr[b.first + common_l - (1 << last)][last]};
	bool ret;
	if (ah != bh)
		ret = ah < bh;
	else
		ret = la < lb;
	loc(assert(ret == (string(s + a.first, s + a.second) < string(s + b.first, s + b.second))));
	return ret;
}
safe_ll make(ll x) {return {x, x};}
safe_ll choose[nax][nax];
safe_ll psum[nax];
int reach[nax];
string get_str(pii a) {
	return string(s + a.first, s + a.second);
}
int main() {
	choose[0][0] = make(1);
	FOR(i, 1, nax - 1) {
		choose[i][0] = choose[i][i] = make(1);
		FOR(j, 1, i - 1) {
			choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
			// if (get(choose[i][j]) < llinf)
				// debug(arr(choose, i, j));
		}
	}
	int n, m;
	ll k;
	scanf("%d%d%lld%s", &n, &m, &k, s);
	REP(i, n) kmr[i][0] = s[i];
	for (int l = 1; (1 << l) <= n; ++l) {
		map <pii, vector <int> > next;
		int nlen = 1 << l, plen = nlen / 2;
		for (int i = 0; i + nlen <= n; ++i) {
			pii curr = {kmr[i][l - 1], kmr[i + plen][l - 1]};
			next[curr].push_back(i);
		}
		int cou = 0;
		for (auto &[_, v] : next) {
			for (int c : v) {
				kmr[c][l] = cou;
				debug(arr(kmr, c, l), range(s, c, c + nlen));
			}
			cou++;
		}
	}
	vpii all;
	REP(i, n) FOR(j, i + 1, n)
		all.emplace_back(i, j);
	sort(ALL(all), cmp);
	for (auto [a, b] : all)
		debug(imie(a), imie(b), string(s + a, s + b));
	int ans = -1;
	int low = 0, high = all.size() - 1;
	while (low <= high) {
		int med = (low + high) / 2;
		memset(reach, 10, sizeof(reach));
		memset(dp, 0, sizeof(dp));
		FOR(i, med, all.size() - 1) {
			auto [a, b] = all[i];
			debug(imie(a), imie(b), get_str(all[i]));
			mini(reach[a], b);
		}
		dp[n][0] = make(1);
		FOR(c, 1, m) {
			psum[0] = make(0);
			REP(i, n + 1) psum[i + 1] = psum[i] + dp[i][c - 1];
			FORD(p, n, 0) {
				int r = reach[p];
				if (r <= 2 * n)
					dp[p][c] = psum[n + 1] - psum[r];
				debug(arr2(dp, p, c));
			}
		}
		safe_ll tot = dp[0][m];
		debug(imie(tot), arr(all, med), get_str(all[med]));
		if (get(tot) >= k) {
			low = med + 1;
			ans = med;
		}
		else {
			high = med - 1;
		}
	}
	auto [a, b] = all[ans];
	printf("%s\n", string(s + a, s + b).c_str());
}