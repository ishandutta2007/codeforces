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
	int N, M; cin >> N >> M;
	vector<int>cs(N);
	for (int i = 0; i < N; ++i) {
		cin >> cs[i];
	}
	vector<vector<vector<int>>>oks(2,vector<vector<int>>(M+1,vector<int>(M+1)));
	oks[0][0][0] = true;
	for (int i = 0; i < N; ++i) {
		int tar = i & 1, cur = tar ^ 1;
		if (i == 0)assert(tar == 0 && cur == 1);
		for (int k = 0; k <= M; ++k) {
			for (int j = 0; j <= M; ++j) {
				oks[cur][k][j] = false;
			}
		}
		for (int make = 0; make <= M; ++make) {
			for (int total = 0; total <= M; ++total) {
				if (oks[tar][make][total]) {
					const int nexttotal = total + cs[i];
					if (nexttotal <= M) {
						oks[cur][make][nexttotal] = true;
						if (make + cs[i] <= M) {
							oks[cur][make + cs[i]][nexttotal] = true;
						}
						if (cs[i] <= M) {
							oks[cur][cs[i]][nexttotal] = true;
						}
						oks[cur][nexttotal][nexttotal] = true;
					}
					oks[cur][make][total] = true;
				}
			}
		}
	}
	int tar = N & 1;
	vector<int>canmakes;
	for (int i = 0; i <= M; ++i) {
		if (oks[tar][i][M])canmakes.emplace_back(i);
	}
	cout << canmakes.size() << endl;
	for (int i = 0; i < canmakes.size(); ++i) {
		cout << canmakes[i];
		if (i != canmakes.size() - 1)cout << " ";
		else cout << endl;
	}
	return 0;
}