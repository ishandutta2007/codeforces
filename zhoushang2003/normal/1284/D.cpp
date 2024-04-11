#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 100005;
struct shit {
	int l1, r1, l2, r2;
};
shit shi[maxn];
int tmp[maxn << 1], tp;

int iseg[maxn * 600], lt[maxn * 600], rt[maxn * 600], ip;
int iquery(int now, int L, int R, int l) {
	if(R < l or !now) return 0;
	if(L >= l) return iseg[now];
	int M = (L + R) >> 1;
	return iquery(lt[now], L, M, l) + iquery(rt[now], M + 1, R, l);
}

void imodi(int &now, int L, int R, int p, int x) {
	if(!now) now = ++ ip;
	iseg[now] += x;
	if(L == R) return;
	int M = (L + R) >> 1;
	if(p <= M) imodi(lt[now], L, M, p, x);
	else imodi(rt[now], M + 1, R, p, x);
}

int seg[maxn << 3];
int query(int now, int L, int R, int r, int il) {
	if(L > r) return 0;
	if(R <= r) return iquery(seg[now], 1, tp, il);
	int M = (L + R) >> 1;
	return query(now << 1, L, M, r, il) + query(now << 1 | 1, M + 1, R, r, il);
}

void modi(int now, int L, int R, int p, int pp, int x) {
	/* if(now == 1) debug("%d %d %d\n", p, pp, x); */
	imodi(seg[now], 1, tp, pp, x);
	if(L == R) return;
	int M = (L + R) >> 1;
	if(p <= M) modi(now << 1, L, M, p, pp, x);
	else modi(now << 1 | 1, M + 1, R, p, pp, x);
}

std::vector<shit> stmp[maxn << 1];
bool solve(int n) {
	std::sort(shi + 1, shi + n + 1, [](shit x, shit y) { return x.l1 < y.l1; });

	/* for(int i = 1; i <= n; i ++) */
	/* 	debug("%d %d %d %d\n", shi[i].l1, shi[i].r1, shi[i].l2, shi[i].r2); */

	int be = 1, tot = 0;
	for(int i = 1; i <= n; i ++) {
		while(shi[i].l1 > be) {
			for(shit s : stmp[be]) {
				modi(1, 1, tp, s.l2, s.r2, -1);
				-- tot;
			}
			++ be;
		}
		int k = query(1, 1, tp, shi[i].r2, shi[i].l2);
		if(k != tot) return 1;
		stmp[shi[i].r1].push_back(shi[i]);
		modi(1, 1, tp, shi[i].l2, shi[i].r2, 1);
		++ tot;
	}

	for(int i = 1; i <= tp; i ++)
		stmp[i].clear();

	for(int i = 1; i <= tp; i ++)
		iseg[i] = lt[i] = rt[i] = 0;
	memset(seg, 0, sizeof seg);

	return 0;
}

int main() {
	int n = read;
	for(int i = 1; i <= n; i ++)
		read(shi[i].l1, shi[i].r1, shi[i].l2, shi[i].r2);

	tp = 0;
	for(int i = 1; i <= n; i ++) {
		tmp[++ tp] = shi[i].l1;
		tmp[++ tp] = shi[i].r1;
	}
	std::sort(tmp + 1, tmp + tp + 1);
	for(int i = 1; i <= n; i ++) {
		shi[i].l1 = int(std::lower_bound(tmp + 1, tmp + tp + 1, shi[i].l1) - tmp);
		shi[i].r1 = int(std::lower_bound(tmp + 1, tmp + tp + 1, shi[i].r1) - tmp);
	}

	tp = 0;
	for(int i = 1; i <= n; i ++) {
		tmp[++ tp] = shi[i].l2;
		tmp[++ tp] = shi[i].r2;
	}
	std::sort(tmp + 1, tmp + tp + 1);
	for(int i = 1; i <= n; i ++) {
		shi[i].l2 = int(std::lower_bound(tmp + 1, tmp + tp + 1, shi[i].l2) - tmp);
		shi[i].r2 = int(std::lower_bound(tmp + 1, tmp + tp + 1, shi[i].r2) - tmp);
	}

	if(solve(n)) return puts("NO"), 0;
	for(int i = 1; i <= n; i ++) {
		std::swap(shi[i].l1, shi[i].l2);
		std::swap(shi[i].r1, shi[i].r2);
	}
	if(solve(n)) puts("NO");
	else puts("YES");
	/* debug("%lf\n", (sizeof iseg) / 1024.0 / 1024.0 * 3); */
}