#include<cstdio>
#include<vector>
using namespace std;
const int N=300005;
bool vi[N],bb[N],b2[N],inq[N];
struct Edge{
	int t,u,v;
}ee[N];
struct edge{
	int to,next,id;
}e[N<<1];
int n,m,s,i,xb,h[N],mini,ans,q[N],x,t,w;
void dfs(int x){
	++mini;vi[x]=1;
	for(int i=h[x];i;i=e[i].next){
		if(ee[e[i].id].t==1){
			if(!vi[e[i].to])dfs(e[i].to);
		}else{
			b2[e[i].id]=bb[e[i].id]=e[i].to==ee[e[i].id].v;
			if(!inq[e[i].to])q[++w]=e[i].to,inq[e[i].to]=1;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&ee[i].t,&ee[i].u,&ee[i].v);
		e[++xb]=(edge){ee[i].v,h[ee[i].u],i};h[ee[i].u]=xb;
		if(ee[i].t==2)e[++xb]=(edge){ee[i].u,h[ee[i].v],i},h[ee[i].v]=xb;
	}
	dfs(s);ans=mini;
	while(t<w){
		x=q[++t];if(vi[x])continue;++ans;
		for(i=h[x];i;i=e[i].next)
			if(!vi[e[i].to] && !inq[e[i].to]){
				inq[e[i].to]=1;
				q[++w]=e[i].to;
				if(ee[e[i].id].t==2)b2[e[i].id]=ee[e[i].id].v==e[i].to;
			}
	}
	printf("%d\n",ans);
	for(i=1;i<=m;++i)if(ee[i].t==2)putchar(b2[i]?'+':'-');
	printf("\n%d\n",mini);
	for(i=1;i<=m;++i)if(ee[i].t==2)putchar(bb[i]?'-':'+');
	return 0;
}