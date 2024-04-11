#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

vector<int>memo;
int kk = -1;

int dfs(const int now, const int from, const vector<vector<int>>&edges){ 
	int a = 0;
	int b = 0;
	int c = 0;
	for (auto e : edges[now]) {
		if (e == from)continue;
		else {
			int sta = dfs(e, now, edges);
			if (sta == 0)c++;
			else if (sta == 1) {
				b++;
			}
			else if (sta == 2) {
				a++;
			}
			else if (sta == 3) {
				kk = e;
				throw(false);
			}
		}
	}

	if (a == 0 && b == 0 && c <= 1) {
		return memo[now]=0;
	}
	else if (a == 0 && b == 0&&c==2) {
		return  memo[now] = 1;
	}
	else if (a <=1) {
		return  memo[now] = 2;
	}
	else if (a == 2) {
		return  memo[now] = 3;
	}
	else {
		throw(false);
	}
}

int main() {
	int N; cin >> N;
	memo.resize(N);
	vector<vector<int>>edges(N, vector<int>());
	for (int i = 0; i < N - 1; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	bool ok = true;
	try {

		dfs(0, -1, edges);
	}
	catch (...) {
		ok = false;
	}
	if (kk != -1) {
		ok = true;
		try {
			dfs(kk, -1, edges);
		}
		catch (...) {
			ok = false;
		}
	}
	if (ok)cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}