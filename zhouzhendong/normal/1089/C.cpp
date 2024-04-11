#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const int inf = 0x3f3f3f3f;

int n, m;
int a[N], b[N];
int dis[N][N];

void init() {
	memset(dis, 0x3f, sizeof dis);
	scanf("%d%d", &n, &m);
	while (m--) {
		int k, x;
		scanf("%d", &k);
		int las = 0;
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &x);
			if (las) {
				dis[x][las] = 1;
				dis[las][x] = 1;
			}
			las = x;
		}
	}
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dis[i][j] > dis[i][k] + dis[k][j]) {
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}
}

int getdis(int x) {
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		ans += dis[a[x]][a[i]];
	}
	return ans;
}

int out() {
	int x = 1, d = inf;
	for (int i = 1; i <= m; ++i) {
		int tmp = getdis(i);
		if (tmp < d) {
			d = tmp;
			x = i;
		}
	}
	printf("%d\n", a[x]);
	fflush(stdout);
	return x;
}

void change(int x) {
	int y;
	scanf("%d", &y);
	int cnt = 0;
	for (int i = 1; i <= m; ++i) {
		if (dis[a[x]][a[i]] > dis[y][a[i]]) {
			b[++cnt] = a[i];
		}
	}
	for (int i = 1; i <= cnt; ++i) {
		a[i] = b[i];
	}
	m = cnt;
}

void Solve() {
	m = n;
	for (int i = 1; i <= n; ++i) {
		a[i] = i;
	}
	while (1) {
		int x = out();
		char res[10];
		scanf("%s", res + 1);
		if (res[1] == 'F') {
			break;
		}
		change(x);
	}
}

int main() {
	init();
/*	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			cout << dis[i][j] << ' ';
		puts("");
		}*/
	for (int i = 1; i <= n; ++i) {
		Solve();
	}
	return 0;
}