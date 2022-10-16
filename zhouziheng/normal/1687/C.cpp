#include<cstdio>
#include<vector>
#include<queue>
#include<set>

using namespace std;

typedef set<int>::iterator IT;
long long a[300000],b[300000],c[300000],s[300000];
vector<int> ed[300000];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		int n=0,m=0;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
		for(int i=1;i<=n;i++)c[i]=a[i]-b[i];
		for(int i=1;i<=n;i++)s[i]=s[i-1]+c[i];
		
		queue<int> q;set<int> S;
		for(int i=0;i<=n;i++)if(s[i])S.insert(i);else q.push(i);
		
		for(int i=1,l=0,r=0;i<=m;i++)
		{
			scanf("%d%d",&l,&r);ed[l-1].push_back(r),ed[r].push_back(l-1);
		}
		
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=0;i<ed[u].size();i++)
			{
				if(s[ed[u][i]])continue;
				int l=min(ed[u][i],u),r=max(ed[u][i],u);
				IT it=S.lower_bound(l);
				while(it!=S.end()&&*(it)<=r)
				{
					int p=*it;s[p]=0;q.push(p);
					IT f=it;it++;S.erase(f);
				}
			}
		}
		puts(S.empty()?"YES":"NO");
		for(int i=0;i<=n;i++)ed[i].clear();
	}
}