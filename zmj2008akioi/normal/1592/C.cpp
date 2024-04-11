#include <cstdio>
const int rt=1;
int t,n,k,u,v,nw,cnt,ucnt,arr[100010],cld[100010],now[100010],head[100010],to[200010],next[200010];
bool vis[100010];
inline void addedge(int u,int v){
	++cnt;
	if(!head[u])head[u]=cnt;
	else next[now[u]]=cnt;
	now[u]=cnt,next[cnt]=0,to[cnt]=v;
}
bool dfs(int pos){
	if(vis[pos])return false;vis[pos]=true;
	cld[pos]=arr[pos];
	for(register int i=head[pos];i;i=next[i])if(dfs(to[i]))cld[pos]^=cld[to[i]];
	if(cld[pos]==nw)cld[pos]=0,++ucnt;
	return true;
}
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d",&n,&k);
		nw=cnt=0;
		for(register int i=1;i<=n;++i)scanf("%d",&arr[i]),nw^=arr[i],vis[i]=head[i]=0;
		for(register int i=1;i<n;++i){
			scanf("%d %d",&u,&v);
			addedge(u,v),addedge(v,u);
		}
		if(!nw)printf("Yes\n");
		else if(k==2)printf("No\n");
		else{
			ucnt=0,dfs(rt);
			if(ucnt>=2)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}