#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	map<pair<int, int>, set<pair<int, int> > > mp;
	for (int i=0;i<=20;++i) {
		for (int j=0;j<360;++j) {
			mp[{i, j}].emplace(i+1, j);
			mp[{i+1, j}].emplace(i, j);
			mp[{i, j}].emplace(i, (j+359)%360);
			mp[{i, j}].emplace(i, (j+1)%360);
		}
	}
	for (int i=0;i<n;++i) {
		char c;
		cin >> c;
		if (c == 'C') {
			int r, t1, t2;
			cin >> r >> t1 >> t2;
			while (t1 != t2) {
				mp[{r-1, t1}].erase({r, t1});
				mp[{r, t1}].erase({r-1, t1});
				t1 = (t1 + 1) % 360;
			}
		} else {
			int r1, r2, t;
			cin >> r1 >> r2 >> t;
			int t1 = (t + 359) % 360;
			while (r1 < r2) {
				mp[{r1, t}].erase({r1, t1});
				mp[{r1, t1}].erase({r1, t});
				r1++;
			}
		}
	}

	vector<vector<bool> > reachable(22, vector<bool>(360, false));
	vector<pair<int, int> > q;
	for (int i=0;i<360;++i) {
		reachable[0][i] = true;
		q.push_back({0, i});
	}
	for (int i=0;i<q.size();++i) {
		if (q[i].first >= 20) {
			cout << "YES" << endl;
			return;
		}
		for (auto &p: mp[q[i]]) {
			if (reachable[p.first][p.second]) continue;
			reachable[p.first][p.second] = true;
			q.push_back(p);
		}
	}
	cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}