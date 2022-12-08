#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	int T;
	cin >> T;
	forn(tc, T) {
		tint n, l, r;
		cin >> n >> l >> r;
		map<tint, tint> lc, rc;
		forn(i, l) {
			tint c;
			cin >> c;
			lc[c]++;
		}
		forn(i, r) {
			tint c;
			cin >> c;
			rc[c]++;
		}
		
		if(l < r) {
			swap(l, r);
			swap(rc, lc);
		}
		tint ans = 0;
		for(auto p: lc) {
			tint c = p.first, cl = p.second, cr = rc[c];
			tint pairs = min(cl, cr);
			r -= pairs;
			l -= pairs;
			cl -= pairs;
			while(cl >= 2 && l > r) {
				cl -= 2;
				ans++;
				l -= 2;
			}
		}
		while(r < l) {
			r++;
			l--;
			ans++;
		}
		ans += r;
		cout << ans << endl;
	}
}