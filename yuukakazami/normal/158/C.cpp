/*
 * c.cpp
 *
 *  Created on: 2012-3-4
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

vector<string> split(string s, string del = " ") {
	s += del[0];
	string w = "";
	vector<string> ret;
	foreach(e,s) {
		if (del.find(*e) == string::npos)
			w += *e;
		else {
			if (w != "")
				ret.push_back(w);
			w = "";
		}
	}
	return ret;
}

int main() {
	vector<string> cur;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "pwd") {
			cout << "/";
			for (int i = 0; i < cur.size(); ++i) {
				cout << cur[i] << "/";
			}
			cout << endl;
		} else {
			string s;
			cin >> s;
			if (s[0] == '/')
				cur.clear();
			vector<string> p = split(s, "/");
			for (int i = 0; i < p.size(); ++i) {
				if (p[i] == "..")
					cur.pop_back();
				else
					cur.push_back(p[i]);
			}
		}
	}
	return 0;
}