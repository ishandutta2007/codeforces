#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
int a[100001];
ll f[100001][2];
bool done[100001];
vector <int> g[100001];
void predfs(int u){
	done[u]=1;
	for(int &v: g[u]) if(done[v]){
		swap(v, g[u].back());
		g[u].pop_back();
		break;
	}
	for(int v: g[u]) predfs(v);
}
ll ans=0;
void dfs(int u, int b){
	int key=(a[u]>>b)&1;
	f[u][0]=f[u][1]=0;
	f[u][key]=1;
	for(int v: g[u]){
		dfs(v, b);
		ans+=(f[v][0]*f[u][1]+f[v][1]*f[u][0])<<b;
		f[u][key^0]+=f[v][0];
		f[u][key^1]+=f[v][1];
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1, x, y; i<n; i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	predfs(1);
	for(int i=0; i<20; i++)	dfs(1, i);
	for(int i=1; i<=n; i++) ans+=a[i];
	cout<<ans<<'\n';
}