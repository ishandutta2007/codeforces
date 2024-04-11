/*
 * b.cpp
 *
 *  Created on: 2012-4-8
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <deque>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = int(1e6) + 10;

int nA, nB;
int a[MAX_N], b[MAX_N];

typedef long long int64;

deque<int64> bs;

int atA[MAX_N], atB[MAX_N];

int main() {
	cin >> nA >> nB;

	memset(atA, -1, sizeof atA);
	memset(atB, -1, sizeof atB);

	for (int i = 0; i < nA; ++i) {
		scanf("%d", a + i);
		atA[a[i]] = i;
	}

	for (int i = 0; i < nB; ++i) {
		scanf("%d", b + i);
		atB[b[i]] = i;
	}

	int j = 0;
	int ans = 0;
	for (int i = 0; i < nA; ++i) {
		//[i,j)
		while (j - i < nA) {
			int v = a[j % nA];
			int64 bv = atB[v];
			if (bv == -1)
				break;
			if (bs.empty() || bs.back() < bv) {
				bs.push_back(bv);
				++j;
			} else {
				bv += (bs.back() - bv) / nB * nB;
				if (bs.back() > bv)
					bv += nB;
				if (bv - bs.front() <= nB - 1) {
					bs.push_back(bv);
					++j;
				} else
					break;
			}
		}

		ans = max(ans, j - i);

		//[i -> [i+1
		if (i < j)
			bs.pop_front();
		else {
			++j;
		}
	}

	cout << ans << endl;
	return 0;
}