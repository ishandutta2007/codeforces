#include <bits/stdc++.h>
using namespace std;
struct node {
	int id, x;
	inline bool operator<(const node &rhs) const {
		return x > rhs.x;
	}
} a[1005];
int n;
vector<pair<int, int>> ans;
inline void add(node &a, node &b) {
	ans.emplace_back(a.id, b.id);
	b.x -= a.x;
	a.x *= 2;
}
void solve(node &a, node &b, node &c) {
	int rest = b.x / c.x;
	for (; rest; rest >>= 1) {
		if (rest & 1) 
			add(c, b);
		else
			add(c, a);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i].x), a[i].id = i;
	sort(a + 1, a + n + 1);
	if (!a[2].x) {
		puts("-1");
		return 0;
	}
	while (a[3].x) {
		solve(a[1], a[2], a[3]);
		sort(a + 1, a + n + 1);
	}
	printf("%d\n", (int) ans.size());
	for (const auto &p : ans)
		printf("%d %d\n", p.first, p.second);
	return 0;
}