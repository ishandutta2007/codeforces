/*
 * 7258. Lexicographical Substring Search.cpp
 *
 *  Created on: 2011-11-8
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <utility>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef long long int64;

struct State {
	State*suf, *go[26];
	int val;
	int64 cnt;
	bool calced;
	bool inner;
	vector<State*> sufCh;

	bool calced2;
	int64 num;
	int64 calcNum() {
		if (calced2)
			return num;
		calced2 = true;
		num = inner;
		for (int i = 0; i < sufCh.size(); ++i) {
			num += sufCh[i]->calcNum();
		}
		return num;
	}

	int64 get() {
		if (calced)
			return cnt;
		calced = true;
		cnt = calcNum();
		for (int i = 0; i < 26; ++i) {
			if (go[i]) {
				cnt += go[i]->get();
			}
		}
		return cnt;
	}
	State() :
			suf(0), val(0), calced(false), calced2(false) {
		memset(go, 0, sizeof go);
	}
}*root, *last;
State statePool[200000 * 2], *cur;

void init() {
	cur = statePool;
	root = last = cur++;
	last->inner = false;
}

void extend(int w) {
	State*p = last, *np = cur++;
	np->inner = true;
	np->val = p->val + 1;
	while (p && !p->go[w])
		p->go[w] = np, p = p->suf;
	if (!p)
		np->suf = root;
	else {
		State*q = p->go[w];
		if (p->val + 1 == q->val) {
			np->suf = q;
		} else {
			State*nq = cur++;
			nq->inner = false;
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

int main() {
	init();
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); ++i) {
		extend(a[i] - 'a');
	}
	for (State*s = statePool; s != cur; ++s)
		if (s->suf)
			s->suf->sufCh.push_back(s);
	int kth;
	cin >> kth;
	int n = a.size();
	int64 tot = 1LL * (n) * (n + 1) / 2;
	if (kth <= tot) {
		State*s = root;
		string ret = "";
		--kth;
		for (;;) {
			if (s != root) {
				if (kth < s->calcNum()) {
					cout << ret << endl;
					return 0;
				} else {
					kth -= s->calcNum();
				}
			}
			for (int i = 0; i < 26; ++i) {
				if (s->go[i] != 0) {
					if (kth < s->go[i]->get()) {
						ret.insert(ret.end(), 1, char('a' + i));
						s = s->go[i];
						break;
					} else {
						kth -= s->go[i]->get();
					}
				}
			}
		}
	} else {
		cout << "No such line." << endl;
	}
	return 0;
}