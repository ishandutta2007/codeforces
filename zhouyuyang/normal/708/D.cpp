#include<bits/stdc++.h>
#define N 105 
using namespace std;
struct edge{
	int from,to,next,f,v;
}e[N*8];
int head[N],tot=1;
int dis[N],q[N*N];
int vis[N],from[N];
int n,m,ans,S,T;
int in[N],out[N];
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(){
	memset(dis,64,sizeof(vis));
	memset(vis,0,sizeof(vis));
	int h=0,t=1; q[1]=S;
	dis[S]=0; vis[S]=1;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					q[++t]=e[i].to;
				}
			}
	}
	return dis[T]<1e9;
}
void del(){
	int f=1e9;
	for (int i=from[T];i;i=from[e[i].from])
		f=min(f,e[i].f);
	for (int i=from[T];i;i=from[e[i].from])
		ans+=e[i].v*f,e[i].f-=f,e[i^1].f+=f;
}
int main(){
	scanf("%d%d",&n,&m);
	S=n+1; T=n+2; add(n,1,1e9,0);
	for (int i=1;i<=m;i++){
		int x,y,c,f;
		scanf("%d%d%d%d",&x,&y,&c,&f);
		if (c>=f){
			add(x,y,c-f,1);
			add(y,x,f,1);
			add(x,y,1e9,2);
		}
		else{
			ans+=f-c;
			add(y,x,f-c,0);
			add(y,x,c,1);
			add(x,y,1e9,2);
		}
		in[y]+=f;
		out[x]+=f;
	}
	for (int i=1;i<=n;i++)
		if (in[i]>out[i])
			add(S,i,in[i]-out[i],0);
		else add(i,T,out[i]-in[i],0);
	while (bfs()) del();
	printf("%d",ans);
}