#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define INF 2147483647
#define ll long long
#define eps 1e-4
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 400005
struct Edge {
	int v, nxt;
}e[MAXN << 1];
int lst[MAXN], tot = 0;
inline void addedge (int u, int v) {
	e[++tot] = (Edge) {v, lst[u]};
	lst[u] = tot;
}
int dep[MAXN];
void dfs(int u, int fa) {
	for(int i = lst[u]; i; i = e[i].nxt) {
		if(e[i].v != fa) {
			dep[e[i].v] = dep[u] + 1;
			dfs(e[i].v, u);
		}
	}
}
int main()
{
	int n = read();
	For(i, 1, n-1) {
		int u = read(), v = read();
		addedge(u, v); addedge(v, u);
	}
	dep[1] = 1;
	dfs(1, 0);
	double ans = 0;
	For(i, 1, n) ans += 1.0 / dep[i];
	printf("%.10lf\n", ans);
    return 0;
}