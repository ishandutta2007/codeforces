#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = int(1e6), INF = 1 << 28;

struct Info { //0:01,1:10
	int cnt[2][2];

	void rev() {
		static int ncnt[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				ncnt[i][j] = cnt[1 - i][1 - j];
			}
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				cnt[i][j] = ncnt[i][j];
			}
		}
	}

	void set(int x) {
		fill(cnt[0], cnt[2], -INF);
		cnt[x][x] = 1;
	}

	Info() {

	}

	void merge(Info&a, Info&b) {
		fill(cnt[0], cnt[2], -INF);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cnt[i][j] = max(cnt[i][j], a.cnt[i][j]);
				cnt[i][j] = max(cnt[i][j], b.cnt[i][j]);
			}
		}
		for (int i = 0; i < 2; i++) {
			for (int ii = i; ii < 2; ii++) {
				for (int j = ii; j < 2; j++) {
					for (int jj = j; jj < 2; jj++) {
						cnt[i][jj] = max(cnt[i][jj], a.cnt[i][ii] + b.cnt[j][jj]);
						cnt[jj][i] = max(cnt[jj][i], a.cnt[jj][j] + b.cnt[ii][i]);
					}
				}
			}
		}
	}
};

Info a[MAX_N * 4];
bool mark[MAX_N * 4];
int n;

void apply(int t) {
	mark[t] = !mark[t];
	a[t].rev();
}

void relax(int t) {
	if (mark[t]) {
		mark[t] = false;
		apply(t + t);
		apply(t + t + 1);
	}
}

void update(int t) {
	a[t].merge(a[t + t], a[t + t + 1]);
}

void init(int t, int l, int r, int seq[]) {
	if (l + 1 == r) {
		a[t].set(seq[l]);
		return;
	}
	int m = (l + r) >> 1;
	init(t + t, l, m, seq);
	init(t + t + 1, m, r, seq);
	update(t);
}

void rev(int t, int l, int r, int L, int R) {
	if (L >= r || l >= R)
		return;
	if (L <= l && R >= r) {
		apply(t);
		return;
	}
	relax(t);
	int m = (l + r) >> 1;
	rev(t + t, l, m, L, R);
	rev(t + t + 1, m, r, L, R);
	update(t);
}

int ask() {
	Info t = a[1];
	return max(max(t.cnt[0][1], t.cnt[0][0]), t.cnt[1][1]);
}

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	static char buf[MAX_N * 2];
	scanf("%s", buf);
	static int a[MAX_N];
	for (int i = 0; i < n; i++) {
		a[i] = buf[i] == '4' ? 0 : 1;
	}
	init(1, 0, n, a);
	for (int i = 0; i < m; i++) {
		scanf(" ");
		scanf("%s", buf);
		if (buf[0] == 'c') {
			printf("%d\n", ask());
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			rev(1, 0, n, l - 1, r);
		}
	}
}

int main() {
	solve();
}