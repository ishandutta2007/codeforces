#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MOD = 51123987;
void addIt(int&x, int c) {
	x += c;
	if (x >= MOD)
		x -= MOD;
}

int dp[155][55][55][55];
int next[155][3];
int n;
string input;

int main() {
	cin >> n >> input;
	fill(next[n], next[n] + 3, n);
	for (int i = n - 1; i >= 0; --i) {
		memcpy(next[i], next[i + 1], sizeof next[i]);
		next[i][input[i] - 'a'] = i;
	}
	dp[0][0][0][0] = 1;
	int up = n / 3 + 2;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < up; ++a) {
			for (int b = 0; b < up; ++b) {
				for (int c = 0; c < up; ++c) {
					if (int by = dp[i][a][b][c]) {
						if (a + b + c == n && abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1)
							addIt(ans, by);
						addIt(dp[next[i][0]][a + 1][b][c], by);
						addIt(dp[next[i][1]][a][b + 1][c], by);
						addIt(dp[next[i][2]][a][b][c + 1], by);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}