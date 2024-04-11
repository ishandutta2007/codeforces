#include <bits/stdc++.h>

typedef long long ll;
const int N = 150054;
const double eps = 1e-6;

struct problem {
	int score, time; ll lb, ub;
	inline bool operator < (const problem &B) const {return (ll)score * B.time > (ll)time * B.score;}
	inline bool operator == (const problem &B) const {return (ll)score * B.time == (ll)time * B.score;}
} a[N];

int n;
ll T[N];

inline bool up(double &x, const double y) {return x < y ? x = y , 1 : 0;}

int main() {
	int i, j, u, v, Au = -1, Av = -1;
	double L = 0, R = 1, M, coef, max_score;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", &a[i].score);
	for (i = 0; i < n; ++i) scanf("%d", &a[i].time);
	std::sort(a, a + n);
	for (j = i = 0; i < n; ) {
		for (; j < n && a[i] == a[j]; ++j) T[j + 1] = T[j] + a[j].time;
		for (ll tmp = T[i]; i < j; ++i) a[i].lb = tmp + a[i].time, a[i].ub = T[j];
	}
	std::sort(a, a + n, [] (const problem &A, const problem &B) {return A.score < B.score;});
	for (; L + eps < R; ) {
		M = (L + R) / 2, coef = M / T[n]; max_score = -INFINITY, u = v = -1;
		for (j = i = 0; i < n; ) {
			for (; j < n && a[i].score == a[j].score; ++j)
				if (a[j].score * (1. - coef * a[j].ub) < max_score) {v = j; break;}
			if (~v) break;
			for (; i < j; ++i)
				if (up(max_score, a[i].score * (1. - coef * a[i].lb))) u = i;
		}
		~v ? Au = u, Av = v, R = M : L = M;
	}
	if (!~(Au & Av)) return putchar(49), putchar(10), 0;
	printf("%.12lg\n", (double)T[n] * (a[Au].score - a[Av].score) / ((double)a[Au].lb * a[Au].score - (double)a[Av].ub * a[Av].score));
	return 0;
}