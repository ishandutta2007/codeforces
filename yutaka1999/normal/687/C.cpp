#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 505

using namespace std;

bool dp[SIZE][SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	memset(dp,false,sizeof(dp));
	dp[0][0]=true;
	for(int i=0;i<n;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=k-c;j>=0;j--)
		{
			for(int p=j;p>=0;p--)
			{
				if(!dp[j][p]) continue;
				dp[j+c][p]=true;
				dp[j+c][p+c]=true;
			}
		}
	}
	vector <int> ans;
	for(int j=0;j<=k;j++) if(dp[k][j]) ans.push_back(j);
	printf("%d\n",ans.size());
	for(int j=0;j<ans.size();j++)
	{
		if(j!=0) printf(" ");
		printf("%d",ans[j]);
	}puts("");
	return 0;
}