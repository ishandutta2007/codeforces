#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=400005;
int T, n, m, k, nk, rans[N];
vector<int> e[N];
inline int gid(int x, int y) { return (x-1)*(k-1)+y; }
inline void add(int x, int y) { e[x].pb(y); }
int dfn[N], low[N], stk[N], in[N], top, cnt, col[N], tot;
void tarjan(int u)
{
	dfn[u]=low[u]=++cnt;
	in[u]=1;
	stk[++top]=u;
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
		stk[top+1]=0;
		while(stk[top+1]!=u)
		{
			in[stk[top]]=0;
			col[stk[top]]=tot;
			--top;
		}
	}
}
int main()
{
	scanf("%d", &T);
	// int ct=0;
	while(T--)
	{
		// ++ct;
		scanf("%d%d%d", &n, &m, &k);
		// if(ct==51) printf("%d %d %d\n", n, m, k);
		nk=n*(k-1);
		for(int i=1; i<=2*nk; ++i) e[i].clear();
		for(int i=1, tp, x, y, z; i<=m; ++i)
		{
			scanf("%d%d%d", &tp, &x, &y);
			// if(ct==51) printf("%d %d %d ", tp, x, y);
			if(tp==1)
			{
				if(y==1) add(gid(x, 1), gid(x, 1)+nk);
				else if(y<k) add(gid(x, y), gid(x, y-1));
				if(y==k) add(gid(x, k-1)+nk, gid(x, k-1));
				else if(y>1) add(gid(x, y-1)+nk, gid(x, y)+nk);
			}
			if(tp==2)
			{
				scanf("%d", &z);
				// if(ct==51) printf("%d", z);
				for(int a=std::max(1, z-k); a<k; ++a)
				{
					int b=z-a-1;
					// printf("cons %d %d %d\n", i, a, b);
					if(b>0)
					{
						add(gid(x, a)+nk, gid(y, b));
						add(gid(y, a)+nk, gid(x, b));
					}
					else
					{
						add(gid(x, a)+nk, gid(x, a));
						add(gid(y, a)+nk, gid(y, a));
					}
				}
			}
			if(tp==3)
			{
				scanf("%d", &z);
				// if(ct==51) printf("%d", z);
				--z;
				for(int a=1; a<std::min(k, z); ++a)
				{
					int b=z-a;
					if(b<k)
					{
						add(gid(x, a), gid(y, b)+nk);
						add(gid(y, a), gid(x, b)+nk);
					}
					else
					{
						add(gid(x, a), gid(x, a)+nk);
						add(gid(y, a), gid(y, a)+nk);
					}
				}
			}
			// if(ct==51) puts("");
		}
		for(int i=1; i<=n; ++i)
		{
			for(int t=1; t+1<k; ++t) add(gid(i, t), gid(i, t+1)), add(gid(i, t+1)+nk, gid(i, t)+nk);
			if(i<n) for(int t=1; t<k; ++t) add(gid(i+1, t), gid(i, t)), add(gid(i, t)+nk, gid(i+1, t)+nk);
		}
		// puts("fa");
		tot=top=cnt=0;
		std::fill(dfn, dfn+2*nk+1, 0);
		for(int i=1; i<=2*nk; ++i) if(!dfn[i]) tarjan(i);
		for(int i=1; i<=n; ++i)
		{
			rans[i]=1;
			for(int t=1; t<k; ++t)
			{
				if(col[gid(i, t)]==col[gid(i, t)+nk]) { puts("-1"); goto out; }
				if(col[gid(i, t)]>col[gid(i, t)+nk]) rans[i]=t+1;
			}
		}
		for(int i=1; i<=n; ++i) printf("%d ", rans[i]);
		puts("");
		out:;
	}
	return 0;
}