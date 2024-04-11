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
char s[N][N];
int d[N][N];
bool vis[N][N];
int n,k,mx;
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%s",s[i]+1);
	CLR(d,10); d[1][0]=0;
	For(i,1,n) For(j,1,n)
		d[i][j]=min(d[i-1][j],d[i][j-1])+(s[i][j]=='a'?0:1);
	For(i,0,n) For(j,0,n)
		if (d[i][j]<=k) mx=max(mx,i+j);
	For(i,0,n) For(j,0,n) vis[i][j]=(d[i][j]<=k);
	For(i,2,mx) putchar('a');
	For(i,mx+1,2*n)
		if (i<=n+1){
			int x=1,y=i-1; char mn='z';
			for (;y;x++,y--){
				vis[x][y]=vis[x-1][y]|vis[x][y-1];
				if (vis[x][y]) mn=min(mn,s[x][y]);
			}
			x=1,y=i-1;
			for (;y;x++,y--)
				vis[x][y]&=(s[x][y]==mn);
			putchar(mn);
		}
		else{
			int x=i-n,y=n; char mn='z';
			for (;x<=n;x++,y--){
				vis[x][y]=vis[x-1][y]|vis[x][y-1];
				if (vis[x][y]) mn=min(mn,s[x][y]);
			}
			x=i-n,y=n;
			for (;x<=n;x++,y--)
				vis[x][y]&=(s[x][y]==mn);
			putchar(mn);
		}
}