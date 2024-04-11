#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
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

const int N=4000005;
ll a[N],b[N],ans;
int q1[N],q2[N],h1,h2,l;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%lld",&a[i]);
	for (int i=1,j;i<=n;i=j+1){
		for (j=i;j<=n&&a[j+1]>a[j];j++);
		if (i==j) continue;
		for (;h1&&a[q1[h1]]>a[i];)
			b[++l]=a[q1[h1--]]-a[q2[h2--]];
		q1[++h1]=i;
		for (;h2&&a[q2[h2]]<a[j];)
			b[++l]=a[q1[h1--]]-a[q2[h2--]];
		q2[++h2]=j; 
	}
	for (;h2;b[++l]=a[q1[h1--]]-a[q2[h2--]]);
	k=min(k,l);
	nth_element(b+1,b+k,b+l+1);
	For(i,1,k) ans-=b[i];
	printf("%lld\n",ans);
}