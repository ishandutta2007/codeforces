#include<bits/stdc++.h>
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
const int mo=998244353;
const int N=500005;
int n,ans;
int f[N],g[N],P[N],sz[N];
vector<int> e[N];
void dfs(int x,int fa){
	sz[x]=f[x]=1;
	for (auto y:e[x]) if (y!=fa){
		dfs(y,x); sz[x]+=sz[y];
		g[x]=(2ll*g[x]*(f[y]+g[y])+1ll*f[x]*f[y])%mo;
		f[x]=1ll*f[x]*(f[y]+2ll*g[y])%mo;
	}
	ans=(ans+mo-1ll*f[x]*P[n-sz[x]]%mo)%mo;
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	P[0]=1;
	For(i,1,n-1) P[i]=P[i-1]*2%mo;
	ans=1ll*P[n-1]*n%mo;
	dfs(1,0);
	printf("%d",ans*2%mo);
}