#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> ls(l);
	for (int &i: ls) scanf("%d", &i);
	vector<int> rs(r);
	for (int &i: rs) scanf("%d", &i);
	if (l > r) {
		swap(l, r);
		swap(ls, rs);
	}

	int c = (r - l) / 2;
	map<int, int> rc, lc;
	for (int i: rs) rc[i]++;
	for (int i: ls) lc[i]++;
	int ans = 0;
	for (auto &p: rc) {
		p.second -= min(p.second, lc[p.first]);
	}
	for (auto &p: rc) {
		while (c && p.second > 1) {
			p.second -= 2;
			c--;
			ans++;
		}
	}

	for (auto &p: rc) {
		ans += p.second;
	}

	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}