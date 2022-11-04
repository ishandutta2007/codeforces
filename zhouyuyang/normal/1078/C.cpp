#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (ll i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (ll i=(int)(j);i>=(int)(k);--i)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define inf 0x3f3f3f3f
using namespace std;
const int N=300005;
const int mo=998244353;
int n,f[N][3],g[3];
vector<int> e[N];
void dfs(int x,int fa){
	f[x][0]=1;
	for (auto i:e[x]) if (i!=fa){
		dfs(i,x);
		g[0]=1ll*f[x][0]*(f[i][0]+f[i][2])%mo;
		g[1]=(1ll*f[x][0]*f[i][2]+1ll*f[x][1]*(f[i][0]+2ll*f[i][2]))%mo;
		g[2]=(1ll*(f[x][0]+f[x][1])*(f[i][0]+f[i][1])+1ll*f[x][2]*(f[i][0]+2ll*f[i][2]))%mo;
		f[x][0]=g[0]; f[x][1]=g[1]; f[x][2]=g[2];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0);
	printf("%d\n",(f[1][0]+f[1][2])%mo);
}