#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int m;
    cin >> m;
    vector<vector<int> > a(2, vector<int>(m));
    for (int i=0;i<2;++i) for (int &j: a[i]) scanf("%d", &j);
    for (int i=0;i<2;++i) for (int j=0;j<m;++j) ++a[i][j];
    a[0][0] = 0;
    vector<vector<long long> > dp(m, vector<long long>(2));
    vector<vector<long long> > dp1(m, vector<long long>(2));
    
    for (int i=m-1;i>=0;--i) {
        if (i + 1 == m) {
            dp[i][1] = max(a[0][i], a[1][i] + 1);
            dp[i][0] = max(a[1][i], a[0][i] + 1);
            dp1[i][1] = max(a[0][i], a[1][i] + 1);
            dp1[i][0] = max(a[1][i], a[0][i] + 1);
        } else {
            // bottom to top
            dp1[i][1] = max(max(dp1[i+1][1] + 1, a[0][i] + 0ll), a[1][i] + (m-i)*2ll-1);
            dp[i][1] = min(max(max(a[1][i] + (m-i) * 2ll-1, a[0][i] + (m-i) * 2ll - 2), dp[i+1][0]), dp1[i][1]);
            // top to bottom
            dp1[i][0] = max(max(dp1[i+1][0] + 1, a[1][i] + 0ll), a[0][i] + (m-i)*2ll-1);
            dp[i][0] = min(max(max(a[0][i] + (m-i) * 2ll-1, a[1][i] + (m-i) * 2ll - 2), dp[i+1][1]), dp1[i][0]);
        }
        // cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
        // cout << i << " " << dp1[i][0] << " " << dp1[i][1] << endl;
    }

    cout << dp[0][0] << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}