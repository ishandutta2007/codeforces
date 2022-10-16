#include<cstdio>

using namespace std;

int a[101]={};

int main() 
{
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	
	int maxn=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=maxn>a[i]?maxn:a[i];
	}
	maxn+=m;
	
	int minn=1e9,tmp=0;
	while(m--)
	{
		minn=1e9;
		for(int i=1;i<=n;i++)
		{
			if(minn>a[i])
			{
				minn=a[i];
				tmp=i;
			}
		}
		a[tmp]++;
	}
	minn=-1;
	for(int i=1;i<=n;i++)
	{
		minn=minn>a[i]?minn:a[i];
	}
	
	printf("%d %d",minn,maxn);
	
	return 0;
}