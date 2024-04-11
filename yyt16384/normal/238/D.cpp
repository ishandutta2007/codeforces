#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
const int MAXS=2000005;
int n,q;
char s[MAXN];
int next[MAXN];
int prev[MAXN];
int a[MAXS];
int vis[MAXN];
int sum[MAXS][10];
int firstpre[MAXN];
int fp_prev[MAXN];
int fp_next[MAXN];
int fa[MAXN];
int rank[MAXN];
int pp[MAXN];
int m;
void remove(int x)
{
	if (prev[x]!=-1) next[prev[x]]=next[x];
	if (next[x]!=n) prev[next[x]]=prev[x];
}
int getfa(int x)
{
	if (fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
	x=getfa(x);y=getfa(y);
	int p=pp[y];
	if (rank[x]>rank[y])
	{
		int t=x;x=y;y=t;
	}
	if (rank[x]==rank[y]) ++rank[y];
	fa[x]=y;
	pp[y]=p;
}
void remove_fp(int x)
{
	if (fp_prev[x]!=-1) fp_next[fp_prev[x]]=fp_next[x];
	if (fp_next[x]!=n) fp_prev[fp_next[x]]=fp_prev[x];
	if (fp_prev[x]!=-1) merge(x,fp_prev[x]);
	else pp[getfa(x)]=-1;
}
int go(int x,int dir)
{
	if (dir==1) return next[x];
	else return prev[x];
}
void work_firstpre(int l,int r,int m)
{
	for (int i=r;i>l;i=fp_prev[i])
		firstpre[i]=m,remove_fp(i);
}
void work(int st)
{
	int x=st;
	int dir=1;
	while (x>=st&&x<n)
	{
		memcpy(sum[m+1],sum[m],sizeof(sum[m]));
		a[m]=x;
		if (vis[x]==-1) vis[x]=m;
		int prex=x;
		if (isdigit(s[x]))
		{
			++sum[m+1][s[x]-'0'];
			if (s[x]>'0') --s[x];
			else remove(x);
			x=go(x,dir);
		}
		else
		{
			if (s[x]=='<') dir=-1;
			else dir=1;
			x=go(x,dir);
			if (x>=st&&x<n&&(s[x]=='<'||s[x]=='>'))
				remove(prex);
		}
		++m;
		if (dir==-1) work_firstpre(x,pp[getfa(prex)],m);
	}
	a[m++]=x;
}
void init()
{
	scanf("%d%d%s",&n,&q,s);
	for (int i=0;i<n;++i)
		fp_prev[i]=prev[i]=i-1,fp_next[i]=next[i]=i+1;
	memset(vis,-1,sizeof(vis));
	memset(firstpre,-1,sizeof(firstpre));
	for (int i=0;i<n;++i)
		fa[i]=i,rank[i]=0,pp[i]=i;
	for (int i=0;i<n;++i)
		if (vis[i]==-1)
			work(i);
	vis[n]=m-1;
}
void solve()
{
	for (int i=0;i<q;++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		--l;
		int u=vis[l];
		int v=vis[r];
		if (firstpre[l]!=-1&&firstpre[l]<v) v=firstpre[l];
		for (int j=0;j<10;++j)
			printf("%d ",sum[v][j]-sum[u][j]);
		printf("\n");
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("5488.in","r",stdin);
	freopen("5488.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}