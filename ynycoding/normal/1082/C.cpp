#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#define MAXN 100001
using std::priority_queue;
using std::vector;
int n, m, mn=0x3f3f3f3f, ans, sz[MAXN], id[MAXN];
priority_queue<int> q[MAXN];
vector<int> sum[MAXN];
bool cmp(int a, int b) { return sz[a]<sz[b]; }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, a, b; i<=n; ++i) scanf("%d%d", &a, &b), q[a].push(b), ++sz[a];
	for(int i=1; i<=m; ++i)
	{
		id[i]=i;
		sum[i].push_back(0);
		for(int j=1; !q[i].empty(); ++j) sum[i].push_back(sum[i][j-1]+q[i].top()), q[i].pop();
	}
	std::sort(id+1, id+m+1, cmp);
	for(int i=1, l=1; i<=sz[id[m]]; ++i)
	{
		int res=0;
		while(sz[id[l]]<i) ++l;
		for(int j=l; j<=m; ++j) res+=sum[id[j]][i]<0?0:sum[id[j]][i];
		ans=std::max(ans, res);
	}
	printf("%d", ans);
	return 0;
}