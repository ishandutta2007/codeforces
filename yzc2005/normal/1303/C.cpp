#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 1e18;
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
typedef long long ll;
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}
 
const int N = 205, K = 30;
int t, n, in[K], ans[K], fa[K], tot;
bool used[K], g[K][K];
char s[N];
 
int get(int x) {
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
 
void dfs(int u) {
	used[u] = 1; putchar('a' + u);
	fu(v, 0, 25) if(g[u][v] && !used[v]) dfs(v);
}
 
int main() {
	for(rd(t); t; --t) {
		memset(g, 0, sizeof(g));
		memset(used, 0, sizeof(used));
		memset(in, 0, sizeof(in));
		fu(i, 0, 25) fa[i] = i;
		scanf("%s", s + 1); n = strlen(s + 1);
		fu(i, 1, n - 1) g[s[i] - 'a'][s[i + 1] - 'a'] = g[s[i + 1] - 'a'][s[i] - 'a'] = 1;
		bool flg = 0; 
		fu(i, 0, 25) {
			fu(j, 0, 25) in[i] += g[i][j];
			if(in[i] <= 2) continue;
			flg = 1;
			break;
		}
		fu(i, 0, 25) fu(j, i + 1, 25) {
			if(!g[i][j]) continue;
			int u = get(i), v = get(j);
			if(u == v) flg = 1;
			fa[u] = v;
		}
		if(flg) {
			puts("NO");
			continue;
		}
		puts("YES");
		tot = 0; fu(i, 0, 25) if(!used[i] && in[i] == 1) dfs(i);
		fu(i, 0, 25) if(!used[i]) putchar('a' + i);
		puts("");
	}
	return 0;
}