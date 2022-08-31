#include <bits/stdc++.h>
#define lowbit(x) (x & -x)

const int N = 5054;

struct BST {
	struct node {int v, lc, rc;} x[20030731 / 2];

	int Row, Col, cnt = 0, root[N];

	int add(int id, int L, int R, int h, int v) {
		if (!id) id = ++cnt; x[id].v += v;
		if (L == R) return id;
		int M = (L + R - 1) >> 1;
		h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : (x[id].rc = add(x[id].rc, M + 1, R, h, v));
		return id;
	}

	int prefix(int id, int L, int R, int h) {
		if (!id || R <= h) return x[id].v;
		int M = (L + R - 1) >> 1;
		return h <= M ? prefix(x[id].lc, L, M, h) : x[id].lc[x].v + prefix(x[id].rc, M + 1, R, h);
	}

	void add(int r, int c, int v) {
		if (c < 1 || c > Col) return;
		for (; r <= Row; r += lowbit(r)) root[r] = add(root[r], 1, Col, c, v);
	}

	int sum(int r, int c) {
		int s = 0;
		for (; r > 0; r -= lowbit(r)) s += prefix(root[r], 1, Col, c);
		return s;
	}
	
} S, MD, AD;

int n, q;

int main() {
	int op, d, r, c, a;
	scanf("%d%d", &n, &q);
	S.Col = S.Row = MD.Row = AD.Row = n;
	MD.Col = AD.Col = 2 * n - 1;
	for (; q; --q)
		if (scanf("%d", &op), op == 1)
			switch (scanf("%d%d%d%d", &d, &r, &c, &a), d) {
				case 1:
					S.add(r, c, 1), S.add(r + a + 1, c, -1);
					AD.add(r, r + c + a, -1), AD.add(r + a + 1, r + c + a, 1);
					break;
				case 2:
					S.add(r, c + 1, -1), S.add(r + a + 1, c + 1, 1);
					MD.add(r, n - r + c - a, 1), MD.add(r + a + 1, n - r + c - a, -1);
					break;
				case 3:
					S.add(r - a, c, 1), S.add(r + 1, c, -1);
					MD.add(r - a, n - r + c + a + 1, -1), MD.add(r + 1, n - r + c + a + 1, 1);
					break;
				case 4:
					S.add(r - a, c + 1, -1), S.add(r + 1, c + 1, 1);
					AD.add(r - a, r + c - a - 1, 1), AD.add(r + 1, r + c - a - 1, -1);
					break;
			}
		else
			scanf("%d%d", &r, &c),
			printf("%d\n", S.sum(r, c) + MD.sum(r, n - r + c) + AD.sum(r, r + c - 1));
	return 0;
}