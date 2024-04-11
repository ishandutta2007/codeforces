#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 500100
#define M 998244353
using namespace std;

ll n,ds[N],qz[N],suf[N],tot,x,y;

inline bool cmp(ll u,ll v){return u>v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void GG()
{
	puts("-1");
	exit(0);
}

int main()
{
	ll i,j,id,now;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&ds[i]),tot+=ds[i];
	sort(ds+1,ds+n+1,cmp);
	for(i=1;i<=n;i++) qz[i]=qz[i-1]+ds[i];
	for(i=n;i>=1;i--) suf[i]=suf[i+1]+ds[i];
	for(i=n;i>=1;i--)
	{
		id=lower_bound(ds+i+1,ds+n+1,i,greater<ll>())-ds;
		now=i*(i-1)+(id-i-1)*i+suf[id];
		if(qz[i]-now>i) GG();
		Max(x,qz[i]-now);
	}
	x+=(tot&1)^(x&1);
	for(i=1; i<=n; i++) tot+=n-2*ds[i],ds[i]=n-ds[i];
	reverse(ds+1,ds+n+1);
	for(i=1;i<=n;i++) qz[i]=qz[i-1]+ds[i];
	for(i=n;i>=1;i--) suf[i]=suf[i+1]+ds[i];
	for(i=n;i>=1;i--)
	{
		id=lower_bound(ds+i+1,ds+n+1,i,greater<ll>())-ds;
		now=i*(i-1)+(id-i-1)*i+suf[id];
		if(qz[i]-now>i) GG();
		y=max(y,qz[i]-now);
	}
	y+=((tot&1))^(y&1),y=n-y;
	for(i=min(x,y);i<=max(x,y)&&i<=n;i+=2) printf("%lld ",i);
	puts("");
}