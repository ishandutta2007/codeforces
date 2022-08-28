#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 1000005

using namespace std;

int dp[SIZE],cur[SIZE];
char str[SIZE],S[SIZE];
int n,m;

void make(int d,int t,int l)
{
	if(t==0)
	{
		for(int i=0;i<n;i++)
		{
			dp[i]=i;
		}
		return;
	}
	make(d,t/2,l);
	for(int i=0;i<t/2;i++) cur[i]=dp[i];
	for(int i=t/2;i<n;i++) cur[i]=dp[t/2+dp[i-t/2]];
	for(int i=0;i<n;i++) dp[i]=cur[i];
	if(t%2==1)
	{
		for(int i=0;i<t-1;i++) cur[i]=dp[i];
		int sz=t-1;
		for(int i=0;i<d;i++)
		{
			int g=t-1+i;
			while(g<t-1+l)
			{
				cur[sz++]=dp[g];
				g+=d;
			}
		}
		for(int i=t-1+l;i<n;i++) cur[i]=dp[i];
		for(int i=0;i<n;i++) dp[i]=cur[i];
	}
}
int main()
{
	scanf("%s",&str);
	n=strlen(str);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int k,d;
		scanf("%d %d",&k,&d);
		make(d,n-k+1,k);
		for(int j=0;j<n;j++) S[j]=str[dp[j]];
		for(int j=0;j<n;j++) str[j]=S[j];
		printf("%s\n",str);
	}
	return 0;
}