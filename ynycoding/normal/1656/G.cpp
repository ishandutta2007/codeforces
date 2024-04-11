#include <cstdio>
#include <algorithm>
const int N=200005;
int T, n, a[N], p[N], lst[N], cnt[N], to[N][2], fa[N], vis[N];
inline int findfa(int x) { return x==fa[x]?x:fa[x]=findfa(fa[x]); }
inline void adde(int x, int y)
{
	(to[x][0]?to[x][1]:to[x][0])=y;
}
inline void add(int x, int y)
{
//	printf("%d %d\n", x, y);
	adde(x, y), adde(y, x);
}
int cb;
void dfs(int u, int fa)
{
	::fa[u]=cb;
	p[u]=to[u][0]^to[u][1]^fa;
	vis[u]=1;
	if(!vis[p[u]]) dfs(p[u], u);
}
int main()//
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		std::fill(cnt+1, cnt+n+1, 0);
		std::fill(lst+1, lst+n+1, 0);
		for(int i=1; i<=n; ++i)
		{
			vis[i]=0;
			scanf("%d", a+i);
			++cnt[a[i]];
			p[i]=i;
			to[i][0]=to[i][1]=0;
		}
		int id=0;
		int mid=(n+1)/2;
		for(int i=1; i<=n; ++i) if(cnt[i]&1)
		{
			if(id) { puts("NO"); goto out; }
			id=i;
		}
		if((n&1)&&a[mid]==id&&cnt[id]==1) { puts("NO"); goto out; }
		if(a[mid]==id)
		{
			int t=1;
			while(a[t]!=id||t==mid) ++t;
			add(mid, t);
			a[mid]=a[t]=0;
		}
		for(int i=1; i<=n; ++i)
		{
			if(a[i])
			{
				if(lst[a[i]]) add(lst[a[i]], i), lst[a[i]]=0;
				else lst[a[i]]=i;
			}
			if(i*2<=n) add(i, n+1-i);
		}
		if(n&1) add(mid, lst[id]);
		for(int i=mid; i<=n; ++i) if(!vis[i])
		{
			cb=i;
			dfs(i, to[i][0]);
		}
//		for(int i=1; i<=n; ++i) printf("%d %d\n", i, p[i]);
//		puts("");
		for(int i=1; i*2<=n; ++i) if(findfa(i)!=findfa(1))
		{
			std::swap(p[i], p[n]);
			std::swap(p[n+1-i], p[1]);
			std::swap(p[1], p[n]);
			fa[findfa(i)]=findfa(1);
		}
		puts("YES");
		for(int i=1; i<=n; ++i) printf("%d ", p[i]);
		puts("");
//		for(int i=1; i<=n; ++i) printf("%d %d\n", i, p[i]);
//		puts("");
		out:;
	}
	return 0;
}