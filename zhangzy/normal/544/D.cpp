#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int f[4000][4000],used[4000];
int n,m,s1,e1,w1,s2,e2,w2,x,y,ans;
vector<int>r[4000];
queue<int>q;

void bfs(int st)
{
	memset(used,0,sizeof(used));
	used[st]=1;
	q.push(st);
	f[st][st]=0;
	int x;
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		for (int i=0;i<r[x].size();i++)
			if (!used[r[x][i]])
			{
				used[r[x][i]]=1;
				f[st][r[x][i]]=f[st][x]+1;
				q.push(r[x][i]);
			}
	}
}

int main()
{
	memset(f,1,sizeof(f));
	scanf("%d%d",&n,&m);
	ans=m+1;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	scanf("%d%d%d",&s1,&e1,&w1);
	scanf("%d%d%d",&s2,&e2,&w2);
	for (int i=1;i<=n;i++)
		bfs(i);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (f[s1][i]+f[i][j]+f[j][e1]<=w1&&f[s2][i]+f[i][j]+f[j][e2]<=w2)
				ans=min(f[s1][i]+f[s2][i]+f[i][j]+f[j][e1]+f[j][e2],ans);
			if (f[s1][j]+f[j][i]+f[i][e1]<=w1&&f[s2][i]+f[i][j]+f[j][e2]<=w2)
				ans=min(f[s1][j]+f[s2][i]+f[i][j]+f[i][e1]+f[j][e2],ans);
		}
			
	if (f[s1][e1]<=w1&&f[s2][e2]<=w2)
		ans=min(f[s1][e1]+f[s2][e2],ans);
	printf("%d",m-ans);
}