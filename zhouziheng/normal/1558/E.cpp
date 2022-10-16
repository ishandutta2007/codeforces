#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,m;
long long a[3000],b[3000];
vector<int> ed[3000];

bool in_set[3000];

const int INF=1e9;

long long val[3000];bool vis[3000];int lst[3000];

vector<int> path;

bool check(long long x)
{
	queue<int> q;
	memset(val,0,sizeof(val)),memset(vis,0,sizeof(vis)),memset(lst,0,sizeof(lst));
	for(int i=1;i<=n;i++)
	{
		if(in_set[i])q.push(i),val[i]=x,vis[i]=1,lst[i]=0;
	}
	path.clear();
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<ed[u].size();i++)
		{
			int v=ed[u][i];if(!v||v==lst[u])continue;
			if(val[u]>a[v])
			{
				if(vis[v])
				{
					int k=u;while(k){path.push_back(k);k=lst[k];}
					reverse(path.begin(),path.end());
					k=v;while(k){path.push_back(k);k=lst[k];}
					return 1;
				}
				else
				{
					lst[v]=u;val[v]=val[u]+b[v];vis[v]=1;q.push(v);
				}
			}
		}
	}
	return 0;
}

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d%d",&n,&m);
		for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=2;i<=n;i++)scanf("%lld",&b[i]);
		for(int i=1,u=0,v=0;i<=m;i++)
		{
			scanf("%d%d",&u,&v);ed[u].push_back(v),ed[v].push_back(u);
		}
		long long ans=0,now=0;in_set[1]=1;
		while(1)
		{
			//printf("%lld\n",ans);
			long long L=ans,R=INF+1;
			while(L<R)
			{
				int mid=(L+R)>>1;if(check(now+mid))R=mid;else L=mid+1;
			}
			ans=L;
			check(now+L);for(int i=0;i<path.size();i++)in_set[path[i]]=1;
			bool fin=1;for(int i=1;i<=n;i++)if(!in_set[i])fin=0;if(fin)break;
			now=0;
			for(int i=1;i<=n;i++)
			{
				if(in_set[i])
				{
					now+=b[i];
					for(int j=0;j<ed[i].size();j++)if(ed[i][j]&&in_set[ed[i][j]])ed[i][j]=0;
				}
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)ed[i].clear();memset(a,0,sizeof(a)),memset(b,0,sizeof(b)),memset(in_set,0,sizeof(in_set));
	}
}