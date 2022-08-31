#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 505

using namespace std;

int w[SIZE];
int id[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&w[i]);
	memset(id,-1,sizeof(id));
	int sum=0,ret=0;
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);a--;
		if(id[a]==-1)
		{
			ret+=sum;
			for(int j=0;j<n;j++)
			{
				if(id[j]!=-1)
				{
					id[j]++;
				}
			}
			id[a]=0;
			sum+=w[a];
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				if(id[j]!=-1&&id[j]<id[a])
				{
					ret+=w[j];
					id[j]++;
				}
			}
			id[a]=0;
		}
	}
	printf("%d\n",ret);
	return 0;
}