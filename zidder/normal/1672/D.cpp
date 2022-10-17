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
	vector<int> a(n), b(n);
	vector<pair<int, int> > ai, bi;
	map<int, set<int> > ainds;
	for (int i=0;i<n;++i) {
		scanf("%d", &a[i]);
		ai.emplace_back(a[i], 1);
		ainds[a[i]].insert(i);
	}
	for (int i=0;i<n;++i) {
		scanf("%d", &b[i]);
		bi.emplace_back(b[i], 1);
	}
	for (int aind=0, bind=0;bind<n;) {
		auto &ap = ai[aind], bp=bi[bind];
		// cout << ap.first << " " << ap.second << endl;
		// cout << bp.first << " " << bp.second << endl;
		ainds[ap.first].erase(aind);
		if (ap.first == bp.first) {
			ap.second--;
			if (ap.second == 0) aind++;
			bind++;
			continue;
		}
		if (ainds[ap.first].empty()) {
			cout << "NO" << endl;
			return;
		}
		aind++;
		ai[*ainds[ap.first].begin()].second += ap.second;
	}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}