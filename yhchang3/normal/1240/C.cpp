#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int > > e[500001];
int n,k;
long long int dp[500001][2];

void dfs(int x,int p){
	dp[x][0]=dp[x][1]=0;
	vector<long long int> v;
	for(auto it:e[x])
		if(it.first!=p){
			dfs(it.first,x);
			dp[x][1]+=dp[it.first][0];
			v.emplace_back(dp[it.first][1]+it.second-dp[it.first][0]);
		}
	sort(v.begin(),v.end(),greater<long long int>() );
	int c;
	for(c=0;c<min(k-1,(int) v.size());c++)
		if(v[c]<=0){
			break;
		}
		else
			dp[x][1]+=v[c];
	dp[x][0]=dp[x][1];
	if(c<v.size()&&v[c]>0)
		dp[x][0]+=v[c];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1,u,v,w;i<n;i++){
			cin>>u>>v>>w;
			e[u].emplace_back(v,w);
			e[v].emplace_back(u,w);
		}
		dfs(1,0);
		cout<<dp[1][0]<<'\n';
	}
}