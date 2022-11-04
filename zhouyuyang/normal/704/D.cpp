#include<bits/stdc++.h>
#define N 100005
#define rp(x) (x+1+*dx)
#define lp(x) (x+1)
using namespace std;
int x[N],y[N],id[N],dx[N],dy[N];
int cntx[N],cnty[N],lx[N],ly[N];
int q[N*2],dis[N*2],cur[N*2];
int head[N*2],in[N*2],out[N*2];
struct edge{
	int to,next,f;
}e[N*11];
int n,m,r,b,tot=1;
int sum,ans;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(int S,int T){
	memset(dis,-1,sizeof(dis));
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow,int T){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=cur[x];i&&rest;i=e[i].next){
		cur[x]=i;
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f),T);
			rest-=k; e[i].f-=k; e[i^1].f+=k;
		}
	}
	if (rest) dis[x]=-1;
	return flow-rest;
} 
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&b);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		dx[i]=x[i]; dy[i]=y[i];
	}
	sort(dx+1,dx+n+1);
	sort(dy+1,dy+n+1);
	*dx=unique(dx+1,dx+n+1)-dx-1;
	*dy=unique(dy+1,dy+n+1)-dy-1;
	int SS=0,S=1,T=(*dx+*dy+2),TT=T+1;
	for (int i=1;i<=n;i++){
		x[i]=lower_bound(dx+1,dx+*dx+1,x[i])-dx;
		y[i]=lower_bound(dy+1,dy+*dy+1,y[i])-dy;
		cntx[x[i]]++; cnty[y[i]]++; id[i]=tot+1;
		add(lp(x[i]),rp(y[i]),1);
	}
	for (int i=1;i<=*dx;i++) lx[i]=1e9;
	for (int i=1;i<=*dy;i++) ly[i]=1e9;
	for (int i=1;i<=m;i++){
		int tp,pos,l,d;
		scanf("%d%d%d",&tp,&l,&d);
		if (tp==1){
			pos=lower_bound(dx+1,dx+*dx+1,l)-dx;
			if (pos>*dx||dx[pos]!=l) continue;
			lx[pos]=min(lx[pos],d);
		}
		else{
			pos=lower_bound(dy+1,dy+*dy+1,l)-dy;
			if (pos>*dy||dy[pos]!=l) continue;
			ly[pos]=min(ly[pos],d);
		}
	}
	for (int i=1;i<=*dx;i++){
		int lo=max((cntx[i]-lx[i]+1)/2,0);
		int mx=min((cntx[i]+lx[i])/2,cntx[i]);
		if (lo>mx) return puts("-1"),0;
		out[S]+=lo; in[lp(i)]+=lo;
		add(S,lp(i),mx-lo);
	}
	for (int i=1;i<=*dy;i++){
		int lo=max((cnty[i]-ly[i]+1)/2,0);
		int mx=min((cnty[i]+ly[i])/2,cnty[i]);
		if (lo>mx) return puts("-1"),0;
		out[rp(i)]+=lo; in[T]+=lo;
		add(rp(i),T,mx-lo);
	}
	for (int i=S;i<=T;i++)
		if (in[i]>out[i]){
			add(SS,i,in[i]-out[i]);
			sum+=in[i]-out[i];
		}
		else add(i,TT,out[i]-in[i]);
	add(T,S,1e9);
	while (bfs(SS,TT)){
		for (int i=SS;i<=TT;i++)
			cur[i]=head[i];
		sum-=dfs(SS,1e9,TT);
	}
	if (sum)
		return puts("-1"),0;
	while (bfs(S,T)){
		for (int i=S;i<=T;i++)
			cur[i]=head[i];
		ans+=dfs(S,1e9,T);
	}
	bool rev=0;
	if (r>b) swap(r,b),rev=1;
	printf("%lld\n",1ll*r*ans+1ll*b*(n-ans));
	for (int i=1;i<=n;i++)
		putchar((e[id[i]].f==0)^rev?'r':'b');
}