#include<bits/stdc++.h>
using namespace std;

long long int G,B;
int k;

vector<pair<int,int> > e[200001];
int dp[200001];

void dfs(int x,int p){
	dp[x]=1;
	for(auto it:e[x])
		if(it.first!=p){
			dfs(it.first,x);
			if(dp[it.first]&1)
				G+=it.second;
			B+=(long long int) min(dp[it.first],k-dp[it.first])*it.second;
			dp[x]+=dp[it.first];
		}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		G=B=0;
		cin>>k;
		k*=2;
		for(int i=1;i<=k;i++)
			e[i].clear();
		for(int i=1,u,v,w;i<k;i++){
			cin>>u>>v>>w;
			e[u].emplace_back(v,w);
			e[v].emplace_back(u,w);
		}
		dfs(1,0);
		cout<<G<<' '<<B<<'\n';
	}
}