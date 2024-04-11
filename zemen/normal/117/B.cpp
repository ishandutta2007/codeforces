/*
 *
 *  Codeforces Beta Round #88
 *  Problem B
 *
 *  Created on: 23.09.2011
 *      Author: zemen
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	//freopen("in.txt", "r", stdin);
	long long a, b, mod;
	cin >> a >> b >> mod;
	long long per = 1000000000 % mod;
	long long res = 1, cur = per;
	while ((mod - cur <= b || cur == 0) && res <= mod && res <= a) {
		cur += per;
		cur %= mod;
		++res;
	}
	if (res > a || res > mod) {
		printf("2");
	} else {
		int outr = (int)res;
		printf("1 %09d", outr);
	}
}