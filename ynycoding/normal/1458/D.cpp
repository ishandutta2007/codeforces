#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=1000005;
int T, n, cur, ans[N], cnt[N], deg[N], off=500000, top;
char s[N];
void dfs(int u)
{
	for(int t:{0, 1})
	{
		int v=t?u+1:u-1, id=u+t-1;
		while(cnt[id])
		{
			if(deg[u]>1&&cnt[id]==1) break;
			--deg[u], --deg[v];
			--cnt[id];
			putchar(t+'0');
			dfs(v);
		}
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		cur=off;
		scanf("%s", s+1);
		n=strlen(s+1);
		std::fill(cnt+off-n-1, cnt+off+n+1, 0);
		std::fill(deg+off-n-1, deg+off+n+1, 0);
		for(int i=1; i<=n; ++i) if(s[i]=='1') ++cnt[cur], ++deg[cur], ++deg[cur+1], ++cur;
		else --cur, ++deg[cur], ++deg[cur+1], ++cnt[cur];
		top=0;
		dfs(off);
		puts("");
	}
	return 0;
}