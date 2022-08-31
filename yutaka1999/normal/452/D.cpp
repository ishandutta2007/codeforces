#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 10005

using namespace std;

int cap[5],tm[5];
int num[5],left[5];
int st[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<3;i++) scanf("%d",&cap[i]);
	for(int i=0;i<3;i++) scanf("%d",&tm[i]);
	for(int i=0;i<3;i++) num[i]=left[i]=0;
	int now=0;
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			bool up=true;
			for(int j=0;j<3;j++)
			{
				if(cap[j]==num[j])
				{
					up=false;
					break;
				}
			}
			if(up)
			{
				st[i]=now;
				for(int j=0;j<3;j++) num[j]++;
				break;
			}
			now++;
			int sum=0;
			for(int j=0;j<3;j++)
			{
				sum+=tm[j];
				for(;left[j]<i;)
				{
					if(st[left[j]]+tm[j]<=now)
					{
						left[j]++;
						num[j]--;
					}
					else break;
				}
			}
		}
	}
	printf("%d\n",st[n-1]+tm[0]+tm[1]+tm[2]);
	return 0;
}