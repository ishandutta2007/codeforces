#include<iostream>
#include<cstdio>
#define N 60
using namespace std;

int m,n,dir[4][2]= {1,0,-1,0,0,1,0,-1};
char mm[N][N];
string str;
bool vis[N][N];

void dfs(int u,int v,int lu,int lv)
{
	vis[u][v]=1;
	int i,j,nu,nv;
	for(i=0; i<4; i++)
	{
		nu=u+dir[i][0];
		nv=v+dir[i][1];
		if(!nu||!nv||nu>m||nv>n||mm[nu][nv]!=mm[u][v]||nu==lu&&nv==lv) continue;
		if(vis[nu][nv])
		{
			puts("Yes");
			exit(0);
		}
		dfs(nu,nv,u,v);
	}
}

int main()
{
	int i,j;
	cin>>m>>n;
	for(i=1; i<=m; i++)
	{
		cin>>str;
		for(j=1; j<=n; j++)
		{
			mm[i][j]=str[j-1];
		}
	}
	for(i=1; i<=m; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(vis[i][j]) continue;
			dfs(i,j,0,0);
		}
	}
	puts("No");
}