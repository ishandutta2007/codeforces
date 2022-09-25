/*
 * olymp.cpp
 *
 *  Created on: 23.09.2011
 *      Author: zemen
 *
 *  Codeforces Beta Round #89(div. 2, out of competition)
 */
#include <stdio.h>
#include <memory.h>

int main() {
	int n1, n2, k1, k2;
	scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
	int d[2][105][105][12];
	memset(d, 0, sizeof(d));
	d[0][n1 - 1][n2][1] = 1;
	d[1][n1][n2 - 1][1] = 1;
	for (int i = n1 + n2 - 1; i > 0; --i) {
		for (int j = 0; j <= i; ++j) {
			int cn1 = j;
			int cn2 = i - j;
			if (cn1 > n1 || cn2 > n2)
				continue;
			for (int k = 1; k < 11; ++k) {
				if (cn1 > 0) {
					if (k < k1) {
						d[0][cn1 - 1][cn2][k + 1] += d[0][cn1][cn2][k];
						d[0][cn1 - 1][cn2][k + 1] %= 100000000;
					}
					d[0][cn1 - 1][cn2][1] += d[1][cn1][cn2][k];
					d[0][cn1 - 1][cn2][1] %= 100000000;
				}
				if (cn2 > 0) {
					if (k < k2) {
						d[1][cn1][cn2 - 1][k + 1] += d[1][cn1][cn2][k];
						d[1][cn1][cn2 - 1][k + 1] %= 100000000;
					}
					d[1][cn1][cn2 - 1][1] += d[0][cn1][cn2][k];
					d[1][cn1][cn2 - 1][1] %= 100000000;
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i < 11; ++i) {
		res += d[0][0][0][i];
		res += d[1][0][0][i];
		res %= 100000000;
	}
	printf("%d", res);
}