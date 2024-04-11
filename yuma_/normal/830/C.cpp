#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
	int N; cin >> N;
	long long int K; cin >> K;
	vector<long long int>as(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	set<long long int>points;
	for (auto&& a:as) {
		long long int k = sqrt(a)+1;
		map<int, int>mp;
		for (long long int i = 1; i <= k+1; ++i) {
			long long int b = a / i;

			if (b >= 1e5-10) {
				if (b*i == a)points.emplace(b);
				else points.emplace(b + 1);
			}
		}
		//int c; cin >> c;
	}

	for (int i = 1; i < 1e5; ++i) {
		points.emplace(i);
	}
	long long int ans = 1;
	for (auto p : points) {
		long long int sum = 0;
		long long int divsum = 0;
		for (auto a : as) {
			long long int div = a / p;
			long long int plus = a%p;
			divsum += div + (plus ? 1 : 0);
			sum += plus ? p - plus : 0;
		}
		if (sum > K)continue;
		long long int t = p + (K - sum) / divsum;
		ans = max(ans, t);
	}
	cout << ans << endl;
	return 0;
}