#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
inline void ckmin(int &a, int b) {a = min(a, b);}

const int N = 1000005;
int n, k, a, p, dfn, f[N], mn[N], id[N], ans[N];
vector <P> g[N];
char s[2];

void dfs(int u) {
	sort(g[u].begin(), g[u].end());
	fu(i, 0, g[u].size() - 1) {
		int v = g[u][i].second;
		f[v] = f[u] + 1;
		if(id[v]) {
			ckmin(f[v], mn[u] + (++dfn));
			ans[id[v]] = f[v];
		}
		mn[v] = min(mn[u], f[v] - dfn + (id[v] > 0));
		dfs(v);
	}
}

int main() {
	rd(n);
	fu(i, 1, n) rd(p), scanf("%s", s), g[p].push_back(P(s[0] - 'a', i));
	rd(k); 
	fu(i, 1, k) rd(a), id[a] = i;
	dfs(0); 
	fu(i, 1, k) printf("%d ", ans[i]);
}