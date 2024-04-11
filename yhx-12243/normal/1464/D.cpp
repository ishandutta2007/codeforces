#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 1000054, mod = 1000000007, INF = 0x3f3f3f3f;

int n;
int p[N];
int cyc[N];
int a[N];
bool used[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

int solve_pure(int a1, int a2, int a3, int a4, int a5, int a6) {
	int ret, d;
	assert(a1 >= 0 && a2 >= 0 && a3 <= 0 && a4 >= 0 && a5 >= 0 && a6 >= 0);
	assert(a1 + 2 * a2 + 3 * a3 + 4 * a4 + 5 * a5 + 6 * a6 == 0);
	a3 += ret = a4 + a5 + a6, a1 += a4, a2 += a5, a3 += a6;
	assert(a1 + 2 * a2 + 3 * a3 == 0), ret += d = std::min(a1, a2); 
	a1 -= d, a2 -= d;
	if (a1) assert(!(a1 % 3)), ret += a1 / 3 * 2;
	else assert(!(a2 % 3)), ret += a2;
	return ret;
}

int solve() {
	int i, ret = 0, c = INF, d;
	memcpy(a, cyc, (n + 1) << 2);
	for (i = n; i > 6; --i)
		if (a[i])
			d = (i - 4) / 3, ret += a[i] * d, a[3] += a[i] * d, a[i - d * 3] += a[i], a[i] = 0;
//	fprintf(stderr, "[%d] %d %d %d %d %d %d\n", a[1], a[2], a[3], a[4], a[5], a[6]);
	if (a[2] >= 0 && a[4] >= 0) return ret + solve_pure(a[1], a[2], a[3], a[4], a[5], a[6]);
	if (a[2] >= 0 && a[4] == -1) {
		if (a[3] == 1) assert(a[1] == 1), c = 1;
		else {
			if (a[5])					down(c, 1 + solve_pure(a[1] + 1, a[2], a[3], a[4] + 1, a[5] - 1, a[6]));
			if (a[6])					down(c, 1 + solve_pure(a[1], a[2] + 1, a[3], a[4] + 1, a[5], a[6] - 1));
			if (a[2] >= 2)				down(c, 1 + solve_pure(a[1], a[2] - 2, a[3], a[4] + 1, a[5], a[6])); 
			if (a[1] >= 2 && a[2])		down(c, 2 + solve_pure(a[1] - 2, a[2] - 1, a[3], a[4] + 1, a[5], a[6]));
			if (a[1] >= 4)				down(c, 3 + solve_pure(a[1] - 4, a[2], a[3], a[4] + 1, a[5], a[6]));
		}
		assert(c < INF);
		ret += c;
	} else if (a[2] == -1 && a[4] >= 0) {
		if (a[4])					down(c, 1 + solve_pure(a[1], a[2] + 1 + 1, a[3], a[4] - 1, a[5], a[6]));
		if (a[5])					down(c, 1 + solve_pure(a[1], a[2] + 1, a[3] + 1, a[4], a[5] - 1, a[6]));
		if (a[6])					down(c, 1 + solve_pure(a[1], a[2] + 1, a[3], a[4] + 1, a[5], a[6] - 1));
		if (a[1] >= 2)				down(c, 1 + solve_pure(a[1] - 2, a[2] + 1, a[3], a[4], a[5], a[6]));
		assert(c < INF);
		ret += c;
	} else if (a[2] == -2 && a[4] >= 0) {
		if (a[3] == 1) assert(a[1] == 1), c = 2;
		else if (a[3] == 0) {
			if (a[1] == 4) c = 2;
			else if (a[4] == 1) c = 1;
			else assert(0);
		} else {
			if (a[4])					down(c, 1 + solve_pure(a[1], a[2] + 2, a[3], a[4] - 1, a[5], a[6]));
			if (a[5])					down(c, 2 + solve_pure(a[1] + 1, a[2] + 2, a[3], a[4], a[5] - 1, a[6]));
			if (a[6])					down(c, 2 + solve_pure(a[1], a[2] + 3, a[3], a[4], a[5], a[6] - 1));

			if (a[5] >= 2)				down(c, 2 + solve_pure(a[1], a[2] + 2, a[3] + 2, a[4] + 0, a[5] - 2, a[6] - 0));
			if (a[6] >= 2)				down(c, 2 + solve_pure(a[1], a[2] + 2, a[3] + 0, a[4] + 2, a[5] - 0, a[6] - 2));
			if (a[5] && a[6])			down(c, 2 + solve_pure(a[1], a[2] + 2, a[3] + 1, a[4] + 1, a[5] - 1, a[6] - 1));

			if (a[1] >= 4)				down(c, 2 + solve_pure(a[1] - 4, a[2] + 2, a[3], a[4], a[5], a[6]));
			if (a[1] >= 2 && a[5])		down(c, 2 + solve_pure(a[1] - 2, a[2] + 2, a[3] + 1, a[4], a[5] - 1, a[6]));
			if (a[1] >= 2 && a[6])		down(c, 2 + solve_pure(a[1] - 2, a[2] + 2, a[3], a[4] + 1, a[5], a[6] - 1));
		}
		assert(c < INF);
		ret += c;
	}
	else assert(0);
	return ret;
}

void work() {
	int i, j, r, clen, step;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> p[i]; 
	if (n == 1) {cout << "1 0\n"; return;}
	if (n == 2) {cout << '2' << ' ' << p[1] - 1 << '\n'; return;}
	r = 2 - (n + 2) % 3, cout << PowerMod(3, (n - 2 * r) / 3, 1 << r) << ' ';

	memset(used, false, n + 1),
	memset(cyc, 0, (n + 1) << 2);
//	fputc('[', stderr);
	for (i = 1; i <= n; ++i)
		if (!used[i]) {
			clen = 0;
			for (j = i; !used[j]; j = p[j]) used[j] = true, ++clen;
			++cyc[clen];
//			fprintf(stderr, "%d,", clen);
		}
//	fputs("]\n", stderr);

	switch (r) {
		case 0: cyc[3] -= n / 3, step = solve(); break;
		case 1: cyc[3] -= (n - 2) / 3, --cyc[2], step = solve(); break;
		case 2:
			cyc[3] -= (n - 4) / 3, --cyc[4], step = solve(),
			++cyc[4], cyc[2] -= 2, down(step, solve()); break;
		default: step = -1; break;
	}
	cout << step << '\n';
	memset(a, 0, (n + 1) << 2);
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}