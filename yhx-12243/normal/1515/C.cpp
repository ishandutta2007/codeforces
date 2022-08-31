#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
const int N = 100054;

int n, m, H;
int a[N];
std::priority_queue <pr, std::vector <pr>, std::greater <pr>> pq;

void work() {
	int i, j, h;
	cin >> n >> m >> H;
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < m; ++i) pq.emplace(0, i);
	cout << "YES\n";
	for (i = 0; i < n; ++i) {
		std::tie(h, j) = pq.top(), pq.pop();
		cout << j + 1 << (i == n - 1 ? '\n' : ' ');
		pq.emplace(h + a[i], j);
	}
	for (; !pq.empty(); pq.pop());
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}