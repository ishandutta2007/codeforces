#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#define SIZE 55

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int L[SIZE],R[SIZE],X[SIZE],C[SIZE];
int dp[SIZE][SIZE][SIZE];
int rt[SIZE];
int n,m;

int solve(int l,int r,int h)
{
	if(dp[l][r][h]!=-1) return dp[l][r][h];
	int ret=0;
	if(h>0) ret=solve(l,r,h-1);
	for(int i=l;i<=r;i++)
	{
		if(l<i) solve(l,i-1,h);
		if(i<r) solve(i+1,r,h);
	}
	for(int i=0;i<n;i++) rt[i]=0;
	for(int i=0;i<m;i++)
	{
		if(l<=L[i]&&R[i]<=r&&X[i]<=h)
		{
			rt[L[i]]+=C[i];
			rt[R[i]+1]-=C[i];
		}
	}
	for(int i=1;i<n;i++) rt[i]+=rt[i-1];
	for(int i=l;i<=r;i++)
	{
		int score=h*h-rt[i];
		if(l<i) score+=solve(l,i-1,h);
		if(i<r) score+=solve(i+1,r,h);
		ret=max(ret,score);
	}
	return dp[l][r][h]=ret;
}
int main()
{
	int h;
	scanf("%d %d %d",&n,&h,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d %d",&L[i],&R[i],&X[i],&C[i]);
		L[i]--,R[i]--,X[i]++;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(0,n-1,h));
	return 0;
}