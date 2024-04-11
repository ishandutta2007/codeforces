/*
 * D. Hanger.cpp
 *
 *  Created on: 2011-5-29
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef pair<int, int> ipair;

const int BIG = int(1e9) + 10;

const ipair NONE(-1, -1);

struct Paint {
	map<int, ipair> Map;
	Paint() {
		Map[-BIG] = Map[BIG] = NONE;
	}
	ipair get(int x) {
		return (--Map.upper_bound(x))->second;
	}
	void paint(int l, int r, ipair c) {
		//[l,r] to c
		ipair o = get(++r);
		Map.erase(Map.lower_bound(l), Map.lower_bound(r));
		Map[l] = c;
		Map[r] = o;
	}
};

Paint paint;

struct TA {
	map<int, int> cnt;
	void add(int p, int x) {
		for (; p <= BIG; p += p & -p)
			cnt[p] += x;
	}

	int calc(int p) {
		int ret = 0;
		for (; p > 0; p -= p & -p)
			if (cnt.count(p))
				ret += cnt[p];
		return ret;
	}

	int calc(int l, int r) {
		return calc(r) - calc(l - 1);
	}
};

TA ta;

priority_queue<ipair> segments;

ipair make(ipair a) {
	return make_pair(a.second - a.first, a.first);
}

void addSegment(ipair s) {
	segments.push(make(s));
	paint.paint(s.first, s.second, s);
}

bool checkSegment(ipair a) {
	return paint.get(a.first) == a;
}

map<int, int> pos;

ipair concat(ipair a, ipair b) {
	if (a == NONE)
		return b;
	if (b == NONE)
		return a;
	return make_pair(a.first, b.second);
}

void debug(int L) {
	for (int i = 1; i <= L; ++i) {
		if (paint.get(i) == NONE)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int main() {
	int L, nQ;
	scanf("%d%d", &L, &nQ);
	addSegment(make_pair(1, L));
	for (int i = 0; i < nQ; ++i) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", ta.calc(l, r));
		} else {
			if (pos.count(x)) {
				int at = pos[x];
				pos.erase(x);
				ipair seg(at, at);
				ta.add(at, -1);
				seg = concat(paint.get(at - 1), seg);
				seg = concat(seg, paint.get(at + 1));
				addSegment(seg);
			} else {
				while (!segments.empty()) {
					ipair seg = segments.top();
					segments.pop();
					int L = seg.second, R = L + seg.first;
					if (!checkSegment(make_pair(L, R)))
						continue;
					int at = (L + R + 1) / 2;
					ta.add(at, 1);
					pos[x] = at;
					paint.paint(at, at, NONE);
					if (L <= at - 1) {
						addSegment(make_pair(L, at - 1));
					}
					if (at + 1 <= R) {
						addSegment(make_pair(at + 1, R));
					}
					break;
				}
			}
		}
	}
}