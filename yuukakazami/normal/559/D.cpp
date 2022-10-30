#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;

const ld EPS = 1e-8;
inline int sign(ld a) {
	return a < -EPS ? -1 : a > EPS;
}

struct Point {
	ld x, y;
	Point() {
	}
	Point(ld _x, ld _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(ld d) const {
		return Point(x * d, y * d);
	}
	Point operator/(ld d) const {
		return Point(x / d, y / d);
	}
	bool operator<(const Point&p) const {
		int c = sign(x - p.x);
		if (c)
			return c == -1;
		return sign(y - p.y) == -1;
	}
	ld dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	ld det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	ld alpha() const {
		return atan2(y, x);
	}
	ld distTo(const Point&p) const {
		ld dx = x - p.x, dy = y - p.y;
		return hypot(dx, dy);
	}
	ld alphaTo(const Point&p) const {
		ld dx = x - p.x, dy = y - p.y;
		return atan2(dy, dx);
	}
	void read() {
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x, y = _y;
	}
	ld abs() {
		return hypot(x, y);
	}
	ld abs2() {
		return x * x + y * y;
	}
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	ld a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

vector<Point> convexCut(const vector<Point>&ps, Point q1, Point q2) {
	vector<Point> qs;
	int n = ps.size();
	for (int i = 0; i < n; ++i) {
		Point p1 = ps[i], p2 = ps[(i + 1) % n];
		int d1 = crossOp(q1,q2,p1), d2 = crossOp(q1,q2,p2);
		if (d1 >= 0)
			qs.push_back(p1);
		if (d1 * d2 < 0)
			qs.push_back(isSS(p1, p2, q1, q2));
	}
	return qs;
}

ld calcArea(const vector<Point>&ps) {
	int n = ps.size();
	ld ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += ps[i].det(ps[(i + 1) % n]);
	}
	return ret / 2;
}

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

ld convexDiameter(const vector<Point>&ps) {
	int n = ps.size();
	int is = 0, js = 0;
	for (int i = 1; i < n; ++i) {
		if (ps[i].x > ps[is].x)
			is = i;
		if (ps[i].x < ps[js].x)
			js = i;
	}
	ld maxd = ps[is].distTo(ps[js]);
	int i = is, j = js;
	do {
		if ((ps[(i + 1) % n] - ps[i]).det(ps[(j + 1) % n] - ps[j]) >= 0)
			(++j) %= n;
		else
			(++i) %= n;
		maxd = max(maxd, ps[i].distTo(ps[j]));
	} while (i != is || j != js);
	return maxd;
}

const int MAX_N = int(1e5) + 10;
Point ps[MAX_N];
int n;

ld p2[MAX_N];

ld comb(int n, int m) {
	ld ret = 1;
	for (int i = 0; i < m; ++i) {
		ret = ret * (n - i);
		ret /= i + 1;
	}
	return ret;
}

void generate(int _n) {
	n = _n;
	int R = 1000000;
	for (int i = 0; i < n; ++i) {
		double rad = M_PI * 2 / n * i;
		int x = cos(rad) * R, y = sin(rad) * R;
		ps[i].x = x;
		ps[i].y = y;
	}
}

ld eval(vector<Point> ps) {
	ld A = calcArea(ps);
	ld b = 0;
	for (int i = 0; i < ps.size(); ++i) {
		Point p = ps[i], q = ps[(i + 1) % ps.size()];
		int dx = abs(p.x - q.x), dy = abs(p.y - q.y);
		b += (dx == 0 || dy == 0) ? (dx + dy) : (__gcd(dx, dy));
	}
	return A - b / 2 + 1;
}

ld bf() {
	int tot = 0;
	ld S = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int cnt = __builtin_popcount(mask);
		if (cnt < 3)
			continue;
		vector<Point> qs;
		for (int i = 0; i < n; ++i) {
			if (mask >> i & 1)
				qs.push_back(ps[i]);
		}
		S += eval(qs);
		++tot;
	}
	return S / tot;
}

int main() {
	p2[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		p2[i] = p2[i - 1] / 2.0;
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		ps[i].read();
	}

//	generate(3);

	ld ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = (i + 1) % n, ct = 0; j != i && ct < 100;
				(++j) %= n, ++ct) {
			int dx = ps[j].x - ps[i].x, dy = ps[j].y - ps[i].y;
			dx = abs(dx);
			dy = abs(dy);
			int b;
			if (dx == 0 || dy == 0)
				b = dx + dy;
			else
				b = __gcd(dx, dy);
			ld pb = p2[ct] * p2[2] * (1 - p2[n - 2 - ct]);
			ans -= pb * b / 2;
			ld cs = ps[i].det(ps[j]) / 2;
			ans += pb * cs;
		}
	}
	ld good = 1 - (comb(n, 0) + comb(n, 1) + comb(n, 2)) * p2[n];
	ans /= good;
	ans += 1;
	printf("%0.10lf\n", (double) ans);
//	printf("%0.10lf\n", (double) bf());
}