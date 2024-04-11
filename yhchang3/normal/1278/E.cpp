#include<bits/stdc++.h>
using namespace std;

vector<int> ans,e[500001];
vector<int> v[500001];
void dfs(int x,int p){
	for(int it:e[x])
		if(it!=p)
			ans.emplace_back(it);
	ans.emplace_back(x);
	for(int i=(int) e[x].size()-1;i>=0;i--)
		if(e[x][i]!=p)
			dfs(e[x][i],x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	ans.emplace_back(1);
	dfs(1,0);
	for(int i=0;i<ans.size();i++)
		v[ans[i]].emplace_back(i+1);
	for(int i=1;i<=n;i++)
		cout<<v[i][0]<<' '<<v[i][1]<<'\n';
}