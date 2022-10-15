#include <cstdio>
int t,n,u,v,st,mx,dnt,deg[100010],ans[100010],head[100010],to[200010],next[200010];
bool vis[100010];
inline int max(int x,int y){return x>y?x:y;}
inline void addedge(int u,int v){++dnt,++deg[u],next[dnt]=head[u],head[u]=dnt,to[dnt]=v;}
void dfs(int u,int nw){
	vis[u]=true;
	for(register int i=head[u];i;i=next[i])if(!vis[to[i]])ans[(i+1)>>1]=nw,dfs(to[i],5-nw);
}
int main(){
	scanf("%d",&t);
	do{
		mx=0,scanf("%d",&n);
		for(register int i=1;i<=n-1;++i)scanf("%d %d",&u,&v),addedge(u,v),addedge(v,u);
		for(register int i=1;i<=n;++i){
			mx=max(mx,deg[i]);
			if(deg[i]==1)st=i;
		}
		if(mx>2)puts("-1");
		else{
			dfs(st,2);
			for(register int i=1;i<=n-1;++i)printf("%d ",ans[i]);
			putchar('\n');
		}
		for(register int i=1;i<=n;++i)deg[i]=0,head[i]=0,vis[i]=false;
		while(dnt)next[dnt]=0,--dnt;
	}while(--t);
	return 0;
}