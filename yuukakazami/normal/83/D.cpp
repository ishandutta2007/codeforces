/*
 * D. Numbers.cpp
 *
 *  Created on: 2011-5-16
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
bool isPrime(int x) {
	if (x == 2)
		return true;
	if (x % 2 == 0)
		return false;
	for (int i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;
	return true;
}

int f(int n, int k);

int g(int n, int k) {
	int ret = n;
	for (int i = 2; i < k; ++i) {
		ret -= f(n, i);
	}
	return ret;
}

int f(int n, int k) {
	if (n < k || !isPrime(k))
		return 0;
	if (n < 1LL * k * k)
		return 1;
	return g(n / k, k);
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	int ret = f(b, k) - f(a - 1, k);
	cout << ret << endl;
}