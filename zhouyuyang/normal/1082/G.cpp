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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define inf (1ll<<60)
using namespace std;
#define gc getchar
inline int read(){
	int x=0;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
const int N=1005;
struct edge{
	int to,next;
	ll f;
}e[N*8];
int head[N*2],tot=1;
void add(int x,int y,ll v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
int dis[N*2],q[N*2];
int S,T,n,m;
bool bfs(){
	For(i,1,T) dis[i]=-1;
	int t=1; dis[q[1]=S]=0;
	For(h,1,t) for (int i=head[q[h]];i;i=e[i].next)
		if (dis[e[i].to]==-1&&e[i].f){
			dis[q[++t]=e[i].to]=dis[q[h]]+1;
			if (e[i].to==T) return 1;
		}
	return 0;
}
ll dfs(int x,ll flow){
	if (x==T) return flow;
	ll k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
ll ans;
int main(){
	scanf("%d%d",&n,&m); S=n+m+1; T=S+1;
	For(i,1,n) add(i,T,read());
	For(i,1,m){
		add(i+n,read(),inf);
		add(i+n,read(),inf);
		int v=read();
		add(S,i+n,v);
		ans+=v;
	}
	while (bfs()) ans-=dfs(S,inf);
	printf("%lld\n",ans);
}