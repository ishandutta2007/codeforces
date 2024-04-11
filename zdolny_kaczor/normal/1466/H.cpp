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
#define PER(r...)for(bool _=1;_||next_permutation(r);_=false)
#define FS(r)r.first,r.second
#define ALL(r)(r).begin(),(r).end()
#define M0(r) memset(r,0,sizeof(r))
#define sim template<class c
#define forbits(i,m)if(m)for(urs(m)i=ctz(m),i##nvj=m;i##nvj;i##nvj^=((urs(m))1<<i),i=i##nvj?ctz(i##nvj):0)
#define fordbits(i,m)if(m)for(urs(m)i=8*sizeof(m)-clz(m)-1,i##nxd=m;i##nxd;i##nxd^=((urs(m))1<<i),i=i##nxd?8*sizeof(m)-clz(i##nxd)-1:0)
#define ksets(t, m, k, n)for(t m=(((t)1<<(k))-1);m<((t)1<<(n));m=nux(m))
#define urs(r...)typename decay<decltype(r)>::type
#define hur(f,g)sim>int f(c a){if(sizeof(c)==8)return g##ll(a);return g(a);}
using namespace __gnu_pbds;using namespace std;using ll=long long;using ld=long double;using ull=unsigned long long;using vi=vector<int>;using vll=vector<ll>;using pii=pair<int,int>;using pll=pair<ll,ll>;using vpii=vector<pii>;using unt=unsigned int;sim>using min_queue=priority_queue<c,vector<c>,greater<>>;sim,class b,class cmp=less<c>>using ordered_map=tree<c,b,cmp,rb_tree_tag,tree_order_statistics_node_update>;sim,class cmp=less<c>>using ordered_set=ordered_map<c,null_type,cmp>;hur(popc,__builtin_popcount)hur(ctz,__builtin_ctz)hur(clz,__builtin_clz)sim,class N>bool mini(c&o,const N&h){if(o>h)return o=h,1;return 0;}sim,class N>bool maxi(c&o,const N&h){if(o<h)return o=h,1;return 0;}
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
#define def_op(...) struct _{};
#define mask_set(...)
#define exit my_exit
void my_exit(int x) {fflush(stdout);_Exit(x);}
#endif
#define next nexT
#define prev preV
#define tree trEE
#define left lefT
#define right righT
#define div diV
#define y1 y_1
#define pow don't'
ull mix(ull o){o+=0x9e3779b97f4a7c15;o=(o^(o>>30))*0xbf58476d1ce4e5b9;o=(o^(o>>27))*0x94d049bb133111eb;return o^(o>>31);}ull SALT=0x7a14a4b0881ebf9,tqu=0x7a14a4b0881ebf9;ull my_rand(){return tqu=mix(tqu);}void my_srand(ull x){SALT=tqu=x;}const int inf=1023400000;const ll llinf=1234567890000000000ll;ll fix(ll o, ll m){o%=m;if(o<0)o+=m;return o;}
#define rand my_rand
#define srand my_srand
#define random_shuffle(r...)random_shuffle(r,[](int _){return my_rand()%_;})
sim>inline c nux(c m){if(!m)return numeric_limits<c>::max();c A=m&-m;c B=~((A-1)^m);c C=B&-B;c D=(C>>(1+ctz(A)))-1;return C|(m&~(C-1))|D;}sim>void unq(c&x){x.resize(unique(ALL(x))-x.begin());}
//#STAY AT HOME
const int mod = 1e9 + 7, nax = 60;
ll fac[nax], fin[nax];
ll cho(int a, int b) {
	if (b > a || b < 0) return 0;
	return fac[a] * fin[b] % mod * fin[a - b] % mod;
}
ll powe(ll b, ll e) {
	e = fix(e, mod - 1);
	ll r = 1;
	while (e) {
		if (e & 1) r = r * b % mod;
		b = b * b % mod;
		e >>= 1;
	}
	return r;
}
ll inv(ll x) {
	assert(x);
	return powe(x, mod - 2);
}
map <vpii, ll> dp;
ll run(vpii x) {
	if (x.empty()) return 1;
	auto [it, added] = dp.insert(make_pair(x, 0));
	if (!added) return it->second;
	int n = 0, len = x.size();
	for (auto [l, c] : x) n += l * c;
	vi take(len);
	bool next = true;
	ll ans = 0;
	while (next) {
		ll coef = -1;
		REP(i, len) (coef *= cho(x[i].second, take[i]) * (take[i] % 2 ? -1 : 1)) %= mod;
		vpii sub;
		REP(i, len) if (take[i] < x[i].second) sub.emplace_back(x[i].first, x[i].second - take[i]);
		int total_taken = 0;
		REP(i, len) total_taken += take[i] * x[i].first;
		debug(imie(x), imie(sub), imie(total_taken), imie(coef));
		if (sub != x) {
			ll val = run(sub);
			(ans += coef * val % mod * powe(n, -total_taken)) %= mod;
		}
		next = false;
		REP(i, len) {
			take[i]++;
			if (take[i] <= x[i].second) {
				next = true;
				break;
			}
			else
				take[i] = 0;
		}
	}
	debug(imie(x), imie(ans));
	return it->second = ans;
}
void solve() {
	int n;
	scanf("%d", &n);
	vi per(n + 1);
	for (int i = 1; i <= n; ++i) scanf("%d", &per[i]);
	vi done(n + 1);
	vi cycles;
	for (int i = 1; i <= n; ++i) if (!done[i]) {
		int wh = i, len = 0;
		do {
			len++;
			done[wh] = true;
			wh = per[wh];
		}
		while (wh != i);
		cycles.push_back(len);
	}
	debug(imie(cycles));
	map <int, int> parsed;
	for (int x : cycles) parsed[x]++;
	ll ans = run(vpii(ALL(parsed)));
	(ans *= powe(fac[n], n)) %= mod;
	printf("%lld\n", fix(ans, mod));
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < nax; ++i) fac[i] = fac[i - 1] * i % mod;
	REP(i, nax) fin[i] = inv(fac[i]);
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME