#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int de = 500;
int dp[55][2*de+1][2*de+1];

void solve(int test_ind){
	for (int i=0;i<=52;++i) for (int j=0;j<=2*de;++j) for (int k=0;k<=2*de;++k) dp[i][j][k] = 52*52*1000;
	string s;
	cin >> s;
	s = "00" + s;
	vector<int> d(s.size());
	d[0] = s[0] - '0';
	for (int i=1;i<s.size();++i) d[i] = s[i] - s[i-1];
	for (int i=s.size()-2;i>=0;--i) {
		for (int j=-de;j<=de;++j){
			for (int k=-de;k<=de;++k){
				// j += 10
				// j += 11 and k -= 10
				if (i+2 < s.size()) {
					if ((k-d[i+1])%10) continue;
					int j3 = d[i] - 11 * ((k-d[i+1])/10);
					if ((j3-j)%10) continue;
				}
				int j1 = j + de;
				int k1 = k + de;
				if (i + 1 == s.size()) dp[i][j1][k1] = abs(j);
				else
				for (int delta=(-de-k)/11-1;delta<=(de-k)/11+1;++delta) {
					if (i + 2 == s.size()) {
						if (11 * delta + k <= de && 11 * delta + k >= -de) {
							dp[i][j1][k1] = min(dp[i][j1][k1], abs(k + 11 * delta) + abs(j - delta) * (int)(s.size() - i));
						}
					}
					else {
						if (d[i+2] - 10 * delta < -de) break;
						if (11 * delta + k <= de && 11 * delta + k >= -de && d[i+2] - 10 * delta <= de) {
							int j2 = 11 * delta + de + k;
							int k2 = de + d[i+2] - 10 * delta;
							dp[i][j1][k1] = min(dp[i][j1][k1], dp[i+1][j2][k2] + abs(j - delta) * (int)(s.size() - i));
						}
					}
				}
			}
		}
	}

	cout << dp[0][de][de] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}