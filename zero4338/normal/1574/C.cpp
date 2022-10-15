#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll read()
{
	ll ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=2e5+5;
int n,m;
ll a[maxn],sum;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)sum+=(a[i]=read());sort(a+1,a+n+1);
	m=read();
	for(int i=1;i<=m;i++)
	{
		ll x=read(),y=read();
		if(x<a[1])printf("%lld\n",max(0ll,y-sum+a[1]));
		else if(x>a[n])printf("%lld\n",x-a[n]+max(0ll,y-sum+a[n]));
		else
		{
			int it=lower_bound(a+1,a+n+1,x)-a;
			ll ans1=max(0ll,y-sum+a[it]),ans2=x-a[it-1]+max(0ll,y-sum+a[it-1]);
			printf("%lld\n",min(ans1,ans2));
		}
	}
	return 0;
}