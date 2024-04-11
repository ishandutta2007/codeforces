#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
namespace flow
{
	int c[2000010];
	int v[2000010];
	int t[2000010];
	int h[400010];
	int n;
	int tot;
	void init()
	{
		memset(h,0,sizeof h);
		n=0;
		tot=0;
	}
	void add(int x,int y,int z)
	{
		if(!z)
			return;
#ifdef DEBUG
		fprintf(stderr,"link %d -> %d cap: %d\n",x,y,z);
#endif
		n++;
		v[n]=y;
		c[n]=z;
		t[n]=h[x];
		h[x]=n;
		n++;
		v[n]=x;
		c[n]=0;
		t[n]=h[y];
		h[y]=n;
	}
	int op(int x)
	{
		return ((x-1)^1)+1;
	}
	int S,T;
	int d[400010];
	int q[400010];
	int num[400010];
	int cur[400010];
	void bfs()
	{
		memset(d,-1,sizeof d);
		d[T]=0;
		int head=1,tail=0;
		q[++tail]=T;
		while(tail>=head)
		{
			int i,x=q[head++];
			num[d[x]]++;
			for(i=h[x];i;i=t[i])
				if(c[op(i)]&&d[v[i]]==-1)
				{
					d[v[i]]=d[x]+1;
					q[++tail]=v[i];
				}
		}
	}
	int stop;
	int dfs(int x,int flow)
	{
		if(x==T)
			return flow;
		int s=0,u;
		int &i=cur[x];
		for(;i;i=t[i])
			if(d[v[i]]==d[x]-1&&c[i])
			{
				u=dfs(v[i],min(c[i],flow));
				s+=u;
				flow-=u;
				c[i]-=u;
				c[op(i)]+=u;
				if(stop)
					return s;
				if(!flow)
					return s;
			}
		num[d[x]]--;
		if(!num[d[x]])
		{
			d[S]=n;
			stop=1;
			return s;
		}
		d[x]++;
		num[d[x]]++;
		cur[x]=h[x];
		return s;
	}
	int maxflow()
	{
		stop=0;
		bfs();
		int ans=0;
		memcpy(cur,h,sizeof h);
		while(d[S]<=n-1)
			ans+=dfs(S,0x7fffffff);
		return ans;
	}
}
using flow::S;
using flow::T;
namespace sgt
{
	using flow::add;
	int lc[400010];
	int rc[400010];
	int rt;
	int t[400010];
	int id[400010];
	int c[400010];
	int back[400010];
	int cnt=0;
	int now=0;
	int build(int l,int r)
	{
		int p=++cnt;
		back[p]=id[p]=++flow::tot;
		t[id[p]]=1;
		c[p]=now;
		if(l==r)
		{
			add(id[p],T,1);
			return p;
		}
		int mid=(l+r)>>1;
		lc[p]=build(l,mid);
		rc[p]=build(mid+1,r);
		add(id[p],id[lc[p]],0x7fffffff);
		add(id[p],id[rc[p]],0x7fffffff);
		return p;
	}
	void del(int &p,int l,int r,int L,int R)
	{
		if(l<=L&&r>=R)
		{
			id[p]=0;
			c[p]=now-1;
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid)
			del(lc[p],l,r,L,mid);
		if(r>mid)
			del(rc[p],l,r,mid+1,R);
		if(!id[lc[p]]||!id[rc[p]])
		{
			id[p]=id[lc[p]]|id[rc[p]];
			c[p]=now-1;
		}
		else if(c[p]!=now)
		{
			id[p]=++flow::tot;
			c[p]=now;
		}
	}
	void add(int &p,int l,int r,int L,int R)
	{
		if(l<=L&&r>=R)
		{
			id[p]=back[p];
			c[p]=now-1;
			return;
		}
		int mid=(L+R)>>1;
		if(l<=mid)
			add(lc[p],l,r,L,mid);
		if(r>mid)
			add(rc[p],l,r,mid+1,R);
		if(id[lc[p]]==back[lc[p]]&&id[rc[p]]==back[rc[p]])
		{
			id[p]=back[p];
			c[p]=now-1;
		}
		else if(!id[lc[p]]||!id[rc[p]])
		{
			id[p]=id[lc[p]]|id[rc[p]];
			c[p]=now-1;
		}
		else if(c[p]!=now)
		{
			id[p]=++flow::tot;
			c[p]=now;
		}
	}
	void addedge(int p)
	{
		if(t[id[p]])
			return;
		if(id[p]==id[lc[p]])
		{
			addedge(lc[p]);
			return;
		}
		if(id[p]==id[rc[p]])
		{
			addedge(rc[p]);
			return;
		}
		t[id[p]]=1;
		if(id[lc[p]])
		{
			add(id[p],id[lc[p]],0x7fffffff);
			addedge(lc[p]);
		}
		if(id[rc[p]])
		{
			add(id[p],id[rc[p]],0x7fffffff);
			addedge(rc[p]);
		}
	}
}
using sgt::rt;
using flow::add;
struct event
{
	int l,r,x,c;
	event(int _=0,int __=0,int ___=0,int ____=0)
	{
		l=_;
		r=__;
		x=___;
		c=____;
	}
};
event a[100010];
int cmp(event a,event b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.c<b.c;
}
int main()
{
#ifdef DEBUG
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	if(!m)
	{
		printf("%d\n",n);
		return 0;
	}
	S=400001;
	T=400002;
	rt=sgt::build(1,n);
	int i,cnt=0;
	int x1,y1,x2,y2;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a[++cnt]=event(y1,y2,x1,2);
		a[++cnt]=event(y1,y2,x2+1,1);
	}
	sort(a+1,a+cnt+1,cmp);
	int ti=0;
	add(S,sgt::id[rt],a[1].x-1);
	a[cnt+1].x=n+1;
	int j;
	for(i=1;i<=cnt;i=j)
	{
		sgt::now++;
		ti++;
		j=i;
		while(j<=cnt&&a[j].x==a[i].x)
		{
			if(a[j].c==1)
				sgt::add(rt,a[j].l,a[j].r,1,n);
			else
				sgt::del(rt,a[j].l,a[j].r,1,n);
			j++;
		}
		if(sgt::id[rt])
		{
			sgt::addedge(rt);
			add(S,sgt::id[rt],a[j].x-a[i].x);
		}
	}
	int ans=flow::maxflow();
	printf("%d\n",ans);
	return 0;
}