#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MD 10005
#define SIZE 30005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll dp[2][SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int pos=0;
	dp[pos][MD]=1;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int j=0;j<SIZE;j++)
		{
			if(j>=a) dp[pos][j]+=dp[pos^1][j-a];
			if(j+a<SIZE) dp[pos][j]+=dp[pos^1][j+a];
			dp[pos][j]%=MOD;
		}
		ret+=dp[pos][MD]++;
		ret%=MOD;
	}
	printf("%I64d\n",ret);
	return 0;
}