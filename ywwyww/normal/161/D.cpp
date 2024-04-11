#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
using namespace std;
typedef long long ll;
int f[50010][510];
list<int> l[50010];
ll ans;
int n,k;
void dfs(int x,int fa)
{
	f[x][0]=1;
	int i;
	for(auto v:l[x])
		if(v!=fa)
		{
			dfs(v,x);
			for(i=0;i<k;i++)
				ans+=f[x][i]*f[v][k-i-1];
			for(i=0;i<k;i++)
				f[x][i+1]+=f[v][i];
		}
}
int main()
{
	memset(f,0,sizeof f);
	ans=0;
	scanf("%d%d",&n,&k);
	int lx,ly;
	int i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&lx,&ly);
		l[lx].push_back(ly);
		l[ly].push_back(lx);
	}
	dfs(1,0);
	printf("%I64d\n",ans);
	return 0;
}