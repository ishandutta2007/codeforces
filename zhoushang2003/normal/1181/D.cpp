#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
long long n,m,Q,a[N],k[N],c[N],t,r,l,C,A[N];
pair<long long,long long>p[N];
vector<int>q[N],g;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=Q;i++)
		cin>>k[i];
	for(int i=1;i<=Q;i++)
		k[i]-=n;
	for(int i=1;i<=Q;i++)
		p[i]=make_pair(k[i],i);
	sort(p+1,p+Q+1);
	for(int i=1;i<=n;i++)
		c[a[i]]++;
	for(int i=1;i<=m;i++)
		q[c[i]].push_back(i);
	t=n*(m-1),r=Q;
	while(p[r].first>t)
		A[p[r].second]=(p[r].first-t-1)%m+1,r--;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<q[i].size();j++)
			g.push_back(q[i][j]);
		t-=m-g.size(),l=r+1;
		sort(g.begin(),g.end());
		while(p[l-1].first>t)
			l--;
		for(int j=l;j<=r;j++)
			p[j].first-=t;
		C=0;
		for(int j=l;j<=r;j++)
		{
			while(C<g.size()&&g[C]<=p[j].first+C)
				C++;
			A[p[j].second]=p[j].first+C;
		}
		r=l-1;
	}
	for(int i=1;i<=Q;i++)
		cout<<A[i]<<'\n';
	return 0;
}