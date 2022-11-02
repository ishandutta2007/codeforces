/*
 * a.cpp
 *
 *  Created on: 2012-4-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;

int main() {
	int64 a = 1, b = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "UL")
			++a;
		else if (s == "DR")
			++a;
		else if (s != "ULDR")
			++b;
		else
			++a, ++b;
	}
	cout << a * b << endl;
	return 0;
}