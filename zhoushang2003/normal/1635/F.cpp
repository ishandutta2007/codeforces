#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,I=5e18;
int n,m,x[N],w[N],l[N],r,q[N],t,b[N],A[N];
vector<int>p[N],v[N];
void C(int i,int x)
{
	for(;i;i-=i&-i)
		b[i]=min(b[i],x);
}
int Q(int i)
{
	r=I;
	for(;i<=n;i+=i&-i)
		r=min(r,b[i]);
	return r;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>w[i],b[i]=I;
	for(int i=1;i<=m;i++)
		cin>>l[i]>>r,p[r].push_back(i);
	for(int i=1;i<=n;i++)
	{
		while(t&&w[q[t]]>=w[i])
			v[i].push_back(q[t--]);
		v[i].push_back(q[t]),q[++t]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
			t=v[i][j],C(t,(x[i]-x[t])*(w[i]+w[t]));
		for(int j=0;j<p[i].size();j++)
			t=p[i][j],A[t]=Q(l[t]);
	}
	for(int i=1;i<=m;i++)
		cout<<A[i]<<'\n';
}