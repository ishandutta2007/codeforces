#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010;
const long long Inf=1ll<<50;
int n,m;
long long a[N]={},b[N]={};
void init()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	copy(a+1,a+n+1,b+1);
}
bool check(long long t)
{
	int s=0;
	long long d=0;
	for(int i=n;i>=1;--i)
	{
		long long v=min(a[i],d);
		a[i]-=v,d-=v;
		if(a[i]==0)
			continue;
		long long dt=(a[i]+t-i-1)/(t-i);
		if(s+dt>m)
			return false;
		s+=dt;
		d+=(dt*(t-i)-a[i]);
	}
	return true;
}
void work()
{
	long long l=1,r=Inf;
	for(int i=1;i<=n;++i)
		if(a[i])
			l=i+1;
	while(l!=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
		copy(b+1,b+n+1,a+1);
	}
	cout<<l<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}