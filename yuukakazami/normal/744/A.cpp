#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

vector<int> e[1234];
int n,m,k;
int c[1234];

bool vis[1234];
int cnt;

void dfs(int u){
	vis[u] = 1; ++cnt;
	for(auto v:e[u]) if(!vis[v]) dfs(v);
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,k) scanf("%d",c+i),--c[i];

	rep(i,m){int u,v;scanf("%d%d",&u,&v),--u,--v;e[u].push_back(v);e[v].push_back(u);}

	vector<int> cp;
	rep(i,k) {cnt=0; dfs(c[i]); cp.push_back(cnt);}

	sort(cp.begin(),cp.end());

	rep(i,n) if(!vis[i]) {cnt=0;dfs(i);cp.back()+=cnt;}

	int have = 0;
	rep(i,cp.size()) have += cp[i] * (cp[i]-1)/2;

	cout<<have-m<<endl;
}