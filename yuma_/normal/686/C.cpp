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


int main() {
	int N, M; cin >> N >> M;
	int h_size, m_size;
	vector<int>max_h, max_m;
	{
		int num(N-1);
		while (num) {
			max_h.push_back(num % 7);
			num /= 7;
		}
		if (N == 1)max_h.push_back(0);
		reverse(max_h.begin(), max_h.end());
	}
	{
		int num(M-1);
		while (num) {
			max_m.push_back(num % 7);
			num /= 7;
		}
		if (M == 1)max_m.push_back(0);
		reverse(max_m.begin(), max_m.end());
	}
	if (max_h.size() + max_m.size() > 7) {
		cout << 0 << endl;
	}
	else {
		long long int dp[10][1 << 7][2], dp2[10][1 << 7][2];
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
		{
			dp[0][0][1] = 1;
			for (int i = 0; i < max_h.size(); ++i) {
				for (int j = 0; j < (1 << 7); ++j) {
					bitset<7>bs(j);
					for (int k = 0; k < 2; ++k) {
						for (int t = 0; t < 7; ++t) {
							if (bs[t])continue;
							else {
								bs[t] = true;
								if (k == 1) {
									if (t >max_h[i]) {
										continue;
									}
									else if (t == max_h[i]) {
										dp[i + 1][bs.to_ulong()][1] += dp[i][j][k];
									}
									else {
										dp[i + 1][bs.to_ulong()][0] += dp[i][j][k];
									}
								}
								else {
									dp[i + 1][bs.to_ulong()][0] += dp[i][j][k];
								}
								bs[t] = false;
							}
						}
					}
				}
			}
		}
		{
			dp2[0][0][1] = 1;
			for (int i = 0; i < max_m.size(); ++i) {
				for (int j = 0; j < (1 << 7); ++j) {
					bitset<7>bs(j);
					for (int k = 0; k < 2; ++k) {
						for (int t = 0; t < 7; ++t) {
							if (bs[t])continue;
							else {
								bs[t] = true;
								if (k == 1) {
									if (t > max_m[i]) {
										continue;
									}
									else if (t == max_m[i]) {
										dp2[i + 1][bs.to_ulong()][1] += dp2[i][j][k];
									}
									else {
										dp2[i + 1][bs.to_ulong()][0] += dp2[i][j][k];
									}
								}
								else {
									dp2[i + 1][bs.to_ulong()][0] += dp2[i][j][k];
								}
								bs[t] = false;
							}
						}
					}
				}
			}
		}
		long long int ans = 0;
		for (int i = 0; i < (1 << 7); ++i) {
			for (int j = 0; j < (1 << 7); ++j) {
				bitset<7>bs1(i), bs2(j);
				bool ok = true;
				for (int k = 0; k < 7; ++k) {
					if (bs1[k] && bs2[k])ok = false;
				}
				if (ok) {
					ans += (dp[max_h.size()][i][0] + dp[max_h.size()][i][1]) *(dp2[max_m.size()][j][0] + dp2[max_m.size()][j][1]);
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}