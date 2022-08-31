#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int in[4005];
int dp[4005][4005];
int next[4005][4005];
int n;

int memo(int i,int j)
{
	if(dp[i][j]!=0) return dp[i][j];
	if(j==0) return 1;
	return dp[i][j]=1+memo(j,next[j][in[i]]);
}
int solve()
{
	int ret=1;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ret=max(ret,memo(i,j));
		}
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	vector <int> vx;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		vx.push_back(in[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		in[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
	}
	memset(next,0,sizeof(next));
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(next[i][in[j]]==0) next[i][in[j]]=j;
		}
	}
	printf("%d\n",solve());
	return 0;
}