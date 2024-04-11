#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long int64;

const int64 INF = 1LL << 62;

int64 mul(int64 a, int64 b) {
	if (b == 0)
		return 0;
	if (a > INF / b)
		return INF;
	return min(INF, a * b);
}

int main() {
	int64 n;
	cin >> n;
	vector<int64> ans;
	for (int k = 0; k <= 60; ++k) {
		int64 pw = 1LL << k;
		//(pw-1)*a+a(a-1)/2
		int64 L = 0, R = 1LL << 61;
		while (L + 1 < R) {
			int64 M = (L + R) >> 1;
			int64 t = mul(pw - 1, M) + mul(M, M - 1) / 2;
			if (t > n)
				R = M;
			else
				L = M;
		}
		if ((pw - 1) * L + L * (L - 1) / 2 == n && L % 2 == 1) {
//			cout << "HI" << endl;
			ans.push_back(pw * L);
		}
	}
	if (ans.empty())
		ans.push_back(-1);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
}