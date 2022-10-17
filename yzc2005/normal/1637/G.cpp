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
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = (int)1e6 + 77;
int ansSz;
int ans[N][2];
int c[30];

void addAns(int x, int y) {
	ans[ansSz][0] = x;
	ans[ansSz][1] = y;
	ansSz++;
}

void solve(int n, int d) {
	if (n <= 2) {
		for (int i = 0; i < n; i++)
			c[d + i]++;
		return;
	}
	int k = 0;
	while((1 << k) < n) k++;
	if (n == (1 << k)) {
		c[d + k]++;
		n--;
	}
	c[d + k - 1]++;
	int l = (1 << k) - n;
	for (int i = l; i < (1 << (k - 1)); i++) {
		addAns(i << d, ((1 << k) - i) << d);
		c[d + k]++;
	}
	solve(l - 1, d);
	solve((n - l) / 2, d + 1);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		if (n == 2) {
			printf("-1\n");
			continue;
		}
		for (int i = 0; i < 30; i++)
			c[i] = 0;
		ansSz = 0;
		solve(n, 0);
		int k = 29;
		while(c[k] == 0) k--;
		assert(n <= (1 << k) && 2 * n > (1 << k));
		for (int i = 0; i < k; i++) {
			while(c[i] >= 2) {
				addAns(1 << i, 1 << i);
				c[i] -= 2;
				c[i + 1]++;
			}
		}
		for (int i = 0; i < k; i++) {
			while(c[i] >= 2) {
				addAns(1 << i, 1 << i);
				c[i] -= 2;
				c[i + 1]++;
			}
			if (c[i] == 1) {
				addAns(1 << i, 0);
				addAns(1 << i, 1 << i);
				c[i]--;
				c[i + 1]++;
			}
		}
		while(c[k] < n) {
			addAns(1 << k, 0);
			c[k]++;
		}
		printf("%d\n", ansSz);
		for (int i = 0; i < ansSz; i++)
			printf("%d %d\n", ans[i][0], ans[i][1]);
	}

	return 0;
}