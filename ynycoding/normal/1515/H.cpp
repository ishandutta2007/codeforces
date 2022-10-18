#include <cstdio>
#include <algorithm>
const int N=200005, B=65, D=20;
int n, q, rt, a[N], top;
int ch[N*B][2], is[N*B], cnt[N*B], t01[N*B], t10[N*B];
#define ls ch[u][0]
#define rs ch[u][1]
inline void apply(int u, int v01, int v10)
{
	int x=t01[u], y=t10[u];
	t01[u]=(x&(~v10))|((~x)&v01);
	t10[u]=(y&(~v01))|((~y)&v10);
}
inline void pushdown(int u, int d)
{
	apply(ls, t01[u], t10[u]);
	apply(rs, t01[u], t10[u]);
	if((ls&&(t01[u]&(1<<d)))||(rs&&(t10[u]&(1<<d)))) std::swap(ls, rs);
	t01[u]=t10[u]=0;
}
inline void upt(int u, int d)
{
	cnt[u]=cnt[ls]+cnt[rs];
	is[u]=is[ls]|is[rs]|((ls&&rs)<<d);
}
inline void insert(int &u, int d, int v)
{
	if(!u) u=++top;
	cnt[u]=1;
	if(d<0) return;
	if(v&(1<<d)) insert(rs, d-1, v);
	else insert(ls, d-1, v);
	upt(u, d);
}
void split(int u, int &x, int &y, int d, int v)
{
	if(!u) { x=y=0; return; }
	if(d<0) { y=u, x=0; return; }
	pushdown(u, d);
	if(v&(1<<d))
	{
		x=u, y=++top;
		split(rs, rs, ch[y][1], d-1, v);
	}
	else
	{
		y=u, x=++top;
		split(ls, ch[x][0], ls, d-1, v);
	}
	upt(x, d), upt(y, d);
}
int merge(int x, int y, int d)
{
	if(!x||!y) return x|y;
	if(d<0) return x;
	pushdown(x, d), pushdown(y, d);
	int u=x;
	ls=merge(ls, ch[y][0], d-1);
	rs=merge(rs, ch[y][1], d-1);
	upt(u, d);
	return u;
}
void dfs(int u, int d, int v, int tp)//0:and 1:or
{
	if(!(is[u]&v)) return;
	pushdown(u, d);
	if(ls&&rs&&(v&(1<<d))) (tp?rs:ls)=merge(ls, rs, d-1), (tp?ls:rs)=0;
	dfs(ls, d-1, v, tp);
	dfs(rs, d-1, v, tp);
	upt(u, d);
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), insert(rt, D, a[i]);
	for(int i=1, t, l, r, v; i<=q; ++i)
	{
		scanf("%d%d%d", &t, &l, &r);
		int x, y, z;
		split(rt, x, y, D, l);
		split(y, y, z, D, r+1);
		if(t==4) printf("%d\n", cnt[y]);
		else
		{
			scanf("%d", &v);
			if(t==1)
			{
				dfs(y, D, ~v, 0);
				apply(y, 0, ~v);
			}
			if(t==2)
			{
				dfs(y, D, v, 1);
				apply(y, v, 0);
			}
			if(t==3)
			{
				int l=t01[y], r=t10[y];
				t01[y]=(l&(~v))|((~l)&v);
				t10[y]=(r&(~v))|((~r)&v);
			}
		}
		rt=merge(x, y, D);
		rt=merge(rt, z, D);
	}
	return 0;
}