/*
 * d.cpp
 *
 *  Created on: 2012-9-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MOD = 1000000007;

typedef long long int64;

struct Int {
	int x;
	Int() :
			x(0) {
	}
	Int(int _x) :
			x(_x) {
		x %= MOD;
		if (x < 0)
			x += MOD;
	}
	Int(int64 _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(int x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		int t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		int t = x - o.x;
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
};

const int MAX_N = 4000 + 10;
int w, h;

int gcd[MAX_N][MAX_N];

struct Point {
	int x, y;
	Point() {
	}
	Point(int _x, int _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(int d) const {
		return Point(x * d, y * d);
	}
	Point operator/(int d) const {
		return Point(x / d, y / d);
	}
	int det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	int dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

int main() {
	cin >> w >> h;
	++w, ++h;
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			if (!i || !j)
				gcd[i][j] = i + j;
			else {
				if (i >= j)
					gcd[i][j] = gcd[i - j][j];
				else
					gcd[i][j] = gcd[i][j - i];
			}
		}
	}
	static int cnt[4] = { };
	Point ps[4];
	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			cnt[(i % 2) * 2 + j % 2]++;
		}
	}
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ps[i * 2 + j] = Point(i, j);
		}
	}
	Int ans = 0;
	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			for (int c = 0; c < 4; ++c) {
				Point p1 = ps[a], p2 = ps[b], p3 = ps[c];
				if (cross(p1,p2,p3) % 2 == 0) {
					int used[4] = { };
					used[a]++, used[b]++, used[c]++;
					Int way = 1;
					for (int k = 0; k < 4; ++k) {
						for (int i = 0; i < used[k]; ++i) {
							way *= cnt[k] - i;
						}
					}
					ans += way;
				}
			}
		}
	}
//	cout << ans.x << endl;
	for (int dx = -w + 1; dx < w; ++dx) {
		for (int dy = 0; dy < h; ++dy) {
			if (dx == 0 && dy == 0)
				continue;
			int ndx = dx >= 0 ? dx : -dx;
			int g = gcd[ndx][dy];
			if (dy == 0 && dx < 0)
				continue;
			Int mid = g - 1;
			//cout << g + 1 << endl;
			Int way = Int(1) * (w - ndx) * (h - dy) * mid * 6;
			ans -= way;
		}
	}
	cout << ans.x << endl;
	return 0;
}