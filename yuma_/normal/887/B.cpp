#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int N; cin >> N;
	vector<vector<int>>dices(3);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 6; ++j) {
			int a; cin >> a;
			dices[i].push_back(a);
		}
	}
	vector<int>oks(10000);
	for (int use = 1; use <= N; ++use) {

		vector<int>perm(N);
		iota(perm.begin(), perm.end(), 0);
		do{
			int t = 1;
			for (int j = 0; j < use; ++j)t *= 6;
			for (int i = 0; i < t; ++i) {
				vector<int>as(use);
				int rest(i);
				for (int j = 0; j < use; ++j) {
					as[j] = rest % 6;
					rest /= 6;
				}
				{
					int num = 0;
					for (int j = 0; j < use; ++j) {
						int r = 1;
						for (int k = 0; k < j; ++k)r *= 10;
						num += r*dices[perm[j]][as[j]];
					}
					oks[num] = true;
				}
			}
		} while (next_permutation(perm.begin(), perm.end()));
	}
	int ans = -1;
	for (int i = 1; i < 10000; ++i) {
		if (!oks[i]) {
			ans = i-1;
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}