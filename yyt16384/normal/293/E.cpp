#include <algorithm>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
struct data
{
	int u,l,w;
	data() {}
	data(int u,int l,int w):u(u),l(l),w(w) {}
};
int n,l,w;
int edgey[2*MAXN];
int edgew[2*MAXN];
int enext[2*MAXN];
int ehead[MAXN];
int vis[MAXN];
data cc[MAXN];
int cn;
int ss[MAXN];
long long ans;
void addedge(int x,int y,int w)
{
	static int edgen;
	edgey[edgen]=y;edgew[edgen]=w;enext[edgen]=ehead[x];ehead[x]=edgen++;
}
void add(int x,int y,int w)
{
	addedge(x,y,w);
	addedge(y,x,w);
}
void init()
{
	scanf("%d%d%d",&n,&l,&w);
	memset(ehead,-1,sizeof(ehead));
	for (int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		--u;
		add(i,u,v);
	}
}
int getroot(int x)
{
	static int que[MAXN];
	static int fa[MAXN];
	static int sz[MAXN];
	static int msz[MAXN];
	int qb=0,qe=1;
	que[0]=x;
	fa[x]=-1;
	sz[x]=1;
	while (qb<qe)
	{
		int x=que[qb++];
		for (int i=ehead[x];i!=-1;i=enext[i])
			if (edgey[i]!=fa[x]&&!vis[edgey[i]])
			{
				fa[edgey[i]]=x;
				sz[edgey[i]]=1;
				que[qe++]=edgey[i];
			}
	}
	for (int i=qe-1;i>=1;--i)
		sz[fa[que[i]]]+=sz[que[i]];
	for (int i=0;i<qe;++i)
	{
		msz[que[i]]=sz[que[0]]-sz[que[i]];
		if (sz[que[i]]>msz[fa[que[i]]])
			msz[fa[que[i]]]=sz[que[i]];
	}
	for (int i=0;i<qe;++i)
		if (msz[que[i]]*2<=sz[que[0]])
			return que[i];
	return -1;
}
void getdist(int x)
{
	static int que[MAXN];
	static int fa[MAXN];
	static int rr[MAXN];
	static int dist[MAXN];
	static int dist_w[MAXN];
	int qb=0,qe=1;
	que[0]=x;
	fa[x]=-1;
	rr[x]=-1;
	dist[x]=0;
	dist_w[x]=0;
	while (qb<qe)
	{
		int x=que[qb++];
		for (int i=ehead[x];i!=-1;i=enext[i])
			if (edgey[i]!=fa[x]&&!vis[edgey[i]])
			{
				fa[edgey[i]]=x;
				if (rr[x]==-1) rr[edgey[i]]=edgey[i];
				else rr[edgey[i]]=rr[x];
				dist[edgey[i]]=dist[x]+1;
				dist_w[edgey[i]]=dist_w[x]+edgew[i];
				que[qe++]=edgey[i];
			}
	}
	cn=qe;
	for (int i=0;i<qe;++i)
		cc[i]=data(rr[que[i]],dist[que[i]],dist_w[que[i]]);
}
void insert(int x,int y)
{
	if (x>l) return;
	++x;
	while (x<=l+1)
	{
		ss[x]+=y;
		x+=x&-x;
	}
}
int query(int x)
{
	if (x<0) return 0;
	++x;
	int sum=0;
	while (x)
	{
		sum+=ss[x];
		x-=x&-x;
	}
	return sum;
}
void getans(const data *a,int n,int vv)
{
	for (int i=0,j=n-1;i<=n;++i)
	{
		while (j>=0&&(i==n||a[j].w+a[i].w>w))
		{
			ans+=query(l-a[j].l);
			--j;
		}
		if (i==n) break;
		insert(a[i].l,vv);
	}
	for (int i=0;i<n;++i)
		insert(a[i].l,-vv);
}
bool cmp1(const data &x,const data &y)
{
	return x.w<y.w;
}
bool cmp2(const data &x,const data &y)
{
	return x.u<y.u;
}
void work(int x)
{
	x=getroot(x);
	vis[x]=1;
	getdist(x);
	std::sort(cc,cc+cn,cmp1);
	getans(cc,cn,1);
	std::stable_sort(cc,cc+cn,cmp2);
	for (int i=1;i<cn;)
	{
		int l=i;
		while (i<cn&&cc[i].u==cc[l].u) ++i;
		getans(cc+l,i-l,-1);
	}
	for (int i=ehead[x];i!=-1;i=enext[i])
		if (!vis[edgey[i]])
			work(edgey[i]);
}
void solve()
{
	work(1);
	printf(LLFORMAT"d\n",(ans-n)/2);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("8783.in","r",stdin);
	freopen("8783.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}