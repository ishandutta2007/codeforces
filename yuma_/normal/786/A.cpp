#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"
vector<vector<int>>memo(2);
vector<vector<int>>wins(2);
vector<vector<int>>moves(2);

int N;
void solve(int now, int is_fst,bool win) {
	wins[is_fst][now] = win;
	assert(memo[is_fst][now] == 0);
	for (auto m : moves[!is_fst]) {
		int from = (now + N - m) % N;
		if (!memo[!is_fst][from])continue;
		else {

			if (!win) {
				memo[!is_fst][from] = 0;
				solve(from, !is_fst, 1);
			}
			else {
				memo[!is_fst][from]--;
				if (!memo[!is_fst][from]) {
					solve(from, !is_fst, 0);
				}
			}
		}
		
	}
	return;
}

int main() { cin >> N;
	
	for (int i = 0; i < 2;++i) {
		int K; cin >> K;
		while (K--) {
			int a; cin >> a;
			moves[i].emplace_back(a);
		}
	}
	for (int i = 0; i < 2; ++i) {
		memo[i].resize(N);
		wins[i].resize(N);
		fill(memo[i].begin(), memo[i].end(), moves[i].size());
		fill(wins[i].begin(), wins[i].end(), -1);
	}
	wins[0][0] = 0;
	wins[1][0] = 0;
	memo[0][0] = 0;
	memo[1][0] = 0;
	solve(0, 0, 0);
	solve(0, 1, 0);
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j < N; ++j) {
			string st = !memo[i][j] ? wins[i][j] ? "Win" : "Lose" : "Loop";
			cout << st;
			if (j == N - 1)cout << endl;
			else cout << " ";
		}
	}
	return 0;
}