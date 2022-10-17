#include <bits/stdc++.h>
using namespace std;
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
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 100005;
int n, x, y, ans[N], d[N];
vector<int> g[N];
bool vis[N];

int main() {
	rd(n);
	if(n == 2) puts("0"), exit(0);
	if(n == 3) puts("0"), puts("1"), exit(0);
	fu(i, 1, n - 1) rd(x), rd(y), g[x].push_back(i), g[y].push_back(i), ++d[x], ++d[y];
	int u = max_element(d + 1, d + n + 1) - d;
	int cnt = 0;
	ans[g[u][0]] = ++cnt, ans[g[u][1]] = ++cnt;
	if(g[u].size() > 2) ans[g[u][2]] = ++cnt;
	fu(i, 1, n - 1) if(!ans[i]) ans[i] = ++cnt;
	fu(i, 1, n - 1) printf("%d\n", ans[i] - 1);
}