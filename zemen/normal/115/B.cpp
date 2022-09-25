/*
 * olymp.cpp
 *
 *  Created on: 14.09.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <algorithm>

using namespace std;

int minmax[2][200];

int main() {
	int n, m, x;
	char p;
	int lastline = 0;
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		int min = m + 1;
		int max = -1;
		for (int j = 0; j < m; ++j) {
			if (getchar() == 'W') {
				if (min == m + 1) {
					min = j;
				}
				max = j;
			}
		}
		minmax[0][i] = min;
		minmax[1][i] = max;
		if (min != m + 1)
			lastline = i;
		getchar();
	}
	x = 0;
	int res = 0;
	for (int i = 0; i <= lastline; ++i) {
		if (i % 2) {
			int newx = x;
			if (minmax[0][i] < x)
				newx = minmax[0][i];
			if (i < lastline && minmax[0][i + 1] < newx && minmax[0][i + 1] != m + 1) {
				newx = minmax[0][i + 1];
			}
			res += abs(x - newx);
			x = newx;
		} else {
			int newx = x;
			if (minmax[1][i] > x)
				newx = minmax[1][i];
			if (i < lastline && minmax[1][i + 1] > newx && minmax[1][i + 1] != -1) {
				newx = minmax[1][i + 1];
			}
			res += abs(newx - x);
			x = newx;
		}
		++res;
	}
	--res;
	printf("%d", res);
}