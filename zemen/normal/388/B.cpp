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

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int N = 2;
char a[1001][1001];

int build(int u, int v, int l) {
	//~ cerr << "build " << u << ' ' << v << ' ' << l << '\n';
	if (l == 1) {
		a[u][v] = a[v][u] = 1;
		//~ cerr << u << ' ' << v << '\n';
		return 1;
	}
	int w = N;
	++N;
	int len = build(u, w, l / 2) + 2;
	//~ cerr << "ok\n";
	a[w][N + 1] = a[N + 1][w] = 1;
	a[w][N + 2] = a[N + 2][w] = 1;
	a[N + 1][v] = a[v][N + 1] = 1;
	a[N + 2][v] = a[v][N + 2] = 1;
	//~ cerr << w << ' ' << N + 1 << '\n';
	//~ cerr << w << ' ' << N + 2 << '\n';
	//~ cerr << N + 1 << ' ' << v << '\n';
	//~ cerr << N + 2 << ' ' << v << '\n';
	N += 3;
	if (l % 2) {
		int prev = u;
		for (int i = 0; i < len - 1; ++i) {
			a[N][prev] = a[prev][N] = 1;
			//~ cerr << N << ' ' << prev << '\n';
			prev = N;
			++N;
		}
		a[prev][v] = a[v][prev] = 1;
		//~ cerr << prev << ' ' << v << '\n';
	}
	return len;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    build(0, 1, n);
    cout << N << '\n';
    for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << (a[i][j] ? 'Y' : 'N');
		cout << '\n';
	}
}