#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;


int main() {
	int N; cin >> N;
	map<int, int>mp;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		mp[a]++;
	}
	int answer = 1;
	if (mp.size() <= 2) {
		answer = N;
	}
	else {
		for (auto choose : mp) {
			if (choose.second == 1)continue;
			else {
				const int max_use_cnt = choose.second;
				const int max_sum = choose.first * choose.second;
				vector<vector<vector<int>>>
					dp(2, vector<vector<int>>(max_use_cnt + 1,
						vector<int>(max_sum + 1)));

				dp[0][0][0] = 1;
				int nex = 1;
				int cur = 0;
				for (auto m : mp) {
					dp[nex] = vector<vector<int>>(max_use_cnt + 1,
						vector<int>(max_sum + 1));
					for (int i = 0; i <= max_sum; ++i) {
						for (int j = 0; j <= max_use_cnt; ++j) {
							for (int k = 0; k <= m.second; ++k) {
								if (m == choose&&k)break;
								int sum = i + k*m.first;
								int use_cnt = j + k;
								if (sum <= max_sum&&use_cnt <= max_use_cnt) {
									dp[nex][use_cnt][sum] |=
										dp[cur][j][i];
								}
							}
						}

					}
					swap(cur, nex);
				}
				for (int num = 1; num <= choose.second; ++num) {
					if (dp[cur][num][num*choose.first])break;
					answer = max(answer, num);
				}
			}
		}
	}
	
	cout<<answer<<endl;
	return 0;
}