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
int n,ans;
int x[300005];
int y[300005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	int mnx=x[1],mxx=x[1],mny=y[1],mxy=y[1];
	For(i,2,n){
		mnx=min(mnx,x[i]); mxx=max(mxx,x[i]);
		mny=min(mny,y[i]); mxy=max(mxy,y[i]);
	}
	For(i,1,n)
		ans=max(ans,max(x[i]-mnx,mxx-x[i])+max(y[i]-mny,mxy-y[i]));
	printf("%d ",ans*2);
	For(i,4,n) printf("%d ",(mxx-mnx+mxy-mny)*2);
}