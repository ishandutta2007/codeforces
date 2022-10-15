#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int d[1001];

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	// a = 1
	vector<int> a(n, 1);
	vector<int> b(n), c(n);
	for (int i=0;i<n;++i){
		cin >> b[i];
		b[i] = d[b[i]];
	}
	for (int i=0;i<n;++i){
		cin >> c[i];
	}
	k = min(12 * 1000 + 1, k);
	vector<int> dp(k + 1, -1);
	int ans = 0;
	dp[0] = 0;
	for (int i=0;i<n;++i){
		for (int j=k-b[i];j>=0;--j){
			if (dp[j] == -1) continue;
			dp[j+b[i]] = max(dp[j+b[i]], dp[j] + c[i]);
			ans = max(ans, dp[j+b[i]]);
		}
	}
	cout << ans << endl;
	// for b[i] get c[i]
}

int main(){
	for (int i=1;i<=1000;++i) d[i] = 10000;
	d[1] = 0;
	d[0] = 0;
	for (int i=1;i<=1000;++i){
		for (int j=1;j<=i;++j){
			int nk = i + i / j;
			if (nk > 1000) continue;
			d[nk] = min(d[nk], d[i] + 1);
		}
	}
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}