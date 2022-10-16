#include <bits/stdc++.h>
using namespace std;
int n, b;
int c[5001];
int d[5001];
vector <int> f[5001][2];
vector <int> g[5001];
void dfs(int u){
	f[u][0].push_back(0);
	f[u][0].push_back(c[u]);
	f[u][1].push_back(b+1);
	f[u][1].push_back(c[u]-d[u]);
	for(int v: g[u]){
		dfs(v);
		int os=f[u][0].size();
		for(int i=0; i<f[v][0].size(); i++)	f[u][0].push_back(b+1);
		for(int i=0; i<f[v][0].size(); i++)	f[u][1].push_back(b+1);
		for(int i=os-1; i>=0; i--) for(int j=0; j<f[v][0].size(); j++){
			f[u][0][i+j]=min(f[u][0][i+j], f[u][0][i]+f[v][0][j]);
		}
		for(int i=os-1; i>=0; i--) for(int j=0; j<f[v][0].size(); j++){
			f[u][1][i+j]=min(f[u][1][i+j], f[u][1][i]+f[v][0][j]);
			f[u][1][i+j]=min(f[u][1][i+j], f[u][1][i]+f[v][1][j]);
		}
	}
}
int main(){
	cin>>n>>b;
	cin>>c[1]>>d[1];
	for(int i=2, p; i<=n; i++){
		cin>>c[i]>>d[i]>>p;
		g[p].push_back(i);
	}
	dfs(1);
	int ans=0;
	for(int i=0; i<f[1][0].size(); i++) if(f[1][0][i]<=b)	ans=max(ans, i);
	for(int i=0; i<f[1][1].size(); i++) if(f[1][1][i]<=b)	ans=max(ans, i);
	cout<<ans<<'\n';
}