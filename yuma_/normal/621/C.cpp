#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int N, P; cin >> N >> P;
	vector<long double>pers(N);
	for (int i = 0; i < N; ++i) {
		int l, r; cin >> l >> r;
		long double num = r / P - (l - 1) / P;
		pers[i] = num / (r - l + 1);
	}
	long double ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += 2000 * (1 - (1 - pers[i])*(1 - pers[(i + 1) % N]));
	}
	cout <<setprecision(12)<<fixed<< ans << endl;
	return 0;
}