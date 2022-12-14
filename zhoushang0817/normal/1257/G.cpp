#include<bits/stdc++.h>
using namespace std;
const int N=3e6+1,D=998244353;
long long t,x,y,c[N],X,Y,n,m,f[N],g[N],l,r[N],W,w[N],V;
vector<int>a[N];
priority_queue<pair<int,int> >q;
int Q(long long a,int b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
void S(long long *a,int t)
{
	for(int i=0;i<n;i++)
		if(i<r[i])
			swap(a[i],a[r[i]]);
	for(int i=1;i<n;i*=2)
	{
		W=Q(3,(D-1)/2/i),w[0]=1;
		if(t<0)
			W=Q(W,D-2);
		for(int j=1;j<i;j++)
			w[j]=w[j-1]*W%D;
		for(int j=0;j<n;j+=2*i)
			for(int k=0;k<i;k++)
				x=a[j+k],y=w[k]*a[i+j+k]%D,a[j+k]=(x+y)%D,a[i+j+k]=(x-y+D)%D;
	}
}
int main()
{
	cin>>t;
	while(t--&&cin>>x)
		a[x].push_back(1),c[x]++;
	for(int i=0;i<N;i++)
		if(c[i])
			a[i].push_back(1),q.push(make_pair(-c[i],i));
	while(q.size()>1)
	{
		X=q.top().second,n=c[X],q.pop(),Y=q.top().second,m=c[Y],q.pop();
		for(int i=0;i<=n;i++)
			f[i]=a[X][i];
		for(int i=0;i<=m;i++)
			g[i]=a[Y][i];
		m+=n,n=1,l=-1;
		while(n<=m)
			n*=2,l++;
		for(int i=0;i<n;i++)
			r[i]=(r[i/2]/2)|((i&1)<<l);
		S(f,1),S(g,1);
		for(int i=0;i<n;i++)
			(f[i]*=g[i])%=D;
		S(f,-1),V=Q(n,D-2);
		for(int i=0;i<n;i++)
			(f[i]*=V)%=D;
		c[X]=m,q.push(make_pair(-m,X)),a[X].clear();
		for(int i=0;i<=m;i++)
			a[X].push_back(f[i]);
		for(int i=0;i<n;i++)
			f[i]=g[i]=0;
	}
	X=q.top().second;
	cout<<a[X][a[X].size()/2];
	return 0;
}