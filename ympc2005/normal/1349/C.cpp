#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1005;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int Q, n, m, d[N][N];

char s[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &Q);
	memset(d, -1, sizeof(d));
	
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		
		for (int j = 1; j <= m; j++) {
			if (j < m && s[i][j] == s[i][j + 1]) {
				d[i][j] = d[i][j + 1] = 0;
			}
			
			if (i > 1 && s[i][j] == s[i - 1][j]) {
				d[i][j] = d[i - 1][j] = 0;
			}
		} 
	}
	
	queue <pii> q;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (~d[i][j]) {
				q.push(pii(i, j));
			}
		}
	}
	
	while (!q.empty()) {
		pii cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i], cy = y + dy[i];
			
			if (cx < 1 || cx > n || cy < 1 || cy > m || ~d[cx][cy]) {
				continue;
			}
			
			d[cx][cy] = d[x][y] + 1;
			q.push(pii(cx, cy));
		}
	}
	
	for (int x, y, i = 1; i <= Q; i++) {
		ll t;
		scanf("%d%d%lld", &x, &y, &t);
		
		if (~d[x][y] && d[x][y] <= t) {
			printf("%c\n", '0' + ((s[x][y] - '0')^((t - d[x][y])&1)));
		} else {
			printf("%c\n", s[x][y]);
		}
	}
}