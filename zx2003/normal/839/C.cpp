#include<cstdio>
#include<vector>
const int N=100005;
double f[N];
struct edge{
	int to,next;
}e[N<<1];
int h[N],i,n,u,v,xb;
inline void addedge(int u,int v){
	e[++xb]=(edge){v,h[u]};
	h[u]=xb;
	e[++xb]=(edge){u,h[v]};
	h[v]=xb;
}
void dfs(int x,int fa){
	int d=0;
	for(int i=h[x];i;i=e[i].next)if(e[i].to!=fa)dfs(e[i].to,x),f[x]+=f[e[i].to],++d;
	f[x]=d?1+f[x]/d:0;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	dfs(1,0);
	printf("%.7f\n",f[1]);
	return 0;
}