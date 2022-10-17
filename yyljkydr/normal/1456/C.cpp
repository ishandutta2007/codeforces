#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n,a[N],k;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	long long sum=0,ans=0;
	int pos=-1;
	for(int i=n;i>=1;i--)
	{
		if(sum>=0)
			ans+=sum;
		else
		{
			a[i+1]=sum;
			pos=i+1;
			break;
		}
		sum+=a[i];
	}
	for(int i=1;i<=pos;i++)
		ans+=1ll*a[i]*((i-1)/(k+1));
	printf("%lld\n",ans);
}