#include<bits/stdc++.h>
using namespace std;
const int N=2020,Inf=0x7fffffff;
int n,k,f[N]={};
long long a[N]={};
void init()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
}
bool check(long long mid)
{
	for(int i=1;i<=n;++i)
	{
		f[i]=i-1;
		for(int j=1;j<i;++j)
		{
			long long d=max(a[i],a[j])-min(a[i],a[j]);
			if(d<=(i-j)*mid)
				f[i]=min(f[j]+i-j-1,f[i]);
		}
	}
	int x=n;
	for(int i=1;i<=n;++i)
		x=min(x,f[i]+n-i);
	return x<=k;
}
void work()
{
	long long l=0,r=Inf;
	while(l!=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}