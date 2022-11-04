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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=200005;
int n,p,x[N],c[N];
ll t,a[N],b[N];
int main(){
	scanf("%d%lld",&n,&t);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n){
		scanf("%d",&x[i]);
		if (x[i]<i) return puts("No"),0;
		c[i]++; c[x[i]]--;
	}
	For(i,1,n)
		if (p+=c[i]) b[i]=a[i+1]+t;
		else b[i]=max(b[i-1]+1,a[i]+t);
	For(i,1,n)
		if (x[i]+1<=n&&a[x[i]+1]+t<=b[x[i]])
			return puts("No"),0;
	puts("Yes");
	For(i,1,n) printf("%lld ",b[i]);
}