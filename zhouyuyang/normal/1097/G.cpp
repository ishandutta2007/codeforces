#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
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
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
const int N=100005;
vector<int> e[N];
int n,k,ans,sz[N];
int g[N][205],C[205][205];
int tr[205],G[205];
void dfs(int x,int fa){
	sz[x]=g[x][0]=0;
	for (auto i:e[x]) if (i!=fa){
		dfs(i,x);
		int szi=min(sz[i],k);
		For(v1,0,min(k,sz[x]+szi)) G[v1]=0;
		For(v1,0,sz[x]) For(v2,0,min(szi,k-v1))
			G[v1+v2]=(G[v1+v2]+1ll*g[x][v1]*((v2?0:1)+g[i][v2])+(v1?0:g[i][v2]))%mo;
		sz[x]=min(k,sz[x]+szi);
		For(v1,0,sz[x]) g[x][v1]=G[v1];
	}
	For(i,0,sz[x]) g[x][i]=2ll*g[x][i]%mo;
	g[x][0]=(g[x][0]+1)%mo;
	For(i,1,sz[x]) ans=(ans+1ll*g[x][i]*tr[i])%mo;
	for (auto i:e[x]) if (i!=fa)
		For(j,0,sz[i]) ans=(ans+mo-1ll*g[i][j]*tr[j]%mo)%mo;
	g[x][sz[x]+1]=0;
	Rep(i,sz[x],0) g[x][i+1]=(g[x][i+1]+g[x][i])%mo;
	sz[x]=min(k,sz[x]+1);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		e[y].PB(x);
	}
	C[0][0]=1;
	For(i,1,k) tr[i]=power(i,k);
	For(i,1,k) For(j,0,i) C[i][j]=(C[i-1][j]+(j?C[i-1][j-1]:0))%mo;
	For(i,1,k) For(j,0,i-1) tr[i]=(tr[i]+mo-1ll*tr[j]*C[i][j]%mo)%mo;
	dfs(1,0);
	printf("%d\n",ans);
}
/*
f(x)=2f(x/2)+O(xk)
*/