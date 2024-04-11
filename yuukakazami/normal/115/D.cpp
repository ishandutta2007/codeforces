/*
 * d.cpp
 *
 *  Created on: 2011-9-20
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MOD = int(1e6) + 3;

vector<int> doit(string s) {
	vector<int> ret;
	string op = "*";
	for (int i = 0; i < s.length(); ++i) {
		char ch = s[i];
		if (ch == '+' || ch == '-')
			op += '+';
		else if (ch == '*' || ch == '/')
			op += '*';
		else if (op != "") {
			ret.push_back(op.size() - 1);
			if (op.find_first_not_of('+', 1) != string::npos) {
				throw 1;
			}
			op = "";
		}
	}
	if (op != "")
		throw 1;
	return ret;
}

int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int main() {
	vector<int> v;
	string input;
	cin >> input;
	try {
		v = doit(input);
	} catch (...) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> dp(4000, 1);
	for (int i = v.size() - 1; i > 0; --i) {
		dp.erase(dp.begin(), dp.begin() + v[i] + 1);
		partial_sum(dp.begin(), dp.end(), dp.begin(), add);
	}
	cout << dp[v[0]] << endl;
}