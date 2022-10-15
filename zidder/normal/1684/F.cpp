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
	map<int, vector<int> > inds;
	vector<int> a(n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
		inds[a[i]].push_back(i);
	}
	
	vector<int> rs(n);
	for (int i=0;i<n;++i) rs[i] = i + 1;
	for (int i=0;i<m;++i){
		int li, ri;
		scanf("%d%d", &li, &ri);
		li--;
		rs[li] = max(rs[li], ri);
	}
	for (int i=1;i<n;++i) {
		rs[i] = max(rs[i-1], rs[i]);
	}

	vector<pair<int, int> > lr;
	for (int i=0;i<n;++i){
		if (a[i] == 0) continue;
		int ai = a[i];
		for (int j: inds[ai]) a[j] = 0;
		for (int j=1;j<inds[ai].size();++j) {
			int pj = inds[ai][j-1];
			int cj = inds[ai][j];
			if (rs[pj] > cj) {
				lr.emplace_back(pj, cj+1);
			}
		}
		for (int prvv=0, j=0;prvv<inds[ai].size();++prvv){
			while (j+1 < inds[ai].size() && inds[ai][j+1] < rs[inds[ai][prvv]]) j++;
			if (prvv != j) lr.emplace_back(inds[ai][prvv], inds[ai][j] + 1);
		}
	}

	// for (auto &p: lr) {
	// 	cout << p.first << " lr " << p.second << endl;
	// }

	if (lr.empty()) {
		cout << 0 << endl;
		return;
	}


	for (int i=0;i<n;++i) rs[i] = i+1;
	for (auto &p: lr) rs[p.first] = max(rs[p.first], p.second);

	int ans = n;
	multiset<int> R;
	int r = 0;
	for (auto &p: lr) r = max(r, p.first + 1);
	int lmax = n;
	for (auto &p: lr) lmax = min(lmax, p.second - 1);
	for (int l=0;l<=lmax;++l){
		// cout << l << " " << r << endl;
		ans = min(ans, r - l);
		r = max(r, rs[l]);
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