#include<bits/stdc++.h>
using namespace std;

const int N=5e3+1e2+7;

typedef long long ll;

int T,n,s[N],fa[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			fa[i]=i;
		}
		if(n==1)
		{
			printf("%d\n",s[1]-1);
			continue;
		}
		fa[n+1]=n+1;
		for(int i=n;i>=1;i--)
		{
			if(s[i]==1)
				fa[i]=find(i+1);
			else
				fa[i]=i;
		}
		while(find(1)!=n+1)
		{
			int x=1;
			if(s[find(x)]>n)
			{
				int y=find(x);
				ans+=s[y]-n,s[y]=n;
				continue;
			}
			while(x<=n)
			{
				int y;
				if(x+s[x]>n)
					y=n+1;
				else
					y=find(x+s[x]);
				if(s[x]>1)
					s[x]--;
				if(s[x]==1)
				{
					fa[x]=find(x+1);
				}
				x=y;
			}
			ans++;
		}
		printf("%lld\n",ans);
	}
}