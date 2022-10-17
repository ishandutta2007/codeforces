#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define N 100100
using namespace std;

ll n,num[N],sum,ans,a,b;

int main()
{
	ll i,j;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
	}
	sort(num+2,num+n+1);
	for(i=n;sum*b>num[1]*a;i--)
	{
		sum-=num[i];
	}
	cout<<n-i;
}