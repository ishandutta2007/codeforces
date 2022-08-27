#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

typedef std::pair <int, int> pr;
const int N = 2054, full = -233;

int n, K, C;
char a[N], b[N];
int A[N], B[N];
vector <pr> u, v;

std::ostream & operator << (std::ostream &out, const pr &e) {return out << e.first + 1 << ' ' << e.second + 1;}

inline pr work(int l, int x, int *A) {
	int r = l + K, y = A[l] + A[r] - x, phyl, phyr;
	if (x == full) x = A[l] + A[r], y = 0;
	assert(y >= 0);
	if (x <= A[l])
		phyl = std::accumulate(A, A + l, l + x),
		phyr = std::accumulate(A, A + r, r - 1);
	else
		phyl = std::accumulate(A, A + (l + 1), l),
		phyr = std::accumulate(A, A + (r + 1), r - y - 1);
	A[l] = x, A[r] = y, std::reverse(A + (l + 1), A + r);
	return pr(phyl, phyr);
}

inline void generate(char *s, int *r) {
	int i, x = 0, l = 0;
	for (i = 0; i < n; ++i)
		if (s[i] == 49) r[l++] = x, x = 0;
		else ++x;
	r[l] = x;
}

vector <pr> solve(int *A) {
	int i;
	vector <pr> ret;
	if (K & 1) {
		for (i = 0; i <= C - K; ++i) ret.EB(work(i, 0, A));
		for (i = 1; i < K; ++i) ret.EB(work(C - K - 1, 0, A)), ret.EB(work(C - K, 0, A));
	} else {
		for (i = 0; i <= C - K; ++i) ret.EB(work(i, 0, A));
		for (i = 2; i < K; i += 2) ret.EB(work(C - K - 1, full, A)), ret.EB(work(C - K, 0, A));
		ret.EB(work(C - K - 1, 0, A));
	}
	return ret;
}

void work() {
	cin >> n >> K >> a >> b, C = std::count(a, a + n, '1');
	if (!memcmp(a, b, n)) {cout << 0 << '\n'; return;}
	if (!K || K > C || std::count(b, b + n, '1') != C) {cout << -1 << '\n'; return;}
	generate(a, A), generate(b, B);
	if (K == C) {
		if (*A + A[C] != *B + B[C]) {cout << -1 << '\n'; return;}
		pr t = work(0, *B, A);
		if (!memcmp(A + 1, B + 1, (C - 1) << 2)) {cout << 1 << '\n' << t << '\n'; return;}
		pr s = work(0, *B, A);
		if (!memcmp(A + 1, B + 1, (C - 1) << 2)) {cout << 2 << '\n' << t << '\n' << s << '\n'; return;}
		cout << -1 << '\n'; return;
	}
	u = solve(A), v = solve(B);
	if (memcmp(A, B, (C + 1) << 2)) {cout << -1 << '\n'; return;}
	std::reverse(v.begin(), v.end()),
	cout << int(u.size() + v.size()) << '\n';
	for (const pr &e : u) cout << e << '\n';
	for (const pr &e : v) cout << e << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}