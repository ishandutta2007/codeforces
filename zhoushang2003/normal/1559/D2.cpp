#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int n,p,q,f[N],g[N],x,y,P[N],Q[N],A[N],B[N],c;
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
int G(int x)
{
	if(g[x]==x)
		return x;
	return g[x]=G(g[x]);
}
signed main()
{
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++)
		f[i]=g[i]=i;
	while(p--&&cin>>x>>y)
		f[F(x)]=F(y);
	while(q--&&cin>>x>>y)
		g[G(x)]=G(y);
	for(int i=1;i<=n;i++)
		if(F(i)!=F(1)&&G(i)!=G(1))
			A[++c]=1,B[c]=i,f[F(1)]=F(i),g[G(1)]=G(i);
	p=q=0;
	for(int i=1;i<=n;i++)
	{
		if(F(i)!=F(1)&&G(i)==G(1))
			P[++p]=i;
		if(F(i)==F(1)&&G(i)!=G(1))
			Q[++q]=i;
		while(p&&F(P[p])==F(1))
			p--;
		while(q&&G(Q[q])==G(1))
			q--;
		if(p&&q)
			A[++c]=P[p],B[c]=Q[q],f[F(P[p])]=F(Q[q]),g[G(P[p])]=G(Q[q]);
	}
	cout<<c<<'\n';
	for(int i=1;i<=c;i++)
		cout<<A[i]<<' '<<B[i]<<'\n';
	return 0;
}