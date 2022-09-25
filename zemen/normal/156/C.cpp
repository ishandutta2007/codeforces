/*		c.cpp
 *		Created on: 29.02.2012
 *      Author: zemen
 */

#include <algorithm>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define INF __INT_MAX__
#define PI M_PIl
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

int d[101][2601];

void modadd(int &a, int b) {
	a += b;
	a %= MOD;
}

int main(int argc, char **argv) {
	memset(d, 0, sizeof(d));
	d[0][0] = 1;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 2600; ++j)
			for (int k = 1; k < 27; ++k)
				modadd(d[i + 1][j + k], d[i][j]);
	int t;
	scanf("%d\n", &t);
	char s[101];
	for (int i = 0; i < t; ++i) {
		gets(s);
		int n = strlen(s);
		int q = 0;
		for (int i = 0; i < n; ++i)
			q += s[i] - 'a' + 1;
		int res = d[n][q];
		modadd(res, MOD - 1);
		printf("%d\n", res);
	}
}