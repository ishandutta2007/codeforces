#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,k;

int p[N];

int x[N],y[N];

int to[N],fr[N];

int fa[N],ind[N],rk[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

vector<int>g[N],v[N],t;

queue<int>q; 

void topo()
{
	int tot=0;
	for(int i=1;i<=n;i++)
		if(find(i)==i)
			tot++;
	for(int i=1;i<=n;i++)
		if(find(i)==i&&!ind[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		t.push_back(x);
		for(int i=0;i<g[x].size();i++)
		{
			int v=g[x][i];
			if(!--ind[v])
				q.push(v);
		}
	}		
	if(t.size()!=tot)
	{
		puts("0");
		exit(0);
	}
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),fa[i]=i;
	for(int i=1;i<=k;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=k;i++)
	{
		int fx=find(x[i]),fy=find(y[i]);
		if(fx!=fy)
			fa[fy]=fx;
		if(to[x[i]]||fr[y[i]]||to[y[i]]==x[i])
		{
			puts("0");
			return 0;
		}
		to[x[i]]=y[i];
		fr[y[i]]=x[i];
	}
	for(int i=1;i<=n;i++)
		v[find(i)].push_back(i);
	for(int i=1;i<=n;i++)
		if(p[i]!=0)
		{
			if(find(p[i])!=find(i))
				g[find(p[i])].push_back(find(i)),ind[find(i)]++;
		}
	topo();
	vector<int>ans;
	for(int i=0;i<t.size();i++)
	{
		int x=t[i];
		for(int j=0;j<v[x].size();j++)
			if(!fr[v[x][j]])
			{
				int y=v[x][j];
				while(y)
					ans.push_back(y),y=to[y],rk[y]=ans.size();
			}
	}
	for(int i=1;i<=n;i++)
		if(p[i])
		{
			if(find(p[i])==find(i))
			{
				if(rk[p[i]]>rk[i])
				{
					puts("0");
					return 0;
				}
			}
		}
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
}