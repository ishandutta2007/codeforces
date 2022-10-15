#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=100005;
const int maxm=100005;
int n,m,d;
int ans;
int head[maxn],ver[maxm<<1],Next[maxm<<1];
int mon[maxn];
int v[maxn];
int tot;
void add(int x,int y)
{
	ver[++tot]=y;Next[tot]=head[x];
	head[x]=tot;
}
int dep[maxn][4];
int maxp;
void bfs(int u,int type)
{
	memset(v,0,sizeof(v));
	queue<pair<int,int> >q;
	while(!q.empty())q.pop();
	q.push(make_pair(u,0));
	dep[u][type]=0;
	int maxl=0;
	while(!q.empty())
	{
		int x=q.front().first;
		int d=q.front().second;
		q.pop();
		v[x]=1;
		dep[x][type]=d;
		if(mon[x])maxp=x;
		for(int i=head[x];i;i=Next[i])
		if(!v[ver[i]])q.push(make_pair(ver[i],d+1));
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++)
	{
		int x;scanf("%d",&x);mon[x]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	bfs(1,1);
	bfs(maxp,2);
	bfs(maxp,3);
	for(int i=1;i<=n;i++)
	if(dep[i][2]<=d&&dep[i][3]<=d)ans++;
	printf("%d\n",ans);
	return 0;
}//godismadoka