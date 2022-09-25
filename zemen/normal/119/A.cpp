/*
 * olymp.cpp
 *
 *  Created on: 24.09.2011
 *      Author: zemen
 *
 *  Codeforces Beta Round #90
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef long double ld;
#define INF 0x7fffffff

int gcd(int a, int b) {
	while (a != 0 && b != 0)
		if (a > b)
			a %= b;
		else
			b %= a;
	return a ? a : b;
}

int main() {
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	bool play = 0;
	while (1) {
		int g = gcd(play ? b : a, n);
		n -= g;
		if (n == 0)
			break;
		play ^= 1;
	}
	cout << play;
}