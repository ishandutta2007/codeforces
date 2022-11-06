

#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int n; cin >> n;
	long long int aa = 9999999999;
	long long int sum = 0;
	for (int i = 0; i < n; ++i) {
		long long int a; cin >> a;
		sum += a;
		if (a % 2)aa = min(a, aa);
	}
	if (sum % 2) {
		sum -= aa;
	}
	cout << sum << endl;
	return 0;
}