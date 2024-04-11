#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 1054, W = 500054;
typedef std::bitset <W> bitset;

int n, H, V, HS, VS;
int h[N], v[N];
bool h_res[N], v_res[N];

int count[N], use[N], nz[N];
bitset A[N];
pr ans[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

bool divide(int n, int s, int *a, bool *ret) {
	int i, j, x, mx = 0, m = 0;
	memset(count, 0, sizeof count);
	memset(use, 0, sizeof use);
	for (i = 0; i < n; ++i) ++count[ a[i] ], up(mx, a[i]);
	
	A->reset(), A->set(0);
	for (i = 1; i <= mx; ++i)
		if ((x = count[i])) {
			nz[++m] = i, A[m] = A[m - 1];
			for (j = 0; 1 << j <= x; ++j)
				A[m] |= A[m] << (i << j), x -= 1 << j;
			A[m] |= A[m] << (i * x);
		}

	if (!A[m].test(s)) return false;
	for (i = m; i; --i)
		for (j = 0; j <= count[nz[i]]; ++j, s -= nz[i], ++use[nz[i]])
			if (A[i - 1].test(s)) break;

	for (i = 0; i < n; ++i)
		if (use[ a[i] ]) --use[ a[i] ], ret[i] = true;
		else ret[i] = false;
	return true;
}

int C1, D1, X1[N];
int C2, D2, X2[N];
int E1, F1, Y1[N];
int E2, F2, Y2[N];

void work() {
	int i, m = 0, X = 0, Y = 0; HS = VS = 0;
	cin >> H;
	for (i = 0; i < H; ++i) cin >> h[i], HS += h[i];
	cin >> V;
	for (i = 0; i < V; ++i) cin >> v[i], VS += v[i];
	n = H + V, std::sort(h, h + H), std::sort(v, v + V);
	if (H != V || H < 2 || V < 2 || HS & 1 || VS & 1) {cout << "No\n"; return;}
	if (!divide(H, HS / 2, h, h_res)) {cout << "No\n"; return;}
	if (!divide(V, VS / 2, v, v_res)) {cout << "No\n"; return;}
/*
	for (i = 0; i < H; ++i) fprintf(stderr, "%c %d ", h_res[i]?'+':'-', h[i]);
	fputc(10, stderr);
	for (i = 0; i < V; ++i) fprintf(stderr, "%c %d ", v_res[i]?'+':'-', v[i]);
	fputc(10, stderr);
*/
	C1 = C2 = 0;
	for (i = 0; i < H; ++i)
		if (h_res[i])
			X1[C1 + 1] = X1[C1] + h[i], ++C1;
		else
			X2[C2 + 1] = X2[C2] + h[i], ++C2;
	assert(X1[C1] == X2[C2]);

	E1 = E2 = 0;
	for (i = 0; i < V; ++i)
		if (v_res[i])
			Y1[E1 + 1] = Y1[E1] + v[i], ++E1;
		else
			Y2[E2 + 1] = Y2[E2] + v[i], ++E2;
	assert(Y1[E1] == Y2[E2]);

//	fprintf(stderr, "C = (%d, %d), E = (%d, %d)\n", C1, C2, E1, E2);

	D1 = D2 = 0;
	for (i = 1; i < E1; ++i)
		if (X1[D1 + 1] <= X2[D2 + 1])
			++D1;
		else
			++D2;
//	fprintf(stderr, "D1 = %d, D2 = %d\n", D1, D2);

	F1 = F2 = 0;
	for (i = 1; i <= C1; ++i) {
		ans[m++] = pr(X1[i] - X1[i - 1], 0);
		if (i <= D1)
			ans[m++] = pr(0, Y1[F1] - Y1[F1 + 1]), ++F1;
		else
			ans[m++] = pr(0, Y2[F2 + 1] - Y2[F2]), ++F2;
	}
	for (i = C2; i > 0; --i) {
		ans[m++] = pr(X2[i - 1] - X2[i], 0);
		if (i <= D2 + 1)
			ans[m++] = pr(0, Y1[F1] - Y1[F1 + 1]), ++F1;
		else
			ans[m++] = pr(0, Y2[F2 + 1] - Y2[F2]), ++F2;
	}

	assert(m == n);
/*	for (i = 0; i < n; ++i)
		fprintf(stderr, "(%d, %d)\n", ans[i].first, ans[i].second);
*/
	cout << "Yes\n";
	for (i = 0; i < n; ++i) cout << X << ' ' << Y << '\n', X += ans[i].first, Y += ans[i].second;
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}