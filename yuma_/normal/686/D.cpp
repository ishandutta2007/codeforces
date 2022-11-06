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

vector<vector<int>>edges,revedges;

vector<int>child_nums;
vector<int>cens;


int getchi(const int now) {
	if (edges[now].empty())return child_nums[now] = 1;
	else {
		for (auto e : edges[now]) {
			child_nums[now] += getchi(e);
		}
		child_nums[now]++;
		return child_nums[now];
	}
}
int dfs(const int now) {
	if (cens[now] != -1)return cens[now];
	if (edges[now].empty()) {
		return cens[now] = now;
	}
	else {
		vector<pair<int, int>>ps;
		for (auto e : edges[now]) {
			ps.emplace_back(child_nums[e], e);
		}
		sort(ps.begin(), ps.end(),greater<pair<int,int>>());
		const int max_size = (child_nums[now]) / 2;
		int nans =dfs(ps[0].second);
		while (1) {
			if (child_nums[now] - child_nums[nans] <= max_size) {
				return cens[now] = nans;
			}
			else {
				nans = revedges[nans][0];
			}
		}
	}
}


int main() {
	int N, M; cin >> N >> M;
	edges.resize(N);
	revedges.resize(N);
	cens.resize(N);
	fill(cens.begin(), cens.end(), -1);
	child_nums.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int a; cin >> a; a--;
		edges[a].push_back(i + 1);
		revedges[i + 1].push_back(a);
	}
	getchi(0);
	dfs(0);
	for (int i = 0; i < M; ++i) {
		int a; cin >> a; a--;
		cout << dfs(a)+1 << endl;
	}
	return 0;
}