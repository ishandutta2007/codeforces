#include <cstdio>
#include <algorithm>
#define ll long long
const int N=5000005;
int n, m, rt, rans[N], atp;
int fa[N], ch[N][2], top, tp;
ll ad[N][2];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
inline void merge(int x, int y)
{
	fa[findfa(x)]=findfa(y);
}
#define ls ch[u][0]
#define rs ch[u][1]
inline void del(int &u, ll v, int d, ll l1, ll r1)
{
	ll l=v, r=v+(1ll<<(d+1))-1;
	if(!ls&&!rs&&l1<=l&&r<=r1)
	{
		u=-1;
		ad[++tp][0]=v;
		ad[tp][1]=d;
		return;
	}
	if(!u) u=++top;
	ll mid=v|(1ll<<d);
	if(~ls&&l1<mid) del(ls, v, d-1, l1, r1);
	else if(!ls) ls=++top;
	if(~rs&&r1>=mid) del(rs, v|(1ll<<d), d-1, l1, r1);
	else if(!rs) rs=++top;
	if(ls==-1&&rs==-1) u=-1;
}
int stk[N];
int cf, rd;
void mge(int u)
{
	if(fa[u]) { merge(u, cf); return; }
	fa[u]=cf;
	if(ls&&~ls) mge(ls);
	if(rs&&~rs) mge(rs);
}
inline void mdfs(int u, ll v, int d)
{
	if(u==-1) return;
	if(!ls&&!rs) { (!fa[u]?fa[u]=u:0); merge(u, cf); return; }
	if(d==rd) { mge(u); return; }
	if(v&(1ll<<d)) mdfs(rs, v, d-1);
	else mdfs(ls, v, d-1);
}
inline void fix(int u, ll v, int d)
{
	if(!fa[u]) fa[u]=u;
	cf=u, rd=d;
	for(int i=d+1, pr=u; i<=n; ++i)
	{
		mdfs(ch[stk[i]][0]^ch[stk[i]][1]^pr, v^(1ll<<i), i-1);
		pr=stk[i];
	}
}
inline void dfs(int u, ll v, int d)
{
	if(u==-1) return;
	if(!ls&&!rs)
	{
		fix(u, v, d);
		return;
	}
	stk[d]=u;
	dfs(ls, v, d-1);
	dfs(rs, v|(1ll<<d), d-1);
}
inline void ins(int &u, ll v, int d)
{
	if(u==-1) u=++top, ls=rs=-1;
	if(d==rd) { ls=rs=0; fix(u, v, d); return; }
	stk[d]=u;
	if(v&(1ll<<d)) ins(rs, v, d-1);
	else ins(ls, v, d-1);
}
inline int locate(int u, ll v, int d)
{
	if(!ls&&!rs) return u;
	if(v&(1ll<<d)) return locate(rs, v, d-1);
	return locate(ls, v, d-1);
}
char s[100];
int main()
{
	scanf("%d%d", &n, &m);
	--n;
	for(int i=1; i<=m; ++i)
	{
		ll x, y;
		scanf("%s%lld%lld", s, &x, &y);
		if(s[0]=='a') ad[++tp][0]=-x-1, ad[tp][1]=y;
		else del(rt, 0, n, x, y);
	}
	dfs(rt, 0, n);
	for(int i=tp; i; --i)
	{
		ll x=ad[i][0], y=ad[i][1];
		if(x<0)
		{
			x=-x-1;
			rans[++atp]=findfa(locate(rt, x, n))==findfa(locate(rt, y, n));
		}
		else
		{
			rd=ad[i][1];
			ins(rt, ad[i][0], n);
		}
	}
	for(int i=atp; i; --i) puts(rans[i]?"1":"0");
	return 0;
}