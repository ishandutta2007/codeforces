/*
 * D. Plus and xor.cpp
 *
 *  Created on: 2011-4-12
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

typedef unsigned long long uint64;

int main() {
	uint64 A, B;
	cin >> A >> B;
	if (A < B) {
		puts("-1");
		return 0;
	}

	if ((A - B) % 2 != 0) {
		puts("-1");
		return 0;
	}

	uint64 C = (A - B) / 2;
	uint64 X = 0, Y = 0;

	for (uint64 bit = 1ULL << 63; bit >= 1; bit >>= 1) {
		bool dif = (B & bit);
		bool allHas = (C & bit);
		if (allHas && dif) {
			puts("-1");
			return 0;
		}
		if (allHas) {
			X |= bit;
			Y |= bit;
		}
		if (dif) {
			Y |= bit;
		}
	}

	cout << X << " " << Y << endl;
}