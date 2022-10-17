// https://codeforces.com/problemset/problem/1582/E

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
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    vector<long long> p(n+1);
    for (int i=0;i<n;++i) p[i+1] = p[i] + a[i];
    vector<vector<int> > dp(n+1, vector<int>(500, -1));
    dp[n][0] = 1000000001;
    for (int i=n;i>0;--i){
        for (int j=0;j<500;++j){
            if (i <= j) break;
            if (p[i] - p[i-j-1] < dp[i][j]) dp[i-j-1][j+1] = max(dp[i-j-1][j+1]+0ll, p[i] - p[i-j-1]);
        }
        for (int j=0;j<500;++j){
            dp[i-1][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    for (int j=500-1;j>=0;--j){
        if (dp[0][j] == -1) continue;
        cout << j << endl;
        return;
    }
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}