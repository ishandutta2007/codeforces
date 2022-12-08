#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> item;
	forn(i, n) {
		int t, d, p;
		cin >> t >> d >> p;
		item.push_back(make_tuple(d,t,p,i+1));
	}
	sort(item.begin(), item.end());
	
	vector<vector<int> > dp(n+1, vector<int>(2001, -1000000000));
	dp[0][0] = 0;
	forn(i, n) {
		int t = get<1>(item[i]), p = get<2>(item[i]), d = get<0>(item[i]);
		dforn(j, d) {
			dp[i+1][j] = dp[i][j];
			if(j >= t && dp[i][j-t]+p > dp[i+1][j]) {
				dp[i+1][j] = dp[i][j-t]+p;
			}
		}
	}
	
	int bestt = 0;
	forn(i, 2000) if(dp[n][i] > dp[n][bestt]) bestt = i;
	vector<int> ans;
	cout << dp[n][bestt] << endl;
	dforn(i, n) {
		int t = get<1>(item[i]), p = get<2>(item[i]), d = get<0>(item[i]);
		if(bestt < d && bestt >= t && dp[i][bestt-t]+p == dp[i+1][bestt]) {
			ans.push_back(get<3>(item[i]));
			bestt -= t;
		}
	}
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	forn(i, ans.size()) {
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	
	return 0;
}