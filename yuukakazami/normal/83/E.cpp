/*
 * E. Two Subsequences.cpp
 *
 *  Created on: 2011-5-15
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N_STRINGS = int(2e5) + 10;
const int MAX_L_STRING = 20;
int nStrings;
int strings[MAX_N_STRINGS];
int length;

int* delta[MAX_L_STRING + 1];

void readInput() {
	cin >> nStrings;
	for (int i = 0; i < nStrings; ++i) {
		static char tmp[1000];
		scanf(" ");
		scanf("%s", tmp);
		length = strlen(tmp);
		int cur = 0;
		for (int j = 0; j < length; ++j) {
			cur <<= 1;
			cur += tmp[j] - '0';
		}
		strings[i] = cur;
	}
}

void work() {
	for (int i = 0; i <= length; ++i) {
		delta[i] = new int[1 << i];
		fill(delta[i], delta[i] + (1 << i), length);
	}

	int total = length;
	for (int i = 1; i < nStrings; ++i) {
		int last = strings[i - 1];
		int cur = strings[i];
		int maxCommon = 0;
		for (int j = 1; j <= length; ++j) {
			if ((last & ((1 << j) - 1)) == (cur >> (length - j)))
				maxCommon = j;
		}
		total += length - maxCommon;
		int minCost = length;
		for (int j = 0; j <= length; ++j) {
			int pre = cur >> (length - j);
			minCost = min(minCost, delta[j][pre] - j);
		}
		minCost += maxCommon;
		for (int j = 0; j <= length; ++j) {
			int suf = (last & ((1 << j) - 1));
			delta[j][suf] = min(delta[j][suf], minCost);
		}
	}

	int minDelta = 0;
	for (int i = 0; i <= length; ++i) {
		for (int j = 0; j < (1 << i); ++j) {
			minDelta = min(minDelta, delta[i][j]);
		}
	}

	total += minDelta;
	cout << total << endl;
}

int main() {
	readInput();
	work();
}