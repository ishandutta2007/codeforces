#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MAX_N=int(1e6)+10;
vector<int> E[MAX_N];
int n,nE;
bool vis[MAX_N]={};
int n0,n1;

int sumE=0;

void dfs(int u){	
	if(vis[u])
		return;
	vis[u]=true;
	if(E[u].size()%2==0)
		++n0;
	else
		++n1;
	sumE+=E[u].size();
	for_each(E[u].begin(),E[u].end(),dfs);
}

vector<int> c0,c1;

int main(){
	cin>>n>>nE;
	REP(i,nE){
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	REP(i,n)if(!vis[i]){
		n0=0,n1=0;
		sumE=0;
		dfs(i);
		if(sumE>0||i==0)
			c0.push_back(n0),c1.push_back(n1);
	}
	if(c0.size()==1 && c1[0]==0){
		puts("0");
		return 0;
	}
	int ans=0,cnt0=0,cnt1=0;
	REP(i,c1.size()){
		if(c1[i]>0)
			++cnt1,ans+=c1[i];
		else
			++cnt0;
	}
	ans/=2;
	if(cnt1==0){
		cout<<ans+cnt0<<endl;
		return 0;
	}
	if(cnt0==0)
		cout<<ans<<endl;
	else
		cout<<ans+cnt0<<endl;
}