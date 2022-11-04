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

const int mo=1051131;
const int inv2=(mo+1)/2;
ll T;
int a[(1<<25)+1],n,S;
int power(int x,ll y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void dfs(int n,int p,int q){
	if (n==1){
		a[1]=1ll*a[1]*power(p+q,T)%mo;
		return;
	}
	n/=2;
	For(i,1,n){
		int x=a[i],y=a[i+n];
		a[i]=(x+y)%mo,a[i+n]=(x-y+mo)%mo;
	}
	dfs(n,2*p%mo,(1ll*(n-1)*p+q)%mo);
	int val=power((q-1ll*(n-1)*p%mo+mo)%mo,T);
	For(i,1,n){
		int x=a[i],y=1ll*a[i+n]*val%mo;
		a[i]=1ll*(x+y)*inv2%mo;
		a[i+n]=1ll*(x-y+mo)*inv2%mo;
	}
}
int main(){
	scanf("%d%lld%d",&n,&T,&S); n=1<<n;
	For(i,1,S) scanf("%d",&a[i]);
	For(i,S+1,n) a[i]=(a[i-S]*101+10007)%mo;
	dfs(n,1,0); int ans=0;
	For(i,1,n) ans^=a[i];
	printf("%d\n",ans);
}