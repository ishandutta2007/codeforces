#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500100
#define ll long long
using namespace std;

ll n,m,k,num[N],qz[N],l,r,mid,cf[N],tmp[N];

inline bool check(ll u)
{
	memcpy(tmp,cf,sizeof(cf));
	ll i,last=k,now=0,t;
	for(i=1;i<=n;i++)
	{
		now+=tmp[i];
		if(now<u)
		{
			t=u-now;
			if(last<t) return 0;
			last-=t;
			tmp[min(n+1,i+2*m+1)]-=t;
			now=u;
		}
	}
	return 1;
}

int main()
{
	ll i,j;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		qz[i]=qz[i-1]+num[i];
	}
	for(i=1;i<=n;i++)
	{
		num[i]=qz[min(i+m,n)]-qz[max(i-m,1ll)-1];
		cf[i]=num[i]-num[i-1];
	}
	for(l=0,r=4e18;l<r;)
	{
		mid=((l+r)>>1);
		check(mid)?l=mid+1:r=mid;
	}
	cout<<l-1;
}