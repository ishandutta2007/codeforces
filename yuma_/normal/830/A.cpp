#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;


bool check(vector<long long int>&as, vector<long long int>&bs, long long int K, long long int t) {
	vector<int>used(bs.size(), false);
	for (int i = 0; i < as.size(); ++i) {
		long long int dis = abs(K - as[i]);
		if (dis > t)return false;
		long long int x = (t - dis) / 2;
		long long int l, r;
		if (as[i] < K) {
			l = as[i] - x;
			r = K + x;
		}
		else {
			l = K - x;
			r = as[i] + x;
		}
		bool flag = false;
		for (int j = 0; j < bs.size(); ++j) {
			if (used[j])continue;
			if (l > bs[j] || bs[j]>r)continue;
			used[j] = true;
			flag = true;
			break;
		}
		if (!flag)return false;
	}
	return true;
}

int main() {
	long long int N, M, K; cin >> N >> M >> K;
	vector<long long int>as(N), bs(M);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	sort(as.begin(), as.end());
	for (int j = 0; j < M; ++j) {
		cin >> bs[j];
	}
	sort(bs.begin(), bs.end());
	long long int amin = -1;
	long long int amax = 2e9;
	while (amin + 1 != amax) {
		long long int amid=(amin + amax) / 2;
		if (check(as, bs, K, amid)) {
			amax = amid;
		}
		else {
			amin = amid;
		}
	}
	cout << amax << endl;
	return 0;
}