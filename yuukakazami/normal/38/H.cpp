/*
 * H. The Great Marathon.cpp
 *
 *  Created on: 2011-9-2
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;
typedef pair<int, int> ipair;

const int MAX_N = 50 + 1;
int dist[MAX_N][MAX_N];
int nV, nE;
int gMin, gMax, sMin, sMax;
ipair distSorted[MAX_N][MAX_N];

int main() {
	cin >> nV >> nE;
	fill(dist[0], dist[nV], INT_MAX / 4);
	for (int i = 0; i < nE; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		dist[a][b] = dist[b][a] = min(dist[a][b], c);
	}
	for (int k = 0; k < nV; ++k) {
		for (int i = 0; i < nV; ++i) {
			for (int j = 0; j < nV; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 0; i < nV; ++i) {
		int cnt = 0;
		ipair*am = distSorted[i];
		for (int j = 0; j < nV; ++j) {
			if (i != j)
				am[cnt++] = make_pair(dist[i][j], i);
		}
		sort(am, am + nV - 1);
	}
	cin >> gMin >> gMax >> sMin >> sMax;
	int64 ans = 0;
	for (int lastGold = 0; lastGold < nV; ++lastGold) {
		for (int firstBronze = 0; firstBronze < nV; ++firstBronze) {
			if (lastGold != firstBronze) {
				ipair goldLine = distSorted[lastGold][0];
				ipair bronzeLine = distSorted[firstBronze][nV - 2];
				if (goldLine > bronzeLine)
					continue;
				static int64 dp[MAX_N][MAX_N][MAX_N];
				memset(dp, 0, sizeof dp);
				dp[0][0][0] = 1;
				for (int i = 0; i < nV; ++i) {
					ipair*am = distSorted[i];
					bool canGold = false, canSilver = false, canBronze = false;
					if (i == lastGold) {
						canGold = true;
					} else if (i == firstBronze) {
						canBronze = true;
					} else {
						canGold = am[0] < goldLine;
						canBronze = am[nV - 2] > bronzeLine;
						ipair*it = upper_bound(am, am + nV - 1, goldLine);
						if (it < am + nV - 1 && *it < bronzeLine) {
							canSilver = true;
						}
					}
					for (int gold = 0; gold <= i; ++gold) {
						for (int silver = 0; silver + gold <= i; ++silver) {
							int64 c = dp[i][gold][silver];
							if (canGold) {
								dp[i + 1][gold + 1][silver] += c;
							}
							if (canSilver) {
								dp[i + 1][gold][silver + 1] += c;
							}
							if (canBronze) {
								dp[i + 1][gold][silver] += c;
							}
						}
					}
				}
				for (int gold = gMin; gold <= gMax; ++gold) {
					for (int silver = sMin; silver <= sMax; ++silver) {
						ans += dp[nV][gold][silver];
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}