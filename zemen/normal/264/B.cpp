#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

int d[100001];
int pr[100];

int main() {
	memset(d, 0, sizeof(d));
	int n, c;
	scanf("%d", &n);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &c);
		int _c = c;
		int prc = 0;
		for (int j = 2; j * j <= _c; ++j)
			if (_c % j == 0) {
				pr[prc++] = j;
				while (_c % j == 0)
					_c /= j;
			}
		if (_c > 1)
			pr[prc++] = _c;
		int rmax = 1;
		for (int j = 0; j < prc; ++j)
			rmax = max(rmax, d[pr[j]] + 1);
		for (int j = 0; j < prc; ++j)
			d[pr[j]] = max(d[pr[j]], rmax);
		res = max(res, rmax);
	}
	printf("%d", res);
}