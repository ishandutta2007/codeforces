#include<bits/stdc++.h>
using namespace std;
#define N 1000005
long long sum[N],ss[N],P;
#define ll long long
long long A[N],a[N],n;
struct node {
	int v,x;
}q[N];
inline int gcd(int x,int y) {
	if (x%y==0) return y;
	return gcd(y,x%y);
}
long long S(long long k) {
    return (k*(k+1)/2ll);
}
ll solve(ll a, ll b, ll c, ll n) {
	if (a == 0) return ((b / c) * (n + 1));
	if (a >= c || b >= c) return solve(a % c, b % c, c, n) + (a / c) * n * (n + 1)
	/ 2 + (b / c) * (n + 1);
	ll m = (a * n + b) / c;
	ll v = solve(c, c - b - 1, a, m - 1);
	return n * m - v;
}
ll fd(ll a, ll b, ll c, ll n) {
	if (b < 0) {
		ll x = (-b + a - 1) / a;
		if (x >= 0) {
			n -= x;
			b += x * a;
		}
	}
	if (n < 0) return 0;
	return solve(a, b, c, n);
}
ll f(ll a, ll b, ll c, ll n, int offset) {
	if (n < 0) return 0;
	if (c < 0) {
		c = -c;
		a = -a;
		b = -b;
	}
	if (a >= 0) return fd(a, b + offset, c, n);
	return fd(-a, b + a * n + offset, c, n);
}
long long get(long long x) {
	return x*(x+1)/2;
}
inline long long work(long long l,long long r,long long d) {
	if (r<=d) return (r+l)*(r-l+1)/2;
	if (l>=d) return (r-l+1)*d;
	return d*(r-d)+(l+d)*(d-l+1)/2;
}
inline bool check(long long x) {
	x--;
	long long j=1,d=0,ans=0;
	for (int i=1;i<=1000000;i++) {
		long long s=1;
		if (!A[i]) continue;
		if (sum[i]<=x) ans+=A[i]*ss[i-1]+get(A[i]);
		else {
			while (s<=A[i]) {
				while (j<i&&s<=A[i]) {
					if (sum[i-1]-sum[j]+i*s>x) j++;
					else {
						long long pp=(x-sum[i-1]+sum[j])/i;
						pp=min(pp,1ll*A[i]);
						long long s1=pp+1;
						ans+=f(-i,x-sum[i-1]+sum[j]-i*(s),j,s1-s-1,0);
						ans-=f(-i,x-sum[i-1]+sum[j]-i*(s)-(A[j])*j,j,s1-s-1,0);
						ans+=1ll*(s1-s)*(ss[i-1]-ss[j]);
						ans+=1ll*(s+s1-1)*(s1-s)/2;
						s=s1;
						if (s<=A[i]) j++;
					}
				}
				if (j==i) {
					long long y=x/i;
					ans+=work(s,A[i],y);
					s=A[i]+1;
				}
			}
		}
		if (ans>=P) return false;
	}
	return true;
}
int main() {
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int r=0;
	for (int i=1;i<=n;i++) {
		q[++r].v=a[i];
		q[r].x=i;
		for (int j=1;j<=r;j++) q[j].v=gcd(q[j].v,a[i]);
		for (int j=2;j<=r;j++) if (q[j].v==q[j-1].v) q[j].x=0;
		int t=0;
		for (int j=1;j<=r;j++) if (q[j].x) q[++t]=q[j];
		r=t;
		q[r+1].x=i+1;
		for (int j=1;j<=r;j++) A[q[j].v]+=q[j+1].x-q[j].x;
		q[r+1].x=0;
	}
	for (int i=1;i<=1000000;i++) ss[i]=ss[i-1]+A[i],sum[i]=sum[i-1]+1ll*A[i]*i;
	P=1ll*n*(n+1)/2;
	P=1ll*P*(P+1)/2;
	P=(P+1)/2;
	long long l=0,rr=1000000000000000000ll,ans=0;
	while (l<=rr) {
		long long mid=(l+rr)>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else rr=mid-1;
	}
	printf("%lld\n",ans);
}