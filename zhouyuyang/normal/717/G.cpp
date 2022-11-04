#include<bits/stdc++.h>
#define N 505
using namespace std;
struct edge{
	int from,to,next,f,v;
}e[N*N];
int head[N],tot=1;
int from[N],vis[N],dis[N];
int q[N*N],n,m,T,ans;
char s[N],c[N]; 
void add(int x,int y,int f,int v){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
bool bfs(){
	memset(from,0,sizeof(from));
	memset(vis,0,sizeof(vis));
	memset(dis,-1,sizeof(dis));
	int h=0,t=1; q[1]=0;
	dis[0]=0; vis[0]=1;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]<dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					q[++t]=e[i].to;
				}
			}
	}
	return dis[T]>=0;
}
void del(){
	int fl=1e9;
	for (int i=from[T];i;i=from[e[i].from])
		fl=min(fl,e[i].f);
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f-=fl,e[i^1].f+=fl,ans+=fl*e[i].v;
}
int main(){
	scanf("%d%s%d",&n,s+1,&m);
	for (int i=0;i<=n;i++)
		add(i,i+1,1e9,0);
	while (m--){
		int v;
		scanf("%s%d",c+1,&v);
		int len=strlen(c+1);
		for (int i=1;i+len-1<=n;i++){
			int fl=1;
			for (int k=1;k<=len&&fl;k++)
				if (s[i+k-1]!=c[k]) fl=0;
			if (fl) add(i,i+len,1,v);
		}
	}
	int lim; scanf("%d",&lim);
	add(n+1,T=n+2,lim,0);
	for (;bfs();del());
	printf("%d",ans);
}