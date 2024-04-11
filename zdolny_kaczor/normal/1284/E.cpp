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
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<c>>;sim>using ordered_set=tree<c,null_type,less<c>,rb_tree_tag,tree_order_statistics_node_update>;hur(popc,__builtin_popcount,popc<ull>(a)+popc<ull>(a>>64))hur(ctz,__builtin_ctz,(ull)a?ctz<ull>(a):64+ctz<ull>(a>>64))hur(clz,__builtin_clz,a>>64?clz<ull>(a>>64):64+clz<ull>(a))pwq(short,16)pwq(uint16_t,16)pwq(char,24)pwq(int8_t,24)pwq(uint8_t,24)sim,class N>bool mini(c&o,const N&h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)ros=h,1;return 0;}sim,class n>using gyv=c;
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
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}__attribute__((no_sanitize_undefined))ll mul(ll a,ll b,ll m){ll q=a*(ld)b/m;ll o=a*b-q*m;o%=m;if(o<0)o+=m;ros;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}sim>c gcd(c o,c b){while(o&&b){int x=ctz(o),y=ctz(b);if(x>y)o>>=x-y;else b>>=y-x;if(o>b)o-=b;else b-=o;}ros?o:b;}sim>c lcm(c o,c b){ros/gcd(o,b)*b;}
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
sim,class m>using _un0rDer3d_M4P=loc(unordered_map)onl(cc_hash_table)<c,m,my_hasher<c>>;
#define unordered_map _un0rDer3d_M4P
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
#define vsv sim,class d,class e
#define nop(o,c,r,l...)>auto operator o(const c&a,const r&b)->decltype(make_pair(l)){return{l};}
#define pcg(o) vsv,class f nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second)vsv,class=typename enable_if<!is_base_of<ios_base,c>::value>::type nop(o,c,pair<d u e>,a o b.first,a o b.second)vsv nop(o,pair<c u d>,e,a.first o b,a.second o b)
#define clp(o) pcg(o)vsv>void operator o##=(pair<c,d>&a,const e&b){a.first o##=b;a.second o##=b;}vsv,class f>void operator o##=(pair<c,d>&a,const pair<e,f>&b){a.first o##=b.first;a.second o##=b.second;}
#define syd(o) sim,class d>auto operator o(pair<c, d> e)->decltype(make_pair(o e.first,o e.second)){return{o e.first,o e.second};}
#define u ,
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)
#undef u
const int nax = 2500;
pii in[nax];
bool acmp(pii a, pii b) {
	// assert(a != pii(0, 0));
	// assert(b != pii(0, 0));
	// bool a1 = a < pii(0, 0), b1 = b < pii(0, 0);
	// if (a1 != b1) return a1;
	return a.first * 1ll * b.second > a.second * 1ll * b.first;
}
ll choose(int n, int s) {
	ll ans = 1;
	REP(i, s) ans = ans * (n - i) / (i + 1);
	rans;
}
pii abs(pii x) {
	return x > pii(0, 0) ? x : -x;
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", FS(&in[i]));
	ll ans = 0;
	REP(i, n) {
		vector <pair <pii, bool> > around(n - 1);
		const int size = n - 1;
		int head = 0;
		REP(j, n) if (i != j)
			around[head++] = {abs(in[i] - in[j]), in[i] > in[j]};
		auto get = [&](int i) {
			i %= (2 * size);
			if (i < 0) i += 2 * size;
			if (i < size) return around[i].second;
			return !around[i - size].second;
		};
		sort(ALL(around), [](pair <pii, bool> a, pair <pii, bool> b){return acmp(a.first, b.first);});
		// debug(imie(around));
		ll curr = choose(n - 1, 4);
		ll in_range = 0;
		REP(i, size) in_range += get(i);
		REP(i, 2 * size) {
			bool here = get(i);
			in_range -= here;
			if (here)
				curr -= choose(in_range, 3);
			in_range += get(i + size);
		}
		ans += curr;
	}
	printf("%lld\n", ans);
}