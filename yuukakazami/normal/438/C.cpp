#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long int64;

int sign(int64 x) {
	return x < 0 ? -1 : x > 0;
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
	int64 dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	int64 det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	void read() {
//		scanf("%lf%lf", &x, &y);
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

bool checkIt(int64 a, int64 b, int64 c, int64 d) {
	if (a > b)
		swap(a, b);
	if (c > d)
		swap(c, d);
	//[a,b] and [c,d]
	if (b < c || a > d)
		return false;
	return true;
}

bool crsSS(Point p1, Point p2, Point q1, Point q2) {
	if (!checkIt(p1.x, p2.x, q1.x, q2.x) || !checkIt(p1.y, p2.y, q1.y, q2.y))
		return false;
	return crossOp(p1,p2,q1) * crossOp(p1,p2,q2) <= 0
			&& crossOp(q1,q2,p1) * crossOp(q1,q2,p2) <= 0;
}

const int MOD = int(1e9) + 7;
typedef long long int64;
struct Int {
	int64 x;
	Int() :
			x(0) {
	}
	Int(int64 _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(int64 x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		int64 t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		int64 t = x - o.x;
		if (t < 0)
			t += MOD;
		return get(t);
	}
	Int operator/(const Int&o) const {
		return (*this) * o.inv();
	}
	Int&operator+=(const Int&o) {
		return (*this) = *this + o;
	}
	Int&operator-=(const Int&o) {
		return (*this) = *this - o;
	}
	Int&operator*=(const Int&o) {
		return (*this) = *this * o;
	}
	Int&operator/=(const Int&o) {
		return (*this) = *this / o;
	}

	Int power(int64 n) const {
		if (!n)
			return get(1);
		const Int&a = *this;
		if (n & 1)
			return power(n - 1) * a;
		else
			return (a * a).power(n >> 1);
	}

	Int inv() const {
		return power(MOD - 2);
	}
	bool operator==(const Int&o) const {
		return x == o.x;
	}
	bool operator!=(const Int&o) const {
		return x != o.x;
	}
};

const int MAX_N = 200 + 10;
Point ps[MAX_N];
int n;

Int dp[MAX_N][MAX_N];
bool save[MAX_N][MAX_N];

bool check[MAX_N][MAX_N]; //check Line

Int calc(int l, int r) {
	//l,l+1,..r
	if (l == r)
		return 1;
	int cnt = r - l + 1;
	if (cnt <= 0)
		cnt += n;
	if (cnt <= 3)
		return 1;
	if (save[l][r])
		return dp[l][r];
	save[l][r] = true;
	Int&ret = dp[l][r] = 0;
	//pick l,r,k
	for (int k = (l + 1) % n; k != r; (++k) %= n) {
		if (check[l][k] && check[r][k] && crossOp(ps[l],ps[r],ps[k]) != 0) {
//			cout << cross(ps[l],ps[l+1],ps[k]) << endl;
//			cout << crossOp(ps[l],ps[l+1],ps[k]) << endl;
			ret += calc(l, k) * calc(k, r);
		}
	}
	return ret;
}

bool inside(Point p) {
	//is p inside?
	Point far(int(1e8) + rand() % int(1e8), int(1e8) + rand() % int(1e8));
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (crossOp(p,ps[i],ps[i+1]) == 0
				&& (ps[i] - p).dot(ps[i + 1] - p) <= 0)
			return true;
		if (crsSS(p, far, ps[i], ps[i + 1])) {
			++cnt;
		}
	}

	return cnt % 2 == 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ps[i].read();
		ps[i].x *= 2, ps[i].y *= 2;
	}
	ps[n] = ps[0];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			//check ps[i]<->ps[j]
			bool ok = true;
			for (int k = 0; k < n; ++k) {
				if (k != i && k != j && (k + 1) % n != i && (k + 1) % n != j) {
					if (crsSS(ps[i], ps[j], ps[k], ps[k + 1])) {
						ok = false;
						break;
					}
				}
				if (k != i && k != j && crossOp(ps[i],ps[j],ps[k]) == 0
						&& (ps[k] - ps[i]).dot(ps[k] - ps[j]) <= 0)
					ok = false;
			}

			if (!inside(
					Point((ps[i].x + ps[j].x) / 2, (ps[i].y + ps[j].y) / 2)))
				ok = false;
			check[i][j] = check[j][i] = ok;
		}
	}

	memset(save, 0, sizeof save);
//	cout << calc(2, 0).x << endl;
	cout << calc(0, n - 1).x << endl;
}