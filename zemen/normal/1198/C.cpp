#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()
 
#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
void solve() {
	int n = nxt(), m = nxt();
	vector<char> used(3 * n);
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		edges[i] = {u, v};
	}
 
	vector<int> match;
	for (int i = 0; i < m; ++i) {
		const auto& [u, v] = edges[i];
		if (!used[u] && !used[v]) {
			used[u] = used[v] = 1;
			match.push_back(i);
		}
	}
	if ((int)match.size() < n) {
		vector<int> ans;
		for (int i = 0; i < 3 * n; ++i) {
			if (!used[i]) {
				ans.push_back(i);
			}
		}
		ans.resize(n);
		printf("IndSet\n");
		for (int x : ans) {
			printf("%d ", x + 1);
		}
		printf("\n");
	} else {
		match.resize(n);
		printf("Matching\n");
		for (int id : match) {
			printf("%d ", id + 1);
		}
		printf("\n");
	}
}
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
	int t = nxt();
	while (t--) {
		solve();
	}
 
	return 0;
}