#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[200001];
using ll=long long;
ll f[200001];
ll g[200002];
void update_pair(int u, int v){
	if(u==v) return;
	if(u>v) swap(u, v);
	///u<v
	f[u]+=v-1;
	f[v]+=u;
	
	g[1]+=v-u;
	g[u]-=v-u;
	
	g[v+1]+=v-u;
	g[n+1]-=v-u;
	
	g[u+1]+=v-u-1;
	g[v]-=v-u-1;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=m; i++) cin>>x[i];
	for(int i=1; i<m; i++) update_pair(x[i], x[i+1]);
	for(int i=1; i<=n; i++) g[i]+=g[i-1];
	for(int i=1; i<=n; i++) cout<<f[i]+g[i]<<" \n"[i==n];
}