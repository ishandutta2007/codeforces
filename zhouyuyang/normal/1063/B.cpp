#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define INF (1<<29)
using namespace std;
const int N=2005;
vector<pii> q[N*N];
int dis[N][N],vis[N][N];
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int n,m,Sx,Sy,le,ri,ans;
char mp[N][N];
void work(){
	For(i,1,n) For(j,1,m) dis[i][j]=1<<30;
	dis[Sx][Sy]=0;
	q[0].push_back(pii(Sx,Sy));
	For(i,0,n*m) For(j,0,q[i].size()-1){
		int x=q[i][j].fi,y=q[i][j].se;
		if (dis[x][y]!=i) continue;
		For(d,0,3){
			int nx=x+dx[d],ny=y+dy[d];
			if (nx<1||nx>n||ny<1||ny>m||mp[nx][ny]=='*') continue;
			if (dis[nx][ny]>dis[x][y]+(ny>y)){
				dis[nx][ny]=dis[x][y]+(ny>y);
				q[dis[nx][ny]].push_back(pii(nx,ny));
			} 
		}
	}
	For(i,1,n) For(j,1,m)
		if (dis[i][j]<=ri&&Sy+dis[i][j]-j<=le) ans++;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&Sx,&Sy);
	scanf("%d%d",&le,&ri);
	For(i,1,n) scanf("%s",mp[i]+1);
	work();
	printf("%d\n",ans);
}