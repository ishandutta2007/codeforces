#include<bits/stdc++.h>
using namespace std;

const int N=2e2+1e1+7;

int n,m;

int g[N][N]; 

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pair<pii,int> >e; 

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				g[i][j]=1e9;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back(mp(mp(u,v),w));
		if(w)
			g[u][v]=1,g[v][u]=-1;
		else
			g[u][v]=1,g[v][u]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	int ans=-1;
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		int mx=0,nok=0;
		for(int j=1;j<=n;j++)
			if(g[i][j]<0)
				nok=1;
			else
				mx=max(mx,g[i][j]);
		for(auto s:e)
		{
			int x=s.fs.fs,v=s.fs.sd,w=s.sd;
			if(w==1)
			{
				if(g[i][v]-g[i][x]!=w)
				{
					puts("NO");
					return 0;
				}
			}
			else
			{
				if(abs(g[i][v]-g[i][x])!=1)
				{
					puts("NO");
					return 0;
				}
			}
		}
		if(nok)
			continue;
		if(mx>ans)
		{
			ans=mx;
			v.clear();
			for(int j=1;j<=n;j++)
				v.push_back(g[i][j]);
		}
	}
	if(ans!=-1)
	{
		puts("YES");
		printf("%d\n",ans);
		for(auto x:v)
			printf("%d ",x);
	}
	else
		puts("NO");
}