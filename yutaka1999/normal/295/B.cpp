#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 505
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
template <class T> void chmin(T&a,T b){a=min(a,b);}

int cost[SIZE][SIZE];
ll d[SIZE][SIZE];
int er[SIZE];
ll ans[SIZE];
bool use[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++)
	{
		fill(d[i],d[i]+n,INF);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	for(int i=0;i<n;i++) scanf("%d",&er[i]),er[i]--;
	for(int i=n-1;i>=0;i--)
	{
		use[er[i]]=true;
		for(int j=0;j<n;j++)
		{
			chmin(d[j][er[i]],(ll) cost[j][er[i]]);
			chmin(d[er[i]][j],(ll) cost[er[i]][j]);
		}
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				chmin(d[j][k],d[j][er[i]]+d[er[i]][k]);
			}
		}
		ans[i]=0;
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(use[j]&&use[k])
				{
					ans[i]+=d[j][k];
				}
			}
		}
	}
	for(int i=0;i<n;i++) printf("%I64d\n",ans[i]);
	return 0;
}