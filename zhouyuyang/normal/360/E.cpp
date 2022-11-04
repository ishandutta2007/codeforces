#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

const int N=10005;
struct edge{
	int from,to,next,v,v2;
}e[N*2];
int head[N],tot,tp[N];
int n,m,K,S1,S2,T;
bool vis[N];
ll dis[N];
PQ<pll > Q;
void add(int x,int y,int v,int v2){
	e[++tot]=(edge){x,y,head[x],v,v2};
	head[x]=tot;
}
bool upd(int x,ll d,int fl){
	if (d>dis[x]||(d==dis[x]&&(fl|tp[x])==tp[x])) return 0;
	if (d==dis[x]) tp[x]|=fl;
	else dis[x]=d,tp[x]=fl;
	Q.push(pll(-dis[x],x));
	return 1;
}
int main(){	
	scanf("%d%d%d%d%d%d",&n,&m,&K,&S1,&S2,&T);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v,0);
	}
	For(i,1,K){
		int x,y,v1,v2;
		scanf("%d%d%d%d",&x,&y,&v1,&v2);
		add(x,y,v1,v2);
	}
	For(i,1,n) dis[i]=1e18;
	upd(S1,0,1); upd(S2,0,2);
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue; vis[x]=1;
		for (int i=head[x];i;i=e[i].next){
			ll trans=dis[x]+(i>m&&tp[x]&2?e[i].v2:e[i].v);
			upd(e[i].to,trans,tp[x]);
		}
	}
	if (tp[T]==1) puts("WIN");
	if (tp[T]==2) puts("LOSE");
	if (tp[T]==3) puts("DRAW");
	if (tp[T]!=2){
		For(i,m+1,m+K)
			if (tp[e[i].from]/2)
				printf("%d ",e[i].v2);
			else printf("%d ",e[i].v);
	}
}