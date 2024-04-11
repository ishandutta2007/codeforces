#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int64;

inline int sign(int64 a) {
	return a < 0 ? -1 : a > 0;
}

struct Point {
	int64 x, y;
	Point() {
	}
	Point(int64 _x, int64 _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(int64 d) const {
		return Point(x * d, y * d);
	}
	Point operator/(int64 d) const {
		return Point(x / d, y / d);
	}
	bool operator<(const Point&p) const {
		int c = sign(x - p.x);
		if (c)
			return c == -1;
		return sign(y - p.y) == -1;
	}
	int64 dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	int64 det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	void read() {
		cin >> x >> y;
	}
	int64 abs2() {
		return x * x + y * y;
	}
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

vector<Point> convexHull(vector<Point> ps) {
	int n = ps.size();
	if (n <= 1)
		return ps;
	sort(ps.begin(), ps.end());
	vector<Point> qs;
	for (int i = 0; i < n; qs.push_back(ps[i++])) {
		while (qs.size() > 1 && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
			qs.pop_back();
	}
	for (int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])) {
		while (qs.size() > t && crossOp(qs[qs.size()-2],qs.back(),ps[i]) <= 0)
			qs.pop_back();
	}
	qs.pop_back();
	return qs;
}

const int64 INF = 1LL << 31;

int n, m;

vector<Point> readPoints(int n) {
	vector<Point> ps(n);
	int64 mx = 0, my = 0;
	for (int i = 0; i < n; ++i) {
		ps[i].read();
		mx = max(mx, ps[i].x);
		my = max(my, ps[i].y);
	}
	ps.push_back(Point(0, my));
	ps.push_back(Point(mx, 0));
	sort(ps.begin(), ps.end());

	int cnt = 1;
	for (int i = 1; i < ps.size(); ++i) {
		while (cnt >= 2 && crossOp(ps[cnt-2],ps[cnt-1],ps[i]) >= 0)
			cnt--;
		ps[cnt++] = ps[i];
	}
	ps.resize(cnt);
	return ps;
}

void check(bool ok) {
	if (!ok) {
		puts("Max");
		exit(0);
	}
}

int main() {
	cin >> n >> m;
	int _;
	cin >> _ >> _;
	vector<Point> low = readPoints(n);

	vector<Point> up = readPoints(m);

	//Now, check whether low is strictly below up
	check(low.back().x < up.back().x);

	int j = 0;
	for (int i = 0; i < low.size(); ++i) {
		while (j + 1 < up.size() && up[j + 1].x <= low[i].x)
			++j;
		if (up[j].x == low[i].x)
			check(up[j].y > low[i].y);
		check(crossOp(up[j],up[j+1],low[i]) == -1);
	}
	puts("Min");
	return 0;
}