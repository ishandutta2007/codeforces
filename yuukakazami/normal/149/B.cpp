/*
 * b.cpp
 *
 *  Created on: 2012-2-17
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <sstream>
#include <cctype>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int calc(string a, int mx) {
	for (int i = 2; i < 10000; ++i) {
		int c = 0;
		for (int j = 0; j < a.size(); ++j) {
			c *= i;
			if (isdigit(a[j]))
				c += a[j] - '0';
			else
				c += a[j] - 'A' + 10;
		}
		if (c > mx)
			return i - 1;
	}
	return 10000;
}

int getmax(string a) {
	int mx = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] >= '0' && a[i] <= '9')
			mx = max(mx, a[i] - '0');
		else
			mx = max(mx, a[i] - 'A' + 10);
	}
	return mx;
}

int main() {
	string a, b, s;
	cin >> s;
	replace(s.begin(), s.end(), ':', ' ');
	istringstream sin(s);
	sin >> a >> b;
	int ret = min(calc(a, 23), calc(b, 59));
	int l = max(getmax(a), getmax(b)) + 1;
	if (ret == 10000)
		puts("-1");
	else if (l > ret)
		puts("0");
	else {
		for (int i = l; i <= ret; ++i) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}