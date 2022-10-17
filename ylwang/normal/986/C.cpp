#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif
 
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
 
const int N = (1 << 22) + 5;
const int S = 2 * N;
int n;
int m;
bool hv[N];
bool used[S];
int ans;
int q[S];
int topQ;
 
void solve(int x) {
	topQ = 0;
	q[topQ++] = x;
	used[x] = 1;
	for (int it = 0; it < topQ; it++) {
		x = q[it];
		if (x < (1 << n)) {
			if (!used[x + (1 << n)]) {
				used[x + (1 << n)] = 1;
				q[topQ++] = x + (1 << n);
			}
		} else {
			int y = (1 << (n + 1)) - 1 - x;
			if (!used[y] && hv[y]) {
				used[y] = 1;
				q[topQ++] = y;
			}
			for (int i = 0; i < n; i++) {
				y = x | (1 << i);
				if (!used[y]) {
					used[y] = 1;
					q[topQ++] = y;
				}
			}
		}
	}
}
 
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
 
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		hv[x] = 1;
	}
	for (int i = 0; i < (1 << n); i++) {
		if (hv[i] && !used[i]) {
			solve(i);
			ans++;
		}
	}
	printf("%d\n", ans);
 
	return 0;
}