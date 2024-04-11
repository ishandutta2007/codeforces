#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;

typedef std::vector <int> vector;
const int N = 300054;

int n;
int ans[N];
vector P[N];

void work() {
	int i, la, gap, x;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> x, P[x].EB(i);
	memset(ans, 63, (n + 1) << 2);
	for (i = n; i; --i) {
		la = -1, gap = 0;
		for (int x : P[i])
			gap = std::max(gap, x - la), la = x;
		gap = std::max(gap, n - la);
		ans[gap] = i, P[i].clear();
	}
	for (i = 1; i <= n; ++i)
		ans[i] = std::min(ans[i], ans[i - 1]),
		cout << (ans[i] >= 0x3f3f3f3f ? -1 : ans[i]) << (i == n ? '\n' : ' ');
}

int main() {
	int T; 
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}