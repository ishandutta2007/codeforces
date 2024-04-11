#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n;
void solve() {
	scanf("%d", &n);
	vector<int> a(n);
	map<int, int> cnt;
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), ++cnt[a[i]];
	for (auto it : cnt) {
		if (it.second % 2 == 0) continue;
		puts("-1");
		return;
	}
	vector<pair<int, int>> ans;
	int offset = 0;
	auto push = [&](int pos, int c) {
		ans.emplace_back(1 + offset + pos, c);
	};
	vector<int> res;
	function<void(vector<int>)> get = [&](vector<int> a) {
		if (a.empty()) return;
		int i = 1;
		for (; a[i] != a[0]; ++i);
		res.emplace_back(i * 2);	
		for (int x = 1, c = 0; x < i; ++x, ++c)
			push(i + c, a[x]);
		offset += i * 2;
		vector<int> b;
		for (int x = i - 1; x; --x)
			b.emplace_back(a[x]);
		for (int x = i + 1; x < (int) a.size(); ++x)
			b.emplace_back(a[x]);
		assert(b.size() == a.size() - 2);
		get(b);
	};
	get(a);
	printf("%d\n", (int) ans.size());
	for (auto it : ans)
		printf("%d %d\n", it.first, it.second);
	printf("%d\n", (int) res.size());
	for (auto x : res)
		printf("%d ", x);
	puts("");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) 
		solve(); 
	return 0;
}