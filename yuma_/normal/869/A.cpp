#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

int main() {
	int N; cin >> N;
	vector<int>xs(N), ys(N);
	set<int>as;
	for (int i = 0; i < N; ++i) {
		cin >> xs[i];
		as.emplace(xs[i]);
	}
	for (int i = 0; i < N; ++i) {
		cin >> ys[i];
		as.emplace(ys[i]);
	}
	bool flag = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (as.find(xs[i] ^ ys[j]) == as.end()) {

			}
			else {
				flag = !flag;
			}
		}
	}
	if (flag)cout << "Koyomi" << endl;
	else cout << "Karen" << endl;
	return 0;
}