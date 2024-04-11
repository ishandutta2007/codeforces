#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7,P=1e9+7;

int n,m;

int fa[N],sz[N],s[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		fa[i]=i,sz[i]=0,s[i]=1;
	vector<int>v;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k==1)
		{
			int x;
			scanf("%d",&x);
			int fx=find(x);
			if(sz[fx])
				continue;
			sz[fx]=1;
			v.push_back(i);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			int fx=find(x),fy=find(y);
			if(fx==fy)
				continue;
			if(sz[fx]&&sz[fy])
				continue;
			fa[fy]=fx;
			sz[fx]|=sz[fy];
			s[fx]+=s[fy];
			v.push_back(i);
		}
	}
	long long ans=1;
	for(int i=1;i<=m;i++)
		if(fa[i]==i)
		for(int j=0;j<s[i]-1+sz[i];j++)
			ans=ans*2%P;
	printf("%lld %d\n",ans,v.size());
	for(int i=0;i<v.size();i++)
		printf("%d ",v[i]);
}