#include <bits/stdc++.h>
using namespace std;
int n, q;
int p[300001];
int f[300001];
int ans[300001];
vector <int> g[300001];
void dfs(int u){
	f[u]=1;
	for(int v: g[u]){
		dfs(v);
		f[u]+=f[v];
	}
	bool good=1;
	for(int v: g[u]) if(f[v]*2>f[u]){
		good=0;
		break;
	}
	if(good){
		ans[u]=u;
		return;
	}
	
	int best=g[u][0];
	for(int v: g[u]) if(f[v]>f[best]) best=v;
	ans[u]=ans[best];
	while(f[u]>f[ans[u]]*2) ans[u]=p[ans[u]];	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=2; i<=n; i++){
		cin>>p[i];
		g[p[i]].push_back(i);
	}
	dfs(1);
	for(int i=1, x; i<=q; i++){
		cin>>x;
		cout<<ans[x]<<'\n';
	}
}