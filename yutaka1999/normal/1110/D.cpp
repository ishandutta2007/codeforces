#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
#define SIZE 1000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int cnt[SIZE];
int dp[2][5][5];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);a--;
		cnt[a]++;
	}
	int pos=0;
	for(int i=0;i<m;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int x=0;x<5;x++)
		{
			for(int y=0;y<5;y++)
			{
				int s=cnt[i]-x;
				int t=cnt[i+1]-y;
				int u=cnt[i+2];
				if(s<0||t<0) continue;
				for(int z=0;z<3;z++)
				{
					if(s<z||t<z||u<z||y+z>=5) break;
					dp[pos][y+z][z]=max(dp[pos][y+z][z],dp[pos^1][x][y]+z+(s-z)/3);
				}
			}
		}
	}
	int ret=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			ret=max(ret,dp[pos][i][j]);
		}
	}
	printf("%d\n",ret);
	return 0;
}