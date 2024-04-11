#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <cstdlib>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

//const int MAX_NLOGN = MAX_N_VERTEXS * 20;

struct Tree;

struct Vertex {
	vector<Vertex*> adj;
	int value;

	int size, depth, ordInPath;

	Vertex*pathTop, *father;

	Tree*tree;

	void changeValue(int newValue);
};

const int MAX_N_VERTEXS = 100000 + 10;

Vertex vs[MAX_N_VERTEXS];
struct Node {
	Node*ch[2];
	int key, size;
	Vertex*value;

	Node(Vertex* _value);

	Node() {
		size = 0;
		key = INT_MAX;
	}

	void update() {
		size = ch[0]->size + ch[1]->size + 1;
	}
} Tnull, *null = &Tnull;

Node::Node(Vertex* _value) {
	value = _value;
	size = 1;
	key = rand();
	ch[0] = ch[1] = null;
}

bool cmp(Vertex*a, Vertex*b) {
	return a->value < b->value;
}

struct Treap {
	Node*root;
	int nSmall;

	Treap() {
		root = null;
		nSmall = 0;
	}

	void rotate(Node*&t, bool d) {
		Node*p = t->ch[d];
		t->ch[d] = p->ch[!d];
		p->ch[!d] = t;
		t->update();
		p->update();
		if (t == root)
			root = p;
		t = p;
	}

	void doInsert(Node*&t, Vertex* x) {
		if (t == null) {
			t = new Node(x);
			return;
		}
//		bool dir = x->value > t->value->value;
		bool dir = cmp(t->value, x);
		doInsert(t->ch[dir], x);
		if (t->ch[dir]->key < t->key)
			rotate(t, dir);
		else
			t->update();
	}

	void doErase(Node*&t, Vertex* x) {
		if (t == null)
			return;
		if (t->value == x) {
			bool dir = t->ch[1]->key < t->ch[0]->key;
			if (t->ch[dir] == null) {
				delete t;
				t = null;
				return;
			}
			rotate(t, dir);
			doErase(t->ch[!dir], x);
		} else {
			bool dir = cmp(t->value, x);
			doErase(t->ch[dir], x);
		}
		t->update();
	}

	int doCountSmall(Node*t, int x) { //<x
		if (t == null)
			return 0;
		if (t->value->value >= x) {
			return doCountSmall(t->ch[0], x);
		}
		return doCountSmall(t->ch[1], x) + 1 + t->ch[0]->size;
	}

	void insert(Vertex* x) {
		doInsert(root, x);
		--nSmall;
	}

	void erase(Vertex* x) {
		doErase(root, x);
	}

	int countSmall(int x) {
		return doCountSmall(root, x) + nSmall;
	}

	void debug(Node*t) {
		if (t == null)
			return;
		debug(t->ch[0]);
		cout << t->value - vs + 1 << endl;
		debug(t->ch[1]);
	}

	void debug() {

	}
};

Tree**seq;
int nSeq;
Tree*L[100000], *R[100000];
int nL, nR;

struct Tree {
	int left, right;
	Treap*treap;
	Vertex*at;

	Tree*ch[2];
	bool dir;

	Tree(Vertex* pathValue[], int _left, int _right) {
		left = _left;
		right = _right;
		//      cout << left << "-" << right << endl;
		int mid = left + right >> 1;

		treap = new Treap;
//		for (int i = left; i < right; ++i) {
//			treap->insert(pathValue[i]);
//		}
		treap->nSmall = right - left;

		if (left + 1 == right) {
			at = pathValue[left];
			return;
		}
		ch[0] = new Tree(pathValue, left, mid);
		ch[1] = new Tree(pathValue, mid, right);
	}

	int countSmall(int askLeft, int askRight, int x) {
		if (askRight <= left || right <= askLeft)
			return 0;
		if (askLeft <= left && askRight >= right)
			return treap->countSmall(x);
		int ret = 0;
		for (int c = 0; c < 2; ++c) {
			ret += ch[c]->countSmall(askLeft, askRight, x);
		}
		return ret;
	}

	void get(int askLeft, int askRight) {
		if (askRight <= left || right <= askLeft)
			return;
		if (askLeft <= left && askRight >= right) {
			seq[nSeq++] = this;
			return;
		}
		for (int c = 1; c >= 0; --c) { //back to up
			ch[c]->get(askLeft, askRight);
		}
	}

	void changeE(int at, Vertex*x) {
		if (at < left || at >= right)
			return;
		treap->erase(x);
		if (left + 1 == right)
			return;
		for (int c = 0; c < 2; ++c) {
			ch[c]->changeE(at, x);
		}
	}
	void changeA(int at, Vertex*x) {
		if (at < left || at >= right)
			return;
		treap->insert(x);
		if (left + 1 == right)
			return;
		for (int c = 0; c < 2; ++c) {
			ch[c]->changeA(at, x);
		}
	}
	Vertex*find(int k, int y) { //kth <y
		if (left + 1 == right)
			return at;
		ch[0]->dir = ch[1]->dir = dir;
		if (dir == 0) { //L
			int c = ch[1]->treap->countSmall(y);
			if (c >= k)
				return ch[1]->find(k, y);
			else
				return ch[0]->find(k - c, y);
		} else {
			int c = ch[0]->treap->countSmall(y);
			if (c >= k)
				return ch[0]->find(k, y);
			else
				return ch[1]->find(k - c, y);
		}
	}
	void debug() {
		if (left + 1 == right) {
			cout << treap->root->value - vs + 1 << " ";
		} else {
			ch[!dir]->debug();
			ch[dir]->debug();
		}
	}
};

void Vertex::changeValue(int newValue) {
//	pathTop->tree->changeE(ordInPath, this);
	value = newValue;
	pathTop->tree->changeA(ordInPath, this);
}

