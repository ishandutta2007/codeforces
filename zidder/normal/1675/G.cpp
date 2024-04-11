#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(m+1, vector<int>(2*m+1, 10000000)));
	// [i][v][m + x] means in >=i, x moved from left, v as value, then needs [i][v][m+x] steps
	dp[n][0][m] = 0;


	// v[i] = a[i] + m[i] - m[i+1]
	// m[i+1] = v[i] - a[i] - m[i]
	// [i][v][m] = abs(m) + min{v1 <= v} [i+1][v1][v-a[i]-m[i]]
	// [i][v][m] -> [i-1][v0][v0-a[i]-m]
	for (int i=n-1;i>=0;--i){
		for (int j=-m;j<=m;++j) {
			for (int v=1;v<=m;++v){
				dp[i+1][v][j+m] = min(dp[i+1][v][j+m], dp[i+1][v-1][j+m]);
			}
		}
		for (int v=0;v<=m;++v){
			for (int j=-m;j<=m;++j){
				if (j-v+a[i] < -m || j-v+a[i] > m) continue;
				dp[i][v][j+m] = abs(j) + dp[i+1][v][m+j-v+a[i]];
			}
		}
	}

	int ans = 100000000;
	for (int v=0;v<=m;++v){
		ans = min(ans, dp[0][v][m]);
	}
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