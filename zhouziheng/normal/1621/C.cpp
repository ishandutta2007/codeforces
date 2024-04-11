#include<cstdio>
#include<vector>

using namespace std;

int query(int x){printf("? %d\n",x);fflush(stdout);scanf("%d",&x);return x;}

vector<int> V;
int p[30000];bool vis[30000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			int u=0;V.clear();
			while(1)
			{
				u=query(i);if(vis[u])break;vis[u]=1,V.push_back(u);
			}
			for(int j=0;j<V.size()-1;j++)p[V[j]]=V[j+1];p[V.back()]=V[0];
		}
		printf("!");for(int i=1;i<=n;i++)printf(" %d",p[i]);puts("");fflush(stdout);
	}
}