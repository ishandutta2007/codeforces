#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int N; cin >> N;
	vector<string>sts(N);
	for (int i = 0; i < N; ++i) {
		string st; cin >> st;
		sts[i] = st.substr(1);
	}
	vector<int>anss(N);

	for (int i = N - 1; i > 0; --i) {
		for (int j = 0; j <= min(sts[i - 1].size(), sts[i].size()); ++j) {
			if ( j== min(sts[i - 1].size(), sts[i].size())) {
				sts[i - 1] = sts[i - 1].substr(0,j);
				break;
			}
			if (sts[i - 1][j]>sts[i][j]) {
				sts[i - 1] = sts[i - 1].substr(0,j);
				break;
			}
			else if (sts[i - 1][j] == sts[i][j])continue;
			else {
				break;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << "#" << sts[i] << endl;
	}
	return 0;
}