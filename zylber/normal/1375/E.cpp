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
typedef vector<pii> vp;
typedef vector<vp> vvp;

bool check(vp& a) {
	forn(i, a.size()-1) {
		if(a[i].first > a[i+1].first) return false;
	}
	return true;
}

int main()
{
		int n;
		cin >> n;
		vp a(n);
		vp ans;
		forn(i, n) {
			cin >> a[i].first;
			a[i].second = i;
		}
		
		vvi invs(n);
		dforn(i, n) {
			forn(j, i) {
				if(a[j] > a[i]) {
					invs[i].push_back(j);
				}
			}
		}
		
		dforn(i, n) {
			vvi cinvs;
			forn(j, invs[i].size()) {
				int pos = invs[i][j];
				cinvs.push_back({a[pos].first, a[pos].second, pos});
			}
			
			sort(cinvs.begin(), cinvs.end());
			forn(j, cinvs.size()) {
				int pos = cinvs[j][2];
				ans.push_back({pos+1, i+1});
				swap(a[pos], a[i]);
			}
		}
		
		if(check(a)) {
			cout << ans.size() << endl;
			forn(i, ans.size()) {
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		} else {
			cout << -1 << endl;
		}
}