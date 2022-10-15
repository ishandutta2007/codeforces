// https://codeforces.com/blog/entry/55288

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
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);

	vector<vector<int> > inds(n+2);

	for (int i=0;i<n;++i){
		inds[a[i]].push_back(i);
	}
	if (inds[1].size() == n){
		cout << 1 << endl;
		return;
	}
	if (inds[1].empty()){
		cout << 2 << endl;
		return;
	}

	set<pair<int, int> > intervals;
	for (int i: inds[1]) intervals.insert(make_pair(i, i));
	for (int i=2;i<=n+1;++i){
		// cout << i << endl;
		// for (auto &p: intervals){
		// 	cout << p.first << " " << p.second << endl;
		// }
		// cout << endl;
		if (inds[i].empty()) {
			cout << i + 1 << endl;
			return;
		}
		set<pair<int, int> > new_intervals, rintervals;
		for (auto &p: intervals){
			rintervals.emplace(p.second, p.first);
			auto it = lower_bound(inds[i].begin(), inds[i].end(), p.first);
			if (it == inds[i].end()) continue;
			int j = *it;
			if (p.first < j && p.second > j){
				new_intervals.insert(p);
			}
		}
		if (intervals.size() == new_intervals.size()){
			cout << i << endl;
			return;
		}
		for (int j: inds[i]){
			auto it = intervals.upper_bound(make_pair(j, 0));
			if (it != intervals.end()){
				if (new_intervals.find(*it) == new_intervals.end()){
					auto iti = lower_bound(inds[i].begin(), inds[i].end(), it->first);
					--iti;
					new_intervals.emplace(*iti, it->second);
				}
			}
			it = rintervals.upper_bound(make_pair(j, 0));
			if (it == rintervals.begin()) continue;
			it--;
			if (new_intervals.find(make_pair(it->second, it->first)) == new_intervals.end()){
				auto iti = lower_bound(inds[i].begin(), inds[i].end(), it->first);
				new_intervals.emplace(it->second, *iti);
			}
		}
		swap(intervals, new_intervals);
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}