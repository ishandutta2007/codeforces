/*
 * E. Guard Towers.cpp
 *
 *  Created on: 2011-5-21
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

struct Point {
	int x, y;
	int color;
	void read() {
		int ox, oy;
		scanf("%d%d", &ox, &oy);
		x = ox + oy;
		y = ox - oy;
	}
};

vector<Point*> byX, byY, points;
bool cmpX(Point*a, Point*b) {
	return a->x < b->x;
}
bool cmpY(Point*a, Point*b) {
	return a->y < b->y;
}

inline int dist(Point*a, Point*b) {
	return max(abs(a->x - b->x), abs(a->y - b->y));
}

int maxDist(const vector<Point*> ps) {
	if (ps.empty())
		return -1;
	Point*p1 = *max_element(ps.begin(), ps.end(), cmpX);
	Point*p2 = *min_element(ps.begin(), ps.end(), cmpX);
	int ret = dist(p1, p2);
	p1 = *max_element(ps.begin(), ps.end(), cmpY);
	p2 = *min_element(ps.begin(), ps.end(), cmpY);
	ret = max(ret, dist(p1, p2));
	return ret;
}

int nComp;
bool check(int L) {
	//	cout << L << endl;
	int n = points.size();
	nComp = 0;
	for (int i = 0; i < n; ++i) {
		points[i]->color = -1;
	}
	int Lx = 0, Rx = n - 1, Ly = 0, Ry = n - 1;
	for (int i = 0; i < n; ++i) {
		Point*p = points[i];
		if (p->color == -1) {
			++nComp;
			p->color = 0;
			queue<Point*> que;
			que.push(p);
			while (que.size()) {
				Point*p = que.front();
				que.pop();
				while (true) {
					bool update = false;

					while (Lx < n && byX[Lx]->color != -1)
						++Lx;
					if (Lx < n && dist(byX[Lx], p) > L) {
						Point*q = byX[Lx];
						q->color = 1 - p->color;
						que.push(q);
						update = true;
					}

					while (Rx >= 0 && byX[Rx]->color != -1)
						--Rx;
					if (Rx >= 0 && dist(byX[Rx], p) > L) {
						Point*q = byX[Rx];
						q->color = 1 - p->color;
						que.push(q);
						update = true;
					}

					while (Ly < n && byY[Ly]->color != -1)
						++Ly;
					if (Ly < n && dist(byY[Ly], p) > L) {
						Point*q = byY[Ly];
						q->color = 1 - p->color;
						que.push(q);
						update = true;
					}

					while (Ry >= 0 && byY[Ry]->color != -1)
						--Ry;
					if (Ry >= 0 && dist(byY[Ry], p) > L) {
						Point*q = byY[Ry];
						q->color = 1 - p->color;
						que.push(q);
						update = true;
					}

					if (!update)
						break;
				}
			}
		}
	}

	vector<Point*> ps[2];
	for (int i = 0; i < points.size(); ++i) {
		Point*p = points[i];
		ps[p->color].push_back(p);
	}

	return maxDist(ps[0]) <= L && maxDist(ps[1]) <= L;
}

const int MOD = 1000000007;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		Point*p = new Point;
		p->read();
		points.push_back(p);
	}
	byX = byY = points;
	sort(byX.begin(), byX.end(), cmpX);
	sort(byY.begin(), byY.end(), cmpY);
	int L = -1, R = 1e5;
	while (L + 1 < R) {
		int M = L + R >> 1;
		if (check(M))
			R = M;
		else
			L = M;
	}
	check(R);
	int ret = 1;
	for (int i = 0; i < nComp; ++i) {
		(ret <<= 1) %= MOD;
	}
	cout << R << endl;
	cout << ret << endl;
}