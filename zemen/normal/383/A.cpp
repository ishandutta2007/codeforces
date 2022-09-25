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

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int a[1000001];
ll res = 0;

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    int lc = 0, rc = 0;
    for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i])
			++rc;
		else
			++lc;
	}
	int lb = 0, rb = n;
	while (lb < rb) {
		if (a[lb] == 0) {
			++lb;
			--lc;
			continue;
		}
		if (a[rb - 1] == 1) {
			--rb;
			--rc;
			continue;
		}
		if (lc > rc) {
			res += rc;
			--lc;
			--rb;
		} else {
			res += lc;
			--rc;
			++lb;
		}
	}
	cout << res << '\n';
}