#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[200005];
ll k;
ll add(ll x,ll y){
	return min(k,x+y);
}
ll mul(ll x,ll y){
	if (!x||!y) return 0;
	if (k/x<y) return k;
	return min(x*y,k);
}
struct Mat{
	ll a[12][12];
	Mat(){
		memset(a,0,sizeof(a));
	}
	friend Mat operator *(Mat a,Mat b){
		Mat c;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				for (int k=1;k<=n;k++)
					c.a[i][j]=add(c.a[i][j],mul(a.a[i][k],b.a[k][j]));
		return c;
	}
	friend Mat operator ^(Mat a,ll b){
		Mat c;
		for (int i=1;i<=n;i++)
			c.a[i][i]=1;
		for (;b;b/=2,a=a*a)
			if (b&1) c=c*a;
		return c;
	}
}b,c,d;
int main(){
	scanf("%d%lld",&n,&k);
	int nn=0,tg=0;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		tg|=(x!=0);
		if (tg) a[++nn]=x;
	}
	n=nn;
	if (n>10){
		for (int i=0;;i++){
			for (int j=1;j<=n;j++)
				if (a[j]==k)
					return printf("%d",i),0;
			for (int j=1;j<=n;j++)
				a[j]=add(a[j],a[j-1]);
		}
	}
	for (int i=1;i<=n;i++)
		b.a[1][i]=a[i];
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)	
			c.a[i][j]=1;
	ll l=0,r=k+233,ans,mid;
	while (l<=r){
		ll mid=(l+r)/2;
		d=b*(c^mid);
		if (d.a[1][n]==k)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld",ans);
}