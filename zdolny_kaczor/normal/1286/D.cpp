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
sim, class m>
#ifdef LOCAL
using _un0rDer3d_M4P=unordered_map<c,m,my_hasher<c>>;
#else
struct _un0rDer3d_M4P : public cc_hash_table<c,m,my_hasher<c>>{bool count(const c&x)const{return this->find(x) != this->end();}};
#endif
#define unordered_map _un0rDer3d_M4P
#if defined(LOCAL) || defined(LOCAL2)
void __tmi() {cerr << "total time: " << clock() / (ld)CLOCKS_PER_SEC << "s" << endl;}int _ = (atexit(__tmi), 0);
#endif
#define rer(o,f) zet_p operator o(zet_p y)const{return zet_p(v f loc(,w o y.w));}zet_p&operator o##=(zet_p y){return*this=*this o y;}
#define ycc(o) sim>typename enable_if<is_integral<c>::value,zet_p>::type operator o(c a, zet_p b){return zet_p(a) o b;}
const int mod = 998244353;
ll inv(ll b){assert(b);int e=mod-2;ll o=1;while(e){if(e&1)o=o*b%mod;b=b*b%mod;e>>=1;}ros;}struct zet_p{int v;loc(ld w;)sim=int,typename=typename enable_if<is_integral<c>::value>::type>zet_p(c r=0):v(r%mod)loc(,w(r)){}loc(sim>zet_p(c a, ld b):v(a%mod),w(b){})rer(+,+y.v)rer(-,-y.v)rer(*,*1ll*y.v)rer(/,*inv(y.v))int get()const{return ((unt)v+mod)%mod;}zet_p operator-()const{return zet_p(-v loc(,-w));}bool operator==(zet_p y)const{return(v-y.v)%mod==0;}};ycc(+)ycc(-)ycc(*)ycc(/)sim>bool operator==(c a, zet_p b){return zet_p(a)==b;}loc(ostream&operator<<(ostream &o,zet_p y){ros<<"["<<y.get()<<"~"<<y.w<<"]";})
struct event{
	int nom, den;
	int i;
	bool dl, dr;
};
bool operator<(event a, event b) {
	return a.nom * 1ll * b.den < b.nom * 1ll * a.den;
}
ostream &operator<<(ostream &o, event x) {
	ros << "{" << x.nom << "/" << x.den << "; " << x.i << (x.dl ? 'R' : 'L') << ", " << x.i + 1 << (x.dr ? 'R' : 'L') << "}";
}
const int nax = 1 << 17;
int v[nax], p[nax], x[nax];
struct matr {
	zet_p a[2][2];
	zet_p* operator[](int _) {return a[_];}
};
const matr id = {zet_p(1), zet_p(0), zet_p(0), zet_p(1)};
matr operator*(matr a, matr b) {
	matr ans = {0, 0, 0, 0};
	REP(i, 2) REP(j, 2) REP(k, 2)
		ans[i][k] += a[i][j] * b[j][k];
	rans;
}
loc(ostream &operator<<(ostream &o, matr m) {
	ros << "\n\t" << m.a[0][0] << "\t" << m.a[0][1] << "\n\t" << m.a[1][0] << "\t" << m.a[1][1] << "\n";
})
const zet_p percent = zet_p(1) / zet_p(100);
namespace blocking {
	matr tree[nax * 2];
	void init_tree(int p[], int n) {
		REP(i, n) {
			tree[i + nax][0][0] = tree[i + nax][1][0] = zet_p(100 - p[i]) * percent;
			tree[i + nax][0][1] = tree[i + nax][1][1] = zet_p(p[i]) * percent;
		}
		FOR(i, n, nax - 1)
			tree[i + nax] = id;
		FORD(i, nax - 1, 1)
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
	}
	void recalc(int x) {
		x += nax;
		x /= 2;
		while (x) {
			tree[x] = tree[x * 2] * tree[x * 2 + 1];
			x /= 2;
		}
	}
	int blocked[nax][2][2];
	zet_p get() {
		return tree[1][0][0] + tree[1][0][1];
	}
	void do_block(int i, int x, int y, int v) {
		blocked[i][x][y] += v;
		assert(blocked[i][x][y] >= 0);
		tree[i + nax][x][y] = (blocked[i][x][y] ? 0 : (y ? zet_p(p[i]) : zet_p(100 - p[i])) * percent);
		recalc(i);
	}
	void block(int i, int x, int y) {
		do_block(i, x, y, 1);
	}
	void unblock(int i, int x, int y) {
		do_block(i, x, y, -1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d%d%d", x + i, v + i, p + i);
	blocking::init_tree(p, n);
	vector <event> events;
	REP(i, n - 1) {
		int d = x[i + 1] - x[i];
		events.push_back(event{d, v[i + 1] + v[i], i, true, false});
		if (v[i + 1] > v[i])
			events.push_back(event{d, v[i + 1] - v[i], i, false, false});
		if (v[i + 1] < v[i])
			events.push_back(event{d, -v[i + 1] + v[i], i, true, true});
	}
	sort(ALL(events));
	debug(imie(events));
	zet_p ans = 0;
	for (event e : events) {
		zet_p len = zet_p(e.nom) / e.den;
		debug(imie(len));
		REP(x, 2) REP(y, 2) if (x != e.dl || y != e.dr) blocking::block(e.i + 1, x, y);
		zet_p p = blocking::get();
		debug(imie(p) * imie(len));
		ans += p * len;
		REP(x, 2) REP(y, 2) if (x != e.dl || y != e.dr) blocking::unblock(e.i + 1, x, y);
		blocking::block(e.i + 1, e.dl, e.dr);
	}
	printf("%d\n", ans.get());
}