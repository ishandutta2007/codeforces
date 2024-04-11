/*
 * D. Powerful array.cpp
 *
 *  Created on: 2011-5-23
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <cmath>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N = 200000 + 10;
const int MAX_N_QUERIES = 200000 + 10;
struct Query;

Query*queryFirst[MAX_N] = { };

typedef long long int64;

struct Query {
	int l, r;
	int64 ans;
	Query*next;
	void read() {
		scanf("%d%d", &l, &r);
		--l;
		--r;
		next = queryFirst[r];
		queryFirst[r] = this;
		ans = 0;
	}
};

Query queries[MAX_N_QUERIES];
int n, nQ;
int a[MAX_N];
const int MAX_V = 1000000 + 10;
int cnt[MAX_V] = { };

const int MAX_N_SQRT = 10000;

int bigIdx[MAX_V];
int bigs[MAX_N_SQRT], nBigs;
vector<int> pos[MAX_N_SQRT];

void readInput() {
	scanf("%d%d", &n, &nQ);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < nQ; ++i) {
		queries[i].read();
	}
}
int prevSame[MAX_N];
int last[MAX_V];

struct TA {
	int64 a[MAX_N];
	int n;
	void init(int _n) {
		memset(a, 0, sizeof a);
		n = _n;
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	void add(int l, int r, int x) {
		add(l, x);
		add(r + 1, -x);
	}
	int64 calc(int p) {
		int64 ret = 0;
		for (p++; p > 0; p -= p & -p)
			ret += a[p - 1];
		return ret;
	}
};

TA ta;

void work() {
	memset(last, -1, sizeof last);
	int Sqrt = sqrt(n) + 1;
	for (int i = 0; i < n; ++i) {
		int me = a[i];
		cnt[me]++;
		prevSame[i] = last[me];
		last[me] = i;
	}

	nBigs = 0;
	for (int i = 0; i < MAX_V; ++i) {
		if (cnt[i] >= Sqrt) {
			bigs[nBigs] = i;
			bigIdx[i] = nBigs++;
		}
	}

	for (int i = 0; i < n; ++i) {
		int w = a[i];
		if (cnt[w] >= Sqrt) {
			pos[bigIdx[w]].push_back(i);
		}
	}

	for (int i = 0; i < nQ; ++i) {
		Query*q = queries + i;
		for (int j = 0; j < nBigs; ++j) {
			int w = bigs[j];
			vector<int>&p = pos[j];
			int cnt = upper_bound(p.begin(), p.end(), q->r) - lower_bound(
					p.begin(), p.end(), q->l);
			q->ans += 1LL * cnt * cnt * w;
		}
	}

	ta.init(n);
	for (int i = 0; i < n; ++i) {
		int w = a[i];
		int at = i;
		int cur = 1;
		if (cnt[w] < Sqrt) {
			while (at != -1) {
				ta.add(prevSame[at] + 1, at, cur * w);
				at = prevSame[at];
				cur += 2;
			}
		}
		for (Query*q = queryFirst[i]; q; q = q->next) {
			q->ans += ta.calc(q->l);
		}
	}

	for (int i = 0; i < nQ; ++i) {
		printf("%I64d\n", queries[i].ans);
	}
}

int main() {
	readInput();
	work();
}