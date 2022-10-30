/*
 * C. Winning Strategy.cpp
 *
 *  Created on: 2011-7-16
 *      Author: mac
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

const int MAX_N = 100 + 10;
double dp[2][MAX_N * 5], prob[MAX_N];
int main() {
	double*am = dp[0], *nam = dp[1];
	int n;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		scanf("%lf", prob + i);
	}
	fill(am, am + n * 5, -1e100);
	am[n * 5] = 0;
	double best = 0;
	int lastBest = 0;
	for (int i = 0; i <= lastBest + n; i++) {
		for (int j = 0; j <= n * 5; ++j) {
			nam[j] = -1e100;
			for (int k = 0; k <= n; ++k) {
				int nj = j + n - 2 * k;
				if (nj >= 0 && nj <= n * 5)
					nam[j] = max(nam[j], am[nj] + prob[k]);
			}
			double cur = nam[j] / (i + 1);
			if (cur > best + 1e-14) {
				best = cur;
				lastBest = j;
			}
		}
		swap(am, nam);
	}
	printf("%0.10lf\n", best);
	return 0;
}