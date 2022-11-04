#include<bits/stdc++.h>
const int N=12005;
const int M=2000000;
using namespace std;
struct edge{
	int to,next,f;
}e[M*2];
int head[N],tot=1;
int q[N],dis[N],sex[N];
int n,m,S,T,g,ans,cur[N];
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
int bfs(){
	for (int i=1;i<=T;i++) dis[i]=-1;
	int h=0,t=1; dis[S]=0; q[1]=S;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (e[i].f&&dis[e[i].to]==-1){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int &i=cur[x];i&&rest;i=e[i].next)
		if (e[i].f&&dis[e[i].to]==dis[x]+1){
			k=dfs(e[i].to,min(e[i].f,rest));
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int main(){
	scanf("%d%d%d",&n,&m,&g);
	for (int i=1;i<=n;i++) scanf("%d",&sex[i]);
	S=n+m+1; T=n+m+2;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		sex[i]?add(i,T,x):add(S,i,x);
	}
	for (int i=1;i<=m;i++){
		int tp,x,cnt;
		scanf("%d%d%d",&tp,&x,&cnt);
		for (int j=1;j<=cnt;j++){
			int id; scanf("%d",&id);
			tp?add(id,n+i,1e9):add(n+i,id,1e9);
		}
		scanf("%d",&cnt); ans+=x; x+=cnt*g;
		tp?add(n+i,T,x):add(S,n+i,x);
	}
	for (;bfs();){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		ans-=dfs(S,1e9);
	}
	printf("%d",ans);
}