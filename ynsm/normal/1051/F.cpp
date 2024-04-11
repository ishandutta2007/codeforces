//BOOOOOOOOOOOOM 
#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, LOG = 19, mod = (int)1e9 + 7;
const ll inf = 1e18;

vector< pii > g[N];
vector< pair< pii, int > > ae;
int n, m, q;
ll up[N][LOG], depth[N], was[N], tin[N], tout[N], timer;

void dfs(int v,int p){
	up[v][0] = p;
	for(int i = 1; i < LOG; i++)
		up[v][i] = up[ up[v][i - 1] ][i - 1];
	tin[v] = timer++;
	was[v] = 1;
	
	for(auto to:g[v]){
		if(to.f == p)
			continue;
		if(was[to.f]){
			if(depth[to.f] > depth[v])
				ae.pb({{to.f, v}, to.s});	
		}else{
			depth[to.f] = depth[v] + to.s;
			dfs(to.f,v);
		}
	}
	tout[v] = timer++;
}
bool upper(int v,int u){
	return (tin[v] <= tin[u] && tin[u] <= tout[v]);
}
int lca(int v,int u){
	if(upper(v, u))
		return v;
   	if(upper(u, v))
   		return u;
	for(int i = LOG - 1; i >= 0; i--)
		if(!upper(up[v][i], u))
			v = up[v][i];
	return up[v][0];
}
ll dist(int v,int u){
	return depth[v] + depth[u] - 2 * depth[ lca(v, u) ];
}

vector< int > vec;
ll dp[100][100], d1[100], d2[100];
	
void precalc(){
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			if(i != j)
				dp[i][j] = inf;
	
	for(int i = 0; i < ae.size(); i++){
		int a = ae[i].f.f;
		int b = ae[i].f.s;
		ll w = ae[i].s;
		//cerr << a << " " << b << " " << w<<endl;
		vec.pb(a);
		vec.pb(b);                  
		int x = vec.size() - 2;
		int y = vec.size() - 1;
		dp[x][y] = min(dp[x][y], w);
		dp[y][x] = min(dp[y][x], w);
    }         
    int n = vec.size();
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		dp[i][j] = min(dp[i][j], dist(vec[i], vec[j]) );
	
	for (int k=0; k<n; ++k)
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j]);

}
ll get(int v,int u){
	ll ans = dist(v, u);

    for(int i = 0; i < vec.size(); i++){
		d1[i] = dist(vec[i], v);
		d2[i] = dist(vec[i], u);
	}
	
	for(int i = 0; i < vec.size(); i++)
    	for(int j = 0; j < vec.size(); j++)
    		ans = min(ans, dp[i][j] + d1[i] + d2[j]);

	return ans;
}
int main(){    
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++){
    	int v, u, w;
    	scanf("%d%d%d", &v, &u, &w);
    	g[v].pb({u,w});
    	g[u].pb({v,w});
    }
    dfs(1,1);
    precalc();
    scanf("%d", &q);
    while(q--){
    	int v, u;
    	scanf("%d%d", &v, &u);
    	printf("%lld\n", get(v, u));
    }
	return 0;
}