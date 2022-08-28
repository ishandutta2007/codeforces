#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 100005
#define INF 1000000005

using namespace std;

struct getmax
{
	int que[SIZE];
	int s,e;
	
	void init()
	{
		s=e=0;
	}
	void add(int k)
	{
		while(s<e&&que[e-1]<k) e--;
		que[e++]=k;
	}
	void rem(int k)
	{
		if(s<e&&que[s]==k)
		{
			s++;
		}
	}
	int get()
	{
		return s==e?INF:que[s];
	}
};
struct getmin
{
	int que[SIZE];
	int s,e;
	
	void init()
	{
		s=e=0;
	}
	void add(int k)
	{
		while(s<e&&que[e-1]>k) e--;
		que[e++]=k;
	}
	void rem(int k)
	{
		if(s<e&&que[s]==k)
		{
			s++;
		}
	}
	int get()
	{
		return s==e?INF:que[s];
	}
};
getmax mx;
getmin mn;
int to[SIZE],dp[SIZE],in[SIZE];

int main()
{
	int n,s,L;
	scanf("%d %d %d",&n,&s,&L);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int now=0;
	mx.init();
	mn.init();
	for(int i=0;i<n;i++)
	{
		mx.add(in[i]);
		mn.add(in[i]);
		while(mx.get()-mn.get()>s)
		{
			mn.rem(in[now]);
			mx.rem(in[now]);
			now++;
		}
		to[i]=now;
	}
	mn.init();
	int l=0,r=0;//[l,r)
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		while(r<=i-L)
		{
			if(dp[r]!=-1) mn.add(dp[r]+1);
			r++;
		}
		while(l<r&&l<to[i-1])
		{
			if(dp[l]!=-1) mn.rem(dp[l]+1);
			l++;
		}
		dp[i]=mn.get()==INF?-1:mn.get();
	}
	printf("%d\n",dp[n]);
	return 0;
}