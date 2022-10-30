#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 100 + 10;

int n;
vector<pair<int, int> > ps;

vector<int> ix;

bool saved[MAX_N * 3][MAX_N * 3][2];
bool ok[MAX_N * 3][MAX_N * 3][2];

bool check(int l, int r, bool can = true) {
	if (saved[l][r][can])
		return ok[l][r][can];
	saved[l][r][can] = true;
	bool&ret = ok[l][r][can];
	if (l == r)
		return ret = true;

	//Now, who cover the ix[l]?
	for (int i = 0; i < ps.size(); ++i) {
		if (ps[i].first < ix[l] || ps[i].first > ix[r])
			continue;
		if (ps[i].first == ix[l] && can) {
			//right
			int cr = ix[l] + ps[i].second;
			for (int j = i + 1; j < ps.size(); ++j) {
				if (ps[j].first <= cr) {
					cr = max(cr, ps[j].first + ps[j].second);
				}
			}
			if (cr >= ix[r])
				return ret = true;
			int now = lower_bound(ix.begin(), ix.end(), cr) - ix.begin();
			//[l,now] is covered
			if (check(now, r))
				return ret = true;
		}
		if (ps[i].first - ps[i].second <= ix[l]) {
			int cr = ps[i].first;
			for (int j = 0; j < ps.size(); ++j) {
				if (ps[j].first >= ix[l] && ps[j].first <= ix[r]) {
					if (ps[j].first == ix[l] && !can)
						continue;
					if (ps[j].first <= cr && j != i) {
						cr = max(cr, ps[j].first + ps[j].second);
					}
				}
			}
			if (cr >= ix[r])
				return ret = true;
			int now = lower_bound(ix.begin(), ix.end(), cr) - ix.begin();
			//[l,now] is covered
			if (check(now, r, cr != ps[i].first))
				return ret = true;
		}
	}
	return ret = false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, l;
		cin >> a >> l;
		ps.push_back(make_pair(a, l));
		ix.push_back(a - l);
		ix.push_back(a);
		ix.push_back(a + l);
	}
	sort(ps.begin(), ps.end());
	sort(ix.begin(), ix.end());
	ix.erase(unique(ix.begin(), ix.end()), ix.end());

//	for (int i = 0; i < ix.size(); ++i) {
//		cout << ix[i] << " ";
//	}
//	cout << endl;

	for (int i = 0; i < ix.size(); ++i) {
		for (int j = i; j < ix.size(); ++j) {
			check(i, j);
		}
	}

	int dp[MAX_N * 3];
	dp[0] = 0;
	for (int i = 1; i < ix.size(); ++i) {
		dp[i] = dp[i - 1];
		if (check(0, i)) {
			dp[i] = max(dp[i], ix[i] - ix[0]);
		}
		for (int j = 1; j < i; ++j) {
			if (check(j, i)) {
				dp[i] = max(dp[i], dp[j - 1] + ix[i] - ix[j]);
			}
		}
	}
	cout << dp[ix.size() - 1] << endl;
}