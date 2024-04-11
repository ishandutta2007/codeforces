#include<iostream>
#include<cstdio>
#define INF 0x3f3f3f3f
#define N 100100
#define ll long long
using namespace std;

ll n,l,r,num[N],a,b,mn,mx;
char str[N];

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
	{
		if(str[i]=='0')
		{
			a++;
			if(b>=4)
			{
				mn=INF;
				for(j=i-4;j<=i;j++)
				{
					mn=min(mn,num[j]);
				}
				if(r>=mn) r=mn-1;
				if(l>r) l=r;
			}
			b=0;
		}
		if(str[i]=='1')
		{
			b++;
			if(a>=4)
			{
				mx=-INF;
				for(j=i-4;j<=i;j++)
				{
					mx=max(mx,num[j]);
				}
				if(l<=mx) l=mx+1;
				if(r<l) r=l;
			}
			a=0;
		}
		if(a>=5)
		{
			mx=-INF;
			for(j=i-4;j<=i;j++)
			{
				mx=max(mx,num[j]);
			}
			if(l>mx) l=mx;
			if(r<l) r=l;
		}
		if(b>=5)
		{
			mn=INF;
			for(j=i-4;j<=i;j++)
			{
				mn=min(mn,num[j]);
			}
			if(r<mn) r=mn;
			if(l>r) l=r;
		}
	}
	cout<<l<<" "<<r;
}