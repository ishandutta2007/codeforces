#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <stack>
#define SIZE 105
#define MX 10005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];
int dp[SIZE][MX];
int C[SIZE][SIZE];

void make()
{
	for(int i=0;i<SIZE;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			if(C[i][j]>=MOD) C[i][j]-=MOD;
		}
	}
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	if(A[0]==A[n-1])
	{
		printf("%d\n",n);
		return 0;
	}
	int nxt=-1;
	for(int i=n-1;i>=0;i--)
	{
		if(A[i]!=A[0])
		{
			nxt=A[i];
		}
	}
	if(nxt==A[n-1])
	{
		printf("%d\n",n);
		return 0;
	}
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=MX-1;j>=A[i];j--)
		{
			for(int k=1;k<=i+1;k++)
			{
				dp[k][j]+=dp[k-1][j-A[i]];
				if(dp[k][j]>=MOD) dp[k][j]-=MOD;
			}
		}
	}
	int ret=0;
	for(int i=0;i<n;)
	{
		int f=i;
		for(;i<n&&A[i]==A[f];i++);
		for(int j=f;j<i;j++)
		{
			int c=j-f+1;
			if(dp[c][c*A[f]]==C[i-f][c])
			{
				//printf("%d : %d %d\n",j,dp[c][c*A[f]],C[i-f][c]);
				ret=max(ret,c);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}