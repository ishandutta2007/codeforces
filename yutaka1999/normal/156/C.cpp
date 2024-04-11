#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define SIZE 105
#define MX 2605

using namespace std;
typedef long long int ll;

ll dp[SIZE][MX];
char str[SIZE];

int main()
{
	dp[0][0]=1;
	for(int i=1;i<SIZE;i++)
	{
		for(int j=0;j<MX;j++)
		{
			for(int k=0;k<26;k++)
			{
				if(j<k) break;
				dp[i][j]+=dp[i-1][j-k];
				dp[i][j]%=MOD;
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",&str);
		int sz=strlen(str);
		int sum=0;
		for(int i=0;i<sz;i++) sum+=str[i]-'a';
		int ret=(int) dp[sz][sum];
		ret--;
		if(ret<0) ret+=MOD;
		printf("%d\n",ret);
	}
	return 0;
}