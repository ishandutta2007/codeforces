#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ia[100005], b[100005], ib[100005], ra[100005], rb[100005];
bool vis[100005];
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}	
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}	
	iota(ia + 1, ia + n + 1, 1);
	sort(ia + 1, ia + n + 1, [&](int i, int j) {
		return a[i] < a[j];
	});
	iota(ib + 1, ib + n + 1, 1);
	sort(ib + 1, ib + n + 1, [&](int i, int j) {
		return b[i] < b[j]; 
	});
	for (int i = 1; i <= n; ++i) {
		ra[ia[i]] = i;
		rb[ib[i]] = i;
	}
	memset(vis + 1, false, n);
	vis[ia[n]] = vis[ib[n]] = true;
	queue<int> que;
	que.emplace(ia[n]);
	que.emplace(ib[n]);	
	int ptr_a = n, ptr_b = n;
	auto push = [&](int x) {
		if (!vis[x]) {
			vis[x] = true;
			que.emplace(x);
		}	
	};
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		int pa = ra[u];
		while (ptr_a > pa) {
			--ptr_a;
			push(ia[ptr_a]);
		} 
		int pb = rb[u];
		while (ptr_b > pb) {
			--ptr_b;
			push(ib[ptr_b]);
		}
	}
	for (int i = 1; i <= n; ++i)
		putchar(vis[i] ? '1' : '0');
	puts("");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}