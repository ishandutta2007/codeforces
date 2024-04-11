
#include "bits/stdc++.h"
using namespace std;

int base;
int dp[30001][501];

int main() {
	memset(dp, -1, sizeof(dp));
	int n; cin >> n >>base;
	vector<int>gems(30001);
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		gems[a]++;
	}
	if (base < 300) {
		dp[base][base] = gems[base];
		for (int island = base; island < 30001; ++island) {
			for (int speed = 0; speed <= 500; ++speed) {
				if (dp[island][speed] != -1) {
					for (int ds = -1; ds <= 1; ++ds) {
						const int nspeed = speed + ds;
						if (nspeed) {
							const int nisland = island + nspeed;
							if (nisland <= 30000) {
								dp[nisland][nspeed] = max(dp[nisland][nspeed], dp[island][speed] + gems[nisland]);
							}
						}
					}
				}
			}
		}
	}
	else {
		dp[base][250] = gems[base];
		for (int island = base; island < 30001; ++island) {
			for (int speed = 0; speed <= 500; ++speed) {
				if (dp[island][speed] != -1) {
					for (int ds = -1; ds <= 1; ++ds) {
						const int nspeed = speed + ds;
						if (nspeed) {
							const int nisland = island + nspeed-250+base;
							if (nisland <= 30000) {
								dp[nisland][nspeed] = max(dp[nisland][nspeed], dp[island][speed] + gems[nisland]);
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 30001; ++i) {
		for (int j = 0; j < 500; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}