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
		tint n, m, x;
		cin >> n >> m >> x;
		vi y(n);
		forn(i, n) {
			cin >> y[i];
		}
		
		set<pair<tint, tint>> sums;
		forn(i, m) sums.insert({0, i+1});
		vi ans(n);
		forn(i, n) {
			pair<tint, tint> k = *sums.begin();
			sums.erase(k);
			k.first += y[i];
			ans[i] = k.second;
			sums.insert(k);
		}
		cout << "YES" << endl;
		forn(i, n) {
			if(i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}