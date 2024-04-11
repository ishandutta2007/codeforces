#include<iostream>
#include<cstdio>
#define N 1010
#define ll long long
using namespace std;

ll n,m,c[50],ans,tmp,an;

inline ll cnt(ll u)
{
	ll res=0;
	for(;u;u>>=1) res+=(u&1);
	return res;
}

int main()
{
	register ll i,j;
	cin>>n>>m;
	tmp=m;
	for(i=0; i<n; i++)
	{
		scanf("%lld",&c[i]);
		if(i) c[i]=min(c[i],c[i-1]*2);
	}
	for(i=n; i<=32; i++) c[i]=c[i-1]*2;
	for(i=32; i>0; i--) c[i-1]=min(c[i],c[i-1]);
	ans=0x3f3f3f3f3f3f3f3f;
	for(;cnt(m)!=1; m+=m&(-m))
	{
		an=0;
		for(i=32; i>=0; i--)
		{
			if(m&((ll)1 << i))
			{
				an+=c[i];
			}
		}
		ans=min(an,ans);
	}
	for(i=32; ((ll)1 << i)>=tmp; i--) ans=min(ans,c[i]);
	cout<<ans<<endl;
}