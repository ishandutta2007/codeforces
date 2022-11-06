#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;



int main() {
	int n, m; cin >> n >> m;
	vector<bool>oks(m, false);
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		for (int j = 0; j < t; ++j) {
			int a; cin >> a; a--;
			oks[a] = true;
		}
	}
	if (all_of(oks.begin(), oks.end(), [](const bool a) {return a; })) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}