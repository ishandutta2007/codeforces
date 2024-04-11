#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i=0;i<n;++i) cin >> s[i];
	for (int i=0;i<n;++i) {
		int prev = -1, c = 0;
		for (int j=0;j<m;++j) {
			if (s[i][j] == 'W') continue;
			c++;
			if (c > 2) {
				s[i][prev] = 'W';
			}
			prev = j;
		}
	}
	vector<pair<int, int> > blacks;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (s[i][j] == 'B') blacks.emplace_back(i, j);
	// 2000 B
	// log(2000)(k) * 1000(x) * 2000(B)

	// max |a-x| + (b-y, y-b)
	int mx = 100000;
	pair<int, int> ans;
	for (int i=0;i<n;++i) {
		int m1 = -10000, m2 = -100000;
		for (auto &p: blacks) m1 = max(m1, abs(p.first - i) + p.second); // b - y
		for (auto &p: blacks) m2 = max(m2, abs(p.first - i) - p.second); // b + y
		int j = (m1 - m2) / 2;
		int mx2 = max((m1 - j), (m2 + j));
		if (mx2 < mx) {
			mx = mx2;
			ans = {i, j};
		}
	}
	// cout << mx << endl;
	cout << ans.first + 1 << " " << ans.second + 1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}