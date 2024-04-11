/*
 * c.cpp
 *
 *  Created on: 2012-4-20
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

int main() {
	int n, m, x1, x2, y1, y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	int dx = abs(x1 - x2), dy = abs(y1 - y2);
	if (dx > 4 || dy > 4)
		puts("Second");
	else if (dx + dy >= 7) {
		puts("Second");
	} else {
		puts("First");
	}
	return 0;
}