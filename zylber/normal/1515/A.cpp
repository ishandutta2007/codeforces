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
		tint n, x;
		cin >> n >> x;
		vi w(n);
		forn(i, n) cin >> w[i];
		tint sum = 0;
		int valid = 1;
		forn(i, n) {
			sum += w[i];
			if(sum == x) {
				if(i == n-1) {
					valid = 0;
					cout << "NO" << endl;
				} else {
					sum -= w[i];
					sum += w[i+1];
					swap(w[i], w[i+1]);
				}
			}
		}
		if(valid) {
			cout << "YES" << endl;
			forn(i, n) {
				if(i) cout << " ";
				cout << w[i];
			}
			cout << endl;
		}
	}
}