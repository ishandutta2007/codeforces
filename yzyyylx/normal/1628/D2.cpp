#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 1000000
#define N 1001000
#define M 1000000007
using namespace std;

ll T,n,m,K,ans,jc[N],nj[N];

ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
inline void Add(ll &u,ll v){u=(u+v)%M;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline ll C(ll u,ll v){return jc[u]*nj[v]%M*nj[u-v]%M;}
inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}

int main()
{
	ll i,j,k,p,q,a,b,now;
	jc[0]=1;for(i=1;i<=MN;i++) jc[i]=jc[i-1]*i%M;
	nj[MN]=po(jc[MN],M-2);for(i=MN-1;i>=0;i--) nj[i]=nj[i+1]*(i+1)%M;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld%lld%lld",&n,&m,&K);
		for(i=0;i<m;i++) Add(ans,C(n,i)*(m-i)%M);
		printf("%lld\n",ans*po(po(2,n-1),M-2)%M*K%M);
	}
}