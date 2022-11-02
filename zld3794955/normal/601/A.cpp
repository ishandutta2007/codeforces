#include<bits/stdc++.h>
using namespace std;
const int N=404;
int n,m,a[N][N]={},con=0,dis[N]={};
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
}
void work()
{
	con=a[1][n];
	queue<int> q;
	bool v[N]={};
	q.push(1);
	v[1]=true;
	dis[1]=0;
	dis[n]=-1;
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(int j=1;j<=n;++j)
			if(a[s][j]!=con && !v[j])
			{
				v[j]=true;
				q.push(j);
				dis[j]=dis[s]+1;
			}
	}
	cout<<dis[n]<<endl;
}
int main()
{
	init();
	work();
	return 0;
}