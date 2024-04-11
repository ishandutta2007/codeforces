/*
 * D. Professor's task.cpp
 *
 *  Created on: 2011-3-29
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef long long int64;

struct Point {
	int x, y;
	double alpha;
	void read() {
		scanf("%d%d", &x, &y);
	}
	bool operator<(const Point&p) const {
		return alpha < p.alpha;
	}
};

#define cross(p1,p2,p3) (1LL*(p2.x-p1.x)*(p3.y-p1.y)-1LL*(p3.x-p1.x)*(p2.y-p1.y))

inline int sign(int64 x) {
	return x < 0 ? -1 : x > 0;
}

#define crossOp(p1,p2,p3) (sign(cross(p1,p2,p3)))

const int MAX_N_POINTS = 100000 + 10;

Point ps[MAX_N_POINTS];
int type[MAX_N_POINTS];
int nQs;

void inputData() {
	scanf("%d", &nQs);
	for (int i = 0; i < nQs; ++i) {
		scanf("%d", type + i);
		ps[i].read();
	}
}

set<Point> curSet;

Point getPrev(Point me) {
	if (curSet.count(me) > 0)
		return me;
	set<Point>::iterator it = curSet.lower_bound(me);
	if (it != curSet.begin())
		return *--it;
	return *--curSet.end();
}

Point getNext(Point me) {
	set<Point>::iterator it = curSet.upper_bound(me);
	if (it == curSet.end())
		return *curSet.begin();
	return *it;
}

bool isInside(Point me) {
	Point prev = getPrev(me);
	Point next = getNext(me);
	return crossOp(prev,next,me) >= 0;
}

void addPoint(Point me) {
	if (isInside(me))
		return;
	while (true) {
		Point next1 = getNext(me);
		curSet.erase(next1);
		Point next2 = getNext(me);
		if (crossOp(me,next2,next1) < 0) {
			curSet.insert(next1);
			break;
		}
	}
	while (true) {
		Point prev1 = getPrev(me);
		curSet.erase(prev1);
		Point prev2 = getPrev(me);
		if (crossOp(prev2,me,prev1) < 0) {
			curSet.insert(prev1);
			break;
		}
	}
	curSet.insert(me);
}

void work() {
	double rands[] = { 0.4352341254, 0.8242147544, 0.3614575554 };
	double mx = 0, my = 0, sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += rands[i];
		mx += ps[i].x * rands[i];
		my += ps[i].y * rands[i];
	}
	mx /= sum;
	my /= sum;

	for (int i = 0; i < nQs; ++i) {
		ps[i].alpha = atan2(ps[i].y - my, ps[i].x - mx);
	}

	curSet.clear();
	for (int i = 0; i < 3; ++i) {
		curSet.insert(ps[i]);
	}

	for (int i = 3; i < nQs; ++i) {
		if (type[i] == 1) {
			addPoint(ps[i]);
		} else {
			if (isInside(ps[i]))
				puts("YES");
			else
				puts("NO");
		}
	}
}

int main() {
	inputData();
	work();
}