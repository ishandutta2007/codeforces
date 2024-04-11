#include<bits/stdc++.h>
using namespace std;
const long long Inf=1ll<<60;
class tree
{
	static const int N=200020,D=20;
	int n,root,last[N],end[N+N],next[N+N],total_edge,d[N],f[N][D];
	void dfs(int s,int fa)
	{
		for(int i=last[s];i;i=next[i])
		{
			int j=end[i];
			if(j!=fa)
			{
				d[j]=d[s]+1;
				f[j][0]=s;
				for(int k=1;f[j][k-1];++k)
					f[j][k]=f[f[j][k-1]][k-1];
				dfs(end[i],s);
			}
		}
	}
	int lower(int u,int v)
	{
		return d[u]>d[v] ? u : v;
	}
	public:
	void init(int n_)
	{
		n=n_,root=0;
		fill(last,last+N,0);
		total_edge=0;
		fill(d,d+N+N,0);
		for(int i=0;i<N;++i)
			fill(f[i],f[i]+D,0);
	}
	void add_edge(int u,int v)
	{
		next[++total_edge]=last[u];
		last[u]=total_edge;
		end[total_edge]=v;
		next[++total_edge]=last[v];
		last[v]=total_edge;
		end[total_edge]=u;
	}
	void prepare(int r=1)
	{
		root=r;
		dfs(root,0);
	}
	int LCA(int u,int v)
	{
		if(d[u]<d[v])
			swap(u,v);
		for(int i=D-1;i>=0;--i)
			if((1<<i)<=d[u]-d[v])
				u=f[u][i];
		if(u==v)
			return u;
		for(int i=D-1;i>=0;--i)
			if(f[u][i]!=f[v][i])
				u=f[u][i],v=f[v][i];
		return f[u][0];
	}
	int dis(int u,int v)
	{
		int p=LCA(u,v);
		return d[u]-d[p]+d[v]-d[p];
	}
	pair<int,int> intersection(int u,int v,int x,int y)
	{
		int a=lower(LCA(u,x),LCA(u,y)),b=lower(LCA(v,x),LCA(v,y));
		int p=lower(LCA(u,v),LCA(x,y));
		if(d[a]<d[p] && d[b]<d[p])
			return make_pair(0,0);
		return make_pair(lower(a,p),lower(b,p));
	} //According to ainta's code
}T;
void init()
{
	int n;
	scanf("%d",&n);
	T.init(n);
	for(int i=1,u=0,v=0;i!=n;++i)
	{
		scanf("%d%d",&u,&v);
		T.add_edge(u,v);
	}
	T.prepare();
}
long long gcd(long long a,long long b)
{
	return b ? gcd(b,a%b) : a;
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	long long g=exgcd(b,a%b,y,x);
	y=y-a/b*x;
	return g;
}
long long same_dir(int a1,int m1,int a2,int m2)
{
	long long x=0,y=0,z=a2-a1, g=exgcd(m1,m2,x,y);
	if(z%g)
		return Inf;
	x*=z/g,y*=-z/g;
	m1/=g,m2/=g;
	if(x<0)
	{
		long long t=max((-x+m2-1)/m2,(-y+m1-1)/m1);
		x+=t*m2,y+=t*m1;
	}
	long long t=min(x/m2,y/m1);
	return (x-t*m2)*m1*g+a1;
}
long long G(long long M,long long D,long long L,long long R)
{
	if(D+D>M)
		return G(M,M-D,M-R,M-L);
	if((L-1)/D < R/D)
		return (L+D-1)/D;
	long long t=G(D,(D-M%D)%D,L%D,R%D);
	return t==Inf ? Inf : (L+M*t+D-1)/D;
}
long long diff_dir(int a1,int m1,int a2,int m2,int d)
{
	long long z1=((a2-a1-d)%m2+m2)%m2, z2=((a2-a1+d)%m2+m2)%m2;
	if(z1%2)
		return Inf;
	long long p=0ll;
	if(m2==d+d || z1>z2 || z1==0)
		p=0ll;
	else
		if((z1-1)/gcd(m1,m2) >= z2/gcd(m1,m2))
			return Inf;
		else
			p=G(m2,m1%m2,z1,z2);
	long long q=(p*m1+a1+d-a2)/m2;
	return (d+m1*p+m2*q+a1+a2)/2;
}
long long calc(int u,int v,int x,int y)
{
	static const bool DEBUG=false;
	pair<int,int> path=T.intersection(u,v,x,y);
	int a=path.first,b=path.second;
	if(a==0 && b==0)
		return -1;
	int f1=T.dis(u,v)*2,f2=T.dis(x,y)*2,d=T.dis(a,b);
	int t1=T.dis(u,a),t2=T.dis(u,b),t3=T.dis(x,a),t4=T.dis(x,b);
	((t1<t2 ? t2 : t1)*=-1)+=f1;
	((t3<t4 ? t4 : t3)*=-1)+=f2;
	long long ans=Inf;
	ans=min(ans,same_dir(t1,f1,t3,f2));
	ans=min(ans,same_dir(t2,f1,t4,f2));
	ans=min(ans,diff_dir(t1,f1,t4,f2,d));
	ans=min(ans,diff_dir(t2,f1,t3,f2,d));
	return ans==Inf ? -1 : ans;
}
void work()
{
	int t,u,v,x,y;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d%d%d",&u,&v,&x,&y);
		printf("%I64d\n",calc(u,v,x,y));
	}
}
int main()
{
	init();
	work();
	return 0;
}