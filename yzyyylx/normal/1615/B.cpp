#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define N 100100
#define M
using namespace std;

ll T,n,m,sum,ans,L,R,num[N];

inline ll calc(ll u,ll v)
{
	ll res=0;
	if(u&(1 << v))
	{
		res=u%(1 << v)+1;
		res+=u/(1 << v)/2*(1 << v);
	}
	else
	{
		res+=u/(1 << v)/2*(1 << v);
	}
	return res;
}

int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&L,&R);
		for(i=0;i<=20;i++) ans=max(ans,calc(R,i)-calc(L-1,i));
		printf("%lld\n",R-L+1-ans);
	}
}