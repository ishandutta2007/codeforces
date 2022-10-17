#include<bits/stdc++.h>
using namespace std;

const int N=3e6+1e3+7,P=998244353;

int T,n,ind[N];

vector<int>g[N];

int f[N];

queue<int>q;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			g[i].clear();
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			ind[i]=k;
			for(int j=0;j<k;j++)
			{
				int x;
				scanf("%d",&x);
				g[x].push_back(i);
			}
		}
		fill(f+1,f+n+1,1);
		for(int i=1;i<=n;i++)
			if(!ind[i])
				q.push(i);
		int ans=1;
		int tot=0;
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			tot++;
			ans=max(ans,f[x]);
			for(auto v:g[x])
			{
				f[v]=max(f[v],f[x]+(x>v));
				if(!--ind[v])
					q.push(v);
			}
		}
		if(tot<n)
			puts("-1");
		else
			printf("%d\n",ans);
	}
}