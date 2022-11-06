#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"

int dp[1001][1001][11]; 
int main() {
	int a, b,K; cin >> a >> b >> K;
	string s, t; cin >> s >> t;
	vector<vector<int>>sames(a, vector<int>(b));
	for (int i = a - 1; i >= 0; --i) {
		for (int j = b - 1; j >= 0; --j) {
			if (i == a - 1 || j == b - 1) {
				sames[i][j] = s[i] == t[j];
			}
			else {
				if (s[i] == t[j]) {
					sames[i][j] = sames[i + 1][j + 1] + 1;
				}
				else {
					sames[i][j] = 0;
				}
			}
		}
	}
	int ans = 0;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			
			for (int k = 0; k < K;++k) {
				
				int amin = max(0, sames[i][j] - 20);
				int amax = sames[i][j];
				for (int t = amax; t <= amax; ++t) {
					dp[i + t][j + t][k + 1] = max(dp[i + t][j + t][k + 1], dp[i][j][k] + t);
				}

				dp[i + 1][j][k] = max(dp[i][j][k], dp[i + 1][j][k]);
				dp[i][j + 1][k] = max(dp[i][j][k], dp[i][j + 1][k]);
			}
		}
	}
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k <= K; ++k) {
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}