#include<iostream>
#include<cstdio>
#define ll long long
#define N 100100
using namespace std;

ll num[N],qz[N],n,ans,M;

int main()
{
	ll i,j,p,q;
	cin>>n>>M;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		qz[i]=qz[i-1]+num[i];
	}
	for(i=1;i<n;i++)
	{
		ans=max(qz[i]%M+(qz[n]-qz[i])%M,ans);
	}
	cout<<ans;
}