#include<cstdio>
#include<cstring>
using namespace std;
int h[41000],s[41000];
int main()
{
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	int l=0;
	memset(h,0,sizeof(h));
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if(x==0)
		{
			if(l!=0)
			{
				for(int j=1;j<=i-l;j++)h[j]+=i-j-l+1;
				l=0;
			}
		}
		else if(l==0)l=i;
	}
	if(l!=0)
	{
		for(int j=1;j<=n-l+1;j++)h[j]+=n-j-l+2;
		l=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);
		if(x==0)
		{
			if(l!=0)
			{
				for(int j=1;j<=i-l;j++)s[j]+=i-j-l+1;
				l=0;
			}
		}
		else if(l==0)l=i;
	}
	if(l!=0)
	{
		for(int j=1;j<=m-l+1;j++)s[j]+=m-j-l+2;
		l=0;
	}
	long long ss=0;
	for(int i=1;i<=n;i++)
	{
		if(k%i==0&&k/i<=m)
		{
			ss+=1ll*h[i]*s[k/i];
		}
	}
	printf("%lld\n",ss);
	return 0;
}