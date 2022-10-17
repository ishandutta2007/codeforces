#include<bits/stdc++.h>
using namespace std;
int a[100001],sol[100001];
int main()
{
	int n,k,sum=0;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%k)
	{
		printf("No\n");
		return 0;
	}
	int tot=sum/k,cnt=0,now=0,pos=0;
	for(int i=1;i<=n;i++)
	{
		if(now+a[i]>tot)
		{
			printf("No\n");
			return 0;
		}
		if(now+a[i]==tot)
		{
			sol[++pos]=cnt+1;
			cnt=now=0;
		}
		else
		{
			now+=a[i];
			cnt++;
		}
	}
	printf("Yes\n");
	for(int i=1;i<=k;i++)
		printf("%d ",sol[i]);
	putchar('\n');
	return 0;
}