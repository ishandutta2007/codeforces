/*
 * a.cpp
 *
 *  Created on: 2011-4-15
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <map>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

int main() {
	int n;
	string name;
	int ans = -INT_MAX;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string me;
		cin >> me;
		int tmp = 0;
		int x;
		cin >> x;
		tmp += 100 * x;
		cin >> x;
		tmp -= 50 * x;
		for (int j = 0; j < 5; ++j) {
			cin >> x;
			tmp += x;
		}
		if (tmp > ans) {
			ans = tmp;
			name = me;
		}
	}

	cout << name << endl;
}