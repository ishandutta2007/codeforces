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
 
#define inf (1ll<<60)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=205;
int n,t,k;
ll a[N],b[N],c[N];
ll sa[N],sb[N];
ll f[N][N][2];
ll g[N][N][2];
int main(){
	scanf("%d%d%d",&n,&t,&k);
	For(i,1,n) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
	++n; a[n]=c[n]=inf;
	For(i,1,n) sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i];
	For(i,1,n) For(j,0,t) For(fl,0,1){
		f[i][j][fl]=g[i][j][fl]=inf;
		if (1ll*j*b[i]+1ll*fl*a[i]<=c[i]&&f[i-1][j][fl]!=inf){
			f[i][j][fl]=f[i-1][j][fl];
			ll v=(1ll*fl*sa[i-1]+1ll*j*sb[i-1]+k-1)/k;
			if (v*k<=1ll*fl*sa[i]+1ll*j*sb[i])
				g[i][j][fl]=v;
		}
		For(l,0,j-1)
			if (g[i][l][fl]<inf){
				ll v1=1ll*fl*sa[i]+1ll*l*sb[i]-1ll*k*g[i][l][fl];
				ll v2=(max(v1+1ll*(j-l)*b[i]-c[i],0ll)+k-1)/k;
				if (1ll*v2*k<=v1&&f[i-1][j-l][0]<inf){
					f[i][j][fl]=min(f[i][j][fl],g[i][l][fl]+v2+f[i-1][j-l][0]);
					ll v=(1ll*(j-l)*sb[i-1]+k-1)/k;
					if (v*k<=(j-l)*sb[i]+v1-v2*k)
						g[i][j][fl]=min(g[i][j][fl],g[i][l][fl]+v2+v);
				}
			}
	}
	printf("%lld\n",f[n][t][1]);
}