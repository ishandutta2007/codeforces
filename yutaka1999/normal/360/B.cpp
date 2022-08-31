#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 2005
#define INF 2000000005

using namespace std;
typedef long long int ll;

int in[SIZE];
int dpl[SIZE],dpr[SIZE];
int k,n;

bool ok(ll x)
{
	memset(dpl,0,sizeof(dpl));
	memset(dpr,0,sizeof(dpr));
	for(int i=n-1;i>=0;i--)
	{
		int cnt=0;
		ll l=in[i],r=in[i];
		dpr[i]=SIZE;
		for(int j=i+1;j<n;j++)
		{
			if(l-x<=in[j]&&in[j]<=r+x) dpr[i]=min(dpr[i],dpr[j]+cnt);
			cnt++;
			l-=x;
			r+=x;
		}
		dpr[i]=min(dpr[i],cnt);
	}
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		ll l=in[i],r=in[i];
		dpl[i]=SIZE;
		for(int j=i-1;j>=0;j--)
		{
			if(l-x<=in[j]&&in[j]<=r+x) dpl[i]=min(dpl[i],dpl[j]+cnt);
			cnt++;
			l-=x;
			r+=x;
		}
		dpl[i]=min(dpl[i],cnt);
	}
	for(int i=0;i<n;i++) if(dpl[i]+dpr[i]<=k) return true;
	return false;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	ll s=-1,e=INF;
	while(e-s>1)
	{
		ll med=(s+e)/2;
		if(ok(med)) e=med;
		else s=med;
	}
	printf("%I64d\n",e);
	return 0;
}