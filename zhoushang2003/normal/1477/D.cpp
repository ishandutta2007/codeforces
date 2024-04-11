#import<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,x,y,A[N],B[N],C,f[N],c[N];
vector<int>e[N],g[N];
main()
{
	for(cin>>n;cin>>n>>m;)
	{
		for(int i=1;i<=n;i++)
			e[i].clear(),g[i].clear(),e[i].push_back(i),e[i].push_back(n+1);
		for(int i=1;i<=m;i++)
			cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
		for(int i=1;i<=n;i++)
			sort(e[i].begin(),e[i].end()),f[i]=c[i]=0;
		C=0;
		for(int i=1;i<=n;i++)
		{
			if(e[i].size()==n+1)
			{
				A[i]=B[i]=++C;
				continue;
			}
			if(f[i])
				continue;
			for(int j=0;j<e[i].size();j++)
				if(e[i][j]!=j+1)
					x=j+1,j=N;
			if(!f[x])
				f[i]=f[x]=i,c[i]=2;
			else if(f[x]==x)
				f[i]=x,c[x]++;
			else if(c[f[x]]==2)
				c[f[x]]=0,f[f[x]]=x,f[i]=f[x]=x,c[x]=3;
			else
				c[f[x]]--,f[i]=f[x]=i,c[i]=2;
		}
		for(int i=1;i<=n;i++)
			if(f[i]!=i)
				g[f[i]].push_back(i);
		for(int i=1;i<=n;i++)
			if(g[i].size())
			{
				A[i]=++C;
				for(int j=0;j<g[i].size();j++)
					B[g[i][j]]=C,A[g[i][j]]=++C;
				B[i]=C;
			}
		for(int i=1;i<=n;i++)
			cout<<A[i]<<' ';
		puts("");
		for(int i=1;i<=n;i++)
			cout<<B[i]<<' ';
		puts(""); 
	}
}