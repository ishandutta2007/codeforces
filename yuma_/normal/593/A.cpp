#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;



int main() {
	int n; cin >> n;
	vector<string>ts;
	for (int i = 0; i < n; ++i) {
		string st; cin >> st;
		for (int j = 0; j < st.size(); ++j) {

		}
		ts.emplace_back(st);
	}
	int amax = 0;
	for (int i = 0; i < 26; ++i) {
		for (int j =i+1; j < 26; ++j) {
			int nans = 0;
			for (int k = 0; k < n; ++k) {
				bool ok = true;
				for (int l = 0; l < ts[k].size(); ++l) {
					if (ts[k][l] != 'a' + i && ts[k][l] != 'a' + j) {
						ok = false;
					}
				}
				if (ok)nans += ts[k].size();
			}
			amax = max(amax, nans);
		}
	}
	cout << amax << endl;
	return 0;
}