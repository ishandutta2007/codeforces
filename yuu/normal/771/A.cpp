#include <bits/stdc++.h>
using namespace std;
int n, m;
long long r[150001];
long long e[150001];
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
void unite(int u, int v){
	u=root(u);
	v=root(v);
	e[u]++;
	if(u==v) return;
	if(r[u]>r[v]) swap(u, v);
	r[u]+=r[v];
	e[u]+=e[v];
	r[v]=u;
}
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++) r[i]=-1;
	for(int i=1, a, b; i<=m; i++){
		cin>>a>>b;
		unite(a, b);
	}
	for(int i=1; i<=n; i++) if(i==root(i)){
		long long sz=-r[i];
		if((sz*(sz-1))/2!=e[i]){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}