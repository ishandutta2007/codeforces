#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, m, a[N], cnt[N], buf[N];
vector<int> v[N], b[N];
bool mark[N];
void solve() {
	scanf("%d%d", &n, &m);
	vector<int> p;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		p.emplace_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) {
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	int t = p.size();
	memset(cnt + 1, 0, t * 4);
	for (int i = 1; i <= n; ++i)
		a[i] = get(a[i]), ++cnt[a[i]], v[i].clear();
	for (int i = 1; i <= t; ++i)
		v[cnt[i]].emplace_back(i), b[i].clear(), b[i].emplace_back(i);
	vector<int> id;
	for (int i = 1; i <= n; ++i) {
		if (!v[i].empty()) id.emplace_back(i);
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = get(x), y = get(y);
		if (cnt[x] <= cnt[y]) b[x].emplace_back(y);
		if (cnt[y] <= cnt[x]) b[y].emplace_back(x);
	}
	for (int i = 1; i <= t; ++i)
		sort(b[i].begin(), b[i].end(), [&](int i, int j) {
			return cnt[i] > cnt[j];
		});
	long long ans = 0;
	for (int i = 0; i < (int) id.size(); ++i) {
		for (int j = i; j < (int) id.size(); ++j) {
			int v1 = id[i] + id[j], tmp = id[j], v2 = 0;
			const auto &vec = v[tmp];
			for (auto x : v[id[i]]) {
				int tot = 0;
				while (!b[x].empty() && cnt[b[x].back()] == tmp)
					buf[++tot] = b[x].back(), b[x].pop_back();
				for (int i = 1; i <= tot; ++i)
					mark[buf[i]] = true;
				int j = vec.size() - 1;
				for (; ~j && mark[vec[j]]; --j);
				if (~j) v2 = max(v2, p[x - 1] + p[vec[j] - 1]);
				for (int i = 1; i <= tot; ++i)
					mark[buf[i]] = false;
			}
			ans = max(ans, 1ll * v1 * v2);
		}
	}
	printf("%lld\n", ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}