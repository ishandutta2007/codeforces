/*		b.cpp
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

int main(int argc, char **argv) {
	int n;
	scanf("%d", &n);
	int a[4];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; ++i) {
		int y;
		scanf("%d", &y);
		a[y - 1]++;
	}
	int res = a[3] + a[2] + a[1] / 2 + a[1] % 2;
	int empty = a[2] + (a[1] % 2) * 2;
	a[0] -= empty;
	if (a[0] > 0)
		res += (a[0] + 3) / 4;
	printf("%d", res);
}