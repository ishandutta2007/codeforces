#include<iostream>
#include<cstdio>
#define ll long long
#define N 5010
#define M 998244353
using namespace std;

ll a,b,c,jc[N];

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

inline ll zh(ll u,ll v)
{
	return jc[u]*po(jc[v]*jc[u-v]%M,M-2)%M;
}

inline ll ask(ll u,ll v)
{
	ll i,j,res=1;
	if(u>v) swap(u,v);
	for(i=1;i<=u;i++)
	{
		res=(res+zh(u,i)*zh(v,i)%M*jc[i]%M)%M;
	}
	return res;
}

int main()
{
	ll i,j;
	jc[0]=1;
	for(i=1;i<=5000;i++) jc[i]=jc[i-1]*i%M;
	cin>>a>>b>>c;
	cout<<ask(a,b)*ask(a,c)%M*ask(b,c)%M;
}