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

#define INF (1ll<<61)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005;
int n,x[N],y[N];
int X[N],Y[N],cnt[2][2];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		X[i]=x[i]; Y[i]=y[i];
	}
	sort(X+1,X+n+1);
	sort(Y+1,Y+n+1);
	int m=(n+1)/2,cx=X[m],cy=Y[m];
	int dx=X[m+1]-X[m],dy=Y[m+1]-Y[m];
	if (n&1){
		dx=min(dx,X[m]-X[m-1]);
		dy=min(dy,Y[m]-Y[m-1]);
	}
	ll ans=0; bool fl=0;
	For(i,1,n){
		ans+=abs(x[i]-cx)+abs(y[i]-cy);
		++cnt[x[i]<=cx][y[i]<=cy];
		if (x[i]==cx&&y[i]==cy) fl=1; 
	}
	if (cnt[0][0]&&cnt[0][1])
		if ((n%2==0)||fl) ans-=min(dx,dy);
	printf("%lld\n",ans*2);
}