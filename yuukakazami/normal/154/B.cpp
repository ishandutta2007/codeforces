/*
 * b.cpp
 *
 *  Created on: 2012-2-24
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	static vector<int> ps[100010];
	for (int i = 2; i <= n; ++i) {
		if (ps[i].empty()) {
			for (int j = i; j <= n; j += i)
				ps[j].push_back(i);
		}
	}
	static int who[100010], st[100010];
	memset(who, -1, sizeof who);
	memset(st, 0, sizeof st);
	for (int i = 0; i < m; ++i) {
		scanf(" ");
		char cmd;
		int x;
		scanf("%c %d", &cmd, &x);
		if (cmd == '+') {
			if (st[x] == 1) {
				puts("Already on");
			} else {
				bool ok = 1;
				for (vector<int>::iterator e = ps[x].begin(); e != ps[x].end(); ++e) {
					if (who[*e] != -1) {
						printf("Conflict with %d\n", who[*e]);
						ok = 0;
						break;
					}
				}
				if (ok) {
					for (vector<int>::iterator e = ps[x].begin(); e != ps[x].end(); ++e) {
						who[*e] = x;
					}
					puts("Success");
					st[x] = 1;
				}
			}
		} else {
			if (st[x] == 0) {
				puts("Already off");
			} else {
				st[x] = 0;
				for (vector<int>::iterator e = ps[x].begin(); e != ps[x].end(); ++e) {
					who[*e] = -1;
				}
				puts("Success");
			}
		}
	}
	return 0;
}