#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;
int64 n, x, y, c;

//1,5,13,
bool check(int64 T) {
	int64 ans = T * T + (T + 1) * (T + 1);
	if (x + T >= n) {
		ans -= (T - (n - 1 - x)) * (T - (n - 1 - x));
	}
	if (x - T < 0) {
		ans -= (T - x) * (T - x);
	}
	if (y + T >= n) {
		ans -= (T - (n - 1 - y)) * (T - (n - 1 - y));
	}
	if (y - T < 0) {
		ans -= (T - y) * (T - y);
	}
	if (n - x + n - y <= T) {
		int64 t = T - (n - x + n - y) + 1;
		ans += t * (t + 1) / 2;
	}
	if (n - x + y + 1 <= T) {
		int64 t = T - (n - x + y + 1) + 1;
		ans += t * (t + 1) / 2;
	}
	if (x + 1 + n - y <= T) {
		int64 t = T - (x + 1 + n - y) + 1;
		ans += t * (t + 1) / 2;
	}
	if (x + 1 + y + 1 <= T) {
		int64 t = T - (x + 1 + y + 1) + 1;
		ans += t * (t + 1) / 2;
	}
//	cout << T << ":" << ans << endl;
	return ans >= c;
}

int main() {
	cin >> n >> x >> y >> c;
	--x, --y;
	int64 L = -1, R = n * 3;
	while (L + 1 < R) {
		int64 M = (L + R) / 2;
		if (check(M))
			R = M;
		else
			L = M;
	}
	cout << R << endl;
	return 0;
}