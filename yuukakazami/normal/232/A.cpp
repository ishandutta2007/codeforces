#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int comb(int n, int m) {
	int r = 1;
	for (int i = 0; i < m; ++i) {
		r *= n - i;
		r /= i + 1;
	}
	return r;
}
bool edge[100][100];

int main() {
	//find a maximal
	int k;
	cin >> k;
	int bs = 0;
	for (int i = 100; i >= 3; --i) {
		if (comb(i, 3) <= k) {
			bs = i;
			break;
		}
	}
	//1..bs,a cluster
	vector<int> vs;
	int cur = bs;
	k -= comb(bs, 3);
	for (int j = bs; j >= 2; --j) {
		while (comb(j, 2) <= k) {
			k -= comb(j, 2);
			++cur;
			vs.push_back(j);
		}
	}
	cout << cur << endl;
	memset(edge, 0, sizeof edge);
	for (int i = 0; i < bs; ++i) {
		for (int j = 0; j < bs; ++j) {
			if (i != j)
				edge[i][j] = true;
		}
	}
	for (int i = 0; i < vs.size(); ++i) {
		int me = bs + i;
		for (int j = 0; j < vs[i]; ++j) {
			edge[j][me] = edge[me][j] = true;
		}
	}
	for (int i = 0; i < cur; ++i) {
		for (int j = 0; j < cur; ++j) {
			cout << edge[i][j] ? 1 : 0;
		}
		cout << endl;
	}
	return 0;
}