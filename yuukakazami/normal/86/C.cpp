/*
 * C. Genetic engineering.cpp
 *
 *  Created on: 2011-5-23
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <map>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const string CHARS = "ACGT";
const int MOD = int(1e9) + 9;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> strs;
	set<string> all, ends;
	all.insert("");
	int maxL = 0;

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		maxL = max(maxL, int(s.length()));
		strs.push_back(s);
		for (int j = 1; j <= s.size(); ++j) {
			all.insert(s.substr(0, j));
		}
		ends.insert(s);
	}
	map<string, int> index;
	int cnt = 0;
	foreach(iter,all) {
		index[*iter] = cnt++;
	}

	vector<int> maxEnd(cnt, 0);
	foreach(iter,all) {
		string s = *iter;
		foreach(iter2,ends) {
			string e = *iter2;
			if (s.length() >= e.length() && s.substr(s.length() - e.length())
					== e)
				maxEnd[index[s]] = max(maxEnd[index[s]], int(e.length()));
		}
	}

	vector<vector<int> > next(cnt, vector<int> (4));
	foreach(iter,all) {
		string s = *iter;
		int me = index[s];
		for (int c = 0; c < 4; ++c) {
			char ch = CHARS[c];
			string ns = s + ch;
			while (all.count(ns) == 0)
				ns = ns.substr(1);
			next[me][c] = index[ns];
		}
	}

	vector<vector<int> > am(cnt, vector<int> (maxL, 0));
	am[index[""]][0] = 1;

	for (int i = 0; i < n; ++i) {
		vector<vector<int> > nam(cnt, vector<int> (maxL, 0));
		for (int oldState = 0; oldState < cnt; ++oldState) {
			for (int oldNeed = 0; oldNeed < maxL; ++oldNeed) {
				int cur = am[oldState][oldNeed];
				if (!cur)
					continue;
				for (int c = 0; c < 4; ++c) {
					int newState = next[oldState][c];
					int newNeed = oldNeed + 1;
					if (maxEnd[newState] >= newNeed)
						newNeed = 0;
					if (newNeed >= maxL)
						continue;
					nam[newState][newNeed] += cur;
					if (nam[newState][newNeed] >= MOD)
						nam[newState][newNeed] -= MOD;
				}
			}
		}
		am = nam;
	}

	int ans = 0;
	for (int i = 0; i < cnt; ++i) {
		(ans += am[i][0]) %= MOD;
	}
	cout << ans << endl;
}