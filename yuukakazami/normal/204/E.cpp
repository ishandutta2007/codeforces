#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<int>*merge(set<int>*a, set<int>*b) {
	if (a->size() < b->size())
		swap(a, b);
	a->insert((*b).begin(), (*b).end());
	delete b;
	return a;
}

struct Node {
	Node*go[27], *par;
	int val, id;
	vector<Node*> ch;
	Node() {
		memset(go, 0, sizeof go);
		val = 0;
		par = 0;
		id = -1;
	}
	int nInclude;
	set<int>* dfs() {
		set<int>*st = new set<int>();
		if (id != -1) {
			st->insert(id);
		}
		for (vector<Node*>::iterator it = ch.begin(); it != ch.end(); ++it) {
			st = merge(st, (*it)->dfs());
		}
		nInclude = st->size();
		return st;
	}
};
const int MAX_N = int(1e5) + 10;
const int MAX_LEN = MAX_N * 2;
const int MAX_N_STATES = MAX_LEN * 2;

Node nodePool[MAX_N_STATES], *cur = nodePool;
Node*root, *last;

void init() {
	root = last = cur++;
}

void extend(int w, int id = -1) {
	Node*p = last, *np = cur++;
	np->val = p->val + 1;
	np->id = id;
	while (p && p->go[w] == 0)
		p->go[w] = np, p = p->par;
	if (p == 0)
		np->par = root;
	else {
		Node*q = p->go[w];
		if (q->val == p->val + 1)
			np->par = q;
		else {
			Node*nq = cur++;
			memcpy(nq->go, q->go, sizeof q->go);
			nq->val = p->val + 1;
			nq->par = q->par;
			q->par = np->par = nq;
			while (p && p->go[w] == q)
				p->go[w] = nq, p = p->par;
		}
	}
	last = np;
}

string a[MAX_N];
int n, k;

int main() {
	init();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < a[i].size(); ++j) {
			extend(a[i][j] - 'a', i);
		}
		extend(26);
	}
	for (Node*i = nodePool; i != cur; ++i)
		if (i->par)
			i->par->ch.push_back(i);
	root->dfs();
	for (int i = 0; i < n; ++i) {
		string&s = a[i];
		int l = 0;
		Node*c = root;
		long long ans = 0;
		for (int j = 0; j < s.size(); ++j) {
			int w = s[j] - 'a';
			while (c && c->go[w] == 0) {
				c = c->par;
				if (c)
					l = c->val;
			}
			if (c) {
				c = c->go[w];
				++l;
			} else {
				c = root;
				l = 0;
			}
			while (c && c->nInclude < k) {
				c = c->par;
				if (c)
					l = c->val;
				else
					l = 0;
			}
			ans += l;
		}
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}