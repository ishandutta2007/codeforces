//Konrad Paluszek, University of Warsaw (former XIV LO Staszic)
# include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define FOR(i, b, e) for (auto i = (b); i <= (e); ++i)
#define REP(i, n) for (urs(n) i = 0; i < (n); ++i)
#define FORD(i, b, e) for (auto i = (b); i >= (int)(e); --i)
#define UNTIL(t) while (clock() < (t) * CLOCKS_PER_SEC)
#define ALL(r) (r).begin(), (r).end()
#define FS(r) r.first, r.second
#define MAKE(b, e) <urs(*(b))>(b, e)
#define sim template <class c
#define ros return o
#define rans return ans
#define forbits(i, m) if (m) for (urs(m) i = ctz(m), quq = m; quq; quq ^= ((decltype(m))1 << i), i = ctz(quq)) 
#define fordbits(i, m) if (m) for (urs(m) i = 8 * sizeof(m) - clz(m) - 1, quq = m; quq; quq ^= ((decltype(m))1 << i), i = 8 * sizeof(m) - clz(quq) - 1)
#define urs(r) typename decay<decltype(r)>::type
#define hur(f, g) sim> int f(c a) {if (sizeof(c) == 8) return g##ll(a); else return g(a);}
using ll = long long; using ld = long double; using ull = unsigned long long;using pii = pair <int, int>;using pll=pair<ll,ll>;
using vpii = vector <pii>; using unt = unsigned int;sim> using min_queue = priority_queue<c, vector<c>, greater<c>>;
template <typename T>using ordered_set =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
hur(popc, __builtin_popcount) hur(ctz, __builtin_ctz) hur(clz, __builtin_clz)
sim,class N>bool mini(c&o,N h){if(o>h)ros=h,1;return 0;}sim,class N>bool maxi(c&o,N h){if(o<h)ros=h,1;return 0;}
#ifdef LOCAL
#define loc(r...) r
string vqx(int l, string f){stringstream o;o<<"\033[1;"<<30+l%8<<"m"<<f<<"#"<<l<<": \033["<<30+(int)(l*3.125)%8<<"m";ros.str();}
ostream & operator<<(ostream &d, __int128 x) {int dig[50],c=0; if (x < 0) d << "-",x = -x;do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
ostream & operator<<(ostream &d, __uint128_t x) {int dig[50],c=0; do {dig[c++] = x % 10;x /= 10;} while (x);while (c)d << dig[--c]; return d;}
#define oor >ostream &operator<<(ostream &o,
#define bnt ;}sim> struct
sim,class N oor pair<c,N>u){ros<<"<"<<u.first<<", "<<u.second<<">";}
sim,typename=typename enable_if<!is_same<c,string>::value,urs(c().end())>::type oor c u){
int q=0;o<<"{";for(auto e:u)o<<", "+2*!q++<<e;ros<<"}";} void dor(bool x){cerr<<dec<<"\033[0m"<<endl;}
sim,class...N>void dor(int w,c x,N...y){cerr<<boolalpha<<x<<"; "+2*w;dor(0,y...);}
#define debug(c...)::dor(1,vqx(__LINE__,__FUNCTION__),c);
#define rcu m);}g(+) g(-) g(*) g(/) g(%) g(<<) g(>>) g(^) g(|) g(&) g(>=) g(<=) g(>) g(<) g(!=) g(==)
#define zub(h,t,n...) class N> auto operator h(n u)->nep<urs(t)> {return ngy(t,
sim>string bte(c u){stringstream o;o<<boolalpha<<u;ros.str()bnt nep;sim>c yyo(nep<c>);sim>nep<c>ngy(c,string,int m=0);
sim>c yyo(c o){ros bnt nep{c v;string d;int m; nep<c>mask(){return ngy(v,d,1);}
#define g(o) template<zub(o, v o u, N) "(" + bte(*this) + ") " #o " (" + bte(u) + ")", m);}
template<zub([],v[yyo(u)],N)d+"["+bte(u)+"]",rcu};sim>nep<c>ngy(c v,string d,int m){return nep<c>{v,d,m};}
sim>c yyo(nep<c> o){ros.v;}sim>int uhn(c){return 0;}sim>int uhn(nep<c>o){ros.m;}
#define ccy(r...) sim> class enable_if<r is_integral<c>::value,string>::type ema(c u){
ccy(!)return bte(u);}ccy()stringstream o;o<<"[";int q=0;forbits(i,u)o<<", "+2*!q++<<i;ros.str()+"]";}
#undef g
#define g(o) sim, zub(o, yyo(p) o u.v, c p, nep<N>) "(" + bte(p) + ") " #o " (" + bte(u) + ")", uhn(p) + u.m);}
sim>string bte(nep<c>o){ros.d+" = "+(o.m?ema(o.v):bte(o.v));}
sim oor nep<c>m){ros<<bte(rcu sim> nep<c> ngy(nep<c> o,string d="",int m=0){ros;}
#undef g
#define imie(a...) ngy(a, #a)
#define imask(a...) ngy(a, #a, 1)
#define range_v(u, g, c) ngy(list<urs(u[0])>(&u[yyo(g)], &u[yyo(c)] + 1), #u "[" + bte(g) + "..." + bte(c) + "]")
#define range(i, j) ngy(list<urs(*i)>(i, j), "[" #i "..." #j ")")
#define arr(a, i) imie(a)[imie(i)]
#define arr2(a, i, j) imie(a)[imie(i)][imie(j)]
#define arr3(a, i, j, k) imie(a)[imie(i)][imie(j)][imie(k)]
#define arr4(a, i, j, k, q) imie(a)[imie(i)][imie(j)][imie(k)][imie(q)]
#define ckx(o) template<zub(o, o yyo(u), nep<N>) #o "(" + bte(u) + ")", u.m);}
ckx(+)ckx(-)ckx(!)ckx(~)
#else
#define loc(...)
#define debug(...)
#endif
#define vsv sim, class d, class e
#define nop(o,c,r,l...) auto operator o(c a, r b)-> decltype(make_pair(l)) {return {l};}
#define pcg(o) vsv, class f> nop(o, pair <c u d>, pair <e u f>, a.first o b.first, a.second o b.second) \
vsv,class = typename enable_if<!is_base_of<ios_base, c>::value>::type> nop(o, c, pair<d u e>, a o b.first, a o b.second) \
vsv> nop(o, pair<c u d>, e, a.first o b, a.second o b)
#define clp(o) pcg(o) \
vsv> void operator o##= (pair <c,d> & a, e b) {a.first o##= b; a.second o##= b;} \
vsv, class f> void operator o##= (pair <c,d> & a, pair <e,f> b) {a.first o##= b.first; a.second o##= b.second;}
#define syd(o) sim, class d> auto operator o(pair<c, d> e) -> decltype(make_pair(o e.first, o e.second)) {return {o e.first, o e.second};}
#define u ,
clp(+)clp(-)clp(*)clp(/)clp(%)clp(^)clp(|)clp(>>)clp(<<)clp(&)pcg(&&)pcg(||)syd(-)syd(+)syd(~)syd(!)
#undef u
ull mix(ull x){x += 0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
sim,class n>using gyv=c;namespace std{sim,class n>struct hash<pair<c,n>>{size_t operator()(const pair<c,n>&x)const{
return mix(hash<typename decay<c>::type>()(x.first))^hash<typename decay<n>::type>()(x.second);}};
#define muu(v...) struct hash<v>{size_t operator()(const v&x)const{size_t ans = x.size();for (auto &e : x) ans = mix(ans ^ hash<typename v::value_type>()(e));rans;}};
sim> muu(vector<c>)sim> muu(list<c>)sim> muu(set<c>)sim, class n> muu(map <c,n>)sim, size_t N> muu(array<c,N>)}
#ifndef LOCAL
sim, class m> using _un0rDer3d_M4P = cc_hash_table<c, m, hash<c>>;
#define unordered_map _un0rDer3d_M4P
#endif
#define next __n3kst
#define prev __prew
#define tree __tRe3
#define left __l3fT
#define right __Ri9ht
const int nax = 1e5 + 44;
char a[nax], b[nax];
int mod;
int gen;
ll powe(ll b, int e) {
	ll r = 1;
	while (e) {
		if (e & 1) r = r * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return r;
}
int find_gen() {
	int e = mod - 1;
	vector <int> primes;
	for (int i = 2; i * i <= e; ++i) {
		if (e % i == 0) {
			primes.push_back(i);
			while (e % i == 0) e /= i;
		}
	}
	if (e > 1) primes.push_back(e);
	e = mod - 1;
	while (true) {
		int r = rand() % mod;
		if (r == 0) continue;
		bool good = true;
		for (int x : primes)
			if (powe(r, e / x) == 1) {
				good = false;
				break;
			}
		if (good) return r;
	}
}
static vector<ll> t[30];
vector <ll> dft(vector<ll> a) {
	const int n = a.size();
	assert((n & (n - 1)) == 0);
	assert((mod - 1) % n == 0);
	for(int i = 1, k = 0; i < n; ++i) {
		for(int bit = n / 2; (k ^= bit) < bit; bit /= 2);;;
		if(i < k) swap(a[i], a[k]);
	}
	for(int len = 1, who = 0; len < n; len *= 2, ++who) {
		vector<ll> & om = t[who];
		if(om.empty()) {
			om.resize(len);
			REP(i, len) om[i] = i%2 || !who ? powe(gen, (mod - 1) / (2 * len) * i) : t[who-1][i/2];
		}
		for(int i = 0; i < n; i += 2 * len)
			REP(k, len) {
				ll x = a[i + k], y = a[i+k+len] * om[k] % mod;
				a[i+k] += y;
				a[i + k] %= mod;
				a[i+k+len] = (x - y) % mod;
			}
	}
	for (ll &x : a) if (x < 0) x += mod;
	return a;
}
bool is_prime(int p) {
	if (p <= 1) return false;
	for (int i = 2; i * i <= p; ++i) if (p % i == 0) return false;
	return true;
}
void set_mod(int x) {
	mod = x;
	gen = find_gen();
	REP(i, 30) t[i].clear();
}
vector <ll> P;
void ans(ll b) {
	ll val = 0;
	FORD(i, (int) P.size() - 1, 0)
		val = (val * b + P[i]) % mod;
	debug(imie(b), imie(val));
	assert(val == 0);
	printf("%d %lld\n", mod, b);
	exit(0);
}
int main() {
	vector <int> primes;
	for (int p = 3; p <= 25; p += 2) {
		for (int x = p; x < 1e7; x *= 2)
			if (x >= 100000 && is_prime(x + 1))
				primes.push_back(x + 1);
	}
	sort(ALL(primes));
	debug(imie(primes));
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s%s", a, b);
	REP(i, n) P.push_back(a[i] - b[i]);
	for (int p : primes) {
		set_mod(p);
		int e = p - 1;
		int nn = e & -e;
		ll omega = powe(gen, e / nn);
		debug(imie(nn), imie(e), imie(omega));
		ll v = 1;
		REP(_, e / nn) {
			vector <ll> poly(nn);
			ll c = 1;
			REP(i, n)	{
				poly[i % nn] = (poly[i % nn] + P[i] * c) % mod;
				c = c * v % mod;
			}
			vector <ll> vals = dft(poly);
			REP(i, nn) if (vals[i] == 0) {
				debug(imie(v), imie(omega), imie(i));
				ll x = v * powe(omega, i) % mod;
				if (x >= 2 && x <= mod - 2) ans(x);
			}
			v = v * gen % mod;
		}
	}
	printf("no to dupa\n");
}