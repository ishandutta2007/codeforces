#include<bits/stdc++.h>
using namespace std;

vector<int> edge[300001];

int dp[300001];
int ans;

void dfs(int x,int p){
	int biggest=0,secondbiggest=0;
	for(int it:edge[x]){
		if(it==p)	continue;
		dfs(it,x);
		if(dp[it]>=biggest){
			secondbiggest=biggest;
			biggest=dp[it];
		}
		else
			secondbiggest=max(secondbiggest,dp[it]);
	}
	dp[x]=edge[x].size()+biggest+(biggest==0?0:-1);
	ans=max(ans,dp[x]+(p!=0));
	ans=max(ans,int(biggest+secondbiggest+edge[x].size()-1));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			edge[x].emplace_back(y);
			edge[y].emplace_back(x);
		}
		ans=0;
		dfs(1,0);
		for(int i=1;i<=n;i++){
			edge[i].clear();
			dp[i]=0;
		}
		cout<<ans<<endl;
	}
}