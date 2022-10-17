#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, lcp[N][N], rmin[N];
long long k;
char s[N];
vector<int> g[N];
long long sum[N][N], dp[N][N];
int main() {
	scanf("%d%d%lld", &n, &m, &k);
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			v.emplace_back(i, j);
	scanf("%s", s + 1);
	for (int i = n; i; --i)
		for (int j = n; j; --j)
			lcp[i][j] = (s[i] == s[j]) ? lcp[i + 1][j + 1] + 1 : 0;
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		int len = lcp[a.first][b.first];
		if (a.first + len > a.second || b.first + len > b.second)
			return a.second - a.first > b.second - b.first;
		return s[a.first + len] > s[b.first + len];
	});
	int l = 0, r = (int) v.size() - 1;
	pair<int, int> ans;
	auto check = [&](int mid) {
		fill(rmin + 1, rmin + n + 1, n + 2);
		for (int i = 0; i <= mid; ++i) 
			rmin[v[i].first] = min(rmin[v[i].first], v[i].second + 1);
		memset(dp, 0, sizeof dp);
		memset(sum, 0, sizeof sum);
		dp[n + 1][0] = sum[n + 1][0] = 1;
		for (int i = n; i; --i) {
			for (int j = 0; j <= m; ++j) {
				dp[i][j] = sum[rmin[i]][j - 1];
				sum[i][j] = min(k, sum[i + 1][j] + dp[i][j]);
			} 
		}
		return dp[1][m] >= k;
	};
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = v[mid];
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	for (int i = ans.first; i <= ans.second; ++i)
		printf("%c", s[i]);
	return 0;
}