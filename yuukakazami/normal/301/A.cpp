/*
 * a.cpp
 *
 *  Created on: 2013-5-5
 *      Author: mac
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int MAX_N = 300;
int n;
int a[MAX_N];

int main() {
	cin >> n;
	int x = n;
	n = n * 2 - 1;

	int sum = 0, cnt = 0;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += abs(a[i]);
		if (a[i] < 0)
			++cnt;
	}

	if (cnt % 2 == 0 || x % 2 == 1) {
		cout << sum << endl;
	} else {
		int who = 1000000;
		for (int i = 0; i < n; ++i) {
			who = min(who, abs(a[i]));
		}
		sum -= who * 2;
		cout << sum << endl;
	}
}