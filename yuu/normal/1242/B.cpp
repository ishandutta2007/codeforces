#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[100001];
int r[100001];
int f[100001];
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	if(u==v) return;
	if(r[u]>r[v]) swap(u, v);
	r[u]+=r[v];
	r[v]=u;
}
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
	for(int i=1; i<=n; i++) r[i]=-1;
	for(int i=1; i<=n; i++){
		sort(g[i].begin(), g[i].end());
		int old=0;
		for(int x: g[i]){
			if(old+1<x){
				f[old+1]++;
				f[x-1]--;
				unite(i, old+1);
			}
			old=x;
		}
		if(old+1<=n){
			f[old+1]++;
			f[n]--;
			unite(i, old+1);
		}
	}
	for(int i=1; i<=n; i++){
		f[i]+=f[i-1];
		if(f[i]) unite(i, i+1);
	}
	int cnt=0;
	for(int i=1; i<=n; i++) cnt+=(i==root(i));
	cnt--;
	cout<<cnt<<'\n';
}