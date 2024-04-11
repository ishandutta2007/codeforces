#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 2010
#define M 1000000007
using namespace std;

ll m,n,k,dp[N],jc[200100];
P num[N];

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

inline ll C(ll u,ll v){return jc[u]*po(jc[v],M-2)%M*po(jc[u-v],M-2)%M;}
inline ll ask(P u,P v){if(u.fi>v.fi || u.se>v.se) return 0;return C(v.fi+v.se-u.fi-u.se,v.fi-u.fi);}

int main()
{
	ll i,j,p,q;
	cin>>m>>n>>k;
	jc[0]=1;for(i=1;i<=200000;i++) jc[i]=jc[i-1]*i%M;
	for(i=1;i<=k;i++)
	{
		scanf("%lld%lld",&p,&q);
		if(p==q&&q==1 || p==m&&q==n)
		{
			puts("0");
			return 0;
		}
		num[i]=mp(p,q);
	}
	k++;
	num[k]=mp(m,n);
	sort(num+1,num+k+1);
	
	for(i=1;i<=k;i++)
	{
		dp[i]=ask(mp(1,1),num[i]);
		for(j=1;j<i;j++)
		{
			dp[i]=(dp[i]-dp[j]*ask(num[j],num[i])%M+M)%M;
		}
	}
	cout<<dp[k];
}