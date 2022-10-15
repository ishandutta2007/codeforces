#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e3+5;
int n,m;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
	int dis[maxn][maxn];
	void solve(int u,int *dis)
	{
		memset(dis,-1,sizeof(int)*(n+1));
		queue<int>q;
		dis[u]=0;q.push(u);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int &i:e[x])if(dis[i]==-1){dis[i]=dis[x]+1;q.push(i);}
		}		
	}
}o;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)o.add(read(),read());
	for(int i=1;i<=n;i++)o.solve(i,o.dis[i]);
	int s1=read(),t1=read(),l1=read(),s2=read(),t2=read(),l2=read();
	if(o.dis[s1][t1]>l1||o.dis[s2][t2]>l2){puts("-1");return 0;}
	int ans=o.dis[s1][t1]+o.dis[s2][t2];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(o.dis[s1][i]+o.dis[i][j]+o.dis[j][t1]<=l1&&o.dis[s2][i]+o.dis[i][j]+o.dis[j][t2]<=l2)
				ans=min(ans,o.dis[s1][i]+o.dis[s2][i]+o.dis[i][j]+o.dis[j][t1]+o.dis[j][t2]);
			if(o.dis[s1][i]+o.dis[i][j]+o.dis[j][t1]<=l1&&o.dis[s2][j]+o.dis[j][i]+o.dis[i][t2]<=l2)
				ans=min(ans,o.dis[s1][i]+o.dis[s2][j]+o.dis[i][j]+o.dis[j][t1]+o.dis[i][t2]);
			
		}
	printf("%d\n",m-ans);
	return 0;
}