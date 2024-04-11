/*
 *
 *  Codeforces Beta Round #88
 *  Problem C
 *
 *  Created on: 23.09.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, s, t, f;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &s, &f, &t);
		if (s == f) {
			printf("%d\n", t);
			continue;
		}
		--s;
		--f;
		int pos = t % (2 * m - 2);
		int time1, time2;
		bool down = (pos > m - 1);
		if (down)
			pos = m * 2 - 2 - pos;
		if (pos == s) {
			time1 = 0;
		} else if (pos > s && down) {
			time1 = pos - s;
			pos = s;
		} else if (pos > s && (!down)) {
			time1 = (m - pos - 1) + (m - s - 1);
			pos = s;
			down = 1;
		} else if (pos < s && down) {
			time1 = pos + s;
			pos = s;
			down = 0;
		} else if (pos < s && (!down)) {
			time1 = s - pos;
			pos = s;
		}

		if (down)
			if (f <= pos) {
				time2 = pos - f;
			} else {
				time2 = f + pos;
			}
		else
			if (f >= pos) {
				time2 = f - pos;
			} else {
				time2 = (m - f - 1) + (m - pos - 1);
			}

		printf("%d\n", t + time1 + time2);
	}
}