#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+2,M=202,I=1e18;
struct S
{
	long long s,t,d,w;
};
struct P
{
	long long w,d,t;
	bool operator<(const P&t)const
	{
		if(t.w!=w)
			return t.w>w;
		return t.d>d;
	}
};
bool v[N];
long long n,m,k,c,W,D,a[N],p[N],f[N][M],A=I;
S w[N];
priority_queue<P>q;
bool C(S x,S y)
{
	return x.s<y.s;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
		cin>>w[i].s>>w[i].t>>w[i].d>>w[i].w;
	sort(w,w+k,C),w[k].s=n+1;
	for(int i=0;i<k;i++)
	{
		q.push({w[i].w,w[i].d,w[i].t});
		for(int j=w[i].s;j<w[i+1].s;j++)
		{
			while(!q.empty()&&q.top().t<j)
				q.pop();
			if(!q.empty())
				a[j]=q.top().w,p[j]=q.top().d+1;
		}
	}
	for(int i=1;i<=n;i++)
		if(!p[i])
			p[i]=i+1;
	for(int i=1;i<=n+1;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=I;
	f[1][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[p[i]][j]=min(f[p[i]][j],f[i][j]+a[i]),f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
	for(int i=0;i<=m;i++)
		A=min(A,f[n+1][i]);
	cout<<A;
	return 0;
}