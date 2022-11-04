#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot;
int sz[N],vis[N];
int mn,rt,pos,n,Sz;
double cost,sub,ans;
int a[N]; 
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void getsz(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			getsz(e[i].to,x);
			sz[x]+=sz[e[i].to];
		}
}
void getrt(int x,int fa){
	int mx=Sz-sz[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			getrt(e[i].to,x);
			mx=max(mx,sz[e[i].to]);
		}
	if (mx<mn)
		mn=mx,rt=x;
}
void calc(int x,int fa,int dis){
	sub+=sqrt(dis)*a[x];
	cost+=sqrt(dis)*dis*a[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			calc(e[i].to,x,dis+e[i].v);
}
void solve(int x){
	getsz(x,0);
	Sz=sz[x]; mn=1e9;
	getrt(x,0);
	vis[rt]=1;
	double mx=0;
	int t=rt; cost=0;
	for (int i=head[rt];i;i=e[i].next){
		sub=0;
		calc(e[i].to,rt,e[i].v);
		if (sub>mx) mx=sub,t=e[i].to;
	}
	if (cost<ans)
		ans=cost,pos=rt;
	if (!vis[t]) solve(t);
}
int main(){
	ans=1e100;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	solve(1);
	printf("%d %.10lf",pos,ans);
}