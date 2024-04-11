#include<bits/stdc++.h>
#define ll long long
#define gg {printf("0");return 0;}
using namespace std;
int n;
ll w,a[1010];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>w;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll minx=0,maxn=w;
	for(int i=n;i>=1;i--)
	{
		if(a[i]>0)
		{
			maxn-=a[i];
			minx-=a[i];
			if(maxn<0)gg;
			if(minx<0)minx=0;
		}
		else
		{
			maxn-=a[i];
			minx-=a[i];
			if(minx>w)gg;
			if(maxn>w)maxn=w;
		}
	}
	cout<<maxn-minx+1;	
}