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
	vector<int>hs(N);
	for (int i = 0; i < N; ++i) {

		cin >> hs[i];
	}
	vector<pair<int, int>>anss;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (hs[j] > hs[j + 1]) {
				swap(hs[j], hs[j + 1]);
				anss.emplace_back(j + 1, j + 2);
			}

		}
	}
	for (auto a : anss) {
		cout << a.first << " " << a.second << endl;
	}
	return 0;
}