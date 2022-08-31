#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1005
#define INF 1000000005

using namespace std;

int mp[SIZE][SIZE];
bool use[SIZE][SIZE];
int f[SIZE];
int n,m;

bool ok(int x)
{
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++)
	{
		int sz=0;
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]>=x)
			{
				for(int k=0;k<sz;k++)
				{
					if(use[j][f[k]]) return true;
					use[j][f[k]]=true;
				}
				f[sz++]=j;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	int s=-1,e=INF;
	while(e-s>1)
	{
		int med=(s+e)/2;
		if(ok(med)) s=med;
		else e=med;
	}
	printf("%d\n",s);
	return 0;
}