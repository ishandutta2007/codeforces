#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=300005;

int n, f[N], pa[N], is[N], rans[N], cur, sz;
vector<int> e[N];
void dfs(int u, int fa)
{
	pa[u]=fa;
	for(int v:e[u]) if(v!=fa)
	{
		dfs(v, u);
		f[u]^=f[v]+1;
	}
}
inline void ins(int x)
{
	if(is[x]) return;
	int p=0;
	while(!is[x])
	{
		is[x]=1;
		sz^=1;
		for(int v:e[x]) if(v!=pa[x]&&v!=p) cur^=f[v]+1;
		p=x;
		x=pa[x];
	}
	cur^=f[p]+1;
}
int main()
{
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0);
	cur=f[1], is[1]=1;
	rans[1]=f[1]?1:2;
	for(int i=2; i<=n; ++i)
	{
		ins(i);
		rans[i]=(cur^sz)?1:2;
	}
	for(int i=1; i<=n; ++i) putchar(rans[i]+'0');
	return 0;
}