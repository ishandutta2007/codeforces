#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 150005
#define INF 1000000000000000000LL

using namespace std;
typedef long long int ll;

struct getmax
{
	ll que[SIZE];
	int s,e;
	
	void init()
	{
		s=e=0;
	}
	void add(ll x)
	{
		while(e>s&&que[e-1]<x) e--;
		que[e++]=x;
	}
	void rem(ll x)
	{
		if(s<e&&que[s]==x)
		{
			s++;
		}
	}
	ll get()
	{
		return que[s];
	}
};
getmax que;
ll dp[SIZE],cur[SIZE],nxt[SIZE];
int n,m;

void make(ll d)
{
	que.init();
	for(int i=0;i<n;i++)
	{
		que.add(dp[i]);
		if((ll) i>d) que.rem(dp[i-d-1]);
		cur[i]=que.get();
	}
}
int main()
{
	int d,now=1;
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;
		ll pl=(ll) (c-now)*(ll) d;
		now=c;
		make(pl);
		for(int j=0;j<n;j++) nxt[j]=cur[j];
		for(int l=0,r=n-1;l<r;l++,r--) swap(dp[l],dp[r]);
		make(pl);
		for(int l=0,r=n-1;l<r;l++,r--) swap(cur[l],cur[r]);
		for(int j=0;j<n;j++)
		{
			dp[j]=max(nxt[j],cur[j]);
			dp[j]+=(ll) b-abs(a-j);
		}
	}
	ll ret=-INF;
	for(int i=0;i<n;i++) ret=max(ret,dp[i]);
	printf("%I64d\n",ret);
	return 0;
}