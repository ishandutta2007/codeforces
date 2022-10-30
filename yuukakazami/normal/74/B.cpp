/*
 * b.cpp
 *
 *  Created on: 2011-4-15
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

int n, initS, initC;

char event[210];
int len;

int main() {
	cin >> n >> initS >> initC;
	--initS;
	--initC;
	int curC = initC;
	string a, b;
	cin >> a >> b;
	int dirC = b == "head" ? -1 : 1;
	if (curC == initS) {
		puts("Controller 0");
		return 0;
	}
	string move;
	cin >> move;

	vector<bool> am, nam;
	am.assign(n, false);
	am[initS] = true;
	for (int i = 0; i < move.size(); ++i) {
		nam.assign(n, false);

		vector<bool> foribid(n, false);
		foribid[curC] = true;
		curC += dirC;
		foribid[curC] = true;
		if (curC == 0 || curC == n - 1)
			dirC *= -1;
		if (move[i] == '0') {
			for (int at = 0; at < am.size(); ++at) {
				if (am[at]) {
					if (at + 1 < n && !foribid[at + 1])
						nam[at + 1] = true;
					if (at != curC && !foribid[at])
						nam[at] = true;
					if (at > 0 && !foribid[at - 1])
						nam[at - 1] = true;
				}
			}
		} else {
			for (int at = 0; at < nam.size(); ++at) {
				if (at != curC)
					nam[at] = true;
			}
		}

//		cout << i << ":" << curC + 1 << endl;
//		foreach(iter,nam)
//			cout << *iter << " ";
//		cout << endl;

		am = nam;
		bool any = false;
		for (int at = 0; at < am.size(); ++at) {
			any |= am[at];
		}
		if (!any) {
			printf("Controller %d\n", i + 1);
			return 0;
		}
	}
	puts("Stowaway");
}