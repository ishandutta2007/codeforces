#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
ll A[SIZE],mx[SIZE];
ll dp[SIZE][3];
ll L[SIZE];
ll ans;

void dfs(int v=0,int p=-1)
{
	dp[v][0]=dp[v][1]=dp[v][2]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			ll gt=dp[to][0]+A[to];
			for(int j=0;j<3;j++)
			{
				if(dp[v][j]<gt)
				{
					swap(dp[v][j],gt);
				}
			}
		}
	}
	mx[v]=dp[v][0]+dp[v][1]+A[v];
	L[v]=A[v];
	ll a=0,b=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			ll gt=dp[to][0]+A[to];
			int pos=2;
			ll sum=dp[v][0]+dp[v][1]+dp[v][2]+A[v];
			for(int j=0;j<3;j++)
			{
				if(dp[v][j]==gt)
				{
					pos=j;
					break;
				}
			}
			sum-=dp[v][pos];
			ans=max(ans,sum+mx[to]);
			if(dp[v][0]==gt) pos=1;
			else pos=0;
			ans=max(ans,dp[v][pos]+L[to]+A[v]);
			L[v]=max(L[v],dp[v][pos]+mx[to]+A[v]);
			L[v]=max(L[v],L[to]+A[v]);
			mx[v]=max(mx[v],mx[to]);
			ll nw=mx[to];
			if(a<nw) swap(a,nw);
			if(b<nw) swap(b,nw);
		}
	}
	L[v]=max(L[v],mx[v]);
	ans=max(ans,mx[v]);
	ans=max(ans,L[v]);
	ans=max(ans,a+b);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ans=0;
	dfs();
	printf("%lld\n",ans);
	return 0;
}