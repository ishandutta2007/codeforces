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
int id[100001];
int ans[100001];
int main(){
	cin>>n>>m;
	for(int i=1, a, b; i<=m; i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i=1; i<=n; i++) r[i]=-1;
	for(int i=1; i<=n; i++){
		sort(g[i].begin(), g[i].end());
		int old=0;
		for(int x: g[i]){
			if(old+1<x){
				unite(i, old+1);
				f[old+1]++;
				f[x-1]--;
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
	for(int i=1; i<=n; i++) for(int j: g[i]) if(root(i)==root(j)){
		cout<<"-1\n";
		return 0;
	}
 	for(int i=1; i<=n; i++) if(i==root(i)){
		cnt++;
		ans[i]=cnt;
	}
	if(cnt!=3){
		cout<<"-1\n";
		return 0;
	}
	for(int i=1; i<=n; i++) ans[i]=ans[root(i)];
	for(int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
}