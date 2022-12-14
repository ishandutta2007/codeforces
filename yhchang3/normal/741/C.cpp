#include<bits/stdc++.h>
using namespace std;

int color[200010];
vector<int> e[200010];

int u[100010],v[100010];

void dfs(int x){
	for(int it:e[x])
		if(!color[it]){
			color[it]=3-color[x];
			dfs(it);
		}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
		e[u[i]].emplace_back(v[i]);
		e[v[i]].emplace_back(u[i]);
	}
	for(int i=1;i<n;i++){
		e[2*i].emplace_back(2*i+1);
		e[2*i+1].emplace_back(2*i);
	}
	e[2*n].emplace_back(1);
	e[1].emplace_back(2*n);
	for(int i=1;i<=2*n;i++)
		if(!color[i]){
			color[i]=1;
			dfs(i);
		}
	for(int i=1;i<=n;i++)
		cout<<color[u[i]]<<' '<<color[v[i]]<<'\n';
}