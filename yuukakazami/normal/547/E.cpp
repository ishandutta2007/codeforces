#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(2e5) + 10;
const int MAX_Q = int(5e5) + 10;

const int MAX_LEN = MAX_N * 2;

struct State {
	State*suf, *go[27], *nxt;
	vector<State*> child;
	int rt, l, r;

	int val, cnt;
	State() :
			suf(0), val(0) {
		rt = -1;
		memset(go, 0, sizeof go);
	}
}*root, *last;
State statePool[MAX_LEN * 2], *cur;

void init() {
	cur = statePool;
	root = last = cur++;
}

void extend(int w, int pos) {
	State*p = last, *np = cur++;
	np->val = p->val + 1;
	np->cnt = 1;
	np->rt = pos;
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

int n, q;
int start[MAX_N], end[MAX_N]; //[l,r)
string str[MAX_N];
char buf[MAX_N];
int seq[MAX_LEN], pt;

void dfs(State*u) {
	u->l = pt;
	if (u->rt != -1)
		seq[pt++] = u->rt;

	for (vector<State*>::iterator e = u->child.begin(); e != u->child.end();
			++e) {
		dfs(*e);
	}

	u->r = pt;
}

long long answer[MAX_Q];

struct Query {
	int l, r, id;

	Query(int l, int r, int id) :
			l(l), r(r), id(id) {
	}
};

vector<Query> atk[MAX_N];

struct Event {
	int l, r, add, id; //[l,r]

	Event(int l, int r, int add, int id) :
			l(l), r(r), add(add), id(id) {
	}
};

vector<Event> atE[MAX_LEN];

void addEvent(int l, int r, int L, int R, int id) {
	atE[R].push_back(Event(l, r, 1, id));
	if (L > 0)
		atE[L - 1].push_back(Event(l, r, -1, id));
}

struct TA {
	int a[MAX_LEN], n;

	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof(int) * (n + 1));
	}

	void add(int p, int x) {
		for (++p; p <= n; p += p & -p)
			a[p] += x;
	}

	int get(int p) {
		int r = 0;
		for (++p; p; p -= p & -p)
			r += a[p];
		return r;
	}

	int get(int l, int r) {
		int ret = get(r);
		if (l > 0)
			ret -= get(l - 1);
		return ret;
	}
} ta;

int main() {
	init();
	cin >> n >> q;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		str[i] = buf;
		int L = strlen(buf);
		start[i] = cur;
		for (int j = 0; j < L; ++j) {
			extend(buf[j] - 'a', cur);
			++cur;
		}
		end[i] = cur;
		extend(26, cur);
		++cur;
	}

	//add child
	for (State*i = statePool; i != ::cur; ++i)
		if (i->suf)
			i->suf->child.push_back(i);

	dfs(root);

	for (int i = 0; i < q; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		--l, --r, --k;
		atk[k].push_back(Query(l, r, i));
	}

	for (int i = 0; i < n; ++i) {
		State*u = root;
		for (int j = 0; j < str[i].size(); ++j) {
			u = u->go[str[i][j] - 'a'];
		}

		for (vector<Query>::iterator e = atk[i].begin(); e != atk[i].end();
				++e) {
			int l = start[e->l];
			int r = end[e->r] - 1;
			//[l,r]
			addEvent(l, r, u->l, u->r - 1, e->id);
		}
	}

	ta.init(cur);

	for (int i = 0; i < pt; ++i) {
		ta.add(seq[i], 1);
		for (vector<Event>::iterator e = atE[i].begin(); e != atE[i].end();
				++e) {
			answer[e->id] += e->add * ta.get(e->l, e->r);
		}
	}

	for (int i = 0; i < q; ++i) {
//		printf("%I64d\n", answer[i]);
		cout << answer[i] << endl;
	}
}