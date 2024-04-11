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
const int N=55;
vector<int> e[N];
double f[N][N],g[N][N];
int n,sz[N];
void dfs(int x,int fa){
	g[x][0]=1;
	for (auto i:e[x]) if (i!=fa){
		dfs(i,x);
		Rep(j,sz[x],0){
			double v=g[x][j]; g[x][j]=0;
			For(k,0,sz[i]) g[x][j+k]+=v*f[i][k];
		}
		sz[x]+=sz[i];
	}
	For(i,0,sz[x]){
		double tmp=0.5*g[x][i];
		For(j,0,i){
			f[x][i-j]+=tmp;
			tmp*=1.0*(i-j)/(sz[x]+1-i+j);
		}
	}
	For(i,0,sz[x]) f[x][i]/=(sz[x]+1-i);
	For(i,0,sz[x]) f[x][i+1]+=g[x][i];
	++sz[x];
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n){
		CLR(f,0); CLR(g,0); CLR(sz,0);
		double ans=1; 
		for (auto j:e[i]) dfs(j,i),ans*=f[j][0];
		printf("%.15lf\n",ans);
	}
}