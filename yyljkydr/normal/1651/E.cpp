#include<bits/stdc++.h>
using namespace std;

const int N=3e3+1e2+7;

int n,vis[N];

vector<int>g[N];

vector<int>v;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	long long ans=0;
	for(int i=1;i<=n*2;i++)
	{
		if(vis[i])
			continue;
		v.clear();
		int x=i;
		while(!vis[x])
		{
			vis[x]=1;
			v.push_back(x);
			for(auto p:g[x])
				if(!vis[p])
					x=p;
		}
		int m=v.size();
		for(int i=0;i<m;i++)
		{
			int mna=1e9,mxa=-1e9;
			int mnb=1e9,mxb=-1e9;
			int len=1;
			int j=i;
			while(1)
			{
				if(v[j]<=n)
					mna=min(mna,v[j]),mxa=max(mxa,v[j]);
				else
					mnb=min(mnb,v[j]),mxb=max(mxb,v[j]);
				int pa=0,qa=n+1;
				int pb=n,qb=n*2+1;
				int p=v[(i-1+m)%m];
				bool ok=1;
				if(p<=n)
				{
					if(p>=mna&&p<=mxa)
						ok=0;
					else if(p<mna)
						pa=max(pa,p);
					else
						qa=min(qa,p);
				}
				else
				{
					if(p>=mnb&&p<=mxb)
						ok=0;
					else if(p<mnb)
						pb=max(pb,p);
					else
						qb=min(qb,p);
				}
				p=v[(j+1)%m];
				if(p<=n)
				{
					if(p>=mna&&p<=mxa)
						ok=0;
					else if(p<mna)
						pa=max(pa,p);
					else
						qa=min(qa,p);
				}
				else
				{
					if(p>=mnb&&p<=mxb)
						ok=0;
					else if(p<mnb)
						pb=max(pb,p);
					else
						qb=min(qb,p);
				}
				if(ok&&len>=2)
					ans+=1ll*(mna-pa)*(qa-mxa)*(mnb-pb)*(qb-mxb)*(len/2);
				j=(j+1)%m;
				len++;
				if(j==i)
					break;
			}
			if(!i)
				ans+=1ll*mna*(n+1-mxa)*(mnb-n)*(n*2+1-mxb)*(v.size()>>1);
		}
	}
	printf("%lld\n",ans);
}