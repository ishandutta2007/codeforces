#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> g[100000];
int p[100000];
int np[100000];
int h[100000];

vector <int> id;
vector <int> ans;
void dfs(int u){
	for(int v: g[u]){
		dfs(v);
		h[u]=max(h[u], h[v]);
	}
	h[u]++;
	sort(g[u].begin(), g[u].end(), [](int a, int b){
		return h[a]<h[b];
	});
}
void make(int u){
	if(u) np[u]=id.back();
	id.push_back(u);
	for(int v: g[u]) make(v);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1; i<n; i++){
		cin>>p[i];
		g[p[i]].push_back(i);
	}
	dfs(0);
	make(0);
	for(auto x: id){
		while(np[x]!=p[x]){
			ans.push_back(x);
			np[x]=np[np[x]];
		}
	}
	for(int x: id) cout<<x<<' ';
	cout<<'\n';
	cout<<ans.size()<<'\n';
	for(auto &x: ans) cout<<x<<' ';
	cout<<'\n';
}