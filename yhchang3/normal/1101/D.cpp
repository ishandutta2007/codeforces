#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> factor[N+1],edge[N+1];
bool iscomposite[N+1];
int a[N+1];
map<int,int> dp[N+1];
int ans;

void dfs(int x,int p){
	for(int prime:factor[a[x]]){
		dp[x][prime]=1;
		ans=max(ans,1);
	}
	for(int it:edge[x]){
		if(it==p)	continue;
		dfs(it,x);
		for(int prime:factor[a[x]]){
			ans=max(dp[x][prime]+dp[it][prime],ans);
			dp[x][prime]=max(dp[x][prime],1+dp[it][prime]);
		}
	}
}

int main(){
	for(int i=2;i<=N;i++)
		if(!iscomposite[i]){
			factor[i].emplace_back(i);
			for(int j=i+i;j<=N;j+=i){
				iscomposite[j]=true;
				factor[j].emplace_back(i);
			}
		}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		edge[x].emplace_back(y);
		edge[y].emplace_back(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
}