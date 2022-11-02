#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
const int MAX_N = int(3e5) + 10;
int n;
typedef long long int64;
int64 a[MAX_N];

const int64 INF = 1LL << 60;

int64 dp[MAX_N]; //chose it and it is the last one
int64 sum[MAX_N];

int64 get(int l, int r) {
	if (l > r)
		return 0;
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main() {
	cin >> n;
	map<int, int> first, last;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (i > 0)
			sum[i] += sum[i - 1];
		if (a[i] > 0)
			sum[i] += a[i];
		last[a[i]] = i;
		if (!first.count(a[i]))
			first[a[i]] = i;
	}

	int bi = -1, bj = -1;
	int64 ans = -INF;

	for (map<int, int>::iterator it = first.begin(); it != first.end(); ++it) {
		int me = it->first;
		int i = it->second, j = last[me];
		if (i < j) {
			int64 ret = get(i + 1, j - 1) + a[i] + a[j];
			if (ret > ans) {
				ans = ret;
				bi = i, bj = j;
			}
		}
	}
	static bool remain[MAX_N];

	remain[bi] = remain[bj] = true;
	for (int k = bi + 1; k < bj; ++k) {
		remain[k] = (a[k] > 0);
	}

	int cut = 0;
	for (int i = 0; i < n; ++i) {
		if (!remain[i])
			++cut;
	}

	cout << ans << " " << cut << endl;
	for (int i = 0; i < n; ++i) {
		if (!remain[i])
			cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}