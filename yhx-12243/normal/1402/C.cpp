#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::vector <int> vector;
typedef std::pair <int, int> pr;
const int N = 500054;

int n, Z, Hz;
int a[N], z[N];
vector r[N];
pr w[N];
std::priority_queue <int, vector, std::greater <int>> pq;

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

void work() {
	int i, ans = 0, x = 0, M = 0;
	cin >> n;
	for (Z = i = 0; i < n; ++i)
		if (cin >> a[i], !a[i]) z[Z++] = i;
	if (Z < 2) {cout << '0' << '\n'; return;}
	Hz = Z / 2, std::fill(w + 1, w + (n + 1), pr(0, Hz + 1));
	for (i = 0; i < n; ++i)
		if (a[i]) i < z[Hz] ? up(w[a[i]].first, x) : down(w[a[i]].second, x);
		else if (i == z[Hz]) x = 2 - (Z & 1);
		else ++x;
	for (i = 1; i <= n; ++i)
		if (w[i].first + 1 >= w[i].second) ++ans;
		else if (0 < w[i].first || w[i].second <= Hz) r[w[i].first].EB(w[i].second);
	memset(z, 0, (Hz + 1) << 2);
	for (x = 0; x <= Hz; r[x].clear(), ++x)
		for (int y : r[x])
			if (pq.emplace(y), M < x) ++M;
			else ++z[pq.top()], pq.pop();
	ans += M;
	for (i = 1, x = Hz; x >= 0; --x, ++i) M = min(z[x], i), ans += M, i -= M;
	for (; !pq.empty(); pq.pop());
	cout << min(ans + M, Hz) << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}