#include <cstdio>
const int N=1e6+10;
int n,m,dnt,ans[N],head[N],to[N],val[N],next[N];bool zr[N],vis[N];
void ad(int u,int v,int w){next[++dnt]=head[u],head[u]=dnt,to[dnt]=v,val[dnt]=w;}
int main(){
	scanf("%d %d",&n,&m);
	for(int u,v,x,i=1;i<=m;++i)scanf("%d %d %d",&u,&v,&x),ad(u,v,x),ad(v,u,x);
	for(int i=0;i<30;++i){
		for(int j=1;j<=n;++j)zr[j]=vis[j]=false;
		for(int j=1;j<=dnt;++j)if(!(val[j]&(1<<i)))zr[to[j]]=true;
		for(int j=1;j<=n;++j){
			if(zr[j])continue;bool tag=true;
			for(int k=head[j];k;k=next[k])if(zr[to[k]]||(to[k]<=j&&!vis[to[k]])){tag=false;break;}
			if(!tag)vis[j]=true;else vis[j]=false;
		}
		for(int j=1;j<=n;++j)ans[j]|=vis[j]<<i;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}