#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <bitset>
#define x first
#define y second
#define pb push_back
#define N 105
using std::bitset;
using std::vector;
using std::pair;
using std::priority_queue;
int n, ok[N], sz[N], tot, x, y, mx, tp;
int rs[N];
vector<int> e[N], val[N], id;
bitset<N> bs[N], cur, stk[N];
inline int gmx(const bitset<N> &a)
{
	int x=n;
	while(~x&&!a[x]) --x;
	return x;
}
bool operator <(const bitset<N> &a, const bitset<N> &b) { return a.to_string()<b.to_string(); }
struct cmp
{
	bool operator()(const bitset<N> &a, const bitset<N> &b) { return a<b; }
};
priority_queue<bitset<N>, vector<bitset<N>>, cmp> q;
void proc(int u)
{
	auto &b=bs[u];
	cur.reset();
	tp=0;
	for(int x:id) stk[++tp]=bs[x];
	for(int i=1; i<=tp; ++i)
	{
		int j=0;
		while(stk[i][j]) stk[i][j]=0, ++j;
		stk[i][j]=1;
	}
	for(int i=sz[u]; ~i; --i)
	{
		while(!q.empty()) q.pop();
		for(int j=1; j<=tp; ++j) if(stk[j].count()) q.push(stk[j]);
		for(int j=i-1; ~j&&!q.empty(); --j)
		{
			if(gmx(q.top())<j) q.pop();
			else if(gmx(q.top())>j) break;
			else
			{
				auto x=q.top();
				q.pop();
				x.flip(j);
				if(x.count()) q.push(x);
			}
		}
		if(!q.empty())
		{
			b.set(i);
			int id=0;
			for(int j=1; j<=tp; ++j) if(stk[id]<stk[j]) id=j;
			if(stk[id].count()==1||gmx(stk[id])<i) rs[id]=i, stk[id].reset();
			else stk[id].flip(i);
		}
	}
}
void dfs(int u, int fa)
{
	sz[u]=1;
	for(int v:e[u]) if(v!=fa) dfs(v, u), sz[u]+=sz[v];
	id.clear();
	for(int v:e[u]) if(v!=fa) id.pb(v);
	proc(u);
	int c=0;
	for(int v:e[u]) if(v!=fa)
	{
		val[u].pb(rs[c+1]);
		++c;
	}
	else val[u].pb(-1);
}
void grt(int u, int fa)
{
	int c=0;
	for(int v:e[u]) if(v!=fa)
	{
		if(ok[v])
		{
			grt(v, u);
			if(val[u][c]>mx) mx=val[u][c], x=u, y=v;
		}
		++c;
	}
	else ++c;
}
void del(int u, int fa)
{
	ok[u]=0, --tot;
	for(int v:e[u]) if(v!=fa&&ok[v]) del(v, u);
}
int main()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	tot=n;
	dfs(1, 0);
	std::fill(ok+1, ok+n+1, 1);
	int pr=1;
	while(tot>1)
	{
		mx=-1;
		grt(pr, 0);
		printf("? %d %d\n", x, y);
		fflush(stdout);
		int t;
		scanf("%d", &t);
		if(t==x) std::swap(x, y);
		del(x, y);
		pr=y;
	}
	printf("! %d\n", pr);
	return 0;
}