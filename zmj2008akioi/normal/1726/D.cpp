#include <cstdio>
const int N=2e6+10;
int T,n,m,pu,pv,pd,dnt,f[N],p[N],bkt[N],ans[N],dep[N],head[N],to[N],val[N],next[N];
bool vis[N];
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
int find(int x){return f[x]==x?f[x]:f[x]=find(f[x]);}
void ad(int u,int v,int w){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v,val[dnt]=w;}
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=next[i]){
		if(vis[to[i]])continue;
		dep[to[i]]=dep[u]+1,p[to[i]]=val[i],dfs(to[i]);
	}
	vis[u]=false;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&m),dnt=0;int t=0;
		for(int i=1;i<=n;++i)f[i]=i,bkt[i]=head[i]=0;
		for(int i=1;i<=m;++i)ans[i]=0;
		for(int u,v,i=1;i<=m;++i){
			scanf("%d %d",&u,&v);
			if(find(u)!=find(v))ad(u,v,i),ad(v,u,i),f[find(u)]=find(v);
			else pu=u,pv=v,pd=i,ans[i]=1,t+=(++bkt[u])==2,t+=(++bkt[v])==2;
		}
		dfs(1);
		if(t==3){
			if(dep[pu]<dep[pv])swp(pu,pv);
			ans[pd]=0,ans[p[pu]]=1;
		}
		for(int i=1;i<=m;++i)putchar(ans[i]^48);
		putchar('\n');
	}
	return 0;
}