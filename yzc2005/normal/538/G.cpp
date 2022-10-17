#include <bits/stdc++.h>
using namespace std;
inline void my_assert(bool f) {
	if (!f) puts("NO"), exit(0);
}
int n, l;
inline long long div_down(long long x, long long y) {
	if (y < 0) x = -x, y = -y;
	if (x % y == 0) return x / y;
	return x > 0 ? x / y : x / y - 1;
}
inline long long div_up(long long x, long long y) {
	if (y < 0) x = -x, y = -y;
	if (x % y == 0) return x / y;
	return x > 0 ? x / y + 1 : x / y;
}
vector<int> solve(vector<pair<long long, long long>> v) {
	vector<pair<long long, long long>> buc(l + 1, pair<long long, long long>(-1e18, -1e18));
	buc[0] = {0, 0};
	buc[l] = {-1, 0};
	long long D = -1e18;
	for (const auto &p : v) {
		long long t, x;
		tie(t, x) = p;
		my_assert((x + t) % 2 == 0);
		long long cnt = t / l;
		int pos = t % l;
		if (buc[pos].first != -1e18) {
			long long dis = x - buc[pos].second;
			long long dt = cnt - buc[pos].first;
			my_assert(dis % dt == 0);
			long long d = dis / dt;
			my_assert((d + l) % 2 == 0);
			my_assert(D == -1e18 || D == d);
			D = d;
		} else {
			buc[pos] = {cnt, x};
		}
	}
	vector<int> ans;
	auto construct = [&](long long D) {
		long long x1 = 0, t1 = 0;
		for (int i = 1; i <= l; ++i) {
			if (buc[i].first == -1e18) continue;
			long long t2 = i;
			long long x2 = buc[i].second - buc[i].first * D;
			long long dis = abs(x2 - x1);
			long long dt = t2 - t1;
			my_assert(dis <= dt);
			for (int o = 0; o < dis; ++o)
				ans.emplace_back(x1 < x2 ? 1 : 0);
			dt -= dis;
			assert(dt % 2 == 0);
			for (int o = 0; o < dt / 2; ++o)
				ans.emplace_back(1), ans.emplace_back(0);
			t1 = t2, x1 = x2;
		}
	};
	if (D != -1e18) {
		construct(D);
	} else {
		long long L = -1e18, R = 1e18;
		long long last = 0;
		auto push = [&](pair<long long, long long> x, pair<long long, long long> y, long long c) {
			if (x.first < y.first) swap(x, y);
			long long k = x.first - y.first, b = y.second - x.second;
			if (!k) return;
			L = max(L, div_up(b + c, -k));
			R = min(R, div_down(c - b, k));
		};
		for (int i = 1; i <= l; ++i) {
			if (buc[i].first == -1e18) continue;
			push(buc[i], buc[last], i - last);
			last = i;
		}
		if ((L + l) % 2) ++L;
		my_assert(L <= R);
		construct(L);
	}
	assert((int) ans.size() == l);
	return ans;
}
int main() {
	scanf("%d%d", &n, &l);
	vector<pair<long long, long long>> vx, vy;
	for (int i = 0; i < n; ++i) {
		long long t, x, y;
		scanf("%lld%lld%lld", &t, &x, &y);
		vx.emplace_back(t, x + y);
		vy.emplace_back(t, x - y);
	}
	auto ax = solve(vx), ay = solve(vy);
	string op = "LDUR";
	for (int i = 0; i < l; ++i)
		cout << op[ax[i] << 1 | ay[i]];
	cout << "\n";
	return 0;
}