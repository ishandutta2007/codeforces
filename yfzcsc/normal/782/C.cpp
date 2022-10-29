#include<bits/stdc++.h>
#define maxn 400100
using namespace std;
struct edge{
	int r,nxt;
}e[maxn<<1];
int col[maxn],esz,head[maxn],n,k,d[maxn],vis[maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
	d[u]++,d[v]++;
}
void dfs(int u,int f){
	vis[col[u]]=vis[col[f]]=u;
	for(int i=1,t=head[u];i<=k&&t;++i)if(vis[i]!=u){
		if(col[e[t].r])t=e[t].nxt;
		if(!t)break;
		col[e[t].r]=i;
		t=e[t].nxt;
	}
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		dfs(e[t].r,u);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),addedge(u,v);
	for(int i=1;i<=n;++i)k=max(k,d[i]+1);
	col[0]=col[1]=1,dfs(1,0);
	printf("%d\n",k);
	for(int i=1;i<=n;++i)printf("%d ",col[i]);
}