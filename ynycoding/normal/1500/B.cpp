#include <cstdio>
#include <algorithm>
#define ll long long
const int N=500005;
int n, m, d, a[N], id[N], rid[N<<2], b[N], vis[N], isvis[N], cnt[N<<2], len, ivnm, ivmn;
ll pos[N];
ll k;
void exgcd(int a, int b, int &x, int &y)
{
	if(!b) { x=1, y=0; return; }
	exgcd(b, a%b, y, x), y-=(a/b)*x;
}
inline int inv(int a, int b)
{
	int x, y;
	exgcd(a, b, x, y);
	return (x%b+b)%b;
}
int main()
{
	scanf("%d%d%lld", &n, &m, &k);
	for(int i=0; i<n; ++i) scanf("%d", a+i);
	for(int i=0; i<m; ++i) scanf("%d", b+i), rid[b[i]]=i+1;
	d=std::__gcd(n, m);
	ivnm=inv(m/d, n/d), ivmn=inv(n/d, m/d);
	ll M=(1ll*n*m/d), M1=M/d;
	for(int i=0; i<n; ++i) if(rid[a[i]]&&(rid[a[i]]-1)%d==i%d)
	{
		id[i]=rid[a[i]];
		int u=i/d, v=(id[i]-1)/d;
		pos[i]=(1ll*u*m/d%M*ivnm+1ll*v*n/d%M*ivmn)%M1*d+(i%d);
	}
	ll l=0, r=1ll*std::max(n, m)*k;
	while(l<r)
	{
		ll mid=(l+r+1)>>1;
		ll t=mid/M, res=mid%M;
		ll cur=mid;
//		printf("rest %d %d\n", t, res);
		for(int i=0; i<n; ++i) if(id[i])
		{
			cur-=t;
			cur-=pos[i]<res;
		}
		if(cur<k) l=mid;
		else r=mid-1;
	}
	printf("%lld\n", l+1);
	return 0;
}