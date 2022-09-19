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
void __resources();
void my_exit(int x) {fflush(stdout);
#ifdef LOCAL2
__resources();
#endif
_Exit(x);}
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
struct matching {
	int n;
	vector <vi> graph;
	vector <bool> visited;
	vector <bool> matched;
	vi lmatch;
	matching(int n_) : n(n_), graph(n), visited(n), matched(n), lmatch(n, -1) {}
	void add_edge(int a, int b) {
		graph[a].push_back(b);
	}
	bool dfs(int x) {
		if (x == -1) return true;
		if (visited[x]) return false;
		visited[x] = true;
		for (int v : graph[x]) {
			if (dfs(lmatch[v])) {
				matched[x] = true;
				lmatch[v] = x;
				return true;
			}
		}
		return false;
	}
	int run() {
		int ans = 0;
		bool any = true;
		while (any) {
			fill(ALL(visited), false);
			any = false;
			REP(i, n) if (!matched[i] && dfs(i)) {
				any = true;
				ans++;
			}
		}
		return ans;
	}
};
void run(int a, int b, vi &t) {
	if (a < b) swap(a, b);
	if (b == 0) return;
	int r = a % b;
	if (r)
		t.push_back(r);
	run(b, r, t);
}
void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	vi a(n);
	for (int &x : a) scanf("%d", &x);
	vi a_copy = a;
	matching M(n);
	int threshold = m / 3;
	int big = 0;
	REP(i, n) if (a[i] > threshold) big++;
	REP(i, n) REP(j, n)
		if (a[i] <= threshold && a[j] > threshold && a[j] % a[i] == 0 && 2ll * a[j] + a[i] <= m)
			M.add_edge(i, j);
	int s = M.run();
	if (s != big) {
		puts("-1");
		exit(0);
	}
	vector <pii> ans;
	REP(i, n) {
		if (M.lmatch[i] != -1) {
			int j = M.lmatch[i];
			debug(arr(a, i), arr(a, j));
			assert(a[i] && a[j]);
			ans.emplace_back(2 * a[i] + a[j], a[j] + a[i]);
			a[i] = a[j] = 0;
		}
	}
	for (int x : a) if (x) {
		assert(3ll * x <= m);
		ans.emplace_back(3 * x, 2 * x);
	}
	printf("%d\n", (int) ans.size());
	for (auto [l, r] : ans) {
		printf("%d %d\n", l, r);
	}
#ifndef LOCAL
	return;
#endif
	vi would;
	for (auto [l, r] : ans) run(l, r, would);
	sort(ALL(would));
	sort(ALL(a_copy));
	debug(imie(would), imie(a_copy));
	assert(would == a_copy);
}
int main() {
	// unt seed = TIME; debug(imie(seed));srand(seed);
	int t = 1;
	// scanf("%d", &t);
	REP(_, t) solve();
	exit(0);
}
//#STAY AT HOME