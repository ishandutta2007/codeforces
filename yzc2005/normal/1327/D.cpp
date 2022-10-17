#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 200005;
int t, n, p[N], c[N], tmp[N];
vector <int> d[N];
bool vis[N];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d", &n);
		fu(i, 1, n) scanf("%d", &p[i]);
		fu(i, 1, n) scanf("%d", &c[i]);
		fu(i, 1, n) d[i].clear() , vis[i] = 0;
		fu(i, 1, n) for(int j = i; j <= n; j += i) d[j].push_back(i);
		int ans = 0x3f3f3f3f;
		fu(i, 1, n) {
			if(vis[i]) continue;
			int u = i, len = 0;
			do {
				tmp[++len] = p[u];
				u = p[u];
				vis[u] = 1;
			} while(u != i);
			fu(j, 0, d[len].size() - 1) {
				int div = d[len][j];
				fu(q, 1, div) {
					bool ok = 1;
					for(int k = div + q; k <= len; k += div) if(c[tmp[k]] != c[tmp[k - div]]) ok = 0;
					if(ok) ckmin(ans, div);
				}
			}
		}
		printf("%d\n", ans);
	}
}