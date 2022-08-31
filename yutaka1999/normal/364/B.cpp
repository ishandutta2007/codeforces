#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MX 500005

using namespace std;

bool dp[MX];

int main()
{
	int n,d;
	scanf("%d %d",&n,&d);
	dp[0]=true;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		for(int j=MX-1;j>=a;j--) dp[j]|=dp[j-a];
	}
	int now=0,bef=0,cnt=0;
	for(int i=0;i<MX;i++)
	{
		if(dp[i])
		{
			if(i-now<=d) bef=i;
			else
			{
				cnt+=now!=bef;
				now=bef;
				if(i-now<=d) bef=i;
				else break;
			}
		}
	}
	cnt+=bef!=now;
	now=bef;
	printf("%d %d\n",now,cnt);
	return 0;
}