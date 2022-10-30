/*
 * b.cpp
 *
 *  Created on: 2011-9-3
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = int(1e5) + 10;
int last[MAX_N];

vector<int> divs[MAX_N];

int main() {
	for (int i = 1; i < MAX_N; ++i) {
		for (int j = i; j < MAX_N; j += i)
			divs[j].push_back(i);
	}
	memset(last, -1, sizeof last);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		int ans = 0;
		foreach(e,divs[x]) {
			if (last[*e] < i - y) {
				++ans;
			}
			last[*e] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}