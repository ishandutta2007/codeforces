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
	if (s[0][0] == '1'){
		cout << -1 << endl;
		return;
	}
	vector<pair<pair<int, int>, pair<int, int> > > ans;
	for (int i=0;i<n;++i) {
		if (s[i][0] == '1'){
			ans.emplace_back(make_pair(make_pair(i-1, 0), make_pair(i, 0)));
		}
		for (int j=0;j<m-1;++j){
			if (s[i][j+1] == '1'){
				ans.emplace_back(make_pair(make_pair(i, j), make_pair(i, j+1)));
			}
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto &p: ans) {
		cout << 1 + p.first.first << " " << 1 + p.first.second << " " << 1 + p.second.first << " " << 1 + p.second.second << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}