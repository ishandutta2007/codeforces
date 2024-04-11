#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define INF (1ll<<60)
using namespace std;
const int N=200005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot;
bool vis[N],has_find;
int fa[N],fav[N],sz[N];
int R[N*2],v[N*2],id[N*2];
ll ans[N],sub[N],dep[N];
ll Sz[N*2],SV[N*2];
ll Ans[N];
int n;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void find_ring(int x){
	if (has_find) return;
	vis[x]=1;
	for (int i=head[x];i&&!has_find;i=e[i].next)
		if (e[i].to!=fa[x])
			if (!vis[e[i].to]){
				fa[e[i].to]=x; fav[e[i].to]=e[i].v;
				find_ring(e[i].to);
			}
			else{
				for (int y=x;y!=e[i].to;y=fa[y])
					R[++*R]=y,v[*R]=fav[y];
				R[++*R]=e[i].to; v[*R]=e[i].v;
				has_find=1;
				return;
			}
}
void dfs1(int x,int fa,int id){
	sz[x]=1; ans[x]=0; ::id[x]=id;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			dep[e[i].to]=dep[x]+e[i].v;
			dfs1(e[i].to,x,id);
			sz[x]+=sz[e[i].to];
			ans[x]+=ans[e[i].to]+1ll*sz[e[i].to]*e[i].v;
		}
}
void dfs2(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			ans[e[i].to]=ans[x];
			ans[e[i].to]-=1ll*sz[e[i].to]*e[i].v;
			ans[e[i].to]+=1ll*(sz[R[id[x]]]-sz[e[i].to])*e[i].v;
			dfs2(e[i].to,x);
		}
}
void solve_ring(){
	For(i,1,*R) Sz[i]=Sz[i+*R]=sz[R[i]];
	For(i,1,*R) v[i+*R]=v[i];
	For(i,1,2*(*R)){
		v[i]+=v[i-1];
		SV[i]=1ll*Sz[i]*v[i-1]+SV[i-1];
		Sz[i]+=Sz[i-1];
	}
	ll ring_len=v[*R];
	for (int i=1,j=1;i<=*R;i++){
		for (;(v[j]-v[i-1])*2<=ring_len;j++);
		Ans[i]+=(SV[j]-SV[i])-1ll*(Sz[j]-Sz[i])*v[i-1];
		Ans[i]+=1ll*(Sz[i+*R]-Sz[j])*v[i+*R-1]-(SV[i+*R]-SV[j]);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	find_ring(1);
	memset(vis,0,sizeof(vis));
	For(i,1,*R) vis[R[i]]=1;
	ll totsum=0;
	For(i,1,*R){
		dfs1(R[i],0,i);
		dfs2(R[i],0);
		sub[i]=ans[R[i]];
		totsum+=sub[i];
	}
	For(i,1,n){
		ans[i]=ans[i]+totsum-sub[id[i]];
		ans[i]=ans[i]+1ll*(n-sz[R[id[i]]])*dep[i];
	}
	solve_ring();
	For(i,1,n)
		printf("%lld ",ans[i]+Ans[id[i]]);
}