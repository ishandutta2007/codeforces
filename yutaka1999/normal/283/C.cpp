#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 305
#define MX 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int to[SIZE];
int deg[SIZE];
ll dp[2][MX];
int val[SIZE],in[SIZE];
bool use[SIZE];

int main()
{
	int n,q,t;
	scanf("%d %d %d",&n,&q,&t);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	memset(to,-1,sizeof(to));
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		to[a]=b;
		deg[b]++;
	}
	memset(dp,0,sizeof(dp));
	int pos=0;
	dp[pos][0]=1;
	for(int i=0;i<n;i++)
	{
		if(deg[i]==0)
		{
			int sz=0,sum=0;
			for(int j=i;j!=-1;j=to[j])
			{
				use[j]=true;
				sum+=in[j];
				val[sz++]=sum;
			}
			for(int k=0;k<sz;k++)
			{
				pos^=1;
				for(int j=0;j<=t;j++)
				{
					dp[pos][j]=dp[pos^1][j];
					if(j>=val[k])
					{
						dp[pos][j]+=dp[pos][j-val[k]];
						if(dp[pos][j]>=MOD) dp[pos][j]-=MOD;
					}
				}
				if(k!=sz-1)
				{
					for(int j=0;j<=t;j++)
					{
						dp[pos][j]-=dp[pos^1][j];
						if(dp[pos][j]<0) dp[pos][j]+=MOD;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			puts("0");
			return 0;
		}
	}
	printf("%llld\n",dp[pos][t]);
	return 0;
}