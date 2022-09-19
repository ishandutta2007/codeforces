# include <bits/stdc++.h>
using namespace std;
const int MN = 1 << 17;
int tree[MN * 2];
void mark(int l, int r, int val, int wh = 1, int lb = 0, int rb = MN - 1) {
	if (l > rb || r < lb) return;
	if (l <= lb && r >= rb) tree[wh] |= val;
	else {
		mark(l, r, val, wh * 2, lb, (lb + rb) / 2);
		mark(l, r, val, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
	}
}
int read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1) {
	if (l > rb || r < lb) return ~0;
	if (l <= lb && r >= rb) return tree[wh];
	return read(l, r, wh * 2, lb, (lb + rb) / 2) & read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
int l[MN], r[MN], q[MN];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", l + i, r + i, q + i);
		mark(l[i], r[i], q[i]);
	}
	for (int i = 2; i < MN * 2; ++i)
		tree[i] |= tree[i / 2];
	for (int i = MN - 1; i >= 0; --i) {
		tree[i] = tree[i * 2] & tree[i * 2 + 1];
	}
	for (int i = 0; i < m; ++i) {
		if (read(l[i], r[i]) != q[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", tree[i + MN]);
	printf("\n");
}