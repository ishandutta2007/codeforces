#include<bits/stdc++.h>
using namespace std;

int c[200001],a[200001];
int vis[200001];

int ans=0;

void dfs(int x){
	vis[x]=1;
	if(vis[a[x]]==0)
		dfs(a[x]);
	else if(vis[a[x]]==1){
		int minimum_cost=1000000000;
		int now=x;
		do{
			minimum_cost=min(minimum_cost,c[now]);
			now=a[now];
		}while(now!=x);
		ans+=minimum_cost;
	}
	vis[x]=2;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	cout<<ans<<endl;
}