#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
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
	int m, n;
	cin >> m >> n;
	vector<string> nums(n);
	forn(i, n) cin >> nums[i];
	
	vector<tint> c(m,1);
	
	forn(i, m) {
		forn(j, i) {
			int match = 1;
			forn(k, n) {
				if(nums[k][i] != nums[k][j]) {
					match = 0;
					break;
				}
			}
			if(match) {
				c[i] = 0;
				c[j]++;
				break;
			}
		}
	}
	
	vector<vector<tint> > choose(m+1, vector<tint>(m+1, 0));
	forn(i, m+1) {
		choose[i][0] = 1;
		choose[i][i] = 1;
		forn(j, m+1) {
			if(i && j) choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%MOD;
		}
	}
	
	vector<tint> dp(m+1);
	dp[0] = 1;
	forn(i, m+1) {
		if(i) {
			forn(j, i) {
				dp[i] += (choose[i-1][j]*dp[i-1-j])%MOD;
				dp[i] %= MOD;
			}
		}
	}
	
	tint ans = 1;
	forn(i, m) {
		if(c[i]) ans = (ans * dp[c[i]])%MOD;
	}
	cout << ans << endl;
	
	return 0;
}