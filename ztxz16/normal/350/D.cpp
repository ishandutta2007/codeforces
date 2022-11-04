#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int N = 300005;
const int M = 2005;
const double EPS = 1e-8;
const double PI = acos(-1.0);

int sign(const double &a) {
	return a < -EPS ? -1 : a > EPS;
}

int n, m;

struct Point {
	double x, y;
	
	Point (double x = 0.0, double y = 0.0) :
		x(x), y(y) {}
	
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	
	friend Point operator - (const Point &a, const Point &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	
	friend Point operator * (const Point &a, const double &b) {
		return Point(a.x * b, a.y * b);
	}
	
	friend int operator < (const Point &a, const Point &b) {
		return sign(a.x - b.x) < 0 || (sign(a.x - b.x) == 0 && sign(a.y - b.y) < 0);
	}
	
} p1[N], p2[N];

bool operator < (const pair <pair <double, double>, Point> &a, const pair <pair <double, double>, Point> &b) {
	return sign(a.first.first - b.first.first) < 0 || (sign(a.first.first - b.first.first) == 0 && sign(a.first.second - b.first.second) < 0)
		|| (sign(a.first.first - b.first.first) == 0 && sign(a.first.second - b.first.second) == 0 && a.second < b.second);
}

vector <pair <pair <double, double>, Point> > v;

double getJJ(const Point &a, const Point &b) {
	if (sign(b.x) == 0) {
		return 0.0;
	}
	
	if (sign(a.x) == 0) {
		return a.y;
	}
	
	return a.y - b.y * a.x / b.x;
}

struct Circle {
	double x, y, r;
	
	void read() {
		scanf("%lf %lf %lf", &x, &y, &r);
	}
	
	friend double dis2(const Circle &a, const Circle &b) {
		return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	}
	
	friend Point operator - (const Circle &a, const Circle &b) {
		return Point(a.x - b.x, a.y - b.y);
	}
	
	friend Point operator + (const Circle &a, const Circle &b) {
		return Point(a.x + b.x, a.y + b.y);
	}
	
} c[M];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p1[i].read(), p2[i].read();
	}
	
	for (int i = 1; i <= m; i++) {
		c[i].read();
	}
	
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			if (sign(c[i].r - c[j].r) == 0 && sign(dis2(c[i], c[j]) - (c[i].r + c[j].r) * (c[i].r + c[j].r)) > 0) {
				Point delta = c[j] - c[i];
				delta = Point(-delta.y, delta.x);
				double now = atan2(delta.y, delta.x);
				if (sign(now) < 0) {
					now = atan2(-delta.y, -delta.x);
				}
				
				if (sign(now - PI) == 0 || (sign(now + PI) == 0)) {
					now = 0.0;
				}
				
				double jj = getJJ((c[i] + c[j]) * 0.5, delta);
				v.push_back(make_pair(make_pair(now, jj), (c[i] + c[j]) * 0.5));
			}
		}
	}
	
	long long ans = 0;
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		Point delta = p2[i] - p1[i];
		double now = atan2(delta.y, delta.x);
		double jj = getJJ(p1[i], delta);
		if (sign(now) < 0) {
			now = atan2(-delta.y, -delta.x);
		}
		
		if (sign(now - PI) == 0 || (sign(now + PI) == 0)) {
			now = 0.0;
		}
		
		if (p2[i] < p1[i]) {
			swap(p1[i], p2[i]);
		}
		
		ans += (upper_bound(v.begin(), v.end(), make_pair(make_pair(now, jj), p2[i]))) - (lower_bound(v.begin(), v.end(), make_pair(make_pair(now, jj), p1[i])));
	}
	
	cout << ans << endl;
	return 0;
}