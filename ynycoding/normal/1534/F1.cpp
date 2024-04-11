#include <cstdio>
#include <vector>
#include <algorithm>
#include <assert.h>
#define pb push_back
using std::vector;
const int N=400005;
int n, m, a[N], l[N], r[N], tl[N], tr[N], is[N], mn[N], mx[N], pmx[N], pmn[N], id[N], rid[N], tot, ccnt;
int *bel[N], pool1[N];
char *s[N], pool[N];
int stk[N], dfn[N], in[N], low[N], cnt, top;
vector<int> e[N];
inline void upt(int a, int b) { l[a]=std::min(l[a], l[b]), r[a]=std::max(r[a], r[b]); }
void tarjan(int u)
{
	low[u]=dfn[u]=++cnt;
	stk[++top]=u;
	in[u]=1;
	for(int v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=std::min(low[u], low[v]);
		}
		else if(in[v]) low[u]=std::min(low[u], dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		++tot;
		l[tot]=0x3f3f3f3f;
		while(stk[top+1]!=u)
		{
			int x=stk[top];
			rid[x]=tot;
			in[x]=0;
			l[tot]=std::min(l[tot], tl[x]);
			r[tot]=std::max(r[tot], tr[x]);
			for(int v:e[x]) if(rid[v]) upt(tot, rid[v]);
			--top;
		}
	}
}
int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
void dfs(int x, int y)
{
	if(!x||!y||x>n||y>m) return;
	if(bel[x][y]||s[x][y]=='.') return;
	bel[x][y]=ccnt;
	tl[ccnt]=std::min(tl[ccnt], y);
	tr[ccnt]=std::max(tl[ccnt], y);
	for(int i=0; i<4; ++i) dfs(x+dx[i], y+dy[i]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		s[i]=pool+(i-1)*m;
		bel[i]=pool1+(i-1)*m;
		scanf("%s", s[i]+1);
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(!bel[i][j]&&s[i][j]=='#')
	{
		++ccnt;
		tl[ccnt]=0x3f3f3f3f;
		dfs(i, j);
	}
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", a+i);
		int t=n+1;
		while(a[i]) --t, a[i]-=s[t][i]=='#';
		a[i]=t<=n?bel[t][i]:0;
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j) if(bel[i][j])
		{
			int x=bel[i][j];
			if(id[j-1]&&id[j-1]!=x) e[x].pb(id[j-1]);
			if(id[j]&&id[j]!=x) e[x].pb(id[j]);
			if(id[j+1]&&id[j+1]!=x) e[x].pb(id[j+1]);
		}
		for(int j=1; j<=m; ++j) if(bel[i][j])
			id[j]=bel[i][j];
	}
	for(int i=1; i<=ccnt; ++i) if(!dfn[i]) tarjan(i);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(bel[i][j])
	{
		l[rid[bel[i][j]]]=std::min(l[rid[bel[i][j]]], j);
		r[rid[bel[i][j]]]=std::max(r[rid[bel[i][j]]], j);
	}
	std::fill(id+1, id+m+1, 0);
	for(int i=1; i<=m; ++i)
	{
		is[rid[a[i]]]=1;
	}
	for(int i=1; i<=m; ++i) e[i].clear();
	for(int i=1; i<=tot; ++i) if(is[i])
	{
		e[r[i]].pb(i);
	}
	int ans=0;
	for(int i=1, r=0; i<=m; ++i)
	{
		for(int x:e[i]) if(l[x]>r)
		{
			++ans;
			r=i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}