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

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int a[101][101];
int s[101];
int q[101];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    int res = 0, sum = 0;
    int e = 0;
    for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < s[i]; ++j) {
			cin >> a[i][j];
			sum += a[i][j];
		}
		for (int j = 0; j < s[i] / 2; ++j)
			res += a[i][j];
		if (s[i] % 2)
			q[e++] = a[i][s[i] / 2];
	}
	sort(q, q + e);
	for (int i = e - 1; i >= 0; i -= 2)
		res += q[i];
	cout << res << ' ' << sum - res << '\n';
}