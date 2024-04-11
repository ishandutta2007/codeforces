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
int n,ans;
const int N=15000005;
int a[N],b[300005];
bool fl[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void sieve(){
	For(i,2,N-1) if (!fl[i])
		For(j,2,(N-1)/i) fl[i*j]=1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&b[i]);
	int G=b[1]; sieve();
	For(i,2,n) G=gcd(G,b[i]);
	For(i,1,n) a[b[i]/G]++;
	Rep(i,N-1,2) if (!fl[i]) {
		int v=(N-1)/i;
		For(j,2,v) a[i]+=a[i*j];
		ans=max(ans,a[i]);
	}
	printf("%d\n",ans==0?-1:n-ans);
}