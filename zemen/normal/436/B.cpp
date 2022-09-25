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

#define NAME "b"

char a[2004][2004];
int ans[2004];

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '.')
				continue;
			if (a[i][j] == 'L' && j >= i)
				ans[j - i]++;
			if (a[i][j] == 'R' && i + j < m)
				ans[i + j]++;
			if (a[i][j] == 'U' && i % 2 == 0)
				ans[j]++;
		}
	for (int i = 0; i < m; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
}