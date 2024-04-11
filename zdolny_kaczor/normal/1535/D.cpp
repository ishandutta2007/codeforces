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
#include </home/konrad/cp/headers/debuglib.hpp>
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
const int nax = 1 << 19;
char who[nax];
int which[nax];
int ans[nax];
void solve() {
	int k;
	scanf("%d%s", &k, who);
	int top = 2 * (1 << k);
	vi renum(1 << k);
	int head = 0;
	for (int l = k - 1; l >= 0; --l) {
		int size = 1 << l;
		for (int i = 0; i < size; ++i) renum[head++] = (1 << l) + i;
	}
	auto map = [&](char c) {
		if (c == '0') return 0;
		if (c == '1') return 1;
		if (c == '\?') return -1;
		assert(false);
	};
	int len = (1 << k) - 1;
	for (int i = 0; i < len; ++i)
		which[renum[i]] = map(who[i]);
	for (int i = (1 << k); i < 2 * (1 << k); ++i)
		ans[i] = 1;
	auto touch = [&](int i) {
		ans[i] = 0;
		if (which[i] != 1) ans[i] += ans[2 * i];
		if (which[i] != 0) ans[i] += ans[2 * i + 1];
	};
	for (int i = (1 << k) - 1; i; --i) touch(i);
	int q;
	scanf("%d", &q);
	REP(_, q) {
		int c;
		char p;
		scanf("%d %c", &c, &p);
		c = renum[c - 1];
		which[c] = map(p);
		while (c) {
			touch(c);
			c /= 2;
		}
		printf("%d\n", ans[1]);
		debug(range(ans, 1, top), range(which, 1, top));
	}
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME