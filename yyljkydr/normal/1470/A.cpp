#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int T;

int n,m;

int k[N],c[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&k[i]);
		sort(k+1,k+n+1);
		reverse(k+1,k+n+1);
		multiset<int>s;
		for(int i=1;i<=m;i++)
			scanf("%d",&c[i]),s.insert(c[i]);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			int t=k[i];
			if(s.empty())
				ans+=c[t];
			else
			{
				int x=*s.begin();
				if(x<c[t])
					ans+=x,s.erase(s.begin());
				else
					ans+=c[t];
			}
		}
		printf("%lld\n",ans);
	}
}