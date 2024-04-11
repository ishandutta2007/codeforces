#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

const int MN = 155;
int n, k;
int s;
int a[MN];
int dp[MN][MN*MN];
int main() {
	for (int i = 0; i < MN; i++) {
		for (int j = 0; j < MN*MN; j++) {
			dp[i][j] = 1e9;
		}
	}
	cin >> n >> k >> s;
	s += (k-1) * k / 2;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	s = min(s, (n-1) * n / 2);
	for (int i = 0; i <= s; i++) {
		dp[0][i] = 0;
	}
	for (int i = n-1; i >= 0; i--) {
		// for (int j = 0; j <= k; j++) {
		// 	for (int l = 0; l < 10; l++) {
		// 		printf("%d ", dp[j][l]);
		// 	} printf("\n");
		// }
		// printf("\n");
		for (int j = k; j >= 1; j--) {
			for (int l = 0; l <= (i-1)*i / 2; l++) {
				dp[j][l] = min(dp[j-1][l+i] + a[i], dp[j][l]);
			}
		}
	}
		// for (int j = 0; j <= k; j++) {
		// 	for (int l = 0; l < 10; l++) {
		// 		printf("%d ", dp[j][l]);
		// 	} printf("\n");
		// }
		// printf("\n");
	printf("%d\n", dp[k][0]);
    return 0;
}