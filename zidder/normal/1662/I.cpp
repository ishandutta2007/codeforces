#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int INF = 1000000001;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<int> p(n), x(m), l(n);
	for (int i=0;i<n;++i) l[i] = 100 * i;
	for (int i=0;i<n;++i) scanf("%d", &p[i]);
	for (int i=0;i<m;++i) scanf("%d", &x[i]);

	sort(x.begin(), x.end());

	set<pair<pair<int, int>, int> > d; // {{loc, diff}, ind}
	int prev = -INF;
	for (int i=0, j=0;i<n;++i) {
		int nxt = 2 * INF;
		while (j < m && l[i] > x[j]) {
			prev = x[j++];
		}
		if (j != m) nxt = x[j];
		int df = min(nxt - l[i], l[i] - prev);
		d.insert({{l[i] - df, 1}, i});
		d.insert({{l[i] + df, -1}, i});
	}

	long long sm = 0, ans = 0;
	for (auto &pp: d) {
		// cout << pp.first.first << " " << pp.first.second << " " << pp.second << endl;
		if (pp.first.second == -1) {
			sm -= p[pp.second];
		} else {
			sm += p[pp.second];
			ans = max(ans, sm);
		}
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