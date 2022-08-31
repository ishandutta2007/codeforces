#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef std::pair <int, int> pr;
typedef std::multiset <int> set;
const int N = 100054, INF = 0x3f3f3f3f;

int n;
int a[N], c[6];
int b[N], cur[N];
pr f[6][N];
std::priority_queue <pr> pq;
set S;

inline void down(int &x, const int y) {x > y ? x = y : 0;}

int main() {
	int i, x, ans = INF;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (i = 0; i < 6; ++i) cin >> c[i];
	std::sort(c, c + 6);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	std::sort(a, a + n);
	for (i = 0; i < n; ++i)
		cur[i] = 0, b[i] = a[i] - *c, pq.emplace(b[i], i), S.emplace(b[i]);
	for (; !pq.empty(); ) {
		down(ans, *S.rbegin() - *S.begin());
		std::tie(x, i) = pq.top(), pq.pop();
		S.erase(S.find(x));
		b[i] = a[i] - c[++cur[i]];
		if (cur[i] < 5) pq.emplace(b[i], i);
		S.emplace(b[i]);
	}
	down(ans, *S.rbegin() - *S.begin());
	cout << ans << '\n';
	return 0;
}