#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		double R, r, k;
		cin >> R >> r >> k;
		R = 1 / R, r = 1 / r;
		double h = (r - R) / 2, x = (r + R) / 2, y = 2 * h * k, d = x * x + y * y;
		printf("%0.10lf\n", 2 * h / (d - h * h));
	}
	return 0;
}