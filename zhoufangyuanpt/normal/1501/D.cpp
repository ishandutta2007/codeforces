#include<cstdio>
#include<cstring>
using namespace std;
int a[510000],b[510000];
int pa[1010000],pb[1010000];
long long cnt[510000];
int main()
{
	long long n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
	if(n<m)
	{
		long long t=n;n=m;m=t;
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	}
	else
	{
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	}
	memset(pa,-1,sizeof(pa));
	memset(pb,-1,sizeof(pb));
	for(int i=1;i<=n;i++)pa[a[i]]=i;
	for(int i=1;i<=m;i++)pb[b[i]]=i;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=m;i++)
	{
		if(pa[b[i]]!=-1)
		{
			int x=pa[b[i]]-1;
			cnt[((i-x-1)%m+m)%m+1]++;
		}
	}
	long long ss=0,sk=0,y=1;
	do
	{
		if(sk+n-cnt[y]>=k)
		{
			for(long long x=1;x<=n;x++,y=y%m+1)
			{
				ss++;
				if(a[x]!=b[y])sk++;
				if(sk==k)
				{
					printf("%lld\n",ss);
					return 0;
				}
			}
		}
		ss+=n;
		sk+=n-cnt[y];
		y=(y+n-1)%m+1;
	}while(y!=1);
	long long SSR=ss,kkk=sk;
	long long g=(k-1)/kkk;
	sk=g*kkk;ss=g*SSR;
	do
	{
		if(sk+n-cnt[y]>=k)
		{
			for(long long x=1;x<=n;x++,y=y%m+1)
			{
				ss++;
				if(a[x]!=b[y])sk++;
				if(sk==k)
				{
					printf("%lld\n",ss);
					return 0;
				}
			}
		}
		ss+=n;
		sk+=n-cnt[y];
		y=(y+n-1)%m+1;
	}while(y!=1);
	return 0;
}