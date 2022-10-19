#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k,er,wu;

ll ce(ll m)
{
	ll i=0;
	while(m%2==0)
	{
		m/=2;
		i++;
	}
	return i;
}

ll cw(ll m)
{
	ll i=0;
	while(m%5==0)
	{
		m/=5;
		i++;
	}
	return i;
}

ll pow(ll m,ll cs)
{
	ll i,p;
	p=m;
	for(i=2;i<=cs;i++)
	{
		m*=p;
	}
	return m;
}

int main()
{
	ll i,j,ans=1;
	cin>>n>>k;
	er=ce(n);
	wu=cw(n);
	ans*=pow(2,max(k-er,(ll)0));
	ans*=pow(5,max(k-wu,(ll)0));
	cout<<ans*n;
}