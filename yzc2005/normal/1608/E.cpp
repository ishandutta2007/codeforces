#include <bits/stdc++.h>
using namespace std;
int n, X, Y, cnt[100005];
struct node {
	int x, y, c;
} p[100005];
int solve1(vector<int> perm) {
	auto check = [&](int mid) {
		int lim = 0, rest;
		for (int c = 0; c < 3; ++c) {
			memset(cnt, 0, sizeof cnt);
			for (int i = 1; i <= n; ++i) {
				if (p[i].c == perm[c]) {
					++cnt[p[i].x];
				}
			}
			rest = mid;
			while (lim <= X) {
				rest -= cnt[lim++];
				if (rest <= 0) {
					break;
				}
			}
		}
		return rest <= 0;
	};
	int l = 1, r = n / 3, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
int solve2(vector<int> perm) {
	auto check = [&](int mid) {
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; ++i) {
			if (p[i].c == perm[0]) {
				++cnt[p[i].x];
			}
		}
		int lim = 0, rest = mid;
		while (lim <= X) {
			rest -= cnt[lim++];
			if (rest <= 0) {
				break;
			}
		}
		int pos = 0;
		for (int c = 1; c < 3; ++c) {
			memset(cnt, 0, sizeof cnt);
			for (int i = 1; i <= n; ++i) {
				if (p[i].c == perm[c] && p[i].x >= lim) {
					++cnt[p[i].y];
				}
			}
			rest = mid;
			while (pos <= Y) {
				rest -= cnt[pos++];
				if (rest <= 0) {
					break;
				}
			}
		}
		return rest <= 0;
	};
	int l = 1, r = n / 3, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
int solve() {
	int ans = 0;
	vector<int> perm{0, 1, 2};
	do {
		ans = max(ans, solve1(perm));
		ans = max(ans, solve2(perm));
		for (int i = 1; i <= n; ++i) {
			p[i].x = X - p[i].x + 1;
		}
		ans = max(ans, solve1(perm));
		ans = max(ans, solve2(perm));
	} while (next_permutation(perm.begin(), perm.end()));
	return ans;
}
int main() {
	scanf("%d", &n);
	vector<int> px, py;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
		--p[i].c;
		px.emplace_back(p[i].x);
		py.emplace_back(p[i].y);
	}
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	auto get = [&](const vector<int> &p, int x) {
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	for (int i = 1; i <= n; ++i) {
		p[i].x = get(px, p[i].x);
		p[i].y = get(py, p[i].y);
	}
	X = px.size();
	Y = py.size();
	int ans = solve();
	for (int i = 1; i <= n; ++i) {
		swap(p[i].x, p[i].y);
	}
	swap(X, Y);
	ans = max(ans, solve());
	printf("%d\n", ans * 3);
	return 0;
}