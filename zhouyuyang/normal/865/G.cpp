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
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int mo=1000000007;
const int N=255;
int n,m,p[15],c[105];
int f[N],a[N],b[N],d[N];
int X[N],Y[N],Z[N*2];
long long T;
void mult(int *A,int *B){
	CPY(X,A); CPY(Y,B); CLR(Z,0);
	For(i,0,N-1) For(j,0,N-1)
		Z[i+j]=(Z[i+j]+1ll*X[i]*Y[j])%mo;
	Rep(i,N*2-1,N) if (Z[i]){
		int t=Z[i]; Z[i]=0;
		For(j,0,m-1) Z[i-c[j]]=(Z[i-c[j]]+t)%mo;
	}
	memcpy(A,Z,N<<2);
}
void power(ll t){
	if (t==1){
		CPY(d,b);
		return;
	}
	power(t/2); mult(d,d);
	if (t&1) mult(d,b);
}
int main(){
	scanf("%d%d%lld",&n,&m,&T);
	For(i,0,n-1) scanf("%d",&p[i]);
	For(i,0,m-1) scanf("%d",&c[i]);
	f[0]=1;
	For(i,1,N-1) For(j,0,m-1)
		if (c[j]<=i) f[i]=(f[i]+f[i-c[j]])%mo;
	For(i,0,n-1){
		CLR(b,0); b[1]=1; power(p[i]);
		For(j,0,N-1) a[j]=(a[j]+d[j])%mo;
	}
	CPY(b,a); power(T);
	int ans=0;
	For(i,0,N-1) ans=(ans+1ll*f[i]*d[i])%mo;
	printf("%d",ans);
}