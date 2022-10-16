#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

long long a[100010];
vector<int> ed[100010];

int tmp[10];
int dis[100010];
queue<int> q;

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=0;i<=62;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]&(1ll<<i))cnt++;
		}
		if(cnt>=3){printf("3");return 0;}
	}
	for(int i=0;i<=62;i++)
	{
		int t=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]&(1ll<<i)){t++;tmp[t]=j;}
		}
		if(t==2)ed[tmp[1]].push_back(tmp[2]),ed[tmp[2]].push_back(tmp[1]);
	}
	
	int minn=1e9;
	for(int i=1;i<=n;i++)
	{
		if(ed[i].size()>1)
		{
			for(int j=0;j<ed[i].size();j++)
			{
				int x=ed[i][j];
				for(int k=1;k<=n;k++)dis[k]=1e9;dis[i]=dis[x]=0;
				while(!q.empty())q.pop();q.push(x);
				while(!q.empty())
				{
					int t=q.front();q.pop();
					for(int k=0;k<ed[t].size();k++)
					{
						int r=ed[t][k];
						if(dis[r]==1e9){dis[r]=dis[t]+1;q.push(r);}
					}
				}
				int tmp=1e9;
				for(int k=0;k<ed[i].size();k++)
				{
					int t=ed[i][k];
					if(t!=x)tmp=min(tmp,dis[t]);
				}
				minn=min(minn,tmp+2);
			}
		}
	}
	if(minn==1e9)printf("-1");else printf("%d",minn);
	return 0;
}