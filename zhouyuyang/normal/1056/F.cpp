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
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
double f[105][1005];
double P[105],c,T;
pii a[105];
int n;
void solve(){
	int m=0; P[0]=1;
	scanf("%d%lf%lf",&n,&c,&T);
	For(i,1,n){
		scanf("%d%d",&a[i].fi,&a[i].se);
		m+=a[i].se; P[i]=P[i-1]*0.9;
	}
	sort(a+1,a+n+1,greater<pii>());
	For(i,0,n) For(j,0,m) f[i][j]=inf;
	f[0][0]=0;
	For(i,1,n) Rep(j,n,1) For(k,a[i].se,m)
		f[j][k]=min(f[j][k],f[j-1][k-a[i].se]+a[i].fi/P[j]);
	int ans=0;
	For(i,1,n) For(j,1,m) if (f[i][j]!=inf){
		double s=max(sqrt(f[i][j]/c),1/c);
		if (f[i][j]/c/s+s-1/c+10*i<=T) ans=max(ans,j);
	}
	printf("%d\n",ans);
	//f[i][j]/S<=C*S
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}