#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

int main() {
	string st; cin >> st;
	string ast = "AIUEOY";
	vector<int>oks;
	oks.push_back(-1);
	for (int i = 0; i < st.size(); ++i) {
		if (ast.find(st[i])!=string::npos) {
			oks.push_back(i);
		}
	}
	oks.push_back(st.size());
	int ans = 1;
	for (int i = 0; i < oks.size() - 1; ++i) {
		ans = max(ans, oks[i + 1] -oks[i]);
	}
	cout << ans << endl;
	return 0;
}