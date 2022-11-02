/*
 * b.cpp
 *
 *  Created on: 2012-3-1
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 100000 + 10;
int n, m;
int a[MAX_N], type[MAX_N];
bool can[MAX_N];

int nDo = 0, nDont = 0;
int dome[MAX_N], dontme[MAX_N];

int main() {
	memset(can, 0, sizeof can);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		scanf(" ");
		char cmd = getchar();
		scanf("%d", a + i);
		--a[i];
		type[i] = cmd == '+';
		if (cmd == '+') {
			nDo++;
			dome[a[i]]++;
		} else {
			nDont++;
			dontme[a[i]]++;
		}
	}

	int nCan = 0;

	for (int i = 0; i < n; ++i) {
		//if i commit a crime
		int cnt = dome[i];
		cnt += nDont - dontme[i];
		if (cnt == m) {
			can[i] = true;
			++nCan;
		}
	}

	for (int i = 0; i < n; ++i) {
		if (type[i]) {
			if (can[a[i]]) {
				if (nCan == 1)
					puts("Truth");
				else
					puts("Not defined");
			} else {
				puts("Lie");
			}
		} else {
			if (can[a[i]]) {
				if (nCan == 1)
					puts("Lie");
				else
					puts("Not defined");
			} else {
				puts("Truth");
			}
		}
	}
	return 0;
}