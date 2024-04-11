/*
 * c.cpp
 *
 *  Created on: 2012-6-12
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 1500 + 10;

typedef long long int64;

int sign(int64 a) {
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
	Point operator*(double d) const {
		return Point(x * d, y * d);
	}
	Point operator/(double d) const {
		return Point(x / d, y / d);
	}
	bool operator<(const Point&p) const {
		return x != p.x ? x < p.x : y < p.y;
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
	void write() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

Point isSS(Point p1, Point p2, Point q1, Point q2) {
	double a1 = cross(q1,q2,p1), a2 = -cross(q1,q2,p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

Point ps[MAX_N];
int n;

bool e[MAX_N][MAX_N];

bool cmp(int a, int b) {
	return ps[a] < ps[b];
}

int mp[MAX_N];

int RT;
Point CT;

bool cmp2(int a, int b) {
	Point A = ps[a], B = ps[b];
	return crossOp(CT,A,B) > 0;
}

int size[MAX_N];

void dfs(int u, int par) {
	size[u] = 1;
	for (int i = 0; i < n; ++i) {
		if (e[u][i] && i != par)
			dfs(i, u), size[u] += size[i];
	}
}

void work(int rt, int par, vector<int> cur) { // return root
	//take the left-lowerest point
	int low = *min_element(cur.begin(), cur.end(), cmp);
	cur.erase(find(cur.begin(), cur.end(), low));

	mp[low] = rt;

	vector<int> ch;
	for (int i = 0; i < n; ++i) {
		if (e[rt][i] && i != par)
			ch.push_back(i);
	}

        CT = ps[low];

	sort(cur.begin(), cur.end(), cmp2);

	int at = 0;

	for (vector<int>::iterator e = ch.begin(); e != ch.end(); ++e) {
		work(*e, rt, vector<int>(cur.begin() + at, cur.begin() + at + size[*e]));
		at += size[*e];
	}
}

int main() {
	cin >> n;
	memset(e, 0, sizeof e);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		e[a][b] = e[b][a] = true;
	}
	for (int i = 0; i < n; ++i) {
		ps[i].read();
	}
	dfs(0, -1);

	vector<int> cur;
	for (int i = 0; i < n; ++i) {
		cur.push_back(i);
	}

	work(0, -1, cur);

	for (int i = 0; i < n; ++i) {
		printf("%d ", mp[i] + 1);
	}
	puts("");
	return 0;
}