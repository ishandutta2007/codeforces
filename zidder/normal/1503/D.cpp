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
	vector<pair<int, int> > ab(n);
	for (int i=0;i<n;++i) scanf("%d%d", &ab[i].first, &ab[i].second);

	map<int, int> inds;
	for (int i=0;i<n;++i) inds[ab[i].first] = i;
	for (int i=0;i<n;++i) inds[ab[i].second] = i;

	auto flip = [&](int ind) {
		int c = ab[ind].first;
		ab[ind].first = ab[ind].second;
		ab[ind].second = c;
	};
	
	auto remove = [&](int ind) {
		inds.erase(ab[ind].first);
		inds.erase(ab[ind].second);
	};

	int c = 0;
	while (!inds.empty()) {
		int ind = inds.begin()->second;
		int c1 = 0, c2 = 1;
		if (ab[ind].first > ab[ind].second) {flip(ind);c1++;}
		remove(ind);
		int c20 = 0, mx = ab[ind].second, mn = ab[ind].first;
		while (c2 != c20) {
			c20 = c2;
			while (!inds.empty() && inds.rbegin()->first > mx) {
				int ind2 = inds.rbegin()->second;
				c2++;
				if (ab[ind2].first < ab[ind2].second) {flip(ind2);c1++;}
				mn = max(mn, ab[ind2].second);
				remove(ind2);
			}
			while (!inds.empty() && inds.begin()->first < mn) {
				int ind2 = inds.begin()->second;
				c2++;
				if (ab[ind2].first > ab[ind2].second) {flip(ind2);c1++;}
				mx = min(mx, ab[ind2].second);
				remove(ind2);
			}
			// cout << c20 << " " << c2 << endl;
		}
		c += min(c1, c2-c1);
		// cout << ab[ind].first << " " << c1 << " " << c2 << endl;
	}

	sort(ab.begin(), ab.end());
	for (int i=1;i<n;++i) {
		if (ab[i].second > ab[i-1].second) {
			cout << -1 << endl;
			return;
		}
	}

	cout << c << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}