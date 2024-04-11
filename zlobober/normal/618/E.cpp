#include <cstdio>
#include <cassert>
#include <complex>
using namespace std;

const int N = 1 << 19;
typedef complex<double> cm;

cm T[2 * N];
cm mul[2 * N];

void push(int v) {
	assert(v < N);
	mul[2 * v] *= mul[v];
	mul[2 * v + 1] *= mul[v];
	T[v] *= mul[v];
	mul[v] = cm(1, 0);
}

void change(int x, int new_len) {
	int L = 0, R = N - 1;
	int v = 1;
	while (L < R) {
		push(v);
		int M = (L + R) / 2;
		if (L <= x && x <= M) {
			v = 2 * v;
			R = M;
		} else if (M + 1 <= x && x <= R) {
			v = 2 * v + 1;
			L = M + 1;
		} else {
			assert(false);
		}
	}
	T[v] *= mul[v];
	mul[v] = cm(1, 0);
	double cur_len = sqrt(T[v].imag() * T[v].imag() + T[v].real() * T[v].real());
	T[v] = T[v] * (new_len + cur_len) / cur_len;
	while ((v >>= 1) > 0) {
		T[v] = T[2 * v] * mul[2 * v] + T[2 * v + 1] * mul[2 * v + 1];
	}
}

void domul(int l, int r, cm x, int L = 0, int R = N - 1, int v = 1) {
	if (r < L || l > R)
		return;
	else if (l <= L && R <= r)
		mul[v] *= x;
	else {
		push(v);
		domul(l, r, x, L, (L + R) / 2, 2 * v);
		domul(l, r, x, (L + R) / 2 + 1, R, 2 * v + 1);
		T[v] = T[2 * v] * mul[2 * v] + T[2 * v + 1] * mul[2 * v + 1];
	}
}

const double pi = 4 * atan(1.0);

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < N; i++)
		T[N + i] = cm(i < n, 0), mul[N + i] = cm(1, 0);
	for (int i = N - 1; i > 0; i--)
		T[i] = T[2 * i] + T[2 * i + 1], mul[i] = cm(1, 0);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 1) {
			change(y - 1, z);
		} else {
			domul(y - 1, n - 1, cm(cos(z / 180.0 * pi), -sin(z / 180.0 * pi)));
		}
		cm res = T[1] * mul[1];
		printf("%.10lf %.10lf\n", res.real(), res.imag());
	}

}