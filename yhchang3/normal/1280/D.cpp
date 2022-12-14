#include<bits/stdc++.h>
using namespace std;

int n,m;

int b[3001],w[3001];
vector<int> e[3001];
pair<int,long long int> dp[3001][3001],tmp[3001];
int sz[3001];
void dfs(int x,int p){
	sz[x]=1;
	for(int it:e[x]){
		if(it==p)	continue;
		dfs(it,x);
		sz[x]+=sz[it];
	}
	int cur=1;
	dp[x][1].first=0;
	dp[x][1].second=w[x];
	for(int it:e[x]){
		if(it==p)	continue;
		for(int i=1;i<=cur+sz[it];i++)
			tmp[i].first=-1;
		for(int i=1;i<=cur;i++)
			for(int j=1;j<=sz[it];j++){
				tmp[i+j]=max(tmp[i+j],make_pair(dp[x][i].first+dp[it][j].first+(dp[it][j].second>0),dp[x][i].second));
				tmp[i+j-1]=max(tmp[i+j-1],make_pair(dp[x][i].first+dp[it][j].first,dp[x][i].second+dp[it][j].second));
			}
		cur+=sz[it];
		for(int i=1;i<=cur;i++)
			dp[x][i]=tmp[i];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++)
			cin>>w[i],w[i]-=b[i];
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}
		dfs(1,0);
		cout<<dp[1][m].first+(dp[1][m].second>0)<<'\n';
	}
}