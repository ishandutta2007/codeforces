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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)%s
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
const int N=605;
double a[N][N],val[N][N],c[N][N],e[N][N];
int n,nd,m,k,fl[N],be[N],deg[N];
void mul1(){
	For(i,1,nd) For(j,1,nd) e[i][j]=0;
	For(i,1,nd) For(j,1,nd) For(k,1,nd)
		e[i][j]+=c[i][k]*val[k][j];
	For(i,1,nd) For(j,1,nd) c[i][j]=e[i][j];
}
void mul2(){
	For(i,1,nd) For(j,1,nd) e[i][j]=0;
	For(i,1,nd) For(j,1,nd) For(k,1,nd)
		e[i][j]+=val[i][k]*val[k][j];
	For(i,1,nd) For(j,1,nd) val[i][j]=e[i][j];
}
void solve(){
	For(i,1,n) if (fl[i])
		For(j,n+1,nd) val[be[i]-n][j-n]=-a[i][j];
	nd-=n; k-=2;
	For(i,1,nd) c[i][i]=1;
	for (;k;k>>=1,mul2())
		if (k&1) mul1();
	double ans=0;
	For(i,n+1,n+nd) ans-=c[i-n][nd]*a[1][i];
	printf("%.15lf\n",ans);
}
int main(){
	scanf("%d%d%d",&n,&m,&k); nd=n;
	For(i,1,n){
		scanf("%d",&fl[i]);
		if (fl[i]) be[i]=++nd;
	}
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		deg[x]++; deg[y]++;
		a[x][fl[y]?be[y]:y]++;
		a[y][fl[x]?be[x]:x]++;
	}
	For(i,1,n) For(j,1,nd) a[i][j]/=deg[i];
	For(i,1,n) a[i][i]=-1;
	For(i,1,n){
		if (!a[i][i])
			For(j,i+1,n) if (a[j][i]!=0){
				For(k,1,nd) swap(a[j][k],a[i][k]);
				break;
			}
		double tmp=a[i][i];
		For(j,1,nd) a[i][j]/=tmp;
		For(j,1,n) if (i!=j&&a[j][i]!=0)
			Rep(k,nd,i) a[j][k]-=a[j][i]*a[i][k];
	}
	solve();
}