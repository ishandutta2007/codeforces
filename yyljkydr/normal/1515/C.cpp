#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m,x;

int a[N];

typedef pair<int,int> pii;

pii b[N];

int ans[N];

priority_queue<pii,vector<pii>,greater<pii> >q;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&x);
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=pii{a[i],i};
		sort(b+1,b+n+1);
		while(!q.empty())
			q.pop();
		for(int i=1;i<=m;i++)
			q.push(pair<int,int>{0,i});
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			pii x=q.top();
			q.pop();
			ans[b[i].second]=x.second;
			x.first+=b[i].first;
			q.push(x);
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		puts("");
	}
}