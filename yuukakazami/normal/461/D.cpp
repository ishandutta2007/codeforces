#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <cassert>
using namespace std;

const int MAX_N = int(1e5) + 10;
const int MOD = int(1e9) + 7;

struct Edge {
	int t, c;
	Edge(int t, int c) :
			t(t), c(c) {
	}
};

vector<Edge> E[MAX_N];
int n, k;

void addEdge(int u, int v, int c) {
	E[u].push_back(Edge(v, c));
	E[v].push_back(Edge(u, c));
}

bool bad;
//		constraint(r, 0, 0);
//		constraint(r, n + 1, 0);
//	}
//	for (int c = 0; c <= n + 1; ++c) {
//		constraint(n + 1, c, 0);
//	}
int col[MAX_N];

void dfs(int u, int what) {
	if (bad)
		return;
	if (col[u] != -1) {
		if (col[u] != what) {
			bad = true;
		}
		return;
	}
	col[u] = what;
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		dfs(e->t, what ^ e->c);
	}
}

void constraint(int r, int c, int v) {
	int d = min(r - 1, c - 1);
	d = min(d, n - r);
	d = min(d, n - c);
	int cc = abs(r - c) + d + 1;
	int L = cc - d, R = cc + d;
	L -= 2;
	if (L < 0)
		L = 0;
	if (R > n)
		R = n;
	addEdge(L, R, v);
}

//bitset<200> my[60][60];

int main() {

	//50 50;
//	int N = 11;
//	for (int i = 0; i < N; ++i) {
//		my[0][i][i] = true;
//	}
//	for (int r = 1; r < N; ++r) {
//		for (int c = 0; c < N; ++c) {
//			if (r - 2 >= 0)
//				my[r][c] ^= my[r - 2][c];
//			if (c - 1 >= 0)
//				my[r][c] ^= my[r - 1][c - 1];
//			if (c + 1 < N)
//				my[r][c] ^= my[r - 1][c + 1];
//		}
//	}
//
//	for (int r = 0; r < N; ++r) {
//		for (int c = 0; c < N; ++c) {
//			int a = -1, b;
//			for (int k = 0; k < N; ++k) {
//				if (my[r][c][k]) {
//					if (a == -1)
//						a = k;
//					b = k;
//				}
//			}
//			printf("%02d,%02d ", a, b);
////			printf("%02d ", (b - a) / 2);
//			int d = r;
//			d = min(d, c);
//			d = min(d, N - 1 - c);
//			d = min(d, N - 1 - r);
//			int cc = abs(r - c) + d;
//			assert(a == cc - d && b == cc + d);
//		}
//		puts("");
//	}

	cin >> n >> k;
	//1...n
	while (k--) {
		int r, c, v;
		scanf("%d%d", &r, &c);
		char ch;
		scanf(" ");
		scanf("%c", &ch);
		if (ch == 'o')
			v = 1;
		else
			v = 0;
		constraint(r, c, v);
	}
//	for (int r = 1; r <= n; ++r) {
//		constraint(r, 0, 0);
//		constraint(r, n + 1, 0);
//	}
//	for (int c = 0; c <= n + 1; ++c) {
//		constraint(n + 1, c, 0);
//	}
	memset(col, -1, sizeof col);
	int cnt = 0;
	bad = false;
	for (int i = 0; i <= n; ++i) {
		if (bad)
			break;
		if (col[i] == -1) {
			dfs(i, 0);
			++cnt;
		}
	}

	if (bad) {
		puts("0");
		return 0;
	}
	int ans = 1;
	--cnt;
	while (cnt--)
		ans = (ans + ans) % MOD;
	cout << ans << endl;
}