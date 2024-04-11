#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int> > dp(n+1, vector<int>(4, -1)); // .., .*, *., **
	dp[0][0] = 0;
	for (int i=0;i<n;++i){
		if (dp[i][0] != -1) {
			if (s1[i] == '.' && s2[i] == '.') {
				dp[i+1][0] = 0;
			}
			else {
				if (s1[i] == '*' && s2[i] == '.') {
					dp[i+1][1] = 1;
					dp[i+1][2] = 0;
				} else {
					if (s1[i] == '*' && s2[i] == '*') {
						dp[i+1][1] = 1;
						dp[i+1][2] = 1;
						dp[i+1][3] = 0;
					} else {
						dp[i+1][1] = 0;
						dp[i+1][2] = 1;
					}
				}
			}
			continue;
		}
		dp[i+1][1] = 4 * n;
		dp[i+1][2] = 4 * n;
		dp[i+1][3] = 4 * n;
		if (dp[i][3] != -1) {
			if (s1[i] == '.' && s2[i] == '.') {
				dp[i+1][1] = 2 + dp[i][3];
				dp[i+1][2] = 2 + dp[i][3];
				dp[i+1][3] = 2 + dp[i][3];
			}
			else {
				if (s1[i] == '*' && s2[i] == '.') {
					dp[i+1][1] = 3 + dp[i][3];
					dp[i+1][2] = 2 + dp[i][3];
					dp[i+1][3] = 2 + dp[i][3];
				} else {
					if (s1[i] == '*' && s2[i] == '*') {
						dp[i+1][1] = 3 + dp[i][3];
						dp[i+1][2] = 3 + dp[i][3];
						dp[i+1][3] = 2 + dp[i][3];
					} else {
						dp[i+1][1] = 2 + dp[i][3];
						dp[i+1][2] = 3 + dp[i][3];
						dp[i+1][3] = 2 + dp[i][3];
					}
				}
			}
		}
		dp[i+1][1] = min(
			dp[i+1][1],
			dp[i][1] + 1 + (s1[i] == '*')
		);
		dp[i+1][1] = min(
			dp[i+1][1],
			dp[i][2] + 2
		);
		dp[i+1][2] = min(
			dp[i+1][2],
			dp[i][2] + 1 + (s2[i] == '*')
		);
		dp[i+1][2] = min(
			dp[i+1][2],
			dp[i][1] + 2
		);
		if (s2[i] == '*') {
			dp[i+1][3] = min(
				dp[i+1][3],
				dp[i][2] + 1
			);
		}
		if (s1[i] == '*') {
			dp[i+1][3] = min(
				dp[i+1][3],
				dp[i][1] + 1
			);
		}
	}
	int x = n;
	while (s2[x-1] == '.' && s1[x-1] == '.') x--;
	cout << min(dp[x][1], dp[x][2]) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}