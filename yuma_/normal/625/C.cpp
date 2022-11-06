#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


int main() {
	/*long long int N; cin >> N;
	long long int A, B, C; cin >> A >> B >> C;
	if (A <= (B - C)) {
		long long int ans = N / A;
		cout << ans << endl;
	}
	else {
		long long int num = (N - B) / (B - C);
		long long int rest = N - num*(B - C);
		long long int ans(num);
		while (rest >= B) {
			ans++;
			rest -= (B - C);
		}
		ans += rest / A;
		cout << ans << endl;
	}
	return 0;*/
	int N, K; cin >> N >> K;
	vector<vector<int>>nums(N, vector<int>(N));
	int now = 1;
	for (int y = 0; y < N; ++y) {

		for (int x = 0; x < K - 1; ++x) {
			nums[y][x] = now++;
		}
	}
	for (int y = 0; y < N; ++y) {

		for (int x = K-1; x < N; ++x) {
			nums[y][x] = now++;
		}
	}
	int sum = 0;
	for (int y = 0; y < N; ++y) {
		sum += nums[y][K - 1];
	}
	cout << sum << endl;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cout << nums[y][x];
			if (x != N - 1)cout << " ";
		}
		cout << endl;
	}
	return 0;
}