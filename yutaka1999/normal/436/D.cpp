#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MX 2005

using namespace std;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
int in[SIZE];
int pos[MX];
int left[SIZE],right[SIZE];
int id[SIZE];
//vector <edge> vec1[SIZE];
//vector <edge> vec2[SIZE];
int dp[SIZE][2];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<m;i++) scanf("%d",&pos[i]);
	sort(in,in+n);
	int sz=0;
	for(int i=0;i<n;)
	{
		int s=i;
		for(;i<n&&in[i]-in[s]==i-s;i++)
		{
			id[i]=sz;
		}
		left[sz]=s;
		right[sz]=i-1;
		sz++;
	}
	sort(pos,pos+m);
	/*
	for(int i=0;i<sz;i++)
	{
		vec1[i].push_back(edge(i+1,0));
		vec2[i].push_back(edge(i,0));
		int p=upper_bound(pos,pos+m,in[right[i]])-pos;
		for(int j=p;j<m;j++)
		{
			int df=pos[j]-in[right[i]];
			if(right[i]+df<n)
			{
				int to=id[right[i]+df];
				vec1[i].push_back(edge(to+1,j-p+1));
				//printf("*%d %d %d\n",i,to+1,j-p+1);
			}
		}
		p--;
		for(int j=p;j>=0;j--)
		{
			int df=in[right[i]]-pos[j];
			if(right[i]-df>=0)
			{
				int to=id[right[i]-df];
				vec2[to].push_back(edge(i,p-j+1));
				//printf("%d %d %d\n",to,i,p-j+1);
			}
		}
	}for(int i=0;i<sz;i++)
	{
		for(int j=0;j<vec2[i].size();j++)
		{
			edge e=vec2[i][j];
			dp[e.to][1]=max(dp[e.to][1],dp[i][0]+e.cost);
		}
		for(int j=0;j<vec1[i].size();j++)
		{
			edge e=vec1[i][j];
			dp[e.to][0]=max(dp[e.to][0],dp[i][1]+e.cost);
		}
	}*/
	for(int i=0;i<sz;i++)
	{
		dp[i][1]=dp[i][0];
		int p=upper_bound(pos,pos+m,in[right[i]])-pos;
		p--;
		for(int j=p;j>=0;j--)
		{
			int df=in[right[i]]-pos[j];
			if(right[i]-df>=0)
			{
				int to=id[right[i]-df];
				dp[i][1]=max(dp[i][1],dp[to][0]+p-j+1);
			}
		}
		p++;
		dp[i+1][0]=max(dp[i+1][0],dp[i][1]);
		for(int j=p;j<m;j++)
		{
			int df=pos[j]-in[right[i]];
			if(right[i]+df<n)
			{
				int to=id[right[i]+df];
				dp[to+1][0]=max(dp[to+1][0],dp[i][1]+j-p+1);
			}
		}
	}
	int ret=0;
	for(int i=0;i<=sz;i++)
	{
		ret=max(ret,dp[i][0]);
		ret=max(ret,dp[i][1]);
	}
	printf("%d\n",ret);
	return 0;
}