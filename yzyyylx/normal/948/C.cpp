#include<iostream>
#include<cstdio>
#define ll long long
#define N 100100
using namespace std;

ll n,num[N],qz[N],cf[N],ans[N],t[N];

int main()
{
	ll i,j,p,q,l,r,mid;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&p);
		t[i]=p;
		qz[i]=qz[i-1]+p;
	}
	qz[n+1]=1e18;
	for(i=1;i<=n;i++)
	{
		p=num[i]+qz[i-1];
		for(l=i-1,r=n+1;l<r;)
		{
			mid=((l+r)>>1);
			if(p>=qz[mid])
			{
				l=mid+1;
			}
			else r=mid;
		}
		ans[l]+=p-qz[l-1];
		cf[i]++,cf[l]--;
	}
	p=0;
	for(i=1;i<=n;i++)
	{
		p+=cf[i];
		printf("%lld ",ans[i]+p*t[i]);
	}
}