#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;

ll dp[SIZE][2];
bool use[SIZE][2];
int in[SIZE];
int n;

ll memo(int x,int p)
{
	if(x<=0||x>n) return 0;
	if(dp[x][p]!=-1) return dp[x][p];
	if(dp[x][p]==-1&&use[x][p]) return -2;
	use[x][p]=true;
	ll val=memo((p==0?x+in[x]:x-in[x]),1-p);
	return dp[x][p]= val==-2?-2:in[x]+val;
}
int main()
{
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	memset(use,false,sizeof(use));
	for(int i=2;i<=n;i++) scanf("%d",&in[i]);
	for(int i=1;i<n;i++)
	{
		if(memo(i+1,1)!=-2) printf("%I64d\n",i+memo(i+1,1));
		else printf("%d\n",-1);
	}
	return 0;
}