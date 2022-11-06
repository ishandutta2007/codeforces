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

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
bool check(const int x, const int y) {
	if (x == 1) {
		return y >= 0 && y <= 3;
	}
	else if(x==0||x==2){
		return y >= 0 && y <= 2;
	}
	else {
		return false;
	}
}

int main() {
	int N; cin >> N;
	string st; cin >> st;
	int l, r, u, d;
	vector<pair<int, int>>vs;
	for (auto c : st) {
		int num = c - '0';
		if (num == 0) {
			vs.emplace_back(1, 3);
		}
		else {
			vs.emplace_back((num - 1) % 3, (num - 1) / 3);
		}
	}
	bool ok = true;
	for (int way = 0; way < 4; ++way) {
		bool aok = true;
		for (auto v : vs) {
			const int nextx = v.first + dx[way];
			const int nexty = v.second + dy[way];
			if (!check(nextx, nexty)) {
				aok = false;
			}
		}
		if (aok)ok = false;
	}
	if (ok) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}