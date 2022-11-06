#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps=1e-9;

int main() {
	int N; cin >> N;
	int a, b;
	for (int i = 0; i < N; ++i) {
		int c; cin >> c;
		if (c == 1) {
			a = i;
		}
		else if (c == N) {
			b = i;
		}
	}
	if (a < b)swap(a, b);
	int plus = max(N - 1 - a, b);
	int ans = plus + abs(a - b);
	cout << ans << endl;
	return 0;
}