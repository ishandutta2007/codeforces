/*************************************************************************
    > File Name: 987_D.cpp
    > Author: yuki
    > ################### 
    > Mail: ################### 
    > Created Time: Sun 03 Jun 2018 11:07:01 AM CST
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<cmath>
using namespace std;
 /*MACRO*/
#define FORi(l,r) for(int i=(l);i<(r);i++)
#define FORj(l,r) for(int j=(l);j<(r);j++)
#define FORk(l,r) for(int k=(l);k<(r);k++)
#define MEMSET0(i) memset((i),0,sizeof((i)))
#define MEMSET1(i) memset((i),-1,sizeof((i)))

const int maxn=100005;

struct Edge
{
	int u, v;
	int next;
}edge[maxn*2];
int cnt;
int head[maxn];

int n, m, k, s;
vector<int> a[maxn];
int dis[105][maxn];
bool vis[maxn];
queue<int> q;

void add(int u, int v)
{
	cnt++;
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void spfa(int ty)
{
	memset(vis, 0, sizeof(vis));
	while(!q.empty()) q.pop();
	int num=a[ty].size();
	for(int i=0; i<num; i++)
	{
		q.push(a[ty][i]);
		dis[ty][a[ty][i]]=0;
		vis[a[ty][i]]=1;
	}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=head[now]; i!=-1; i=edge[i].next)
		{
			if(dis[ty][edge[i].v] > dis[ty][now]+1)
			{
				dis[ty][edge[i].v]=dis[ty][now]+1;
				if(!vis[edge[i].v])
				{
					q.push(edge[i].v);
					vis[edge[i].v]=1;
				}
			}
		}
	}
}

int main()
{
	while(scanf("%d%d%d%d", &n, &m, &k, &s) != EOF)
	{
		memset(a, 0, sizeof(a));
		memset(edge, 0, sizeof(edge));
		memset(head, -1, sizeof(head));
		int tmp;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &tmp);
			a[tmp].push_back(i);
		}
		int u, v;
		for(int i=1; i<=m; i++)
		{
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		for(int i=1; i<=k; i++)
			for(int j=1; j<=n; j++) dis[i][j]=maxn;
		for(int i=1; i<=k; i++)
			spfa(i);
		int dk[105]={0};
		int ansi;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=k; j++) dk[j]=dis[j][i];
			sort(dk+1, dk+1+k);
			ansi=0;
			for(int j=1; j<=s; j++) ansi+=dk[j];
			printf("%d", ansi);
			if(i == n) printf("\n");
			else printf(" ");
		}
	}
	return 0;
}