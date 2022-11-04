#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<30)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=85;
struct edge{
	int from,to,next,f,v;
}e[N*14];
int head[N*3],tot=1;
int q[N*N],from[N*3],vis[N*3];
int n,k,S,T;
ll dis[N*3],ans;
void add(int x,int y,int v,int f){
	e[++tot]=(edge){x,y,head[x],f,v};
	head[x]=tot;
	e[++tot]=(edge){y,x,head[y],0,-v};
	head[y]=tot;
}
void bfs(){
	For(i,0,3*N-1) dis[i]=INF*INF,vis[i]=0;
	int h=N*10,t=h+1; q[t]=S;
	vis[S]=1; dis[S]=0;
	while (h!=t){
		int x=q[++h]; vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v&&e[i].f){
				dis[e[i].to]=dis[x]+e[i].v;
				from[e[i].to]=i;
				if (!vis[e[i].to]){
					vis[e[i].to]=1;
					if (dis[e[i].to]<=dis[q[h]])
						q[h--]=e[i].to;
					else q[++t]=e[i].to;
				}
			}
	}
}
int v[N],w[N],las[N];
int main(){
	scanf("%d%d",&n,&k);
	k=min(n,k); S=1; T=3*n+1;
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,n) scanf("%d",&w[i]);
	For(i,1,n){
		if (las[v[i]]){
			add(las[v[i]]*3-1,i*3-1,0,INF);
			add(las[v[i]]*3,i*3-1,0,1);
		}
		las[v[i]]=i;
	}
	For(i,1,n){
		add(i*3-2,i*3+1,0,INF);
		add(i*3-2,i*3-1,w[v[i]],1);
		add(i*3-1,i*3,-INF,1);
		add(i*3,i*3+1,0,1);
	}
	For(i,1,k){
		bfs();
		if (dis[T]>=0) break;
		ans+=dis[T];
		for (int j=from[T];j;j=from[e[j].from])
			e[j].f--,e[j^1].f++;
	}
	printf("%lld\n",ans+1ll*INF*n);
}