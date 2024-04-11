#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5e5+10;
int n;
long long v[maxn];
long long ans;
int read()
{
	int ret=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-f;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=(ret<<3)+(ret<<1)+c-'0';
		c=getchar();
	}
	return ret*f;
}
long long maxnum,minnum;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)v[i]=read();
	if(n==1)
	{
		printf("%lld",v[1]);return 0;
	}
	maxnum=-2e9;minnum=2e9;
	for(int i=1;i<=n;i++)
	{
		if(v[i]<0)ans=ans-v[i];
		else ans=ans+v[i];
		maxnum=max(maxnum,v[i]);
		minnum=min(minnum,v[i]);
	}
	if(maxnum<0)ans=ans+2ll*maxnum;
	if(minnum>0)ans=ans-2ll*minnum;
	printf("%lld",ans);
	return 0;
}