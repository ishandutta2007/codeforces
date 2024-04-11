#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	for (int &i: a) --i;

	vector<int> dp1(200), dp2(200);
	if (a[0] < 0) dp1 = vector<int>(200, 1);
	else dp1[a[0]] = 1;

	for (int i=1;i<n;++i) {
		vector<int> dpp1(200), dpp2(200);
		if (a[i] < 0) {
			int c = 0;
			for (int j=0;j<200;++j) {
				(dpp1[j] += c) %= MOD;
				(c += dp1[j]) %= MOD;
				(c += dp2[j]) %= MOD;
			}
			c = 0;
			for (int j=199;j>=0;--j){
				(c += dp2[j]) %= MOD;
				(dpp2[j] += c) %= MOD;
				(dpp2[j] += dp1[j]) %= MOD;
			}
		} else {
			for (int j=a[i];j<200;++j) {
				(dpp2[a[i]] += dp2[j]) %= MOD;
			}
			(dpp2[a[i]] += dp1[a[i]]) %= MOD;
			for (int j=0;j<a[i];++j) {
				(dpp1[a[i]] += dp1[j]) %= MOD;
				(dpp1[a[i]] += dp2[j]) %= MOD;
			}
		}
		dp1 = dpp1;
		dp2 = dpp2;
	}

	int ans = 0;
	if (a.back() < 0) {
		for (int i=0;i<200;++i) (ans += dp2[i]) %= MOD;
	} else ans = dp2[a.back()];
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}