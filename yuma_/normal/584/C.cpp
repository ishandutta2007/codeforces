
#include "bits/stdc++.h"
using namespace std;



int main() {
	int n, t; cin >> n >> t;
	string sts[2]; cin >> sts[0] >> sts[1];
	int dif = 0;
	vector<bool>a;
	for (int i = 0; i < n; ++i) {
		if (sts[0][i] != sts[1][i]) {
			dif++;
		}
	}
	const int same = n - dif;
	const int needsame = n - t;

	if (needsame > same + (n - same) / 2) {
		cout << -1 << endl;
	}
	else {
		if (needsame > same) {
			string nst;
			int zero_to_same = needsame - same;
			int one_to_same(needsame - same);
			for (int i = 0; i < n; ++i) {
				if (sts[0][i] == sts[1][i]) {
					nst.push_back(sts[0][i]);
				}
				else if(zero_to_same){
					nst.push_back(sts[0][i]);
					zero_to_same--;

				}
				else if (one_to_same) {
					nst.push_back(sts[1][i]);
					one_to_same--;
				}
				else {
					for (int j = 0; j < 3; ++j) {
						char c('a' + j);
						if (sts[0][i] != c&&sts[1][i] != c) {
							nst.push_back(c);
							break;
						}
					}
				}
			}
			cout << nst << endl;
		}
		else {
			string nst;
			int same_to_diff = same - needsame;
			for (int i = 0; i < n; ++i) {
				if (sts[0][i] == sts[1][i]) {
					if (same_to_diff) {
						for (int j = 0; j < 3; ++j) {
							char c('a' + j);
							if (sts[0][i] != c&&sts[1][i] != c) {
								nst.push_back(c);
								
								break;
							}
						}
						same_to_diff--;
					}
					else {
						nst.push_back(sts[0][i]);
					}
				}else {
					for (int j = 0; j < 3; ++j) {
						char c('a' + j);
						if (sts[0][i] != c&&sts[1][i] != c) {
							nst.push_back(c);
							break;
						}
					}
				}
			}
			cout << nst << endl;
		}
	}

	return 0;
}