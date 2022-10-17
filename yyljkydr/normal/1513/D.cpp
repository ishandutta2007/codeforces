#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int T,n,a[N],p;

long long ans;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&p);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		vector<pii>c;
		for(int i=1;i<=n;i++)
			c.push_back(mp(a[i],i));
		sort(c.begin(),c.end());
		vector<int>vis(n+1);
		ans=0;
		int tot=0;
		for(auto [x,y]:c)
		{
			if(vis[y])
				continue;
			int l=y,r=y;
			while(l-1>=1&&a[l-1]%a[y]==0)
			{
				l--;
				if(vis[l])
					break;
			}
			while(r+1<=n&&a[r+1]%a[y]==0)
			{
				r++;
				if(vis[r])
					break;
			}
			for(int i=l;i<=r;i++)
				vis[i]=1;
			ans+=1ll*(r-l)*min(x,p);
			tot+=r-l;
		}
		printf("%lld\n",ans+1ll*(n-1-tot)*p);
	}
}
/*
1
20 5
6 8 5 2 7 2 6 3 7 6 7 2 10 7 3 8 6 2 2 4
*/