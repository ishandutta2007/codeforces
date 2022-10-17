#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int T,n,k,a[N],b[N],vis[N],pos[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),pos[a[i]]=i;
		fill(vis+1,vis+n+1,0);
		for(int i=1;i<=k;i++)
			scanf("%d",&b[i]),vis[b[i]]=i;
		set<int>s;
		s.clear();
		a[0]=a[n+1]=0;
		vis[0]=vis[n+1]=k+1;
		s.insert(0),s.insert(n+1);
		for(int i=1;i<=n;i++)
			s.insert(i);
		int ans=1;
		for(int i=1;i<=k;i++)
		{
			int l=*(--s.lower_bound(pos[b[i]])),r=*s.upper_bound(pos[b[i]]),ok=2;
			if(vis[a[l]]>i)
				ok--;
			if(vis[a[r]]>i)
				ok--;
			ans=ans*ok%998244353; 
			if(!ans)
				break;
			if(vis[a[l]]<=i)
				s.erase(l);
			else if(vis[a[r]]<=i)
				s.erase(r);
		}
		printf("%d\n",ans);
	}
}