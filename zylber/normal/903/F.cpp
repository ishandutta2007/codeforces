#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
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

int advanceMask(int i, vector<string>& a, int nm, int n) {
	nm >>= 4;
	forn(k, 4) {
		if(i+2 >= n || a[k][i+2] == '.') nm += (1<<(8+k));
	}
	return nm;
}

int main()
{
	int n;
	cin >> n;
	vector<tint> c(4);
	forn(i, 4) cin >> c[i];
	vector<string> a(4);
	forn(i, 4) cin >> a[i];
	
	vector<vector<vector<tint>>> dp(n+1, vector<vector<tint>>(4, vector<tint>(1<<12, 1000000000))); 
	dp[n][0][(1<<12)-1] = 0;
	
	dforn(i, n) dforn(j, 4) forn(m, (1<<12)) {
		int ni = i, nj = j+1, nm = m;
		if(nj == 4) {
			nj = 0;
			ni++;
			nm = advanceMask(ni, a, nm, n);
		}
		
		if(m&(1<<j)) {
			dp[i][j][m] = min(dp[i][j][m], dp[ni][nj][nm]);
		}
		
		for(int d = 1; d <= min(4-j, n-i); d++) {
			if(d==4) {
				dp[i][j][m] = min(dp[i][j][m], dp[i+1][0][(1<<12)-1]+c[d-1]);
			}
			else
			{
				int pm = m;
				for(int x = j; x < j+d; x++) {
					for(int y = 0; y < d; y++) {
						pm |= (1<<(x+4*y));
					}
				}
				if(ni > i) pm = advanceMask(ni, a, pm, n);
				dp[i][j][m] = min(dp[i][j][m], dp[ni][nj][pm]+c[d-1]);
			}
		}
	}
	
	int sm=0;
	forn(i, 4) forn(j, 3) {
		if(j > n || a[i][j] == '.') sm += (1<<(i+j*4));
	}
	cout << dp[0][0][sm] << endl;
}