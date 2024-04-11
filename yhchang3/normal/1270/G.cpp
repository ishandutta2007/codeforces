#include<bits/stdc++.h>
using namespace std;

vector<int> ans,e[1000001];

bool vis[1000001];
int pa[1000001];
bool dfs(int x,int p){
	vis[x]=true;
	pa[x]=p;
	bool ok=false;
	for(int it:e[x])
		if(!ok&&it==p){
			ok=true;
		}
		else if(vis[it]){
			int y=x;
			pa[it]=x;
			ans.emplace_back(y);
			y=pa[y];
			while(y!=ans[0]){
				ans.emplace_back(y);
				y=pa[y];
			}
			return true;
		}
		else{
			if(dfs(it,x)) return true;
		}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			e[i].clear();
		for(int i=0;i<n;i++)
			vis[i]=false;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			e[i-x].emplace_back(i);
			e[i].emplace_back(i-x);
		}
		ans.clear();
		dfs(0,-1);
		cout<<ans.size()<<'\n';
		for(int it:ans)
			cout<<it+1<<' ';
		cout<<'\n';
	}
}