int nVertexs, nQueries;

inline void scanInt(int&x) {
	scanf("%d", &x);
}

void readInput() {
	scanInt(nVertexs);
	for (int i = 0; i < nVertexs; ++i) {
		Vertex*v = vs + i;
		v->value = -i;
		v->adj.clear();
	}
	for (int i = 0; i < nVertexs; ++i) {
		int p;
		scanInt(p);
		--p;
		if (p >= 0) {
			Vertex*u = vs + i, *v = vs + p;
			u->adj.push_back(v);
			v->adj.push_back(u);
		}
	}
}

Vertex*bfsOrd[MAX_N_VERTEXS];

void doBFS(Vertex*vs, Vertex* que[]) {
	vs->father = 0;
	vs->depth = 0;
	int qh = 0, qt = 0;
	que[qt++] = vs;
	while (qh < qt) {
		Vertex*u = que[qh++];
		foreach(iter,u->adj) {
			Vertex*v = *iter;
			if (v == u->father)
				continue;
			v->father = u;
			v->depth = u->depth + 1;
			que[qt++] = v;
		}
	}
}

Vertex* pathValue[MAX_N_VERTEXS];
void doSplitPath() {
	for (int i = 0; i < nVertexs; ++i) {
		Vertex*v = vs + i;
		v->pathTop = 0;
	}

	for (int at = nVertexs - 1; at >= 0; --at) {
		Vertex*u = bfsOrd[at];
		u->size = 1;
		foreach(iter,u->adj) {
			Vertex*v = *iter;
			if (v == u->father)
				continue;
			u->size += v->size;
		}
	}

	for (int at = 0; at < nVertexs; ++at) {
		Vertex*top = bfsOrd[at];
		if (top->pathTop != 0)
			continue;

		int cnt = 0;
		for (Vertex*u = top; u != 0;) {
			u->ordInPath = cnt;
			u->pathTop = top;
			pathValue[cnt++] = u;

			Vertex*next = 0;
			foreach(iter,u->adj) {
				Vertex*v = *iter;
				if (v == u->father)
					continue;
				if (next == 0 || v->size > next->size)
					next = v;
			}

			u = next;
		}

		top->tree = new Tree(pathValue, 0, cnt);
	}
}

int countSmallPath(Vertex*u, Vertex*v, int x) {
	int ret = 0;
	for (;;) {
		if (u->pathTop == v->pathTop) {
			if (u->depth < v->depth)
				swap(u, v);
			ret += u->pathTop->tree->countSmall(v->ordInPath, u->ordInPath + 1, x);
			return ret;
		} else {
			if (u->pathTop->depth < v->pathTop->depth)
				swap(u, v);
			ret += u->pathTop->tree->countSmall(0, u->ordInPath + 1, x);
			u = u->pathTop->father;
		}
	}
	return ret;
}

Tree*all[1000000];
int nAll;
void getPath(Vertex*u, Vertex*v) {
	bool swaped = false;
	nL = nR = 0;
	for (;;) {
		if (u->pathTop == v->pathTop) {
			if (u->depth < v->depth)
				swap(u, v), swaped ^= 1;
			if (!swaped) { //u
				nSeq = nL, seq = L;
				u->pathTop->tree->get(v->ordInPath, u->ordInPath + 1);
				nL = nSeq;
//				ret += u->pathTop->tree->countSmall(v->ordInPath, u->ordInPath + 1, x);
			} else {
				nSeq = nR, seq = R;
				u->pathTop->tree->get(v->ordInPath, u->ordInPath + 1);
				nR = nSeq;
			}
			break;
		} else {
			if (u->pathTop->depth < v->pathTop->depth)
				swap(u, v), swaped ^= 1;
			if (!swaped) {
				nSeq = nL, seq = L;
				u->pathTop->tree->get(0, u->ordInPath + 1);
				nL = nSeq;
			} else {
				nSeq = nR, seq = R;
				u->pathTop->tree->get(0, u->ordInPath + 1);
				nR = nSeq;
			}
			u = u->pathTop->father;
		}
	}

	nAll = 0;
	for (int i = 0; i < nL; ++i) {
		L[i]->dir = 0;
		all[nAll++] = L[i];
	}
	for (int i = nR - 1; i >= 0; --i) {
		R[i]->dir = 1;
//		R[i]->debug();
//		cout << endl;
		all[nAll++] = R[i];
	}
}

void solve(Vertex*u, Vertex*v, int y, int k) {
//	int cnt = countSmallPath(u, v, y);
//	if (cnt < k) {
//		puts("-1");
//		return;
//	} else {
	getPath(u, v); //u->v
	int cur = k + (u->value < y);
	for (int i = 0; i < nAll; ++i) {
//			cout << cur << endl;
//			cout << "HI" << endl;
//			all[i]->debug();
//			cout << "END" << endl;
		int pre = cur;
		cur -= all[i]->treap->countSmall(y);
		if (cur <= 0) {
			Vertex*ans = all[i]->find(pre, y);
			if (ans == v) {
				puts("-1");
			} else {
				printf("%d\n", ans - vs + 1);
			}
			return;
		}
	}
	puts("-1");
}

void answerQueries() {
	cin >> nQueries;
	for (int i = 1; i <= nQueries; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int c;
			scanf("%d", &c);
			--c;
			vs[c].changeValue(i);
		} else {
			int a, b, k, y;
			scanf("%d%d%d%d", &a, &b, &k, &y);
			--a, --b;
			++y;
			//<y
			Vertex*u = vs + a, *v = vs + b;
			solve(u, v, y, k);
		}
	}
}

void prepare() {
	doBFS(vs + 0, bfsOrd);
	doSplitPath();
}

int main() {
	readInput();
	prepare();
	answerQueries();
}