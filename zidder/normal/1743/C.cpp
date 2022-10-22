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
    string s;
    cin >> s;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);

    vector<pair<int, int> > dp(n, {-1, -1});
    // (uncovered, covered)
    for (int i=0;i<n;++i) {
        if (s[i] == '0') {
            if (i)
                dp[i].first = max(dp[i-1].first, dp[i-1].second);
            else
                dp[i].first = 0;
        } else {
            if (i) dp[i].second = max(dp[i-1].first, dp[i-1].second) + a[i];
            else dp[i].second = a[i];
            if (i) dp[i].first = dp[i-1].first + a[i-1];
        }
    }
    cout << max(dp[n-1].first, dp[n-1].second) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}