#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN=300000+10;

bool all[MAXN*4];
int ans[MAXN];
int n, m;

void modify(int rt, int l, int r, int ll, int rr, int x) {
	if (l==r) {
		if (x!=l) {
			all[rt]=true;
			ans[l]=x;
		}
		return;
	}
	if (!all[lson] && ll<=mid) modify(lson, l, mid, ll, rr, x);
	if (!all[rson] && rr>mid) modify(rson, mid+1, r, ll, rr, x);
	all[rt]=all[lson]&all[rson];
}

int main() {
	scanf("%d%d", &n, &m);
	memset(all, 0, sizeof(all));
	memset(ans, 0, sizeof(ans));
	while (m--) {
		int l, r, x; scanf("%d%d%d", &l, &r, &x);
		modify(1, 1, n, l, r, x);
	}
	for (int i=1; i<=n; i++) {
		if (i!=1) putchar(' ');
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}