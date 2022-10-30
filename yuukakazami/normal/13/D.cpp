/*
 * D. Triangles.cpp
 *
 *  Created on: 2011-8-20
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

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
	int det(const Point&p) const {
		return x * p.y - y * p.x;
	}
	int dot(const Point&p) const {
		return x * p.x + y * p.y;
	}
	void read() {
		scanf("%d%d", &x, &y);
	}
};

#define cross(p1,p2,p3) (1LL*(p2.x-p1.x)*(p3.y-p1.y)-1LL*(p3.x-p1.x)*(p2.y-p1.y))

const int MAX_N = 500 + 10;
Point red[MAX_N], blue[MAX_N];
int nRed, nBlue;
int cnt[MAX_N][MAX_N];

int main() {
	cin >> nRed >> nBlue;
	for (int i = 0; i < nRed; ++i) {
		red[i].read();
	}
	for (int i = 0; i < nBlue; ++i) {
		blue[i].read();
	}
	for (int i = 0; i < nRed; ++i) {
		for (int j = 0; j < nRed; ++j) {
			if (red[i].x >= red[j].x)
				continue;
			int tmp = 0;
			for (int k = 0; k < nBlue; ++k) {
				if (blue[k].x >= red[i].x && blue[k].x < red[j].x && cross(red[i],red[j],blue[k]) > 0)
					++tmp;
			}
			cnt[i][j] = tmp;
			cnt[j][i] = -tmp;
		}
	}
	int ans = 0;
	for (int i = 0; i < nRed; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
				if (cnt[i][j] + cnt[j][k] + cnt[k][i] == 0)
					++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}