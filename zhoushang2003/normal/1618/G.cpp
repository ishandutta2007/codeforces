#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int n,m,q,x,y,c,t,f[N],g[N],s[N],l,A[N];
pair<int,int>p[N],r[N];
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
int C(int x,int l)
{
	return s[x]-s[x-l];
}
signed main()
{
	cin>>n>>m>>q;
	while(n--&&cin>>x)
		p[++c]=make_pair(x,1),t+=x;
	while(m--&&cin>>x)
		p[++c]=make_pair(x,0);
	sort(p+1,p+c+1);
	for(int i=1;i<=c;i++)
		f[i]=i,g[i]=p[i].second,s[i]=s[i-1]+p[i].first;
	for(int i=1;i<c;i++)
		r[i]=make_pair(p[i+1].first-p[i].first,i);
	for(int i=1;i<=q;i++)
		cin>>x,p[i]=make_pair(x,i);
	sort(r+1,r+c),sort(p+1,p+q+1);
	for(int i=1;i<=q;i++)
	{
		while(l<c-1&&r[l+1].first<=p[i].first)
			l++,x=F(r[l].second),y=F(x+1),f[x]=y,t+=C(y,g[x]+g[y])-C(x,g[x])-C(y,g[y]),g[y]+=g[x];
		A[p[i].second]=t;
	}
	for(int i=1;i<=q;i++)
		cout<<A[i]<<'\n';
}