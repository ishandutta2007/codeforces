#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
	node(int nx=0,int ny=0){x=nx;y=ny;}
}h;
int n,m,K,ot[200005],ans=0,u,v,w,ba[10][10][10],vis[200005][10];
int ok[10],pr[10],gy[10];
vector<node>s[200005];
bool cmp(node a,node b){return a.y<b.y;}
void dfs(int p)
{
	if(p==K+1)
	{
		for(int i=1;i<=K;i++)ok[i]=gy[i];
		for(int i=1;i<K;i++)
		{
			for(int j=i+1;j<=K;j++)
			{
				ok[j]|=ba[i][pr[i]][j];
			}
		}
		for(int i=1;i<=K;i++)
		{
			if((1<<(pr[i]-1))&ok[i])
			{
				return;
			}
		}
		ans++;
		return;	
	}
	for(int i=1;i<=p;i++)
	{
		pr[p]=i;
		dfs(p+1);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		s[u].push_back(node(v,w));
		ot[u]++;
	}
	for(int i=1;i<=n;i++)
	{
		sort(s[i].begin(),s[i].end(),cmp);
		for(int j=0;j<s[i].size();j++)
		{
			h=s[i][j];
			if(vis[h.x][ot[i]]&(1<<j))gy[ot[i]]|=(1<<j);
			else vis[h.x][ot[i]]|=(1<<j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=K;j++)
		{
			for(int k=1;k<=j;k++)
			{
				if((1<<(k-1))&vis[i][j])
				{
					for(int u=j+1;u<=K;u++)
					{
						ba[j][k][u]|=vis[i][u];
					}
				}
			}
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}