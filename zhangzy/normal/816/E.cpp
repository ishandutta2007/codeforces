%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#define xxx 5002
using namespace std;
long long f[xxx][xxx][2],n,b,d[xxx],c[xxx],fa[xxx],t,cnt[xxx],ans;
vector<long long>ch[xxx];

void dfs(long long x)
{
	f[x][0][0]=0;
	f[x][1][0]=d[x];
	f[x][1][1]=c[x];
	int y;
	cnt[x]=1;
	for (int i=0;i<ch[x].size();i++)
	{
		y=ch[x][i];
		dfs(y);
		for (int i=cnt[x];i>=0;i--)
			for (int j=1;j<=cnt[y];j++)
				f[x][i+j][0]=min(f[x][i+j][0],f[x][i][0]+f[y][j][0]);
		for (int i=cnt[x];i>0;i--)
			for (int j=1;j<=cnt[y];j++)
				f[x][i+j][1]=min(f[x][i+j][1],f[x][i][1]+min(f[y][j][1],f[y][j][0]));
		cnt[x]+=cnt[y];
	}
}

int main()
{
	memset(f,63,sizeof(f));
	cin>>n>>b;
	cin>>d[1]>>c[1];
	c[1]=d[1]-c[1];
	for (int i=2;i<=n;i++)
	{
		cin>>d[i]>>c[i]>>fa[i];
		c[i]=d[i]-c[i];
		ch[fa[i]].push_back(i);
	}
	dfs(1);
		
	for (int i=1;i<=n;i++)
		if (f[1][i][1]<=b||f[1][i][0]<=b) 
			ans=i;
	cout<<ans;
}