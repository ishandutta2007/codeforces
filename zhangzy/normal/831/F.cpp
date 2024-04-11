#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
ll n,k,ans=1,a[233];

bool C(ll x)
{
	ll sum=0;
	for (ll i=1;i<=n;i++)
		sum+=(a[i]-1)/x+1;
	return sum*x<=k;
}

int main()
{
	cin>>n>>k;
	for (ll i=1;i<=n;i++)
	{
		cin>>a[i];
		k+=a[i];
	}
	for (ll i=sqrt(k);i>0;i--)
	{
		if (C(i)) ans=max(ans,i);
		if (C(k/i)) ans=max(ans,k/i);
	}
	cout<<ans;
}