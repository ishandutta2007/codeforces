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
const int N=505;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
int sz[N],B,n,mx,co[N];
short dp[N][N][N],dq[N][N];
ll dis[N][N];

void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot; dis[x][y]=v;
}
void dfs(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
	For(i,1,n) if (i==x||dis[x][i]<=mx){
		sz[x]=1; dp[x][i][1]=co[i];
		for (int k=head[x];k;k=e[k].next) if (e[k].to!=fa){
			Rep(j,min(sz[x]+sz[e[k].to],B),0){
				int xx=0x3f3f;
				For(l,max(0,j-sz[x]),min(j,sz[e[k].to]))
					xx=min(xx,dp[x][i][j-l]+dq[e[k].to][l]);	
				For(l,max(1,j+1-sz[x]),min(j+1,sz[e[k].to]))
					xx=min(xx,dp[x][i][j+1-l]+dp[e[k].to][i][l]-co[i]);
				dp[x][i][j]=xx;
			}
			sz[x]+=sz[e[k].to];
		}
		For(j,0,sz[x])
			dq[x][j]=min(dq[x][j],dp[x][i][j]);
	}
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			sz[x]+=sz[e[i].to]; 
}
int main(){
	scanf("%d%d",&n,&mx);
	For(i,1,n){
		scanf("%d",&co[i]);
		B+=(co[i]^=1);
	}
	B=n-B; CLR(dis,60);
	CLR(dp,60); CLR(dq,60);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	dfs(1,0); short ans=0x3f3f;
	For(i,1,B) ans=min(ans,dq[1][i]);
	printf("%d\n",ans>1000?-1:ans);
}