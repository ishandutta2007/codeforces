#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 200054;

int n;
char s[N];
int x[N], ans[N];
int cnt = 0, top = 0, stack[N];
std::priority_queue <int, std::vector <int>, std::greater <int>> pq;

int main() {
	int i;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n, n *= 2;
	for (i = 0; i < n; ++i)
		if (cin >> s[i], s[i] == 45) cin >> x[i];
	for (i = 0; i < n; ++i)
		if (s[i] == 43) stack[top++] = i;
		else {
			if (top <= 0) return cout << "NO\n", 0;
			x[stack[--top]] = x[i];
		}
	for (i = 0; i < n; ++i)
		if (s[i] == 43) pq.emplace(x[i]), ans[cnt++] = x[i];
		else {
			if (pq.empty() || pq.top() != x[i]) return cout << "NO\n", 0;
			pq.pop();
		}
	cout << "YES\n";
	for (i = 0; i < cnt; ++i) cout << ans[i] << (i == cnt - 1 ? '\n' : ' ');
	return 0;
}