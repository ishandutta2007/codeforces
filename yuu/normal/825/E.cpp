#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[100001];
int deg[100001];
int ans[100001];
set <int> s;
int main(){
	cin>>n>>m;
	for(int i=1, u, v; i<=m; i++){
		cin>>u>>v;
		g[v].push_back(u);
		deg[u]++;
	}
	for(int i=1; i<=n; i++) if(deg[i]==0) s.insert(i);
	int now=n;
	while(!s.empty()){
		int u=*s.rbegin();
		ans[u]=now;
		s.erase(u);
		for(int v: g[u]){
			deg[v]--;
			if(deg[v]==0) s.insert(v);
		}
		now--;
	}
	for(int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
}