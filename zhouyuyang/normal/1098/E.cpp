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
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
ll F(ll a,ll b,ll c,ll n){
	if (a==0) return (b/c)*(n+1);
	if (a>=c||b>=c) return F(a%c,b%c,c,n)+(a/c)*n*(n+1)/2+(b/c)*(n+1);
	return (a*n+b)/c*n-F(c,c-b-1,a,(a*n+b)/c-1);
}
ll f(ll a,ll b,ll c,ll n){
	if (c<0) a=-a,b=-b,c=-c;
	if (a<=0) b+=a*n,a=-a;
	if (b<0){
		ll x=(a-b-1)/a;
		if (x>=0) n-=x,b+=x*a;
	}
	if (n<0) return 0;
	return F(a,b,c,n);
}
const int N=100005;
//sigma[(ax+b)/c],0<=x<=n 
ll a[N],A[N],S[N];
ll work(ll l,ll r,ll d){
	if (r<=d) return (r+l)*(r-l+1)/2;
	if (l>=d) return (r-l+1)*d;
	return d*(r-d)+(l+d)*(d-l+1)/2;
}
ll check(ll mid){
	mid--;
	ll j=1,ans=0;
	For(i,1,N-1) if (a[i])
		if (S[i]<=mid)
			ans+=1ll*a[i]*A[i-1]+1ll*a[i]*(a[i]+1)/2;
		else{
			ll s=1;
			for (;j<i&&s<=a[i];)
				if (S[i-1]-S[j]+i*s>mid) j++;
				else{
					ll s1=min((mid-S[i-1]+S[j])/i,1ll*a[i])+1;
					ans+=f(-i,mid-S[i-1]+S[j]-i*s,j,s1-s-1);
					ans-=f(-i,mid-S[i-1]+S[j]-i*s-a[j]*j,j,s1-s-1);
					ans+=1ll*(s1-s)*(A[i-1]-A[j]);
					ans+=1ll*(s+s1-1)*(s1-s)/2;
					if ((s=s1)<=a[i]) j++;
				}
			if (j==i) ans+=work(s,a[i],mid/i);
		}
	//printf("%lld %lld\n",mid,ans);
	return ans;
}

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int n,tp;
pii q[50];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x; scanf("%d",&x);
		q[++tp]=pii(x,i);
		Rep(j,tp-1,1)
			q[j].fi=gcd(q[j].fi,x);
		int tmp=1;
		For(j,2,tp)
			if (q[j].fi!=q[j-1].fi)
				q[++tmp]=q[j];
		tp=tmp;
		For(j,1,tp)
			a[q[j].fi]+=(j==tp?i+1:q[j+1].se)-q[j].se;
	}
	For(i,1,N-1){
		A[i]=A[i-1]+a[i];
		S[i]=S[i-1]+1ll*a[i]*i;
	}
	ll P=1ll*n*(n+1)/2;
	P=P*(P+1)/2;
	P=(P+1)/2;
	ll l=1,r=S[N-1],ans=0;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)<P)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",ans);
}