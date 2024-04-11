#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 5010
#define M 20010
using namespace std;

ll n,m,cnt[M],mn[M],mx;

inline ll calc(ll u)
{
	ll i,j,res=(mx-1)*n,t=0;
	for(i=u,j=0;;i=i%n+1,j++)
	{
		if(cnt[i] && cnt[i]==mx) t=max(t,mn[i]+j);
		if(cnt[i] && cnt[i]==mx-1) t=max(t,mn[i]+j-n);
		if(i==u-1 || i==n&&u==1) break;
	}
	return res+t;
}

int main()
{
	memset(mn,0x3f,sizeof(mn));
	ll i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		cnt[p]++;
		if(q<p) q+=n;
		mn[p]=min(mn[p],q-p);
	}
	for(i=1;i<=n;i++) mx=max(mx,cnt[i]);
	for(i=1;i<=n;i++)
	{
		printf("%lld ",calc(i));
	}
}