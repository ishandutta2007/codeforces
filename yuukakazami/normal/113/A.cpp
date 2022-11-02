/*
 * a.cpp
 *
 *  Created on: 2011-9-11
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const string WORD[3][2] = { { "lios", "liala" }, { "etr", "etra" }, { "initis", "inites" } };

typedef pair<int, int> ipair;

ipair getType(string s) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			string w = WORD[i][j];
			if (s.size() >= w.size()) {
				if (s.substr(s.size() - w.size()) == w)
					return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

int main() {
	vector<string> words;
	string s;
	int last = -1;
	vector<ipair> ts;
	while (cin >> s) {
		if (s == "#")
			break;
		words.push_back(s);
		ipair t = getType(s);
		if (t.first == -1) {
			cout << "NO" << endl;
			return 0;
		}
		ts.push_back(t);
	}
	if (ts.size() == 1) {
		cout << "YES" << endl;
	} else {
		for (int i = 0; i < ts.size(); ++i) {
			if (ts[i].second != ts[0].second) {
				cout << "NO" << endl;
				return 0;
			}
		}
		int at = 0;
		while (at < ts.size() && ts[at].first == 0)
			++at;
		if (ts[at].first != 1) {
			cout << "NO" << endl;
		} else {
			++at;
			while (at < ts.size() && ts[at].first == 2)
				++at;
			if (at != ts.size())
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
	return 0;
}