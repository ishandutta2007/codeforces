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

int cnt[5][5];
int a[5][5];
int row[5];
int col[5];
int conv[1000];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	conv[int('R')] = 0;
	conv[int('G')] = 1;
	conv[int('B')] = 2;
	conv[int('W')] = 3;
	conv[int('Y')] = 4;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char s[5];
		scanf("%s", s);
		cnt[conv[int(s[0])]][s[1] - '1']++;
	}
	int ans = 10;
	for (int mask = 0; mask < 1024; ++mask) {
		bool ok = true;
		for (int i1 = 0; i1 < 5; ++i1)
			for (int j1 = 0; j1 < 5; ++j1)
				for (int i2 = 0; i2 < 5; ++i2)
					for (int j2 = 0; j2 < 5; ++j2) {
						if (i2 == i1 && j2 == j1)
							continue;
						if (!cnt[i1][j1] || !cnt[i2][j2])
							continue;
						if (i1 != i2 && (mask & (1 << i1)))
							continue;
						if (i1 != i2 && (mask & (1 << i2)))
							continue;
						if (j1 != j2 && (mask & (1 << (j1 + 5))))
							continue;
						if (j1 != j2 && (mask & (1 << (j2 + 5))))
							continue;
						ok = false, i1 = i2 = j1 = j2 = 10;
					}
		if (ok)
			ans = min(ans, __builtin_popcount(mask));
	}
	cout << ans << '\n';
}