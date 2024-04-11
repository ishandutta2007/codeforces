#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

ll n,m,sum;

inline ll ws(ll u)
{
	ll res=0;
	for(;u;u/=10,res++);
	return res;
}

inline ll ds(ll u)
{
	ll res=0;
	for(;u;res*=10,res+=u%10,u/=10);
	return res;
}

inline ll pow(ll u)
{
	ll res=1,now=10;
	for(;u;)
	{
		if(u&1) res*=now;
		now*=now;
		u>>=1;
	}
	return res;
}

inline ll hw(ll u)
{
	return u*pow(ws(u))+ds(u);
}

int main()
{
	ll i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		sum+=hw(i);
		sum%=m;
	}
	cout<<sum;
}