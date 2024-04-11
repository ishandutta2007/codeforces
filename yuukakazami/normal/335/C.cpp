#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

const int MAX_N = 100 + 10;
bool used[MAX_N][2];
int n, cnt;

int hashCode(int row) {
	return (used[row][0] << 1) + used[row][1];
}

int dp[MAX_N][MAX_N][256];

int sg(int row1, int row2) {
	//can we move?
	int hash1 = hashCode(row1) * 4 + hashCode(row1 + 1);
	int hash2 = hashCode(row2 - 1) * 4 + hashCode(row2);
	int hash = hash1 * 16 + hash2;
	int&ret = dp[row1][row2][hash];
	if (ret != -1)
		return ret;

	bool have[210] = { };

	for (int r = row1; r <= row2; ++r) {
		for (int c = 0; c < 2; ++c) {
			if (used[r][c])
				continue;
			if (r > row1 && used[r - 1][1 - c])
				continue;
			if (used[r][1 - c])
				continue;
			if (r < row2 && used[r + 1][1 - c])
				continue;
			//we can put at there
			used[r][c] = true;
			have[sg(row1, r) ^ sg(r, row2)] = true;
			used[r][c] = false;
		}
	}

	for (int i = 0; i < 210; ++i) {
		if (!have[i])
			return ret = i;
	}

	return -1;
}

int main() {
	cin >> n >> cnt;
	for (int i = 0; i < cnt; ++i) {
		int r, c;
		scanf("%d%d", &r, &c), --r, --c;
		used[r][c] = true;
	}
	memset(dp, -1, sizeof dp);
	cout << (sg(0, n - 1) ? "WIN" : "LOSE") << endl;
}