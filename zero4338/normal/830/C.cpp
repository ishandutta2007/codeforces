#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
typedef long long ll;
using namespace std;
ll read()
{
	ll ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=105;
const int maxm=4e7;
int n,a[maxn];
ll k;
ll ans;
pair<int,int>tmp[maxm];int cnt;
int main()
{
	n=read();k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	ll sum=0;
	for(int i=1;i<=n;i++)sum+=a[n]-a[i];
	if(sum<=k)
	{
		k-=sum;
		ans=a[n]+k/n;
		printf("%lld",ans);return 0;
	}
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		for(int l=1,r;l<=a[i];l=r+1)
		{
			if((a[i]+l-1)/l-1)r=(a[i]-1)/((a[i]+l-1)/l-1);
			else r=a[i];
			int val=ceil(1.0*a[i]/l);
			tmp[++cnt]=make_pair(l,val);
			if(r!=a[i])tmp[++cnt]=make_pair(r+1,-val);
		}
	}
	ll nd=0;sort(tmp+1,tmp+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		nd+=tmp[i].second;if(tmp[i].first==tmp[i+1].first)continue;
		ll val=(k+sum)/nd;
		if(val>=tmp[i].first)ans=max(ans,val);
	}
	printf("%lld",ans);
	return 0;
}