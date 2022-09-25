/*		a.cpp
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
	int n, k;
	scanf("%d%d", &n, &k);
	int res = 0, kth = -1;
	for (int i = 0; i < n; ++i) {
		int y;
		scanf("%d", &y);
		if (!y)
			break;
		if (i + 1 == k)
			kth = y;
		if (i >= k && y < kth)
			break;
		++res;
	}
	printf("%d", res);
}