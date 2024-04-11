#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, m, q;
const int MAX_N = 1000 + 10;
int a[MAX_N][MAX_N];

struct TR {
	bool flip, swap;
	int n;

	TR() {
	}

	TR(bool f, bool s, int n) :
			flip(f), swap(s), n(n) {
	}

	void trans(int&r, int&c) {
		if (swap) {
			std::swap(r, c);
		}
		if (flip) {
			r = n - 1 - r;
		}
	}
};

struct Board {
	int a[MAX_N][MAX_N], n, m;
	int up[MAX_N][MAX_N]; //r,c
	TR tr;

	void init(int n, int m, TR tr) {
		this->n = n, this->m = m;
		this->tr = tr;
	}

	void set(int r, int c, int x) {
		tr.trans(r, c);
		a[r][c] = x;
	}

	void reset(int r, int c, int x) {
		tr.trans(r, c);
		a[r][c] = x;
		processCol(c);
	}

	void processCol(int c) {
		up[0][c] = a[0][c];
		for (int r = 1; r < n; ++r) {
			if (a[r][c] == 1) {
				up[r][c] = up[r - 1][c] + 1;
			} else {
				up[r][c] = 0;
			}
		}
	}

	void doit() {
		for (int c = 0; c < m; ++c) {
			processCol(c);
		}
	}

	int ask(int r, int c) {
		tr.trans(r, c);
//		cout << r << " " << c << endl;
		//at row r, above it ,contain column c
		//min at left
		static int what[MAX_N];
		what[c] = up[r][c];
		for (int i = c - 1; i >= 0; --i) {
			what[i] = min(what[i + 1], up[r][i]);
		}
		for (int i = c + 1; i < m; ++i) {
			what[i] = min(what[i - 1], up[r][i]);
		}

		int ans = 0;
		int R = c;
		for (int i = c; i >= 0; --i) {
			while (R + 1 < m && what[R + 1] >= what[i])
				++R;
			ans = max(ans, what[i] * (R - i + 1));
		}
		int L = c;
		for (int i = c; i < m; ++i) {
			while (L > 0 && what[L - 1] >= what[i])
				--L;
			ans = max(ans, what[i] * (i - L + 1));
		}
		return ans;
	}
} D[4];

int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", a[i] + j);
		}
	}
	D[0].init(n, m, TR(false, false, n));
	D[1].init(n, m, TR(true, false, n));
	D[2].init(m, n, TR(false, true, m));
	D[3].init(m, n, TR(true, true, m));

	for (int i = 0; i < 4; ++i) {
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < m; ++c) {
				D[i].set(r, c, a[r][c]);
			}
		}
		for (int c = 0; c < D[i].m; ++c) {
			D[i].processCol(c);
		}
	}

	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int r, c;
			scanf("%d%d", &r, &c), --r, --c;
			for (int i = 0; i < 4; ++i) {
				D[i].reset(r, c, 1 - a[r][c]);
			}
			a[r][c] = 1 - a[r][c];
		} else {
			int r, c;
			scanf("%d%d", &r, &c), --r, --c;
			int ans = 0;
			for (int i = 0; i < 4; ++i) {
				ans = max(ans, D[i].ask(r, c));
			}
			printf("%d\n", ans);
		}
	}
}