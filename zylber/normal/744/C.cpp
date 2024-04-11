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
typedef tint tipo;
using namespace std;

int main()
{
#ifdef ACMTUYO
	freopen("C.in","r",stdin);
#endif
	int n;
	cin >> n;
	vector<char> color(n);
	vector<int> red(n);
	vector<int> blue(n);
	forn(i, n) {
		cin >> color[i] >> red[i] >> blue[i];
	
	}
	
	
	int maxg = 128;
	vector<vector<int> > dp((1<<n), vector<int>(maxg, -1));
	dp[0][0] = 0;
	forn(mask, (1<<n)) {
		int R = 0, B = 0;
		forn(j, n) {
			if(mask&(1<<j)){
				if(color[j] == 'R') R++;
				else B++;
			}
		}
		
		forn(i, maxg) {
			if(dp[mask][i] > -1) {
				//cout << mask << " " << i << " " << dp[mask][i] << endl;
				forn(j, n) {
					if(!(mask&(1<<j))){
						int gR = max(0, R-red[j]);
						int gB = max(0, B-blue[j]);
						dp[mask|(1<<j)][i+R-gR] = max(dp[mask|(1<<j)][i+R-gR], dp[mask][i]+B-gB);
					}
				}
			}
		}
		
	}
	
	int totR = 0, totB = 0;
	forn(i, n) {
		totR += red[i];
		totB += blue[i];
	}
	
	int ans = 1000000000;
	forn(i, maxg) {
		if(dp[(1<<n)-1][i] > -1) {
			int cR = totR - i, cB = totB - dp[(1<<n)-1][i];
			ans = min(ans, max(cR, cB));
		}
	}
	cout << ans+n << endl;
	return 0;
}