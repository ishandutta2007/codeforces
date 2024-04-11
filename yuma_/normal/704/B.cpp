#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"
  

int main() {
	int N, S, E; cin >> N >> S >> E;
	S--; E--;
	vector<long long int>xs(N),as(N), bs(N), cs(N), ds(N);
	for (int i = 0; i < N; ++i) {
		cin >> xs[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> bs[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> cs[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> ds[i];
	}
	vector<vector<long long int>>dp(2, vector<long long int>(2*N+5,static_cast<long long int>(1e18)));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i) {
		int tar = i & 1, cur = tar ^ 1;
		if (i == 0)assert(tar == 0 && cur == 1);
		fill(dp[cur].begin(), dp[cur].end(), static_cast<long long int> (1e18));
		
		for (int a= 0; a <= 2 * N; ++a) {
			if (i&&!a)continue;
			if (i == S) {
				//out:l
				if (a) {
					dp[cur][a - 1] = min(dp[cur][a - 1], dp[tar][a] + cs[i]);
				}
				//out:r
				dp[cur][a + 1] = min(dp[cur][a + 1], dp[tar][a] + ds[i]);
			}

			else if (i == E) {
				//in:l
				if (a) {
					dp[cur][a - 1] = min(dp[cur][a - 1], dp[tar][a] + as[i]);
				}

				//in:r
				dp[cur][a + 1] = min(dp[cur][a + 1], dp[tar][a] + bs[i]);
			}
			else {
				//in:l,out:l
				if (a>=2) {
					dp[cur][a-2] = min(dp[cur][a-2], dp[tar][a] + as[i] + cs[i]);
				}

				//in:r,out:r
				dp[cur][a+2] = min(dp[cur][a+2], dp[tar][a] + bs[i] + ds[i]);

				//in:l,out:r
				if (a >= 2 || ((a == 1) && S<i)) {
					dp[cur][a] = min(dp[cur][a], dp[tar][a] + as[i] + ds[i]);
				}

				//in:r,out:l
				if (a >= 2||((a==1)&&S>i)) {
					dp[cur][a] = min(dp[cur][a], dp[tar][a] + bs[i] + cs[i]);

				}
			}
		}
		if (i != N - 1) {
			for (int a = 0; a < 2 * N + 5; ++a) {
				dp[cur][a] += a*(xs[i+1] - xs[i]);
			}
		}
	}
	long long int ans = dp[N%2][0];
	cout << ans << endl;
	return 0;
}