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

ll len[200001];
int a[200001];
int fi[200001];

#define B 150000

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    len[0] = 0;
    for (int i = 0; i < n; ++i) {
		int op;
		cin >> op;
		if (op == 1) {
			int c;
			cin >> c;
			if (len[i] < B)
				a[len[i]] = c;
			len[i + 1] = len[i] + 1;
			fi[i + 1] = c;
		} else {
			int l, c;
			cin >> l >> c;
			if (len[i] < B) {
				int pos = len[i];
				for (int q = 0; q < c; ++q)
					for (int i = 0; i < l; ++i) {
						a[pos++] = a[i];
						if (pos >= B) {
							q = c;
							break;
						}
					}
			}
			len[i + 1] = len[i] + ll(l) * ll(c);
			fi[i + 1] = -l;
		}
	}
	//~ for (int i = 0; i < n + 1; ++i)
		//~ cerr << len[i] << ' ';
	//~ cerr << '\n';
	//~ for (int i = 0; i < 30; ++i)
		//~ cerr << a[i] << ' ';
	//~ cerr << '\n';
	//~ cerr << len[n] << '\n';
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll p;
		cin >> p;
		//~ --p;
		int pos = lower_bound(len, len + n + 1, p) - len;
		//~ cerr << pos << ' ';
		//~ continue;
		if (fi[pos] >= 0)
			cout << fi[pos] << ' ';
		else {
			p -= len[pos - 1] + 1;
			p %= ll(-fi[pos]);
			cout << a[p] << ' ';
		}
	}
}