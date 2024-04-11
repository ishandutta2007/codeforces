#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int ans[40001];
int dp[40001][700];
const int MOD = 1000000007;

void solve(int test_ind){
	int n;
	cin >> n;
	cout << ans[n] << endl;;
}

int main(){
	vector<int> p;
	for (int i=1;i<=40000;++i){
		string s1 = to_string(i);
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		if (s1 == s2) p.push_back(i);
	}
	for (int i=0;i<p.size();++i) dp[0][i] = 1;
	for (int i=1;i<=40000;++i) dp[i][0] = 1;

	for (int j=1;j<p.size();++j) {
		for (int i=1;i<=40000;++i){
			dp[i][j] = dp[i][j-1];
			if (i >= p[j]) (dp[i][j] += dp[i-p[j]][j]) %= MOD;
		}
	}
	for (int i=1;i<=40000;++i) ans[i] = dp[i][p.size()-1];

	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}