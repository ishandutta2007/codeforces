#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,k,u,v,i,dep[N],sz[N];
vector<int>e[N];
void dfs(int x,int fa){
	if(fa)e[x].erase(find(e[x].begin(),e[x].end(),fa));
	sz[x]=1;dep[x]=dep[fa]+1;for(int y:e[x])dfs(y,x),sz[x]+=sz[y];
}
int main(){
	scanf("%d%d",&n,&k);k=n-k;
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0);
	priority_queue<pair<int,int>>q;long long ans=0;
	for(q.push({n-1,1});k--;){
		tie(v,u)=q.top();q.pop();ans+=v;
		for(int x:e[u])q.push({sz[x]-dep[x],x});
	}
	printf("%lld\n",ans);
}