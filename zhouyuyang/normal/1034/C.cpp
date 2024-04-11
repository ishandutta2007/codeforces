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
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=1000005;
const int mo=1000000007;
ll sz[N];
int fa[N],f[N];
int g[N],n;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&sz[i]);
	For(i,2,n) scanf("%d",&fa[i]);
	Rep(i,n,2) sz[fa[i]]+=sz[i];
	For(i,1,n){
		ll v=sz[1]/gcd(sz[1],sz[i]);
		if (v<=n) g[v]++;
	}
	Rep(i,n,1) For(j,2,n/i) g[i*j]+=g[i];
	Rep(i,n,1) if (g[i]>=i){
		f[i]=1;
		For(j,2,n/i) f[i]=(f[i]+f[i*j])%mo;
	}
	printf("%d",f[1]);
}