#include <cstdio>
#include <vector>
#include <set>
#define pb push_back
#define MAXN 100001
using std::vector;
using std::set;
int n, m, vis[MAXN];
vector<int> e[MAXN];
set<int> st;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1, a, b; i<=m; ++i) scanf("%d%d", &a, &b), e[a].pb(b), e[b].pb(a);
	st.insert(1);
	for(int cur=0; cur<n; ++cur)
	{
		int u=*(st.begin());
		vis[u]=1;
		st.erase(st.begin());
		printf("%d ", u);
		for(int i=0; i<e[u].size(); ++i)
		{
			int v=e[u][i];
			if(vis[v]) continue;
			st.insert(v);
		}
	}
	return 0;
}