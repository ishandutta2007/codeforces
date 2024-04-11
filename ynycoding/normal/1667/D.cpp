#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=200005;

int T, n, f[N][2], pa[N], rct[N], stk[N][2], top;
vector<int> e[N];
bool dfs(int u, int fa)
{
	pa[u]=fa;
	int a=0, b=0, c=0, ct=e[u].size()-(fa>0);
	rct[u]=ct&1;
	for(int v:e[u]) if(v!=fa)
	{
		if(!dfs(v, u)) return 0;
		if(f[v][0]&&f[v][1]) ++c;
		else if(f[v][rct[v]]) ++a;
		else ++b;
	}
	f[u][0]=(a*2<=ct+1&&b*2<=ct);
	int ra=(ct+1)/2+1-2*rct[u], rb=ct/2-1+2*rct[u];
	f[u][1]=(ct&&a<=ra&&b<=rb);
	// printf("in %d %d %d %d %d %d %d\n", u, f[u][0], f[u][1], a, b, c, rct[u]);
	if(!f[u][0]&&!f[u][1]) return 0;
	return 1;
}
void prt(int u, int p, int fa)
{
	vector<int> a, b, c;
	for(int v:e[u]) if(v!=fa)
	{
		if(f[v][0]&&f[v][1]) c.pb(v);
		else if(f[v][rct[v]]) a.pb(v);
		else b.pb(v);
	}
	int cur=0;
	while(a.size()+b.size()+c.size())
	{
		if(a.size()+b.size()+c.size()==p) stk[++top][0]=pa[u], stk[top][1]=u, cur^=1;
		int x=0;
		if(!cur)
		{
			// if(a.empty()&&c.empty()) exit(514);
			if(a.empty()) x=c.back(), c.pop_back();
			else x=a.back(), a.pop_back();
		}
		else
		{
			// if(b.empty()&&c.empty()) exit(114);
			if(b.empty()) x=c.back(), c.pop_back();
			else x=b.back(), b.pop_back();
		}
		prt(x, cur^rct[x], u);
		cur^=1;
	}
	if(!p&&u!=1) stk[++top][0]=pa[u], stk[top][1]=u;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) f[i][0]=f[i][1]=0, e[i].clear();
		for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), e[x].pb(y), e[y].pb(x);
		if(!dfs(1, 0)||!f[1][0]) { puts("NO"); continue; }
		puts("YES");
		top=0;
		prt(1, 0, 0);
		for(int i=top; i; --i) printf("%d %d\n", stk[i][0], stk[i][1]);
	}
	return 0;
}