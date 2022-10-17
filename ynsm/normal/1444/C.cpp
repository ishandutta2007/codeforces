#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;
 
vector< int > g[N];
vector< pii > gg[N];
int sz[N], p[N], pc[N];
vector< pii > his;

int n, k, m, a[N], b[N], c[N];
ll ans;
bool ok[N];
int get_p(int v){
	if(v == p[v])
		return v;	
	return get_p(p[v]);
}
int get_c(int v){
	if(v == p[v])
		return pc[v];	
	return get_c(p[v]) ^ pc[v];
}
bool Merge(int i, bool per){
	int c = 1;
	
	int v = get_p(a[i]);
	c ^= get_c(a[i]);
	
	int u = get_p(b[i]);
	c ^= get_c(b[i]);
	
	if(v == u)
		return c == 0;
	if(sz[v] < sz[u])
		swap(v, u);
	p[u] = v;
	pc[u] = c;
	sz[v] += sz[u];
	if(per)
    	his.pb({v, u});
	return 1;
}
void relax(){
	reverse(his.begin(), his.end());
	for(auto it : his){
		p[it.s] = it.s;
		pc[it.s] = 0;
		sz[it.f] -= sz[it.s];	
	}      
	his.clear();
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &a[i], &b[i]);
		if(c[a[i]] == c[b[i]]){
			g[c[a[i]]].pb(i);
			continue;
		}
		if(c[a[i]] < c[b[i]])
			swap(a[i], b[i]);
		gg[c[a[i]]].pb({c[b[i]], i});
	}
	for(int i = 1; i <= n; i++)
		p[i] = i, sz[i] = 1;
	for(int i = 1, q = 0; i <= k; i++){
		ok[i] = 1;
		for(auto j : g[i])
			ok[i] &= Merge(j, 0);
		if(ok[i])
			ans += q++;
	}
	for(int i = 1; i <= k; i++){
		sort(gg[i].begin(), gg[i].end());
		for(int j = 0, q = 0; j < gg[i].size(); j = q){
			while(q < gg[i].size() && gg[i][j].f == gg[i][q].f)
				q++;
			bool OK = 1;
			for(int w = j; w < q; w++)
				OK &= Merge(gg[i][w].s, 1);
			relax();
			if(ok[i] && ok[gg[i][j].f] && !OK)
				ans--;
		}
	}
	printf("%lld", ans);
}