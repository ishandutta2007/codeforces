#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
using namespace std;

ll n,m,t,ans;

int main()
{
	ll i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		if(!p) ans+=t;
		t+=p;
	}
	cout<<ans;
}