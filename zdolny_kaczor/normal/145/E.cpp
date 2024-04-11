# include <bits/stdc++.h>
using namespace std;
struct node {
	int zeros, ones, inc, dec;
	node() : zeros (0), ones(0), inc(0), dec(0) {}
	node(int v) {
		inc = dec = 1;
		zeros = ones = 0;
		if (v)
			ones = 1;
		else
			zeros = 1;
	}
	node(int z, int o, int i, int d) : zeros(z), ones(o), inc(i), dec(d) {}
};
node operator! (node a) {
	return node(a.ones, a.zeros, a.dec, a.inc);
}
node operator* (node a, node b) {
	return node(a.zeros + b.zeros, a.ones + b.ones, max(a.zeros + b.inc, a.inc + b.ones), max(a.ones + b.dec, a.dec + b.zeros));
}
const int MN = 1 << 20;
node tree[MN * 2];
bool inv[MN * 2];
void mark(int wh) {
	tree[wh] = !tree[wh];
	inv[wh] = !inv[wh];
}
void push(int wh) {
	if (wh < MN && inv[wh]) {
		mark(wh * 2);
		mark(wh * 2 + 1);
	}
	inv[wh] = false;
}
char in[MN];
void invert(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1) {
	push(wh);
	if (l > rb || r < lb) return;
	if (l <= lb && r >= rb) mark(wh);
	else {
		invert(l, r, wh * 2, lb, (lb + rb) / 2);
		invert(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
		tree[wh] = tree[wh * 2] * tree[wh * 2 + 1];
	}
}
int main() {
	int n, q;
	scanf("%d%d%s", &n, &q, in + 1);
	for (int i = 1; i <= n; ++i) {
		tree[i + MN] = node(in[i] == '4' ? 0 : 1);
	}
	for (int i = MN - 1; i; --i) {
		tree[i] = tree[i * 2] * tree[i * 2 + 1];
	}
	while (q--) {
		char type[10];
		scanf("%s", type);
		if (strcmp(type, "count") == 0) {
			printf("%d\n", tree[1].inc);
		}
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			invert(l, r);
		}
	}
}