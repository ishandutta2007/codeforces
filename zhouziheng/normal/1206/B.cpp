#include<cstdio>

using namespace std;

long long a[100010];

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	
	bool zero=false;
	for(int i=1;i<=n;i++)if(!a[i])zero=true;
	
	if(zero)
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!a[i])ans+=1;
			else if(a[i]>0)ans+=a[i]-1;
			else ans+=-1-a[i];
		}
		printf("%I64d",ans);
	}
	else
	{
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0)ans+=a[i]-1;
			else ans+=-1-a[i];
		}
		int cnt=0;for(int i=1;i<=n;i++)if(a[i]<0)cnt++;
		if(cnt&1)ans+=2;
		printf("%I64d",ans);
	}
	return 0;
}