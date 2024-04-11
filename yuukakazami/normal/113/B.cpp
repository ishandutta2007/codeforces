/*
 * b.cpp
 *
 *  Created on: 2011-9-11
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <string>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
string t, bg, ed;
typedef long long int64;
const int SEED = 1331;
const int MAX_N = 2000 + 10;
int64 pow[MAX_N];
int64 hash[MAX_N];

int64 getHash(int l, int r) {
	return hash[r] - hash[l] * pow[r - l];
}

int64 calcHash(const string&s) {
	int64 ret = 0;
	for (int i = 0; i < s.size(); ++i) {
		ret = ret * SEED + s[i];
	}
	return ret;
}

int64 ss[MAX_N * MAX_N];
int cnt;

int main() {
	cin >> t >> bg >> ed;
	pow[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		pow[i] = pow[i - 1] * SEED;
	}
	hash[0] = 0;
	for (int i = 1; i <= t.size(); ++i) {
		hash[i] = hash[i - 1] * SEED + t[i - 1];
	}
	int64 bh = calcHash(bg), eh = calcHash(ed);
	cnt = 0;
	for (int i = 0; i < t.size(); ++i) {
		if (i + bg.size() <= t.size()) {
			if (getHash(i, i + bg.size()) == bh) {
				for (int j = i; j < t.size(); ++j) {
					if (j + ed.size() <= t.size()) {
						if (getHash(j, j + ed.size()) == eh) {
							if (j + ed.size() >= i + bg.size()) {
								ss[cnt++] = getHash(i, j + ed.size());
							}
						}
					}
				}
			}
		}
	}
	sort(ss, ss + cnt);
	cnt = unique(ss, ss + cnt) - ss;
	cout << cnt << endl;
	return 0;
}