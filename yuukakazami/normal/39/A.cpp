#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <utility>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
string input;
int at;
char peekChar() {
	return input[at];
}
char nextChar() {
	return input[at++];
}

int main() {
	int v;
	cin >> v;
	vector<pair<int, int> > ps;
	cin >> input;
	input = "+" + input;
	input += "@@@@@@";
	at = 0;
	while (peekChar() != '@') {
		int sign = nextChar() == '+' ? 1 : -1;
		int cof = 1;
		if (isdigit(peekChar())) {
			cof = 0;
			while (isdigit(peekChar()))
				cof = cof * 10 + (nextChar() - '0');
			nextChar(); //*
		}
		ps.push_back(make_pair(cof * sign, peekChar() == '+'));
		nextChar(), nextChar(), nextChar();
	}
	sort(ps.begin(), ps.end());
	int ans = 0;
	for (int i = 0; i < ps.size(); ++i) {
//		cout << ps[i].first << " " << ps[i].second << endl;
		if (ps[i].second)
			++v;
		ans += ps[i].first * v;
		if (!ps[i].second)
			++v;
	}
	cout << ans << endl;
	return 0;
}