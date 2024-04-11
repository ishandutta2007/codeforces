#include <bits/stdc++.h>


using namespace std;

int arr[8];
int k;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		int sum=0,ans=k*7;
		for(int i=0;i<7;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		for(int st=0;st<7;st++)
		{
			int cur=0;
			for(int en=st;en<7;en++)
			{
				cur+=arr[en];
				if(cur>=k)
				{
					ans=min(ans,en-st+1);
				}
			}
			int cur2=0;
			for(int en=0;en<=7;en++)
			{
				int all=(k-(cur+cur2)+sum-1)/sum;
				int me=(7-st)+en+7*all;
				ans=min(ans,me);
				cur2+=arr[en];
			}
		}
		printf("%d\n",ans);
	}
}