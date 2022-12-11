#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<vector>
#include<list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
list<int> g[100010];
int a[100010];
//0
//1 
int n,m;
void fail()
{
	printf("No\n");
	exit(0);
}
void set0(int x)
{
	if(a[x]==1)
		fail();
	a[x]=0;
}
void set1(int x)
{
	if(a[x]==0)
		fail();
	a[x]=1;
}
vector<int> s[100010];
int len[100010];
int lx[1000010];
int ly[1000010];
int cnt=0;
void solve(int l,int r,int k)
{
	if(l>=r)
		return;
	int i;
	for(i=l;i<=r;i++)
	{
		if(i>l)
		{
			if(s[i-1][k]>s[i][k])
			{
				set1(s[i-1][k]);
				set0(s[i][k]);
			}
			else if(s[i-1][k]<s[i][k])
			{
				lx[++cnt]=s[i-1][k];
				ly[cnt]=s[i][k];
			}
		}
	}
	int last=l;
	for(i=l;i<=r;i++)
		if(len[i]==k)
		{
			if(i>l&&s[i-1][k]==s[i][k]&&len[i-1]>k)
				fail();
			solve(last,i-1,k+1);
			last=i+1;
		}
		else if(i>l&&s[i-1][k]!=s[i][k])
		{
			solve(last,i-1,k+1);
			last=i;
		}
	solve(last,r,k+1);
}
int b[100010];
void dfs(int x)
{
	if(b[x])
	{
		if(a[x])
			fail();
		return;
	}
	b[x]=1;
	set0(x);
	for(auto v:g[x])
		dfs(v);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,x;
	memset(a,-1,sizeof a);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&len[i]);
		s[i].push_back(0);
		for(j=1;j<=len[i];j++)
		{
			scanf("%d",&x);
			s[i].push_back(x);
		}
	}
	solve(1,n,1);
	for(i=1;i<=cnt;i++)
		g[lx[i]].push_back(ly[i]);
	for(i=1;i<=cnt;i++)
		if(a[lx[i]]==0)
			dfs(lx[i]);
		else
			set1(lx[i]);
	printf("Yes\n");
	int ans=0;
	for(i=1;i<=m;i++)
		if(a[i]==1)
			ans++;
	printf("%d\n",ans);
	for(i=1;i<=m;i++)
		if(a[i]==1)
			printf("%d ",i);
	return 0;
}