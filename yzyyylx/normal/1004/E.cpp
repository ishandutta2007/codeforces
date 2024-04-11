#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 100100
using namespace std;

int n,m,first[N],bb,mx[N],m2[N],up[N],son[N],fa[N],need[N],gen,t,t2,l,r,lx,rx,lt,rt,ans;
bool use[N];
P tmp;
struct Bn
{
	int to,next,quan;
}bn[N<<1];
priority_queue<P>pq;

inline void add(int u,int v,int w)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	bn[bb].quan=w;
	first[u]=bb;
}

int dfs(int now,int last)
{
	int p,q,t=0,t2=0,tmp;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		tmp=dfs(bn[p].to,now)+bn[p].quan;
		if(tmp>t)
		{
			t2=t;
			t=tmp;
			son[now]=bn[p].to;
		}
		else if(tmp>t2) t2=tmp;
	}
	m2[now]=t2;
	return mx[now]=t;
}

void find(int now,int last)
{
	int p,q;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		if(bn[p].to==son[now])
		{
			up[bn[p].to]=bn[p].quan+m2[now];
		}
		else up[bn[p].to]=bn[p].quan+mx[now];
		up[bn[p].to]=max(up[now]+bn[p].quan,up[bn[p].to]);
		find(bn[p].to,now);
	}
}

int Dfs(int now,int last)
{
	int p,q,tmp,t=0;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		fa[bn[p].to]=now;
		need[bn[p].to]=bn[p].quan;
		tmp=Dfs(bn[p].to,now);
		t=max(t,tmp+bn[p].quan);
	}
	return mx[now]=t;
}

inline void gl()
{
	int p;
	lx=lt=0;
	for(p=first[l];p!=-1;p=bn[p].next)
	{
		if(use[bn[p].to]) continue;
		if(mx[bn[p].to]+bn[p].quan>lx)
		{
			lx=mx[bn[p].to]+bn[p].quan;
			lt=bn[p].to;
		}
	}
}

inline void gr()
{
	int p;
	rx=rt=0;
	for(p=first[r];p!=-1;p=bn[p].next)
	{
		if(use[bn[p].to]) continue;
		if(mx[bn[p].to]+bn[p].quan>rx)
		{
			rx=mx[bn[p].to]+bn[p].quan;
			rt=bn[p].to;
		}
	}
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,p,q,o;
	cin>>n>>m;
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&p,&q,&o);
		add(p,q,o);
		add(q,p,o);
	}
	dfs(1,-1);
	find(1,-1);
	p=1e9;
	for(i=1;i<=n;i++)
	{
		q=max(mx[i],up[i]);
		if(q<p)
		{
			p=q;
			gen=i;
		}
	}
	
	Dfs(gen,-1);
	use[gen]=1;
//	for(i=1;i<=n;i++) cout<<need[i]<<" ";puts("");
	if(m==1)
	{
		cout<<mx[gen];
		return 0;
	}
	for(p=first[gen],t=0;p!=-1;p=bn[p].next)
	{
		if(mx[bn[p].to]+bn[p].quan>t)
		{
			t=mx[bn[p].to]+bn[p].quan;
			t2=bn[p].to;
		}
	}
//	cout<<t2<<endl;
	use[t2]=1;
	l=gen,r=t2;
	gl(),gr();
	for(i=3;i<=m&&(lx||rx);i++)
	{
		if(lx>rx)
		{
			l=lt;
			use[l]=1;
			gl();
		}
		else
		{
			r=rt;
			use[r]=1;
			gr();
		}
	}
	for(i=1;i<=n;i++)
	{
		if(use[i]) continue;
//		cout<<i<<" "<<mx[i]+need[i]<<endl;
		ans=max(ans,mx[i]+need[i]);
	}
	cout<<ans;
}