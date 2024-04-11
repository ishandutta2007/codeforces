/*
 * a.cpp
 *
 *  Created on: 2013-4-19
 *      Author: mac
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int n;
bool can[10];
//000000

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

string s;
bool ok(const string&s, int l, int r, int&ret) {
	if (s[l] == '0' && l != r)
		return false;
	ret = 0;
	for (int i = l; i <= r; ++i) {
		ret = ret * 10 + s[i] - '0';
	}
	return ret <= 255;
}

vector<vector<int> > ans;

int p[4];

void rec2(int i, int cur) {
	if (i == s.size()) {
		if (cur == 4) {
			ans.push_back(vector<int>(p, p + 4));
		}
		return;
	}
	if (cur == 4)
		return;
	for (int j = i; j <= i + 2 && j < s.size(); ++j) {
		int t;
		if (ok(s, i, j, t)) {
			p[cur] = t;
			rec2(j + 1, cur + 1);
		}
	}
}

void solve(string s) {
	::s = s;
	rec2(0, 0);
}

int cnt[10];

void rec(string s) {
	if (s.size() > 0) {
		bool ok = true;
		for (int k = 0; k < 10; ++k) {
			if (can[k] && cnt[k] == 0)
				ok = false;
		}
		if (ok) {
			solve(rev(s) + s);
			solve(rev(s) + s.substr(1));
		}
	}
	if (s.size() >= 6)
		return;
	for (int i = 0; i < 10; ++i) {
		if (can[i]) {
			cnt[i]++;
			rec(s + char('0' + i));
			cnt[i]--;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		can[x] = true;
	}
	rec("");

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		vector<int> v = ans[i];
		printf("%d", v[0]);
		for (int j = 1; j < 4; ++j) {
			printf(".%d", v[j]);
		}
		puts("");
	}
}