#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;

int tree[1<<22];
int n, m;

void build(int d, int rt, int l, int r) {
	if (l==r) {
		scanf("%d", &tree[rt]);
		return;
	}
	build(d-1, lson, l, mid);
	build(d-1, rson, mid+1, r);
	if (d&1) tree[rt]=tree[lson] | tree[rson];
	else tree[rt]=tree[lson] ^ tree[rson];
}

void modify(int d, int rt, int l, int r, int p, int v) {
	if (l==r) {
		tree[rt]=v;
		return;
	}
	if (p<=mid) modify(d-1, lson, l, mid, p, v);
	else modify(d-1, rson, mid+1, r, p, v);
	if (d&1) tree[rt]=tree[lson] | tree[rson];
	else tree[rt]=tree[lson] ^ tree[rson];
}


int main() {
	scanf("%d%d", &n, &m);
	build(n, 1, 1, 1<<n);
	while (m--) {
		int p, b; scanf("%d%d", &p, &b);
		modify(n, 1, 1, 1<<n, p, b);
		printf("%d\n", tree[1]);
	}
	return 0;
}