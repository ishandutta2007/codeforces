#include <bits/stdc++.h>
using namespace std;
int n;
int a[300001];
long long f[300001];
vector <int> g[300001];
bool done[300001];
int cnt=0;
long long ans;
void dfs(int u){
	done[u]=1;
	f[u]=a[u];
	for(int &v: g[u]) if(!done[v]){
		dfs(v);
		f[u]+=max(0LL, f[v]);
	}
}
void redfs(int u){
	done[u]=1;
	f[u]=a[u];
	for(int &v: g[u]) if(!done[v]){
		redfs(v);
		f[u]+=max(0LL, f[v]);
	}
	if(f[u]==ans){
		cnt++;
		f[u]=0;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	ans=*max_element(f+1, f+n+1);
	for(int i=1; i<=n; i++) done[i]=0;
	redfs(1);
	cout<<ans*cnt<<' '<<cnt<<'\n';
}