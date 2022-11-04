#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define ldb long double
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
const int N=200005;
ll a[N],b[N],c[N];
int n,ans;
ll G,all;
map<ll,ll> mp1,mp2;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		mp1[a[i]]+=c[i]; mp2[b[i]]+=c[i];
		all+=c[i]; G=gcd(G,c[i]); 
	}
	For(i,1,n)
		if (fabs((ldb)mp1[a[i]]/all-(ldb)c[i]/(ldb)(mp2[b[i]]))>1e-15)
			return puts("0"),0;
	for (ll i=1;i*i<=G;i++)
		if (G%i==0) ans+=1+(i*i!=G);
	printf("%d",ans);
}