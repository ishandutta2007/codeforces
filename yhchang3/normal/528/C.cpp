#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

multiset<int> e[100001];
int deg[100010];

void dfs(int x){
	while(!e[x].empty()){
		int y=*e[x].begin();
		e[x].erase(e[x].find(y));
		e[y].erase(e[y].find(x));
		dfs(y);
	}
	ans.emplace_back(x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		e[u].insert(v),e[v].insert(u);
		deg[u]++;deg[v]++;
	}
	vector<int> odd;
	for(int i=1;i<=n;i++)
		if(deg[i]&1)
			odd.emplace_back(i);
	for(int i=0;i<odd.size();i+=2){
		e[odd[i]].insert(odd[i+1]);
		e[odd[i+1]].insert(odd[i]);
		m++;
	}
	if(m&1){
		m++;
		e[1].insert(1);
		e[1].insert(1);
	}
	dfs(1);
	cout<<m<<'\n';
	for(int i=0;i+1<ans.size();i++)
		if(i&1)
			cout<<ans[i]<<' '<<ans[i+1]<<'\n';
		else
			cout<<ans[i+1]<<' '<<ans[i]<<'\n';

}