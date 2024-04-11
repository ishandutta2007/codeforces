#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 100005

using namespace std;

int left[SIZE],right[SIZE];
vector <int> vec[SIZE];
int dp[SIZE],deg[SIZE];
int n,m;

bool solve(int k)
{
	for(int i=0;i<n;i++)
	{
		vec[i].clear();
		dp[i]=0;
	}
	for(int i=0;i<k;i++)
	{
		vec[right[i]].push_back(left[i]);
		deg[left[i]]++;
	}
	queue <int> que;
	for(int i=0;i<n;i++)
	{
		if(deg[i]==0)
		{
			que.push(i);
		}
	}
	while(!que.empty())
	{
		int v=que.front();que.pop();
		if(dp[v]==n-1) return true;
		for(int i=0;i<vec[v].size();i++)
		{
			int to=vec[v][i];
			deg[to]--;
			dp[to]=max(dp[to],dp[v]+1);
			if(deg[to]==0) que.push(to);
		}
	}
	return false;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--,right[i]--;
	}
	int l=-1,r=m+1;
	while(r-l>1)
	{
		int d=(l+r)/2;
		if(solve(d)) r=d;
		else l=d;
	}
	printf("%d\n",r<=m?r:-1);
	return 0;
}