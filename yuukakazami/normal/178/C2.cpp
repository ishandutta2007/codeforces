/*
 * c.cpp
 *
 *  Created on: 2012-4-28
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

int h, m, nQ;

const int MAX_N = int(2e5) + 10;

typedef long long int64;

set<int> emptySet[MAX_N];

vector<int> seqs[MAX_N];

int id[MAX_N], idx[MAX_N], cnt[MAX_N];
int nId;

int findNext(set<int>&s, int me) {
	set<int>::iterator it = s.lower_bound(me);
	if (it == s.end())
		return *s.begin();
	else
		return *it;
}

map<int, int> where;

int main() {
	cin >> h >> m >> nQ;
	memset(id, -1, sizeof id);
	nId = 0;

	for (int i = 0; i < h; ++i) {
		if (id[i] == -1) {
			int x = i, cur = 0;
			while (id[x] == -1) {
				id[x] = nId;
				idx[x] = cur++;
				seqs[nId].push_back(x);
				x += m;
				x %= h;
			}
			cnt[nId] = cur;
			nId++;
		}
	}

	for (int i = 0; i < h; ++i) {
		emptySet[id[i]].insert(idx[i]);
	}

	long long ans = 0;

	for (int i = 0; i < nQ; ++i) {
		char cmd;
		scanf(" ");
		scanf("%c", &cmd);
		if (cmd == '+') {
			int me, hs;
			scanf("%d%d", &me, &hs);

			int at = idx[hs];

			int nxt = findNext(emptySet[id[hs]], at);

			if (at <= nxt)
				ans += nxt - at;
			else {
				ans += cnt[id[hs]] + nxt - at;
			}

			where[me] = seqs[id[hs]][nxt];
			emptySet[id[hs]].erase(nxt);
		} else {
			int me;
			scanf("%d", &me);

			int at = where[me];
			emptySet[id[at]].insert(idx[at]);
		}
	}
	cout << ans << endl;
	return 0;
}