#include <cstring>
#include <cstdio>
#include <cstdlib> 
#include <cmath>
#include <algorithm>
using namespace std;
const int N=205,M=N*N*10,INF=1e9;
struct edge{
	int x,y,cap,flow,nxt;
};
struct gragh{
	int cnt,fst[N],dist[N],n,S,T,num[N],cur[N],p[N];
	int q[N],head,tail;
	edge e[M];
	void set(int _S,int _T,int _n){
		S=_S,T=_T,n=_n,cnt=1;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,int c){
		cnt++;
		e[cnt].x=a,e[cnt].y=b,e[cnt].cap=c,e[cnt].flow=0;
		e[cnt].nxt=fst[a],fst[a]=cnt;
		cnt++;
		e[cnt].x=b,e[cnt].y=a,e[cnt].cap=0,e[cnt].flow=0;
		e[cnt].nxt=fst[b],fst[b]=cnt;
	}
	void bfs(){
		memset(dist,-1,sizeof dist);
		head=tail=dist[T]=0;
		q[++tail]=T;
		while (head<tail)
			for (int x=q[++head],y,i=fst[x];i;i=e[i].nxt)
				if ((i&1)&&dist[y=e[i].y]==-1)
					dist[q[++tail]=y]=dist[x]+1;
		for (int i=1;i<=n;i++)
			if (dist[i]==-1)
				dist[i]=n;
	}
	void init(){
		bfs();
		memset(num,0,sizeof num);
		for (int i=1;i<=n;i++)
			num[dist[i]]++,cur[i]=fst[i];
	}
	int Augment(int &x){
		int ex_flow=INF;
		for (int i=T;i!=S;i=e[p[i]].x)
			if (e[p[i]].cap-e[p[i]].flow<=ex_flow)
				ex_flow=e[p[i]].cap-e[p[i]].flow,x=e[p[i]].x;
		for (int i=T;i!=S;i=e[p[i]].x)
			e[p[i]].flow+=ex_flow,e[p[i]^1].flow-=ex_flow;
		return ex_flow;
	}
	int ISAP(){
		int x=S,y,MaxFlow=0;
		init();
		while (dist[S]<n){
			if (x==T){
				MaxFlow+=Augment(x);
				continue;
			}
			bool found=0;
			for (int i=cur[x];i;i=e[i].nxt)
				if (dist[y=e[i].y]+1==dist[x]&&e[i].cap>e[i].flow){
					cur[x]=p[y]=i,x=y,found=1;
					break;
				}
			if (!found){
				int d=n+1;
				for (int i=fst[x];i;i=e[i].nxt)
					if (e[i].cap>e[i].flow)
						d=min(d,dist[e[i].y]+1);
				if (!--num[dist[x]])
					return MaxFlow;
				num[dist[x]=d]++,cur[x]=fst[x],x=x==S?x:e[p[x]].x;
			}
		}
		return MaxFlow;
	}
}g;
int n,a[205],A=0,B=0;
int x[205][205],y[205],tot,vis[205];
int isprime(int x){
	for (int i=2;i<x;i++)
		if (x%i==0)
			return 0;
	return 1;
}
void dfs(int X){
	x[tot][++y[tot]]=X;
	vis[X]=1;
	for (int i=g.fst[X];i;i=g.e[i].nxt)
		if (!vis[g.e[i].y]&&(g.e[(i|1)^1].flow==1))
			dfs(g.e[i].y);
}
int main(){
	scanf("%d",&n);
	if (n&1){
		puts("Impossible");
		return 0;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]&1)
			A++;
		else
			B++;
	}
	if (A!=B){
		puts("Impossible");
		return 0;
	}
	g.set(n+1,n+2,n+2);
	for (int i=1;i<=n;i++){
		if (a[i]&1){
			g.add(n+1,i,2);
			for (int j=1;j<=n;j++)
				if (isprime(a[i]+a[j]))
					g.add(i,j,1);
		}
		else
			g.add(i,n+2,2);
	}
	g.bfs();
	int xx=g.ISAP();
	if (xx!=n){
		puts("Impossible");
		return 0;
	}
	tot=0;
	for (int i=1;i<=n;i++){
		if (vis[i])
			continue;
		tot++;
		dfs(i);
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++,puts("")){
		printf("%d ",y[i]);
		for (int j=1;j<=y[i];j++)
			printf("%d ",x[i][j]);
	}
	return 0;
}