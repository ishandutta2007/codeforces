#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
const int N = 1005, K = 45;
const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
inline void rd(int &x) {
    x = 0; 
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
} 
int n, m, k, q, a[N][N], dis[N][N][K];
vector <PII> color[K];
bool vis[N][N][K], visit[K];

inline void prework(int c) {
	queue <PII> q;
	memset(visit, 0, sizeof(visit));
	visit[c] = 1;
	fu(i, 0, color[c].size() - 1) {
		q.push(color[c][i]);
		vis[color[c][i].first][color[c][i].second][c] = 1;
	}
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second, xx, yy; q.pop();
		fu(i, 0, 3) {
			xx = x + dir[i][0], yy = y + dir[i][1];
			if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if(vis[xx][yy][c]) continue;
			vis[xx][yy][c] = 1;
			dis[xx][yy][c] = dis[x][y][c] + 1;
			q.push(PII(xx, yy));
		} 
		if(visit[a[x][y]]) continue;
		visit[a[x][y]] = 1;
		fu(i, 0, color[a[x][y]].size() - 1) {
			xx = color[a[x][y]][i].first, yy = color[a[x][y]][i].second;
			if(vis[xx][yy][c]) continue;
			vis[xx][yy][c] = 1;
			dis[xx][yy][c] = dis[x][y][c] + 1;
			q.push(PII(xx, yy));
		}
	}
}

int main() {
	rd(n), rd(m), rd(k);
	fu(i, 1, n) fu(j, 1, m) rd(a[i][j]), color[a[i][j]].push_back(PII(i, j));
	fu(i, 1, k) prework(i);
	rd(q); for(int x1, y1, x2, y2, ans; q; --q) {
		rd(x1), rd(y1), rd(x2), rd(y2);
		ans = abs(x1 - x2) + abs(y1 - y2);
		fu(c, 1, k) ans = min(ans, dis[x1][y1][c] + dis[x2][y2][c] + 1);
		printf("%d\n", ans); 
	}
	return 0;
}