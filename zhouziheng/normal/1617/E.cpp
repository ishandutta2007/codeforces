#include<cstdio>
#include<vector>
#include<map>

using namespace std;

int a[300000];
vector<int> ed[7000000],val[7000000];

int lg[1<<16];
int LG(int x){if(x<(1<<16))return lg[x];return lg[x>>16]+16;}

int calc(int x)
{
	int k=LG(x-1)+1;return (1<<k)-x;
}

map<int,int> mp;

int fa[7000000],dep[7000000];
void dfs_bas(int u,int f)
{
	fa[u]=f,dep[u]=f?dep[f]+1:0;for(int i=0;i<ed[u].size();i++)if(ed[u][i]!=f)dfs_bas(ed[u][i],u);
}

int main()
{
	int n=0;scanf("%d",&n);
	lg[0]=-1,lg[1]=0;for(int i=2;i<(1<<16);i++)lg[i]=lg[i>>1]+1;
	int cnt=1;mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);int p=a[i];if(mp[p])continue;
		mp[p]=++cnt;int u=calc(p);
		while(!mp[u])
		{
			mp[u]=++cnt;ed[mp[u]].push_back(mp[p]),ed[mp[p]].push_back(mp[u]);
			p=u;u=calc(u);
		}
		ed[mp[u]].push_back(mp[p]),ed[mp[p]].push_back(mp[u]);
	}
	dfs_bas(mp[a[1]],0);int p=1;for(int i=2;i<=n;i++)if(dep[mp[a[i]]]>dep[mp[a[p]]])p=i;
	dfs_bas(mp[a[p]],0);int q=1;for(int i=2;i<=n;i++)if(dep[mp[a[i]]]>dep[mp[a[q]]])q=i;
	printf("%d %d %d\n",p,q,dep[mp[a[q]]]);
}