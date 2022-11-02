#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
using namespace std;
const int MAX_N=5000+10;
vector<int> E[MAX_N];
int n;

int size[MAX_N];

bool can[MAX_N]={};

void dfs(int u,int par){
	size[u]=1;
	REP(i,E[u].size()){
		int v=E[u][i];
		if(v==par)
			continue;
		dfs(v,u);
		size[u]+=size[v];
	}
	
	//let's do dp
	static bool dp[MAX_N];
	REP(i,n+1)dp[i]=false;
	dp[0]=true;
	dp[n-size[u]]=true;
	REP(i,E[u].size()){
		int v=E[u][i];
		if(v==par)
			continue;
		int cur=size[v];
		for(int i=n;i>=cur;--i)
			if(dp[i-cur])
				dp[i]=true;
	}
	REP(i,n+1)can[i]|=dp[i];
}

int main(){
	cin>>n;
	REP(i,n-1){
		int a,b;cin>>a>>b;
		--a,--b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	dfs(0,-1);
	int cnt=0;
	for(int i=1;i<=n-2;i++)
		if(can[i])
			++cnt;
	cout<<cnt<<endl;
	for(int i=1;i<=n-2;i++)
		if(can[i])
			cout<<i<<" "<<n-1-i<<endl;
}