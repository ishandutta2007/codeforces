#include <stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
using namespace std;

long long int kaijou(long long int a, long long int b) {
	long long int ans = 1;
	for (int i = 0; i < b; ++i) {
		ans *= a;
	}
	return ans;
}

int main() {
	
	long long int n, k;
	cin >> n >> k;
	vector< long long int>divs;
	vector< long long int>firsts;
	for (int i = 0; i < n / k; ++i) {
		long long int a;
		cin >> a;
		divs.push_back(a);
	}
	for (int i = 0; i < n / k; ++i) {
		long long int a;
		cin >> a;
		firsts.push_back(a);
	}
	long long int ans = 1;
	const long long int blockmax = kaijou(10, k);
	for (int i = 0; i < n / k; ++i) {
		if (firsts[i] == 0) {
			ans *= ((blockmax - 1) / divs[i] + 1) - (((((firsts[i] + 1)*blockmax) / 10 - 1) / divs[i] + 1));
		}
		else {
			ans *= (((blockmax - 1) / divs[i] + 1) - (((((firsts[i] + 1)*blockmax) / 10 - 1) / divs[i] + 1)) + (((firsts[i] * blockmax) / 10 - 1) / divs[i] + 1));
		}
		ans %= kaijou(10, 9) + 7;
	}
	cout << ans << endl;
	return 0;
}