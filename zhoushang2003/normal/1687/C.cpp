#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5;
int n,m,x,y,a[N],q[N],c,l,r;
vector<int>e[N];
main()
{
	ios::sync_with_stdio(0);
	for(cin>>n;cin>>n>>m;)
	{
		set<int>p;
		e[0].clear(),c=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>x,a[i]=a[i-1]+a[i]-x,e[i].clear();
		for(int i=1;i<=m;i++)
			cin>>x>>y,e[x-1].push_back(y),e[y].push_back(x-1);
		for(int i=0;i<=n;i++)
			if(a[i])
				p.insert(i);
			else
				q[++c]=i;
		while(c)
		{
			x=q[c--];
			for(int i:e[x])
			{
				if(p.count(i))
					continue;
				l=min(x,i),r=max(x,i);
				auto j=p.lower_bound(l);
				while(j!=p.end()&&*j<=r)
					q[++c]=*j,p.erase(j++);
			}
		}
		puts(p.empty()?"YES":"NO");
	}
}