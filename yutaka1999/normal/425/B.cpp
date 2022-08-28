#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 105
#define MX 12
#define BT 1<<11

using namespace std;

int mp[SIZE][SIZE];

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	int ret=k+1;
	if(n>k)
	{
		for(int i=0;i<n;i++)//x
		{
			int cnt=0;
			for(int j=0;j<n;j++)
			{
				int sum=0;
				for(int p=0;p<m;p++)
				{
					if(mp[j][p]!=mp[i][p])
					{
						sum++;
					}
				}
				cnt+=min(sum,m-sum);
			}
			ret=min(ret,cnt);
		}
	}
	else
	{
		for(int S=0;S<1<<n;S++)
		{
			int cnt=0;
			for(int j=0;j<m;j++)
			{
				int sum=0;
				for(int p=0;p<n;p++)
				{
					if(mp[p][j]!=(S>>p&1))
					{
						sum++;
					}
				}
				cnt+=min(sum,n-sum);
			}
			ret=min(ret,cnt);
		}
	}
	if(ret>k) puts("-1");
	else printf("%d\n",ret);
	return 0;
}