#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

int a[7] = { 1,2,3,4,6,12 };

int main() {
	int h, w; cin >> h >> w;
	bool ok=true;
	vector<int>dwas, cans;
	for (int i = 0; i < h; ++i) {
		string st; cin >> st;
		int dwa = -1; int can;
		for (int j = 0; j < st.size(); ++j) {
			if (st[j] == 'S') {
				if (dwa == -1)ok = false;
				can = j;
				continue;
			}
			else if (st[j] == 'G') {
				dwa = j;
			}
		}
		dwas.push_back(dwa);
		cans.push_back(can);

	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	else {
		vector<int>sa;
		for (int i = 0; i < h; ++i) {
			sa.push_back(cans[i] - dwas[i]);
		}
		sort(sa.begin(), sa.end());
		int ans = unique(sa.begin(), sa.end()) - sa.begin();
		cout << ans << endl;
	}
	return 0;
}