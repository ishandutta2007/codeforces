#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define INF 1000005

using namespace std;

vector <int> vec[SIZE];
int A[SIZE],dp[SIZE],ans[SIZE];
bool ok[SIZE],all[SIZE];

void dfs(int v=0,int p=-1)
{
	int mx=0,sum=1;
	all[v]=true;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			all[v]&=all[to];
			if(all[to]) sum+=dp[to];
			else mx=max(mx,dp[to]);
		}
	}
	dp[v]=sum+mx;
	if(!ok[v])
	{
		all[v]=false;
		dp[v]=0;
	}
}
void make(int v=0,int p=-1,int d=0,bool up=true)
{
	int A=0,B=0;
	int sum=1,cnt=0;
	if(up) sum+=d;
	else
	{
		A=d;
		cnt++;
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			int gt=dp[to];
			if(all[to]) sum+=dp[to];
			else
			{
				cnt++;
				if(A<gt) swap(A,gt);
				if(B<gt) swap(B,gt);
			}
		}
	}
	ans[v]=sum+A;
	if(!ok[v]) ans[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			int nxt=sum,nm=cnt;
			if(all[to]) nxt+=A-dp[to];
			else
			{
				nm--;
				if(A==dp[to]) nxt+=B;
				else nxt+=A;
			}
			if(!ok[v])
			{
				nxt=0;
				nm=1;
			}
			make(to,v,nxt,nm==0);
		}
	}
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int l=-1,r=INF;
	while(l+1<r)
	{
		int m=(l+r)/2;
		for(int i=0;i<n;i++) ok[i]=(A[i]>=m);
		dfs();
		make();
		int mx=0;
		for(int i=0;i<n;i++) mx=max(mx,ans[i]);
		if(mx>=k) l=m;
		else r=m;
	}
	printf("%d\n",l);
	return 0;
}