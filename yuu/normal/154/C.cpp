#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n, m;
vector <int> g[1000001];
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll id[1000001];
ll f[1000001];
map <ll, int> cnt;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1; i<=n; i++) id[i]=rng();
	for(int i=1; i<=n; i++) for(int j: g[i]) f[i]+=id[j];
	ll ans=0;
	for(int i=1; i<=n; i++){
		ans+=cnt[f[i]];
		cnt[f[i]]++;
	}
	for(int i=1; i<=n; i++) for(int j: g[i]) if(i<j){
		ans+=(f[i]+id[i])==(f[j]+id[j]);
	}
	cout<<ans<<'\n';
}