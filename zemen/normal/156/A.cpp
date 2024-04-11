/*		a.cpp
 *		Created on: 25.02.2012
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

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

int main(int argc, char **argv) {
	char s[6001], t[2001];
	memset(s, 0, sizeof(s));
	gets(s + 2000);
	gets(t);
	int n = strlen(t);
	int res = n;
	for (int i = 0; i < 6000; ++i) {
		if (i + n > 6000)
			break;
		int c = 0;
		for (int j = 0; j < n; ++j) {
			if (t[j] != s[i + j])
				++c;
		}
		res = min(res, c);
	}
	printf("%d", res);
}