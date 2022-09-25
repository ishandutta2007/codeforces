/*		d.cpp
 *		Created on: 04.03.2012
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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

int a[20000];

int main(int argc, char **argv) {
	/*
	freopen("qwer.log", "w", stdout);
	int res = -INF;
	for (int i = 1; i < 20001; ++i) {
		int n = i;
		int cres = 1;
		int d = 1;
		for (int j = 2; j * j <= n; ++j) {
			while (n % j == 0) {
				++d;
				n /= j;
			}
			cres *= d;
			d = 1;
		}
		if (n > 1)
			cres *= 2;
		res = res < cres ? cres : res;
		printf("%d %d\n", i, cres);
	}
	cout << res;
	*/
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int res = -INF;
	for (int i = 1; i <= n; ++i) {
		if (n % i)
			continue;
		if (n / i < 3)
			continue;
		int cres = -INF;
		for (int j = 0; j < i; ++j) {
			int ccres = 0;
			for (int k = j; k < n; k += i)
				ccres += a[k];
			cres = max(cres, ccres);
		}
		res = max(cres, res);
	}
	printf("%d", res);
}