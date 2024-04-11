#include <bits/stdc++.h>
#define C(a, b) memcpy((a), (b), 16)
#define Inv for (i = 0; i < 4; ++i) cx[i] = pcx[perm[i]], cy[i] = pcy[perm[i]];

typedef std::pair <int, int> pr;
typedef int arr[4];

arr ox, oy, cx, cy, ansX, ansY;
int pd[12], ans;
pr L[64];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void upd_ans(int v) {if (v < ans) ans = v, C(ansX, cx), C(ansY, cy);}

void compute(int a) {
	int i, j, S, perm[4] = {0, 1, 2, 3}, r[4]; pr *_end = L, *it;
	arr x, y, pcx, pcy;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			*_end++ = pr(ox[i], oy[j]), *_end++ = pr(ox[i] - a, oy[j] - a),
			*_end++ = pr(ox[i], oy[j] - a), *_end++ = pr(ox[i] - a, oy[j]);
	std::sort(L, _end), _end = std::unique(L, _end);
	do {
		for (i = 0; i < 4; ++i) x[perm[i]] = ox[i], y[perm[i]] = oy[i];
		if (y[0] == y[1] && y[2] == y[3] && y[2] == y[0] + a) {
			int *u, *v; C(pcy, y), C(r, x), r[1] -= a, r[3] -= a;
			std::tie(u, v) = std::minmax_element(r, r + 4);
			pcx[0] = pcx[2] = (*u + *v) >> 1, pcx[1] = pcx[3] = *pcx + a;
			Inv upd_ans((*v - *u + 1) / 2);
		}
		if (x[0] == x[2] && x[1] == x[3] && x[1] == x[0] + a) {
			int *u, *v; C(pcx, x), C(r, y), r[2] -= a, r[3] -= a;
			std::tie(u, v) = std::minmax_element(r, r + 4);
			pcy[0] = pcy[1] = (*u + *v) >> 1, pcy[2] = pcy[3] = *pcy + a;
			Inv upd_ans((*v - *u + 1) / 2);
		}
		for (it = L; it != _end; ++it) {
			int u, v; std::tie(u, v) = *it;
			for (S = i = 0; i < 4; ++i) {
				pcx[i] = u + (-(i & 1) & a), pcy[i] = v + (-(i >> 1 & 1) & a);
				if (x[i] != pcx[i] && y[i] != pcy[i]) break;
				up(S, abs(x[i] - pcx[i]) + abs(y[i] - pcy[i]));
			}
			if (i == 4) {Inv upd_ans(S);}
		}
	} while (std::next_permutation(perm, perm + 4));
}

void work() {
	int i, cnt = 0;
	scanf("%d%d%d%d%d%d%d%d", ox, oy, ox + 1, oy + 1, ox + 2, oy + 2, ox + 3, oy + 3);
	pd[0] = abs(ox[0] - ox[1]), pd[1] = abs(oy[0] - oy[1]);
	pd[2] = abs(ox[0] - ox[2]), pd[3] = abs(oy[0] - oy[2]);
	pd[4] = abs(ox[0] - ox[3]), pd[5] = abs(oy[0] - oy[3]);
	pd[6] = abs(ox[1] - ox[2]), pd[7] = abs(oy[1] - oy[2]);
	pd[8] = abs(ox[1] - ox[3]), pd[9] = abs(oy[1] - oy[3]);
	pd[10] = abs(ox[2] - ox[3]), pd[11] = abs(oy[2] - oy[3]);
	std::sort(pd, pd + 12), cnt = std::unique(pd, pd + 12) - pd;
	for (ans = INT_MAX, i = 0; i < cnt; ++i) compute(pd[i]);
	ans == INT_MAX ? puts("-1") : printf("%d\n%d %d\n%d %d\n%d %d\n%d %d\n", ans, *ansX, *ansY, ansX[1], ansY[1], ansX[2], ansY[2], ansX[3], ansY[3]);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}