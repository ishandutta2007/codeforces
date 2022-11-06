#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int N; cin >> N;
	vector<int>ns(N);
	for (int i = 0; i < N; ++i) {
		cin >> ns[i];
		ns[i]--;
	}
	vector<int>anss(N);
	for (int l = 0; l < N; ++l) {
		vector<int>nums(N, 0);
		pair<int, int>top(0, 1);
		for (int r = l; r < N; ++r) {
			const int c= ns[r];
			nums[c]++;
			if (top<make_pair(nums[c], -c)) {
				top = make_pair(nums[c], -c);
			}
			anss[-top.second]++;
		}
	}
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i];
		if (i == anss.size() - 1)cout << endl;
		else cout << " ";
	}
	return 0;
}