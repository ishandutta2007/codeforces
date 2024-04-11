#include<stdio.h>
#define P 1000000000
using namespace std;
long long i,n,m,x;
long long ans,da[100005];
inline long long quickme(long long p,long long o)
{
	long long now=p,ans=1;
 	while (o>0)
  	{
		if (o&1)
   		{
		   	ans*=now;
		   	if (ans>P)
		   	return -1;
		}
		now=now*now;
		o=o>>1;
	}
	return ans;
}
inline bool check(long long o,long long p)
{
	long long gt=0;
	while (o)
	{
		gt+=o%10;
		o=o/10;
	}
	if (gt==p)
	return true;
	else return false;
}
int main()
{
	scanf("%I64d%I64d%I64d",&m,&n,&x);
	for (i=1;i<=81;i++)
	{
		long long yy=n*quickme(i,m)+x;
		if (yy>P)
		continue;
		if (check(yy,i))
		{
			ans++;
			da[ans]=yy;
		}
	}
	printf("%I64d\n",ans);
	for (i=1;i<=ans;i++)
	printf("%I64d ",da[i]);
}