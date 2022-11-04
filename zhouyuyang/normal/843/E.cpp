#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define SUB(i,j) for (int all=(int)(j+2147483648ll),i=(int)(j);i>=0;i=(i-1)&j) 
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<30)
using namespace std;
const int N=105;
struct edge2{
	int x,y,g;
}a[N*10];
struct edge{
	int to,next,f;
}e[N*50];
int head[N],tot=1;
int dis[N],q[N];
int n,m,s,t,S,T;
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(int s,int t){
	For(i,1,T) dis[i]=-1;
	int tt=1; dis[q[1]=s]=0;
	For(h,1,tt) for (int i=head[q[h]];i;i=e[i].next)
		if (dis[e[i].to]==-1&&e[i].f)
			dis[e[i].to]=dis[q[h]]+1,q[++tt]=e[i].to;
	return dis[t]!=-1;
}
int dfs(int x,int t,int flow){
	if (x==t) return flow;
	int k,rest=flow;
	for (int i=head[x];i;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,t,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int ans,be[N];
int Ans[N*10],in[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	For(i,1,m){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].g);
		if (a[i].x==s&&a[i].y==t) ans++;
		else if (!a[i].g) add(a[i].x,a[i].y,INF);
		else{
			add(a[i].x,a[i].y,1);
			add(a[i].y,a[i].x,INF);
		}
	}
	S=n+1; T=S+1;
	for (;bfs(s,t);ans+=dfs(s,t,INF));
	printf("%d\n",ans);
	For(i,1,n) be[i]=(dis[i]!=-1);
	CLR(head,0); tot=1;
	For(i,1,m) if (a[i].g){
		Ans[i]=tot+1; add(a[i].x,a[i].y,10000);
		++in[a[i].y]; --in[a[i].x];
	}
	For(i,1,n)
		if (in[i]>0) add(S,i,in[i]);
		else if (in[i]<0) add(i,T,-in[i]);
	add(t,s,INF);
	for (;bfs(S,T);dfs(S,T,INF));
	For(i,1,m)
		if (a[i].x==s&&a[i].y==t) puts("1 1");
		else if (!a[i].g) puts("0 1");
		else{
			int W=10001-e[Ans[i]].f;
			printf("%d %d\n",W,be[a[i].x]>be[a[i].y]?W:INF);
		}
}