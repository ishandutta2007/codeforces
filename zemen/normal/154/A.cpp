/*
 * a.cpp
 *
 *  Created on: 24.02.2012
 *      Author: zemen
 */

#include <algorithm>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <map>
#include <memory.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <time.h>
#include <vector>

using namespace std;

#define PI M_PIl
#define EPS 10E-9
#define INF __INT_MAX__

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

char s[100001];
char p[13][3];
int n, k;

int main(int argc, char **argv) {
	gets(s);
	scanf("%d\n", &k);
	for (int i = 0; i < k; ++i)
		gets(p[i]);
	n = strlen(s);
	int c[2] = {0, 0};
	char buf[2] = {0, 0};
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		if (s[i] == buf[0]) {
			c[0]++;
			continue;
		}
		if (s[i] == buf[1]) {
			swap(c[0], c[1]);
			swap(buf[0], buf[1]);
			c[0]++;
			continue;
		}
		res += min(c[0], c[1]);
		buf[0] = 0;
		buf[1] = 0;
		c[0] = 0;
		c[1] = 0;
		for (int j = 0; j < k; ++j) {
			if (s[i] == p[j][0]) {
				buf[0] = s[i];
				buf[1] = p[j][1];
				c[0] = 1;
				c[1] = 0;
				break;
			}
			if (s[i] == p[j][1]) {
				buf[0] = s[i];
				buf[1] = p[j][0];
				c[0] = 1;
				c[1] = 0;
				break;
			}
		}
	}
	printf("%d", res);
}