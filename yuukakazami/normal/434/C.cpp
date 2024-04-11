#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 200 + 10;
const int MAX_M = 20 + 1;
const int MAX_K = 500 + 10;
const int MOD = 1000000007;
int n, m, k;

const int CHARSET = 20;
const int MAX_N_NODES = int(3e5) + 10;

int pointer;
struct Node {
	Node*ch[CHARSET], *fail, *par;
	Node*jump[CHARSET];

	int end;
	Node() {
		memset(ch, 0, sizeof ch);
		fail = 0;
		end = 0;
	}
	Node*go(int w);
}*root;

Node nodePool[MAX_N_NODES], *cur;
const int MAX_ID = 400 + 10;

int getId(Node*u) {
	return u - nodePool;
}

Node*newNode() {
	Node*t = cur++;
	memset(t->ch, 0, sizeof t->ch);
	t->fail = 0;
	return t;
}

Node* Node::go(int w) {
	if (ch[w] == 0) {
		ch[w] = newNode();
		ch[w]->par = this;
	}
	return ch[w];
}

void init() {
	cur = nodePool;
	root = newNode();
	root->par = 0;
}

void build() {
	static Node*que[MAX_N_NODES];
	int qh = 0, qt = 0;
	que[qt++] = root;
	while (qh < qt) {
		Node*t = que[qh++];
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
			que[qt++] = v;
		}
	}
	//calculate JUMP
	for (int j = 0; j < m; ++j) {
		root->jump[j] = root->ch[j] ? root->ch[j] : root;
//		if (root->jump[j] == 0)
//			root->jump[j] = root;
	}

	for (int i = 1; i < qt; ++i) {
		Node*u = que[i];
		for (int j = 0; j < m; ++j) {
			if (u->ch[j])
				u->jump[j] = u->ch[j];
			else
				u->jump[j] = u->fail->jump[j];
		}
	}

	for (int i = 0; i < qt; ++i) {
		Node*u = que[i];
		if (u->fail)
			u->end += u->fail->end;
	}
}

vector<int> L, R;

vector<int> str[MAX_N];
int v[MAX_N];

void read(vector<int>&arr) {
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

int memo[202][410][501];

int rec(int at, bool leadingZero, bool sameL, bool sameR, Node*u, int have) {
	have += u->end;
	if (have > k)
		return 0;

	if (at == L.size()) {
		return 1;
	}

	bool save = !(sameL || sameR);
	int ret = 0;
	if (save) {
		ret = memo[at][getId(u)][have];
		if (ret != -1)
			return ret;
		ret = 0;
	}

	for (int nxt = 0; nxt < m; ++nxt) { //nxt digit
		if (sameL && nxt < L[at])
			continue;
		if (sameR && nxt > R[at])
			continue;
		Node*nu = u;
		if (!leadingZero || nxt > 0)
			nu = u->jump[nxt];

		ret += rec(at + 1, leadingZero && (nxt == 0), sameL && (nxt == L[at]),
				sameR && (nxt == R[at]), nu, have);
		if (ret >= MOD)
			ret -= MOD;
	}

	if (save) {
		memo[at][getId(u)][have] = ret;
	}

	return ret;
}

int main() {
//	cout << sizeof(memo) / (1024 * 1024.0) << endl;
	cin >> n >> m >> k;
	read(L), read(R);
	while (L.size() < R.size())
		L.insert(L.begin(), 0);

	for (int i = 0; i < n; ++i) {
		read(str[i]);
		cin >> v[i];
	}
	init();
	for (int i = 0; i < n; ++i) {
		Node*u = root;
		for (int j = 0; j < str[i].size(); ++j) {
			u = u->go(str[i][j]);
		}
		u->end += v[i];
	}
	build();
	memset(memo, -1, sizeof memo);
	int ans = rec(0, true, true, true, root, 0);
	cout << ans << endl;
}