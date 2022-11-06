#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


int main() {
	string st; cin >> st;
	vector<int>ns(26);
	vector<int>maxs(26, 0);
	for (int i = 0; i < st.size(); ++i) {
		char ch(st[i]);
		{
			for (int j = 0; j < 26; ++j) {
				if ('a' + j == ch) {
					maxs[j] = max(maxs[j], ns[j] + 1);
					ns[j] = 0;
				}
				else {
					ns[j]++;
				}
			}
		}
	}
	for (int j = 0; j < 26; ++j) {
		maxs[j] = max(maxs[j], ns[j] + 1);
		
	}
	int ans = *min_element(maxs.begin(), maxs.end());
	cout << ans << endl;
	return 0;
}