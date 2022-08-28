#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#define SIZE 50005
#define SQR 250
#define ALL 1000005
#define MM 1024*1024*4
#define MX 20

using namespace std;
typedef pair <int,int> P;

struct trie
{
	int mn[MM];
	
	void init()
	{
		for(int i=0;i<MM;i++) mn[i]=10*ALL;
	}
	void add(int k,int x)
	{
		int rt=0;
		mn[rt]=min(mn[rt],k);
		for(int i=MX-1;i>=0;i--)
		{
			if(!(x>>i&1)) rt=rt*2+1;
			else rt=rt*2+2;
			mn[rt]=min(mn[rt],k);
		}
	}
	void reset(int x)
	{
		int rt=0;
		mn[rt]=10*ALL;
		for(int i=MX-1;i>=0;i--)
		{
			if(!(x>>i&1)) rt=rt*2+1;
			else rt=rt*2+2;
			mn[rt]=10*ALL;
		}
	}
	int getleft(int k,int x)
	{
		int rt=0;
		if(-mn[rt]<k) return 0;
		int ret=0;
		for(int i=MX-1;i>=0;i--)
		{
			if(!(x>>i&1))
			{
				if(-mn[rt*2+2]>=k)
				{
					ret|=1<<i;
					rt=rt*2+2;
				}
				else rt=rt*2+1;
			}
			else
			{
				if(-mn[rt*2+1]>=k)
				{
					ret|=1<<i;
					rt=rt*2+1;
				}
				else rt=rt*2+2;
			}
		}
		return ret;
	}
	int getright(int k,int x)
	{
		int rt=0;
		if(k<mn[rt]) return 0;
		int ret=0;
		for(int i=MX-1;i>=0;i--)
		{
			if(!(x>>i&1))
			{
				if(mn[rt*2+2]<=k)
				{
					ret|=1<<i;
					rt=rt*2+2;
				}
				else rt=rt*2+1;
			}
			else
			{
				if(mn[rt*2+1]<=k)
				{
					ret|=1<<i;
					rt=rt*2+1;
				}
				else rt=rt*2+2;
			}
		}
		return ret;
	}
	bool exist()
	{
		for(int i=0;i<MM;i++)
		{
			if(mn[i]!=10*ALL)
			{
				return true;
			}
		}
		return false;
	}
};
trie start1,start2;
//start1 : x-1 xor
//start2 : x xor
int A[SIZE];
vector <P> query[SIZE/SQR+5];
int left[SIZE],right[SIZE];
int dp[ALL],ans[SIZE];

void make()
{
	dp[0]=0;
	for(int i=1;i<ALL;i++) dp[i]=dp[i-1]^i;
}
int get(int k)
{
	int ret=start2.getleft(k,dp[k-1]);
	ret=max(ret,start1.getright(k,dp[k]));
	return ret;
}
int main()
{
	make();
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&left[i],&right[i]);
		left[i]--;right[i]--;
		query[left[i]/SQR].push_back(P(right[i],i));
		ans[i]=0;
	}
	start1.init();
	start2.init();
	for(int i=0;i<=(n-1)/SQR;i++)
	{
		sort(query[i].begin(),query[i].end());
		int nxt=min(SQR*(i+1),n);
		int to=nxt,mx=0;
		for(int j=0;j<query[i].size();j++)
		{
			if(query[i][j].first<nxt) continue;
			while(to<=query[i][j].first)
			{
				start1.add(A[to],dp[A[to]-1]);
				start2.add(-A[to],dp[A[to]]);
				mx=max(mx,get(A[to]));
				to++;
			}
			int v=query[i][j].second;
			ans[v]=max(ans[v],mx);
			for(int k=nxt-1;k>=left[v];k--) ans[v]=max(ans[v],get(A[k]));
		}
		for(int j=nxt;j<to;j++)
		{
			start1.reset(dp[A[j]-1]);
			start2.reset(dp[A[j]]);
		}
		for(int j=0;j<query[i].size();j++)
		{
			int v=query[i][j].second;
			for(int k=left[v];k<=min(right[v],nxt-1);k++)
			{
				start1.add(A[k],dp[A[k]-1]);
				start2.add(-A[k],dp[A[k]]);
				ans[v]=max(ans[v],get(A[k]));
			}
			for(int k=left[v];k<=min(right[v],nxt-1);k++)
			{
				start1.reset(dp[A[k]-1]);
				start2.reset(dp[A[k]]);
			}
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}