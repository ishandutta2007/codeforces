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
const int N=25;
int n,ans,a[2][N][N];
int w[N][N],u[N][N],v[N][N],p[N][N];
int mn[N],fa[N],vis[N];
void KM(int x){
	int i=x++;
	For(j,1,n+1){
		u[x][j]=u[i][j];
		v[x][j]=v[i][j];
		p[x][j]=p[i][j];
		mn[j]=1<<29;
		vis[j]=0;
	}
	p[x][n+1]=i;
	int j0=n+1;
	for (;;){
		vis[j0]=1;
		int i0=p[x][j0],delta=1<<29,j1;
		For(j,1,n) if (!vis[j]){
			int cur=w[i0][j]-u[x][i0]-v[x][j];
			if (cur<mn[j]) mn[j]=cur,fa[j]=j0;
			if (mn[j]<delta) delta=mn[j],j1=j;
		}
		For(j,1,n+1)
			if (vis[j]){
				u[x][p[x][j]]+=delta;
				v[x][j]-=delta;
			}
			else mn[j]-=delta;
		j0=j1;
		if (p[x][j0]==-1) break;
	}
	for (;;){
		int j1=fa[j0];
		p[x][j0]=p[x][j1];
		if ((j0=j1)==n+1) break;
	}
}
void dfs(int x,int cnt){
	if (x>n){
		ans=max(ans,v[n+1][n+1]);
		return;
	}
	For(c,0,1){
		int ncnt=cnt+c;
		if (ncnt*2<=n&&(x-ncnt)*2<=n){
			For(j,1,n) w[x][j]=a[c][x][j];
			KM(x); dfs(x+1,ncnt);
		}
	}
}
int main(){
	scanf("%d",&n);
	For(c,0,1) For(i,1,n) For(j,1,n)
		scanf("%d",&a[c][i][j]),a[c][i][j]*=-1;
	ans=0;
	For(i,1,n) p[1][i]=-1;
	dfs(1,0);
	printf("%d",ans);
}