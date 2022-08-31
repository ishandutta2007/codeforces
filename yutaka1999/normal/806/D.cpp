#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#define SIZE 2005
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

int A[SIZE][SIZE];
int M[SIZE];
ll ans[SIZE];
ll dp[SIZE];
vector <P> vt;
int n;
int mn;

void solve(int v)
{
	for(int i=0;i<n;i++)
	{
		if(i==v) dp[i]=(ll) mn*(ll) (n-1);
		else
		{
			dp[i]=(ll) mn*(ll) (n-2)+(ll) A[v][i];
			if(n>=3) dp[i]=min(dp[i],(ll) mn*(ll) (n-3)+(ll) M[i]*2LL);
		}
	}
	for(int i=0;i<vt.size();i++)
	{
		int t=vt[i].second;
		if(t==v) continue;
		for(int j=0;j<i;j++)
		{
			int to=vt[j].second;
			dp[t]=min(dp[t],dp[to]+(ll) A[to][t]-(ll) mn);
		}
	}
}
int main()
{
	scanf("%d",&n);
	PP all=PP(INF,P(-1,-1));
	for(int i=0;i<n;i++) M[i]=INF;
	for(int i=0;i<n;i++)
	{
		A[i][i]=0;
		for(int j=i+1;j<n;j++)
		{
			scanf("%d",&A[i][j]);
			A[j][i]=A[i][j];
			all=min(all,PP(A[i][j],P(i,j)));
		}
	}/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",A[i][j]);
		puts("");
	}*/
	for(int i=0;i<n;i++)
	{
		M[i]=INF;
		for(int j=0;j<n;j++) if(i!=j) M[i]=min(M[i],A[i][j]);
		vt.push_back(P(M[i],i));
	}
	sort(vt.begin(),vt.end());
	mn=all.first;
	solve(all.second.first);
	for(int i=0;i<n;i++) ans[i]=dp[i];
	solve(all.second.second);
	for(int i=0;i<n;i++) ans[i]=min(ans[i],dp[i]);
	for(int i=0;i<n;i++) printf("%lld\n",ans[i]);
	return 0;
}