/*
 * d.cpp
 *
 *  Created on: 2011-11-10
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <map>
#include <ctime>
#include <ext/hash_map>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int64;
int64 fib[90];
int64 fibSum[90];
int M;
//const int MAX = 300000;
//
//struct Map {
//	int64 a[MAX];
//	map<int64, int64> mp;
//	Map() {
//		memset(a, -1, sizeof a);
//		mp.clear();
//	}
//	bool has(int64 x) {
//		if (x < MAX)
//			return a[x] != -1;
//		return mp.count(x);
//	}
//
//	int64&operator[](int64 x) {
//		if (x < MAX)
//			return a[x];
//		return mp[x];
//	}
//};

const int MAX_N = 1000000;
pair<int64, int64> ps[2][MAX_N];

int main() {
	fib[0] = 1;
	fib[1] = 2;
	for (int i = 2; i < 90; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] > int64(1e18)) {
			M = i - 1;
			break;
		}
	}
//	cout << M << endl;
//	return 0;
	partial_sum(fib, fib + 90, fibSum);

	int nT;
	cin >> nT;
//	nT = int(1e5);
//	int start = clock();
	for (int i = 0; i < nT; ++i) {
		int64 a;
		cin >> a;
//		a = (((1LL * rand()) << 28) + rand()) % (int64(1e18)) + 1;
//		cout << a << endl;
		pair<int64, int64>*cur = ps[0], *next = ps[1];
		int nCur = 0;
		cur[nCur++] = make_pair(a, 1);
		int64 ans = 0;
		for (int mx = M; mx >= 0; --mx) {
			int nNext = 0;
			for (int i = 0; i < nCur; ++i) {
				int64 a = cur[i].first, c = cur[i].second;
				if (!a) {
					ans += c;
					continue;
				}
				int64 rem = mx == 0 ? 0 : fibSum[mx - 1];
				if (rem >= a) {
					next[nNext++] = make_pair(a, c);
				}
				if (a >= fib[mx]) {
					next[nNext++] = make_pair(a - fib[mx], c);
				}
			}
			sort(next, next + nNext);
			int cnt = 0;
			for (int i = 0; i < nNext; ++i) {
				if (!i || next[i].first != next[i - 1].first) {
					next[cnt++] = next[i];
				} else {
					next[cnt - 1].second += next[i].second;
				}
			}
			nNext = cnt;
			swap(cur, next);
			nCur = nNext;
		}

		for (int i = 0; i < nCur; ++i) {
			if (cur[i].first == 0)
				ans += cur[i].second;
		}
//		cout << a << endl;
		cout << ans << endl;
	}
//	cout << "DONE" << endl;
//	cout << (1.0 * (clock() - start)) / CLOCKS_PER_SEC<<endl;
	return 0;
}