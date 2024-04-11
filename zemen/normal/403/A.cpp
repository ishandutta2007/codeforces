#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "a"

char g[25][25];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int q;
	cin >> q;
	for (int ii = 0; ii < q; ++ii) {
		int n, p;
		cin >> n >> p;
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; ++i)
			g[i][(i + 1) % n] = g[(i + 1) % n][i] = 1;
		for (int i = 0; i < n; ++i)
			g[i][(i + 2) % n] = g[(i + 2) % n][i] = 1;
		if (p)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < i; ++j)
					if (!g[i][j]) {
						g[i][j] = g[j][i] = 1;
						--p;
						if (!p)
							i = j = n;
					}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < i; ++j)
				if (g[i][j])
					cout << i + 1 << ' ' << j + 1 << '\n';
	}
}