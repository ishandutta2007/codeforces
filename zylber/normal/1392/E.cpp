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
using namespace std;
typedef long long tint;
typedef pair<tint, tint> pii;
typedef vector<tint> vi;
typedef vector<vi> vvi;

int main()
{
	int n;
	cin >> n;
	vvi a(n, vi(n, 0));
	vvi g(n, vi(n, 0));
	vvi l(n, vi(n, 0));
	forn(i, n) {
		if(i) dforn(j, n-1) {
			tint s = 1;
			forn(k, i-1) s += a[k][0];
			//cout << s << endl;
			forn(k, j+2) s += a[i-1][k];
			//cout << s << endl;
			for(int k = j+1; k < n; k++) s+= a[i][k];
			//cout << s << endl;
			forn(k, i) s -= a[k][j];
			//cout << s << endl;
			for(int k = j+1; k < n; k++) s-= a[i][k];
			//cout << s << endl;
			a[i][j] = s;
		}
	}
	
	forn(i, n) {
		forn(j, n) {
			if(j) cout << " ";
			cout << a[i][j];
			
		}
		cout << endl;
		cout.flush();
	}
	
	int q;
	cin >> q;
	forn(qq, q) {
		tint ql;
		cin >> ql;
		tint x = n-1, y = n-1, s = 0;
		vector<pii> ans;
		while(x != 0|| y != 0) {
			ans.push_back({x+1, y+1});
			cout.flush();
			s += a[x][y];
			if(y != 0 && x != 0) {
				tint mins = 0;
				forn(i, x+1) {
					mins += a[i][y-1];
				}
				if(mins + s <= ql) {
					y--;
				} else {
					x--;
				}
			} else {
				if(x!= 0) {
					x--;
				} else {
					y--;
				}
			}
		}
		ans.push_back({1,1});
		reverse(ans.begin(), ans.end());
		forn(i, ans.size()) {
			cout << ans[i].first << " " << ans[i].second << endl;
			cout.flush();
		}
	}
}