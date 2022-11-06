#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;



int main() {
	int N; cin >> N;
	vector<long long int>as;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		as.push_back(a);
	}
	sort(as.begin(), as.end(),greater<long long int>());
	long long int now = as[0];
	long long int ans = as[0];
	for (int i = 1; i < N; ++i) {
		if (now <= as[i]) {
			as[i] = now - 1;
		}
		if (as[i] < 0)break;
		now = as[i];
		ans += as[i];
	}
	cout << ans << endl;
	return 0;
}