#include "bits/stdc++.h"
using namespace std;


int main() {
	int N; cin >> N;
	vector<vector<int>>anss(N);
	set<int>v;
	int k(N);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		v.emplace(a);
		while (!v.empty() && *prev(v.end()) == k) {
			anss[i].push_back(k);
			k--;
			v.erase(prev(v.end()));
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < anss[i].size(); ++j) {
			cout << anss[i][j];
			if (j != anss[i].size() - 1)cout << " ";
		}
		cout << endl;
	}
	return 0;
}