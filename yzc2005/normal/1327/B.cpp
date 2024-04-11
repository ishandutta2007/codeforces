#include <bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void ckmax(T &a, T b) {if(a < b) a = b;}
template <class T> inline void ckmin(T &a, T b) {if(a > b) a = b;}

const int N = 100005;
int t, k, x, n;
vector <int> g[N];
bool used[N], had[N];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d", &n);
		fu(i, 1, n) used[i] = had[i] = 0;
		fu(i, 1, n) {
			scanf("%d", &k);
			g[i].clear();
			while(k--) {
				scanf("%d", &x);
				g[i].push_back(x);
			}
		}
		int cnt = 0;
		fu(i, 1, n) {
			int cp = 0;
			fu(j, 0, g[i].size() - 1) if(!used[g[i][j]]) {
				cp = g[i][j];
				break;
			}
			if(cp) had[i] = used[cp] = 1, ++cnt;
		}
		if(cnt == n) {
			puts("OPTIMAL");
			continue;
		}
		puts("IMPROVE");
		int b = 0, g = 0;
		fd(i, n, 1) if(!used[i]) {
			b = i;
			break;
		}
		fd(i, n, 1) if(!had[i]) {
			g = i;
			break;
		} 
		printf("%d %d\n", g, b);
	}
	return 0;
}