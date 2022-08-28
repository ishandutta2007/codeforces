#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 10005

using namespace std;
typedef long long int ll;

int A[SIZE],B[SIZE];
ll dp[SIZE];

int main()
{
	int n,C;
	scanf("%d %d",&n,&C);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n;i++) scanf("%d",&B[i]);
	for(int i=n-1;i>=0;i--)
	{
		for(int j=n;j>=0;j--)//Tl
		{
			dp[j]+=(ll) j*(ll) C+B[i];
			if(j>0) dp[j]=min(dp[j],dp[j-1]+A[i]);
		}
	}
	ll ret=dp[0];
	for(int j=0;j<=n;j++) ret=min(ret,dp[j]);
	printf("%lld\n",ret);
	return 0;
}