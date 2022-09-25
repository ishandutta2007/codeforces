#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <complex.h>
#include <string.h>
#include <memory.h>

#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>

using namespace std;

typedef long long li;
typedef long double ld;

#define INF 0x7fffffff
#define PI acos(-1)

int a[301][301];
int p[301];
int s[301][2];

int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			scanf("%d", &t);
			a[i][t - 1] = j;
		}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		p[t - 1] = i;
	}
	s[0][0] = 0;
	s[0][1] = -1;
	if (p[0] < p[1]) {
		s[1][0] = 0;
		s[1][1] = 1;
	} else {
		s[1][0] = 1;
		s[1][1] = 0;
	}
	for (int i = 2; i < n; ++i) {
		if (p[i] < p[s[i - 1][0]]) {
			s[i][0] = i;
			s[i][1] = s[i - 1][0];
		} else if (p[i] < p[s[i - 1][1]]) {
			s[i][0] = s[i - 1][0];
			s[i][1] = i;
		} else {
			s[i][0] = s[i - 1][0];
			s[i][1] = s[i - 1][1];
		}
	}
	int ans[301];
	for (int i = 0; i < n; ++i) {
		int res = -1;
		int prior = INF;
		for (int j = 0; j < n; ++j) {
			int c;
			if (s[j][0] == i)
				c = 1;
			else
				c = 0;
			if (s[j][c] == -1)
				continue;
			if (a[i][s[j][c]] < prior) {
				prior = a[i][s[j][c]];
				res = j;
			}
		}
		ans[i] = res + 1;
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
}