#include<bits/stdc++.h>
#define N 3000
using namespace std;
struct edge{int to,next,from,f,v;}e[N*10];
int head[N],dis[N],q[N*N],vis[N],from[N];
int l[55],r[55],n,m,S,T,tot=1,ans;
void add(int x,int y,int f,int v){
	e[++tot]=(edge){y,head[x],x,f,v};
	head[x]=tot;
}
void Add(int x,int y,int f,int v){
	add(x,y,f,v);
	add(y,x,0,-v);
}
bool spfa(){
	for (int i=S;i<=T;i++)
		dis[i]=1e9,vis[i]=0;
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
	return dis[T]!=1e9;
}
void del(){
	for (int i=from[T];i;i=from[e[i].from])
		e[i].f--,e[i^1].f++,ans+=e[i].v;
}
int main(){
	scanf("%d%d",&n,&m);
	S=0; T=n*(n+1)+1; 
	for (int i=1;i<=n;i++)
		Add(S,i,1,0),l[i]=1,r[i]=n;
	for (int i=1;i<=m;i++){
		int id,L,R,x;
		scanf("%d%d%d%d",&id,&L,&R,&x);
		for (int j=L;j<=R;j++)
			if (id==1) l[j]=max(l[j],x);
			else r[j]=min(r[j],x);
	}
	for (int i=1;i<=n;i++)
		if (l[i]>r[i]) return puts("-1"),0;
	for (int i=1;i<=n;i++)
		for (int j=l[i];j<=r[i];j++)
			Add(i,j+n,1,0);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			Add(i+j*n,T,1,2*j-1);
	for (int i=1;i<=n;i++)
		for (int j=2;j<=n;j++)
			Add(i+n,i+j*n,1,0);
	while (spfa()) del();
	printf("%d",ans);
}