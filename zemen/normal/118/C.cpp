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
#include <string.h>

#define INF 0x7fffffff

int main() {
	int n, k;
	scanf("%d%d\n", &n, &k);
	char s[10003];
	char glres[10003];
	char res[10003];
	gets(s);
	int min = INF;
	for (int i = 0; i < 10; ++i) {
		memcpy(res, s, sizeof(s));
		int cnt = 0;
		int cur = 0;
		for (int j = 0; j < 10; ++j) {
			if (cnt == k)
				continue;
			for (int c = 0; c < n; ++c) {
				int a = s[c] - '0';
				if (a - i == j) {
					++cnt;
					cur += j;
					res[c] = i + '0';
					if (cnt == k)
						break;
				}
			}
			if (cnt == k || j == 0)
				continue;
			for (int c = n - 1; c >= 0; --c) {
				int a = s[c] - '0';
				if (i - a == j) {
					++cnt;
					cur += j;
					res[c] = i + '0';
					if (cnt == k)
						break;
				}

			}
		}
		if (cur < min) {
			memcpy(glres, res, sizeof(res));
			min = cur;
		} else if (cur == min && strcmp(res, glres) < 0) {
			memcpy(glres, res, sizeof(res));
		}
	}
	printf("%d\n", min);
	puts(glres);
}