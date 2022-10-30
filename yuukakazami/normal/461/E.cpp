/*
 * cheat.cpp
 *
 *  Created on: 2012-5-25
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_LEN = int(1e5) + 10;

struct State {
	State*suf, *go[4];
	int val;
	State() :
			suf(0), val(0) {
		memset(go, 0, sizeof go);
	}
}*root, *last;
State statePool[MAX_LEN * 2], *cur = statePool;

void init() {
	root = last = cur++;
}

void extend(int w) {
	State*p = last, *np = cur++;
	np->val = p->val + 1;
	while (p && !p->go[w])
		p->go[w] = np, p = p->suf;
	if (!p)
		np->suf = root;
	else {
		State*q = p->go[w];
		if (p->val + 1 == q->val)
			np->suf = q;
		else {
			State*nq = cur++;
			memcpy(nq->go, q->go, sizeof q->go);
			nq->val = p->val + 1;
			nq->suf = q->suf;
			q->suf = nq;
			np->suf = nq;
			while (p && p->go[w] == q)
				p->go[w] = nq, p = p->suf;
		}
	}
	last = np;
}

int buf[MAX_LEN];
//int n, m;
typedef long long int64;
typedef vector<vector<int64> > mat;

const int64 INF = 1LL << 61;

mat zero(int n) {
	mat a(n, vector<int64>(n, 0));
	return a;
}

mat unit(int n) {
	mat c = zero(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = (i == j) ? 0 : INF;
		}
	}
	return c;
}

mat mul(mat a, mat b) {
	int n = a.size();
	mat c = zero(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = INF;
			for (int k = 0; k < n; ++k) {
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return c;
}

long long N;
int n;

int64 COST[4][4];
int main() {
	init();
	cin >> N;
	string t;
	cin >> t;
	n = t.size();
	string ABCD = "ABCD";
	for (int i = 0; i < t.size(); ++i) {
		int me = ABCD.find(t[i]);
		buf[i] = me;
		extend(me);
	}

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			COST[i][j] = INF;
		}
	}

	for (int forbid = 0; forbid < 4; ++forbid) {
		State*cur = root;
		int l = 0;

		for (int i = 0; i < n; ++i) {
			while (i + l < n && cur->go[forbid])
				cur = cur->go[buf[i + l]], l++;
			if (!cur->go[forbid]) {
//				COST[buf[i]][forbid] = l;
				COST[buf[i]][forbid] = min(COST[buf[i]][forbid], 1LL * l);
			}
			if (l > 0) {
				--l;
				if (l <= cur->suf->val)
					cur = cur->suf;
			}
		}
	}

//	for (int i = 0; i < 4; ++i) {
//		for (int j = 0; j < 4; ++j) {
//			cout << COST[i][j] << " ";
//		}
//		cout << endl;
//	}

	mat one = zero(4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			one[i][j] = COST[i][j];
		}
	}

	vector<mat> pw(70);
	pw[0] = one;
	for (int i = 1; i < 70; ++i) {
		pw[i] = mul(pw[i - 1], pw[i - 1]);
	}
	mat cur = unit(4);
	long long ans = 0;
	for (int i = 70 - 1; i >= 0; --i) {
		mat ncur = mul(cur, pw[i]);
		int64 best = INF;
		for (int a = 0; a < 4; ++a) {
			for (int b = 0; b < 4; ++b) {
				best = min(best, ncur[a][b]);
			}
		}
		if (best <= N) {
			cur = ncur;
			ans += 1LL << i;
		}
	}
	int64 best = INF;
	for (int a = 0; a < 4; ++a) {
		for (int b = 0; b < 4; ++b) {
			best = min(best, cur[a][b]);
		}
	}
	if (best < N)
		++ans;

	cout << ans << endl;
	return 0;
}