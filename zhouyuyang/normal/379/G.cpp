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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=2505;
int f[N][N][3],sz[N];
int dfn[N],low[N],T;
int fa[N],lp[N],n,m;
vector<int> E[N];
void update(int x,int y){
	For(i,0,2) Rep(j,sz[x],0){
		int val=f[x][j][i];
		f[x][j][i]=-INF;
		For(k,0,2) if (i+k!=3)
			For(l,0,sz[y]) f[x][j+l][i]=max(f[x][j+l][i],val+f[y][l][k]);
	}
	sz[x]+=sz[y];
}
int g[N][3];
void work(int x){
	int Sz,st=lp[1];
	For(i,0,2){
		CLR(g,200); Sz=sz[st];
		For(j,0,Sz) For(k,0,2)
			if (k+i!=3) g[j][k]=f[st][j][k];
			else g[j][k]=-INF;
		For(j,2,*lp){
			int x=lp[j],p[3];
			Rep(v1,Sz,0){
				For(v2,0,2) p[v2]=g[v1][v2],g[v1][v2]=-INF;
				For(v2,0,2) For(v3,0,2) if (v2+v3!=3)
					For(v4,0,sz[x]) g[v1+v4][v3]=max(g[v1+v4][v3],p[v2]+f[x][v4][v3]);
			}
			Sz+=sz[x];
		}
		Rep(v1,sz[x],0){
			int val=f[x][v1][i];
			f[x][v1][i]=-INF;
			For(v2,0,2) if (v2+i!=3)
				For(v3,0,Sz) f[x][v1+v3][i]=max(f[x][v1+v3][i],val+g[v3][v2]);
		}
	}
	sz[x]+=Sz;
}
void dfs(int x){
	dfn[x]=low[x]=++T;
	CLR(f[x],200);
	sz[x]=1;
	f[x][0][0]=0;
	f[x][1][1]=0;
	f[x][0][2]=1;
	For(i,0,E[x].size()-1){
		int to=E[x][i];
		if (to==fa[x]) continue;
		if (dfn[to]==-1){
			*lp=0;
			for (int j=to;j!=x;j=fa[j])
				lp[++*lp]=j;
			work(x);
		}
		else if (!dfn[to]){
			fa[to]=x; dfs(to);
			low[x]=min(low[x],low[to]);
			if (low[to]>dfn[x]) update(x,to);
		}
		else
			low[x]=min(low[x],dfn[to]); 
	}
	dfn[x]=-1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].PB(y); E[y].PB(x);
	}
	dfs(1);
	For(i,0,n)
		printf("%d ",max(f[1][i][0],max(f[1][i][1],f[1][i][2])));
}