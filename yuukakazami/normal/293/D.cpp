#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
using namespace std;

typedef long long int64;

struct Point {
	int x, y;
	void read() {
		cin >> x >> y;
	}
	bool operator<(const Point&p) const {
		return x != p.x ? x < p.x : y < p.y;
	}
	int64 operator^(const Point&p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}
};

int n;
vector<Point> ps;

const int MAX_VALUE = int(2e6) + 100;

int below(Point p1, Point p2, int x, bool inc = true) {
	//
	if (p1.y > p2.y) {
		p1.x *= -1;
		p2.x *= -1;
		x *= -1;
		swap(p1, p2);
	}
	int x1 = p2.x - p1.x, y1 = p2.y - p1.y;
	x -= p1.x;
	int ans = p1.y;
	ans += 1LL * x * y1 / x1 + 1;
	if (!inc && 1LL * x * y1 % x1 == 0)
		--ans;

	return ans;
}

double solve() { //solve for x

	//make counter-clockwise
	int64 det = 0;
	for (int i = 0; i < n; ++i) {
		det += ps[i] ^ ps[(i + 1) % n];
	}

	if (det < 0) {
		reverse(ps.begin(), ps.end());
	}

	int xl = min_element(ps.begin(), ps.end())->x;
	int xr = max_element(ps.begin(), ps.end())->x;

	rotate(ps.begin(), min_element(ps.begin(), ps.end()), ps.end());

	vector<Point> low, up;

	for (int i = 0; i < n; ++i) {
		low.push_back(ps[i]);
		if (ps[i].x == xr)
			break;
	}

	up.push_back(ps[0]);
	for (int i = n - 1; i >= 0; --i) {
		up.push_back(ps[i]);
		if (ps[i].x == xr)
			break;
	}

	static int cnt[MAX_VALUE];

	int i = 0, j = 0;

	double total = 0;

//	for (int i = 0; i < low.size(); ++i) {
//		cout << low[i].x << "," << low[i].y << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < up.size(); ++i) {
//		cout << up[i].x << "," << up[i].y << " ";
//	}
//	cout << endl;

	for (int x = xl; x <= xr; ++x) {
		while (i + 1 < low.size() && low[i].x <= x)
			++i;
		while (j + 1 < up.size() && up[j].x <= x)
			++j;
		cnt[x] = below(up[j - 1], up[j], x, true)
				- below(low[i - 1], low[i], x, false);
		total += cnt[x];
//		cerr << x << ":" << cnt[x] << endl;
	}

//	cerr << total << endl;
	double ret = 0;
	double sum = 0;

	for (int x = xl; x <= xr; ++x) {
		double cur = cnt[x];
		ret += 1.0 * x * x * (total - cur) * cur;
		ret -= 2 * cur * x * sum;
		sum += cur * x;
	}

//	for (int x = xl; x <= xr; ++x) {
//		for (int xx = xl; xx <= xr; ++xx) {
//			ret += 1.0 * (xx - x) * (xx - x) * cnt[x] * cnt[xx];
//		}
//	}

	total = total * (total - 1);

	return ret / total;
}

const int BIG = int(1e6) + 10;

int main() {
	cin >> n;
	ps.resize(n);
	for (int i = 0; i < n; ++i) {
		ps[i].read();
		ps[i].x += BIG;
		ps[i].y += BIG;
	}

	double ans = solve();
	for (int i = 0; i < n; ++i) {
		swap(ps[i].x, ps[i].y);
	}
	ans += solve();
	printf("%0.10lf\n", ans);
}