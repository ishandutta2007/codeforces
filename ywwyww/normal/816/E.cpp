#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
ll f[5010][5010][2];
list<int> l[5010];
int sz[5010];
int n;
ll c[5010];
ll d[5010];
void dfs(int x)
{
	f[x][0][0]=0;
	f[x][1][0]=c[x];
	f[x][1][1]=c[x]-d[x];
	int i,j;
	sz[x]=1;
	for(auto v:l[x])
	{
		dfs(v);
		for(i=sz[x];i>=0;i--)
			for(j=sz[v];j>=0;j--)
			{
				f[x][i+j][0]=min(f[x][i+j][0],f[x][i][0]+f[v][j][0]);
				f[x][i+j][1]=min(f[x][i+j][1],f[x][i][1]+min(f[v][j][0],f[v][j][1]));
			}
		sz[x]+=sz[v];
	}
}
int main()
{
	memset(f,0x7f,sizeof f);
	int n;
	ll b;
	scanf("%d%I64d",&n,&b);
	int x,i;
	for(i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&c[i],&d[i]);
		if(i>=2)
		{
			scanf("%d",&x);
			l[x].push_back(i);
		}
	}
	dfs(1);
	for(i=n;i>=0;i--)
		if(min(f[1][i][1],f[1][i][0])<=b)
		{
			printf("%d\n",i);
			break;
		}
	return 0;
}