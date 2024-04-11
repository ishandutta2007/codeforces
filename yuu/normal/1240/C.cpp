#include <bits/stdc++.h>
using namespace std;
int n, k;
using ll=long long;
ll f[500001][2];
vector <pair <int, int>> g[500001];
bool done[500001];
vector <ll> temp;
void dfs(int u){
	done[u]=1;
	for(auto &v: g[u]) if(done[v.first]){
		swap(v, g[u].back());
		g[u].pop_back();
		break;
	}
	for(auto v: g[u]) dfs(v.first);
	temp.clear();
	for(auto v: g[u]){
		f[u][0]+=f[v.first][0];
		temp.push_back(max(0LL, f[v.first][1]+v.second-f[v.first][0]));
	}
	sort(temp.begin(), temp.end());
	reverse(temp.begin(), temp.end());
	f[u][1]=f[u][0];
	for(int i=0; i<k; i++){
		if(i>=temp.size()) break;
		f[u][0]+=temp[i];
	}
	for(int i=0; i+1<k; i++){
		if(i>=temp.size()) break;
		f[u][1]+=temp[i];
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1; i<=n; i++) f[i][0]=f[i][1]=0;
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1; i<=n; i++) done[i]=0;
	for(int i=1, u, v, w; i<n; i++){
		cin>>u>>v>>w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dfs(1);
	cout<<f[1][0]<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin>>q;
	while(q--) solve();
}