#include<bits/stdc++.h>
using namespace std;

vector<int> edge[100001];

bool vis[100001];

void dfs(int x){
	vis[x]=true;
	for(int it:edge[x])
		if(!vis[it])
			dfs(it);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1,x,y;i<=k;i++){
		cin>>x>>y;
		edge[x].emplace_back(y);
		edge[y].emplace_back(x);
	}
	int ans=k-n;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			dfs(i);
			ans++;
		}
	cout<<ans<<endl;
}