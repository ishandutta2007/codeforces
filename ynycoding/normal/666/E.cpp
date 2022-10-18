#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using std::queue;
const int N=1000005, B=25;
int n, m, q, rt[N], ch[N*B][2], mx[N*B], mxid[N*B], top;
char s[N], t[N];
#define ls ch[u][0]
#define rs ch[u][1]
inline void upt(int u)
{
	mx[u]=std::max(mx[ls], mx[rs]);
	mxid[u]=mx[u]==mx[ls]?mxid[ls]:mxid[rs];
}
void add(int &u, int l, int r, int p)
{
	if(!u) u=++top;
	if(l==r)
	{
		++mx[u], mxid[u]=l;
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) add(ls, l, mid, p);
	else add(rs, mid+1, r, p);
	upt(u);
}
int merge(int x, int y, int l, int r)
{
	if(!x||!y) return x|y;
	int u=++top;
	if(l==r)
	{
		mx[u]=mx[x]+mx[y];
		mxid[u]=l;
		return u;
	}
	int mid=(l+r)>>1;
	ls=merge(ch[x][0], ch[y][0], l, mid);
	rs=merge(ch[x][1], ch[y][1], mid+1, r);
	upt(u);
	return u;
}
int cmx, cid;
void ask(int u, int l, int r, int l1, int r1)
{
	if(!u) return;
	if(l1<=l&&r<=r1)
	{
		if(cmx<mx[u]) cmx=mx[u], cid=mxid[u];
		return;
	}
	int mid=(l+r)>>1;
	if(l1>mid) ask(rs, mid+1, r, l1, r1);
	else if(r1<=mid) ask(ls, l, mid, l1, r1);
	else ask(ls, l, mid, l1, r1), ask(rs, mid+1, r, l1, r1);
}
namespace SAM{
	int nxt[N][26], link[N], len[N], mx[N], deg[N], pa[N][25], srt[N], tp, top;
	queue<int> q;
	inline void init(void) { link[0]=-1; }
	int insert(int x, int p)
	{
		if(nxt[p][x])
		{
			int q=nxt[p][x];
			if(len[q]==len[p]+1) return q;
			int u=++top;
			link[u]=link[q];
			len[u]=len[p]+1;
			memcpy(nxt[u], nxt[q], sizeof(int)*26);
			for(; ~p&&nxt[p][x]==q; p=link[p]) nxt[p][x]=u;
			link[q]=u;
			return u;
		}
		int u=++top;
		len[u]=len[p]+1;
		for(; ~p&&!nxt[p][x]; p=link[p]) nxt[p][x]=u;
		if(~p)
		{
			int q=nxt[p][x];
			if(len[q]==len[p]+1) link[u]=q;
			else
			{
				int t=++top;
				len[t]=len[p]+1;
				link[t]=link[q];
				memcpy(nxt[t], nxt[q], sizeof(int)*26);
				for(; ~p&&nxt[p][x]==q; p=link[p]) nxt[p][x]=t;
				link[q]=link[u]=t;
			}
		}
		return u;
	}
	void build(void)
	{
		for(int i=1; i<=top; ++i) ++deg[link[i]];
		for(int i=1; i<=top; ++i) if(!deg[i]) q.push(i);
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			if(!u) continue;
			srt[++tp]=u;
			--deg[link[u]];
			if(!deg[link[u]]) q.push(link[u]);
			rt[link[u]]=merge(rt[link[u]], rt[u], 1, m);
		}
		for(int i=tp; i; --i)
		{
			int u=srt[i];
			pa[u][0]=link[u];
			for(int k=1; (1<<k)<=top; ++k) pa[u][k]=pa[pa[u][k-1]][k-1];
		}
	}
	inline int gstr(int u, int l)
	{
		for(int k=23; ~k; --k) if(len[pa[u][k]]>=l) u=pa[u][k];
		return u;
	}
}
using SAM::init;
using SAM::link;
using SAM::insert;
using SAM::nxt;
using SAM::build;
using SAM::gstr;
int pos[N], rlen[N];
int main()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	scanf("%d", &m);
	init();
	for(int i=1; i<=m; ++i)
	{
		scanf("%s", t+1);
		int len=strlen(t+1);
		for(int j=1, lst=0; j<=len; ++j)
		{
			lst=insert(t[j]-'a', lst);
			add(rt[lst], 1, m, i);
		}
	}
	build();
	for(int i=1, idx=0, clen=0; i<=n; ++i)
	{
		while(idx&&!nxt[idx][s[i]-'a']) idx=link[idx], clen=std::min(clen, SAM::len[idx]);
		idx=nxt[idx][s[i]-'a'];
		++clen;
		clen=std::min(clen, SAM::len[idx]);
		pos[i]=idx;
		rlen[i]=clen;
	}
	scanf("%d", &q);
	for(int i=1, l, r, pl, pr; i<=q; ++i)
	{
		scanf("%d%d%d%d", &l, &r, &pl, &pr);
		if(rlen[pr]<pr-pl+1) { printf("%d 0\n", l); continue; }
		int idx=gstr(pos[pr], pr-pl+1);
		cmx=0, cid=l;
		ask(rt[idx], 1, m, l, r);
		printf("%d %d\n", cid, cmx);
	}
	return 0;
}