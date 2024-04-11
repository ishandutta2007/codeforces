#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
using std::vector;
const int N=300005;
int n, a[N], dfn[N], out[N], seq[N], cnt, id[N], tid, mx, top, dep[N], rok[N], p[N], rp[N];
ll ans;
vector<int> e[N];
bool cmp(int x, int y) { return a[x]<a[y]; }
void dfs(int u, int fa, int ok)
{
	dfn[u]=++top;
	if(ok&&a[u]>a[fa]) ++cnt, mx=a[fa];
	rok[a[u]]=ok=a[u]<a[fa];
	rp[top]=u;
	dep[u]=dep[fa]+1;
	std::sort(e[u].begin(), e[u].end(), cmp);
	for(int v:e[u]) if(v!=fa) dfs(v, u, ok);
	id[u]=++tid;
	seq[tid]=u;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), p[a[i]]=i;
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
	dfs(1, 0, 0);
	if(cnt>1) return puts("NO"), 0;
	int k=0;
	while(rok[k+1]) ++k;
	if(mx&&k!=mx) return puts("NO"), 0;
	for(int i=k+1; i<=n; ++i) if(rok[i]) return puts("NO"), 0;
	for(int i=1; i<k; ++i) if(id[p[i]]!=i) return puts("NO"), 0;
	if(dfn[p[k]]>dfn[seq[k]]) return puts("NO"), 0;
	for(int i=k+1; i<n; ++i) if(dfn[p[i]]>dfn[p[i+1]]) return puts("NO"), 0;
	puts("YES");
	for(int i=1; i<=n; ++i) if(rok[i]) ans+=dep[p[i]]-1;
	printf("%lld\n", ans);
	for(int i=1; i<=n; ++i) printf("%d ", dfn[i]);
	return 0;
}