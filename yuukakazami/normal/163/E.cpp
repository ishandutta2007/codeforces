/*
 * e.cpp
 *
 *  Created on: 2012-3-26
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

const int CHARSET = 26;

int cur;

struct Node {
	Node*ch[CHARSET], *fail;

	vector<Node*> failCh;
	int l, r; //[l,r)

	Node() {
		memset(ch, 0, sizeof ch);
		fail = 0;
	}
	Node*go(int w) {
		Node*&t = ch[w];
		if (!t)
			t = new Node;
		return t;
	}

	void dfs() {
		l = cur++;
		for (vector<Node*>::iterator e = failCh.begin(); e != failCh.end(); ++e) {
			(*e)->dfs();
		}
		r = cur;
	}
}*root;

void clear() {
	root = new Node;
}

void build() {
	vector<Node*> que;
	int qh = 0;
	que.push_back(root);
	while (qh < que.size()) {
		Node*t = que[qh++];
		if (t->fail != 0) {
			t->fail->failCh.push_back(t);
		}
		for (int c = 0; c < CHARSET; ++c) {
			Node*v = t->ch[c];
			if (!v)
				continue;
			Node*f = t->fail;
			while (f && f->ch[c] == 0)
				f = f->fail;
			if (f == 0)
				v->fail = root;
			else
				v->fail = f->ch[c];
			que.push_back(v);
		}
	}
}

const int MAX_N = 100000 + 10;
const int MAX_LEN = int(1e6) + 10;

int n, k;

char buf[MAX_LEN];

Node*at[MAX_N];

struct TA {
	int*a, n;
	void init(int _n) {
		n = _n;
		a = new int[n];
		memset(a, 0, sizeof(int) * n);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	int get(int p) {
		int r = 0;
		for (p++; p; p -= p & -p)
			r += a[p - 1];
		return r;
	}
	void add(int l, int r, int x) {
		add(l, x);
		add(r, -x);
	}
} ta;

bool in[MAX_N];

int main() {
	root = new Node;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		scanf("%s", buf);
		int l = strlen(buf);
		Node*cur = root;
		for (int j = 0; j < l; ++j) {
			char c = buf[j];
			cur = cur->go(c - 'a');
		}
		at[i] = cur;
		in[i] = true;
	}
	build();
	cur = 0;
	root->dfs();
	ta.init(cur);

	for (int i = 0; i < k; ++i) {
		ta.add(at[i]->l, at[i]->r, 1);
	}

	for (int i = 0; i < n; ++i) {
		scanf(" ");
		char cmd;
		scanf("%c", &cmd);
		int who, l;
		switch (cmd) {
			case '+':
				scanf("%d", &who);
				--who;
				if (!in[who]) {
					ta.add(at[who]->l, at[who]->r, 1);
					in[who] = true;
				}
				break;
			case '-':
				scanf("%d", &who);
				--who;
				if (in[who]) {
					ta.add(at[who]->l, at[who]->r, -1);
					in[who] = false;
				}
				break;
			case '?': {
				scanf("%s", buf);
				l = strlen(buf);
				long long ans = 0;
				Node*cur = root;
				for (int j = 0; j < l; ++j) {
					int me = buf[j] - 'a';
					while (cur && cur->ch[me] == 0)
						cur = cur->fail;
					if (cur != 0)
						cur = cur->ch[me];
					else
						cur = root;
					ans += ta.get(cur->l);
				}
				cout << ans << endl;
				break;
			}
			default:
				break;
		}
	}
	return 0;
}