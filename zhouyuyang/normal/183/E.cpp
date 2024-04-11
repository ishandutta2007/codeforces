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
#define SUB(i,j) for (int all=(int)(j+2147483648ll),i=(int)(j);i>=0;i=(i-1)&j) 
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<30)
using namespace std;
int n,m;
ll a[200005];
ll calc(ll mn,ll mx,ll c){
	mx=min(mx,a[n]);
	Rep(i,n-1,1) mx=min(mx,a[i]-i*c+m);
	ll ans=0,x=mx;
	Rep(i,n,1){
		if (i!=n) x-=c;
		x=min(x,a[i]);
		if (x<mn||mx-x>m-c) return -1;
		ans+=x;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%I64d",&a[i]);
	ll ans=0;
	For(c,1,m/n){
		ll tri=1ll*c*(c-1)/2*n;
		ll mn=tri+c,mx=1ll*m*c-tri;
		ll mndif=c,mxdif=m-c;
		ans=max(ans,calc(mn,mx,c));
	}
	printf("%lld\n",ans);
}