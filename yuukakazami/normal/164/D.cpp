#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 1000;
int n, k;
int x[MAX_N], y[MAX_N];
int dt[MAX_N][MAX_N];
int dis(int i, int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
int ds[MAX_N * MAX_N], nDs;
int bad[MAX_N][MAX_N], nBad[MAX_N];
int cnt[MAX_N], bd;
int perm[MAX_N];

void rec(int it) {
	if (bd > k) {
		return;
	}
	if (it == n) {
		throw 1;
	}
	int i = perm[it];
	if (cnt[i] > 0) {
		rec(it + 1);
		return;
	}
	//use it
	int newbad = 0;
	for (int j = 0; j < nBad[i]; ++j) {
		if (++cnt[bad[i][j]] == 1) {
			++bd;
			newbad++;
		}
	}
	rec(it + 1);
	for (int j = 0; j < nBad[i]; ++j) {
		if (--cnt[bad[i][j]] == 0)
			--bd;
	}
	//ignore it
	if (newbad > 1) {
		++cnt[i];
		++bd;
		rec(it + 1);
		--cnt[i];
		--bd;
	}
}

int cmp(int a, int b) {
	return nBad[a] < nBad[b];
}

bool check(int L) {
	for (int i = 0; i < n; ++i) {
		nBad[i] = 0;
		for (int j = 0; j < n; ++j) {
			if (dt[i][j] > L) {
				bad[i][nBad[i]++] = j;
			}
		}
		perm[i] = i;
	}
	sort(perm, perm + n, cmp);
	memset(cnt, 0, sizeof cnt);
	bd = 0;
	try {
		rec(0);
	} catch (int e) {
		return true;
	}
	return false;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			dt[i][j] = dt[j][i] = dis(i, j);
			ds[nDs++] = dt[i][j];
		}
	}
	sort(ds, ds + nDs);
	int l = -1, r = nDs;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (check(ds[m]))
			r = m;
		else
			l = m;
	}
	check(ds[r]);
	bool used[MAX_N] = { };
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (cnt[i] > 0)
			ans.push_back(i + 1), used[i] = true;
	}
	for (int i = 0; i < n; ++i) {
		if (ans.size() < k && !used[i]) {
			used[i] = true;
			ans.push_back(i + 1);
		}
	}
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}