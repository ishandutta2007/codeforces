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

int getc(const int now, const vector<vector<int>>&edges,vector<int>&c_nums) {
	int num = 1;
	for (auto e : edges[now]) {
		num += getc(e, edges,c_nums);
	}
	return c_nums[now] = num;
}

void dfs(const int now, const vector<vector<int>>&edges, const vector<int>&c_nums, vector<ld>&anss,const ld plus) {
	ld c_all = c_nums[now] - 1;
	for (auto e : edges[now]) {
		ld c_rest = c_all - c_nums[e];
		anss[e] = c_rest / 2 + 1+plus;
		dfs(e, edges, c_nums, anss,plus + c_rest / 2 + 1);
	}
}

int main() {
	int N; cin >> N;
	vector<vector<int>>edges(N);
	for (int i= 0; i < N-1; ++i) {
		int a; cin >> a; a--;
		edges[a].push_back(i + 1);
	}
	vector<int>c_nums(N);
	getc(0, edges, c_nums);
	vector<ld>anss(N);
	anss[0] = 1;
	dfs(0, edges, c_nums, anss,1);
	cout << setprecision(12) << fixed;
	for (int i = 0; i < anss.size(); ++i) {
		cout << anss[i];
		if (i == anss.size() - 1)cout << endl;
		else cout << " ";
	}

	return 0;
}