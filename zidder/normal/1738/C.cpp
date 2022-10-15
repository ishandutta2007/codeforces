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
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    for (int &i: a) i = (i%2+2)%2;
    int c1 = 0, c0 = 0;
    for (int i: a) if (i) c1++; else c0++;

    vector<vector<vector<bool> > > dp(c0+1, vector<vector<bool> > (c1+1, vector<bool>(2, false)));
    dp[0][0] = {true, false};
    for (int i=0;i<=c0;++i) {
        for (int j=0;j<=c1;++j) {
            if (i) {
                dp[i][j][0] = max(dp[i][j][0]+0, (int)!dp[i-1][j][1-j%2]);
                dp[i][j][1] = max(dp[i][j][1]+0, (int)!dp[i-1][j][j%2]);
            }
            if (j) {
                dp[i][j][0] = max(dp[i][j][0]+0, (int)!dp[i][j-1][1-j%2]);
                dp[i][j][1] = max(dp[i][j][1]+0, (int)!dp[i][j-1][j%2]);
            }
            // cout << i << " " << j << " " << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
    }
    if (dp[c0][c1][0]) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    // (c1 - 2) + c0
    // c1/2-1 + c0/2
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}