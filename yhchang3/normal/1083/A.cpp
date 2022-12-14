#include<bits/stdc++.h>
using namespace std;

long long int dp[300001],w[300001];
long long int ans=0;
vector<pair<int,long long int> > edge[300001];
void dfs(int x,int p){
	vector<long long int> v;
	for(auto i:edge[x]){
		if(i.first==p)	continue;
		dfs(i.first,x);
		v.push_back(dp[i.first]+w[x]-i.second);
	}
	v.push_back(w[x]);
	if(v.size()==1)
		dp[x]=v[0],ans=max(ans,dp[x]);
	else{
		sort(v.begin(),v.end(),greater<long long int>());
		dp[x]=v[0];
		ans=max(ans,v[0]+v[1]-w[x]);
		ans=max(ans,v[0]);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=0,u,v,l;i<n-1;i++){
		cin>>u>>v>>l;
		edge[u].push_back({v,l});
		edge[v].push_back({u,l});
	}
	dfs(1,0);
	cout<<ans<<endl;
}