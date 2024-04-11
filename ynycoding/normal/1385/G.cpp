#include <cstdio>
#include <algorithm>
#define N 200005
int T, n, a[N][2], count[N], vis[N<<1], col[N<<1], cnt, swp, ans, tp;
int nxt[N<<2], head[N<<1], to[N<<2], top;
inline void add(int x, int y) { nxt[++top]=head[x], head[x]=top, to[top]=y; }
inline void adde(int x, int y) { add(x, y), add(y, x); }
bool dfs(int u)
{
	vis[u]=tp;
	++cnt, swp+=u&1;
	if(vis[u^1]==tp) return 1;
	for(int i=head[u]; i; i=nxt[i]) if((!vis[to[i]])&&dfs(to[i])) return 1;
	return 0;
}
void gcol(int u)
{
	col[u]=1;
	for(int i=head[u]; i; i=nxt[i]) if(!col[to[i]]) gcol(to[i]);
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		std::fill(nxt+1, nxt+top+1, 0), std::fill(to+1, to+top+1, 0), std::fill(head+1, head+n*2+2, 0), std::fill(vis+1, vis+2*n+2, 0),
		std::fill(col+1, col+2*n+2, 0), std::fill(count+1, count+n+1, 0);
		for(int i=1; i<=n; ++i) a[i][0]=a[i][1]=0;
		scanf("%d", &n);
		top=tp=ans=0;
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), ++count[x],
		a[x][1]?adde(a[x][1]<<1, i<<1|1), adde(i<<1, a[x][1]<<1|1), 0:a[x][1]=i;
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), ++count[x],
		a[x][1]?adde(a[x][1]<<1, i<<1|a[x][0]), adde(a[x][1]<<1|1, i<<1|a[x][0]^1), 0:a[x][0]=1, a[x][1]=i;
		for(int i=1; i<=n; ++i) if(count[i]!=2) { puts("-1"); goto out; }
		for(int i=2; i<=2*n+1; ++i)
		{
			if(vis[i]||vis[i^1]) continue;
			cnt=swp=0, ++tp;
			if(dfs(i)) { puts("-1"); goto out; }
			cnt<swp*2?gcol(i^1), ans+=cnt-swp:(gcol(i), ans+=swp);
		}
		printf("%d\n", ans);
		for(int i=3; i<=2*n+1; i+=2) if(col[i]) printf("%d ", i/2);
		puts("");
		out:;
	}
	return 0;
}