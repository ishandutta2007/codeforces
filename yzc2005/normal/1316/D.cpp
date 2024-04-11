#include <bits/stdc++.h>
//pray for me. 
using namespace std;
typedef long long ll;
typedef pair <int, int> PII;
#define fi first
#define se second
#define fu(i, a, b) for(int i = a, I = (b) + 1; i < I; ++i)
#define fd(i, a, b) for(int i = a, I = (b) - 1; i > I; --i)
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

const int N = 1005;
int n, m;
PII a[N][N];
char ans[N][N];
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char dc[] = {'R', 'D', 'L', 'U'}, dcc[] = {'L', 'U', 'R', 'D'}; 
queue <PII> q, qu;

int main() {
	rd(n);
	fu(i, 1, n) 
		fu(j, 1, n) {
			rd(a[i][j].fi), rd(a[i][j].se);
			if(a[i][j].fi == i && a[i][j].se == j) {
				ans[i][j] = 'X';
				q.push(PII(i, j));
			} else {
				ans[i][j] = '*';
				if(a[i][j].fi == -1) qu.push(PII(i, j));
			}
		} 
	while(!q.empty()) {
		int x = q.front().fi, y = q.front().se; q.pop();
		fu(k, 0, 3) {
			int xx = x + dx[k], yy = y + dy[k];
			if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
			if(a[xx][yy].fi != a[x][y].fi || a[xx][yy].se != a[x][y].se || ans[xx][yy] != '*') continue;
			ans[xx][yy] = dcc[k];
			q.push(PII(xx, yy));
		}
	}
	while(!qu.empty()) {
		int x = qu.front().fi, y = qu.front().se; qu.pop();
		if(ans[x][y] != '*') continue;
		fu(k, 0, 3) {
			int xx = x + dx[k], yy = y + dy[k];
			if(xx < 1 || xx > n || yy < 1 || yy > n) continue;
			if(a[xx][yy].fi != -1) continue;
			ans[x][y] = dc[k];
			if(ans[xx][yy] == '*') ans[xx][yy] = dcc[k];
			break;
		}
	}
	fu(i, 1, n) fu(j, 1, n) if(ans[i][j] == '*') puts("INVALID"), exit(0);
	puts("VALID");
	fu(i, 1, n) printf("%s\n", ans[i] + 1);
	return 0;
}