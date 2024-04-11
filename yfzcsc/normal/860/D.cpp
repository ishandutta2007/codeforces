#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
struct edge{int r,nxt,bh;}e[maxn<<1];
int head[maxn],esz,n,vis[maxn],dep[maxn],b[maxn];
int X[maxn],m,Y[maxn],Z[maxn],sz;
void addedge(int u,int v,int bh){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].bh=bh;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].bh=bh;
}
void dfs(int u,int f){
	dep[u]=1;
//	printf("[%d,%d]",u,f);
	for(int t=head[u];t;t=e[t].nxt)
		if(e[t].r!=f&&!dep[e[t].r])
			dfs(e[t].r,u);
	int tp=0;
	for(int t=head[u];t;t=e[t].nxt)
		if(e[t].r!=f&&!vis[e[t].bh])b[++tp]=t;
	if(tp%2&&f>0)for(int t=head[u];t;t=e[t].nxt)if(e[t].r==f)b[++tp]=t;
	for(int i=1;i+1<=tp;i+=2){
//		printf("{%d,%d}",u,tp);
		X[++sz]=e[b[i]].r,Y[sz]=u,Z[sz]=e[b[i+1]].r;
		vis[e[b[i]].bh]=vis[e[b[i+1]].bh]=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),addedge(u,v,i);
	for(int i=1;i<=n;++i)if(!dep[i])dep[i]=1,dfs(i,-1);
	printf("%d\n",sz);
	for(int i=1;i<=sz;++i)printf("%d %d %d\n",X[i],Y[i],Z[i]);
}