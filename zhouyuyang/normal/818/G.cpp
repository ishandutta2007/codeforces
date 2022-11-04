#include<bits/stdc++.h>
#define P 8010
#define N 4005
using namespace std;
struct edge{int to,next,from,f,c;}e[N*14];
int head[P],dis[P],vis[P],q[P],a[N];
int from[P],S,SS,T,tot=1,ans;
void addE(int x,int y,int f,int c){
	e[++tot]=(edge){y,head[x],x,f,c};
	head[x]=tot;
}
void add(int x,int y,int f,int c){
	addE(x,y,f,c); addE(y,x,0,-c);
}
bool bfs(){
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	int h=0,t=1; q[1]=S; dis[S]=0;
	while (h!=t){
		if ((++h)==P) h=0;
		int x=q[h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].c&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].c;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					if ((++t)==P) t=0;
					q[t]=e[i].to;
				}
			}
	}
	return dis[T]<1e8;
}
int main(){
	int n; scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	S=0; SS=n*2+1; T=n*2+2; add(S,SS,4,0);
	for (int i=1;i<=n;i++){
		add(SS,i,1,0); add(n+i,T,1,0);
		add(i,n+i,1,-1); add(i,n+i,1e9,0);
	}
	//printf("%d\n",tot);
	for (int i=2;i<=n;i++){
		for (int j=i-1;j;j--)
			if (a[j]%7==a[i]%7){
				add(n+j,i,1,0);
				break;
			}
		for (int j=i-1;j;j--)
			if (a[j]==a[i]+1){
				add(n+j,i,1,0);
				break;
			}
		for (int j=i-1;j;j--)
			if (a[j]==a[i]-1){
				add(n+j,i,1,0);
				break;
			}
	}
	//printf("%d\n",tot);
	while (bfs()){
		ans-=dis[T];
		//printf("%d %d\n",dis[T],from[T]);
		for (int i=from[T];i;i=from[e[i].from])
			e[i].f--,e[i^1].f++;
	}
	printf("%d",ans);
}