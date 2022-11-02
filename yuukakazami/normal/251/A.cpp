#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n, d;
typedef long long int64;
const int MAX_N = int(1e5) + 10;
int a[MAX_N];

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	int j = 0;
	int64 ans = 0;
	for (int i = 0; i < n; ++i) {
		while (j < n && a[j] - a[i] <= d)
			++j;
		int can = j - i - 1;
		ans += 1LL * can * (can - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}