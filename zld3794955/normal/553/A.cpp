#include<bits/stdc++.h>
using namespace std;
const int N=1010,mod=1000000007;
int n,a[N]={};
long long d[N]={1},red[N]={},ans=1;
long long power(long long x,long long y)
{
	long long t=1;
	for(; y; y>>=1,x=x*x%mod)
		if(y&1) t=t*x%mod;
	return t;
}
long long C(int a,int b)
{
	return d[a]*red[b]%mod*red[a-b]%mod;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int s=accumulate(a+1,a+n+1,0);
	for(int i=1;i<=s;++i)
		d[i]=d[i-1]*i%mod;
	red[s]=power(d[s],mod-2);
	for(int i=s-1;i>=0;--i)
		red[i]=red[i+1]*(i+1)%mod;
	int m=0;
	for(int i=1;i<=n;++i)
		ans=ans*C(m+a[i]-1,m)%mod,m+=a[i];
	cout<<ans<<endl;
	return 0;
}