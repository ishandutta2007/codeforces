#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, a, b, da, db;
vector <int> g[100001];
bool done[100001];
int f[100001];
int bfs(int u){
	for(int i=1; i<=n; i++) done[i]=0;
	queue <int> q;
	f[u]=0;
	q.push(u);
	done[u]=1;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int v: g[u]) if(!done[v]){
			done[v]=1;
			f[v]=f[u]+1;
			q.push(v);
		}
	}
	return u;
}
void solve(){
	cin>>n>>a>>b>>da>>db;
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(da*2>=db){
		cout<<"Alice\n";
		return;
	}
	int far=bfs(a);
	if(f[b]<=da){
		cout<<"Alice\n";
		return;
	}
	int maxl=f[bfs(far)];
	if(da*2>=maxl) cout<<"Alice\n";
	else cout<<"Bob\n";
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	cin>>t;
	while(t--) solve();
}