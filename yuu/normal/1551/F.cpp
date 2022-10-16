#include <bits/stdc++.h>
using namespace std;
const int base=1000000007;
int n, k;
vector <int> g[101];
map <int, int> level[101];
bool done[101];
int64_t f[101];
void dfs(int u, int depth=0, int branch=0){
	level[depth][branch]++;
	done[u]=1;
	for(int v: g[u]) if(!done[v]){
		dfs(v, depth+1, branch?branch:v);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	if(k==2){
		cout<<n*(n-1)/2<<'\n';
		return;
	}
	int64_t ans=0;
	for(int root=1; root<=n; root++){
		for(int depth=1; depth<=n; depth++) level[depth].clear();
		for(int i=1; i<=n; i++) done[i]=0;
		dfs(root);
		// cerr<<root<<'\n';
		// for(int depth=1; depth<=n; depth++) cerr<<level[depth].size()<<" \n"[depth==n];
		for(int depth=1; depth<=n; depth++){
			if(level[depth].size()<k) break;
			for(int i=1; i<=k; i++) f[i]=0;
			f[0]=1;
			for(auto &x: level[depth]){
				for(int i=k; i>=1; i--){
					f[i]+=f[i-1]*x.second;
					if(f[i]>=base) f[i]%=base;
				}
			}
			ans+=f[k];
		}
	}
	ans%=base;
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}