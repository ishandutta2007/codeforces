#include "bits/stdc++.h"
using namespace std;

int main() {
	string st; cin >> st;
	vector<int>b_sums(st.size() + 1);
	for (int i = 0; i < st.size(); ++i) {
		b_sums[i + 1] = b_sums[i]+st[i] - 'a';
	}
	int ans = 0;
	for (int l = 0; l <= st.size(); ++l) {
		for (int r = l; r <= st.size(); ++r) {
			int num = 0;
			num += b_sums[l] - b_sums[0];
			num += (r - l) - (b_sums[r] - b_sums[l]);
			num += b_sums[st.size()] - b_sums[r];
			ans = max(ans, int(st.size())-num);
		}
	}
	cout << ans << endl;

	return 0;
}