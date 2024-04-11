#include <bits/stdc++.h>
using namespace std;
vector <int> g[200001];
using ll=long long;
const int base=998244353;
int n;
ll f[200001][3];
int ans=0;
void dfs(int u){
	if(g[u].empty()){
		f[u][2]=1;
	}
	else{
		///f[u][0]=not connected to root
		f[u][0]=1;
		for(int v: g[u]){
			dfs(v);
			f[u][2]=(f[u][2]*(f[v][0]+f[v][1]+f[v][2]+f[v][2])+f[u][1]*(f[v][1]+f[v][2]))%base;
			f[u][1]=(f[u][1]*(f[v][0]+f[v][2])+f[u][0]*(f[v][1]+f[v][2]))%base;
			f[u][0]=(f[u][0]*(f[v][0]+f[v][2]))%base;
		}
	}
}
int main(){
	cin>>n;
	for(int i=2, p; i<=n; i++){
		cin>>p;
		g[p].push_back(i);
	}
	///take back solution where only 1 vertex are connected to root
	dfs(1);
	cout<<(f[1][0]+f[1][2])%base<<'\n';
}