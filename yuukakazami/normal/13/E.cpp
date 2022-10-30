/*
 *  [Hnoi2010]Bounce .cpp
 *
 *  Created on: 2011-6-2
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define OUT(x) cout<<"HI:"<<x<<endl;
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N_NODES = 200000 + 10;
struct Node {
	Node*ch[2], *p;
	int size;
	bool isRoot;
	Node*pathFa;
	int id;
	Node() {
		isRoot = false;
		ch[0] = ch[1] = p = this;
		size = 0;
	}
	void update() {
		size = ch[0]->size + ch[1]->size + 1;
	}
	bool dir() {
		return this == p->ch[1];
	}
	void setC(Node*c, bool d) {
		ch[d] = c;
		c->p = this;
	}
	void setRoot(Node*_pathFa);
}*null = new Node;

void Node::setRoot(Node*_pathFa) {
	pathFa = _pathFa;
	p = null;
	isRoot = true;
}

Node* newNode(int _id) {
	Node*t = new Node;
	t->id = _id;
	t->isRoot = true;
	t->ch[0] = t->ch[1] = t->p = null;
	t->size = 1;
	t->pathFa = null;
	return t;
}

void rotate(Node*t) {
	Node*p = t->p;
	bool d = t->dir();
	p->p->setC(t, p->dir());
	p->setC(t->ch[!d], d);
	t->setC(p, !d);
	p->update();
	if (p->isRoot) {
		p->isRoot = false;
		t->isRoot = true;
		t->pathFa = p->pathFa;
	}
}

void splay(Node*t) {
	while (!t->isRoot) {
		if (t->p->isRoot)
			rotate(t);
		else if (t->dir() == t->p->dir())
			rotate(t->p), rotate(t);
		else
			rotate(t), rotate(t);
	}
	t->update();
}

void expose(Node*t) {
	for (Node*u = t, *v = null; u != null; v = u, u = u->pathFa) {
		splay(u);
		u->ch[1]->setRoot(u);
		v->isRoot = false;
		u->setC(v, 1);
		u->update();
	}
}

const int MAX_N = 100000 + 10;
Node*nodes[MAX_N];
int n;
Node*fa[MAX_N];

void setFather(int a, int b) {
	if (fa[a] != null) {
		expose(fa[a]);
	}
	splay(nodes[a]);
	fa[a] = nodes[a]->pathFa = (a + b <= n ? nodes[a + b] : null);
}

int main() {
	scanf("%d", &n);
	int nQ;
	scanf("%d", &nQ);
	for (int i = 1; i <= n; ++i) {
		nodes[i] = newNode(i);
	}
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		fa[i] = null;
		setFather(i, x);
	}
	for (int i = 0; i < nQ; ++i) {
		int cmd;
		scanf("%d", &cmd);
		if (cmd == 1) {
			int at;
			scanf("%d", &at);
			Node*t = nodes[at];
			expose(t);
			splay(t);
			while (t->ch[0] != null)
				t = t->ch[0];
			printf("%d %d\n", t->id, nodes[at]->ch[0]->size + 1);
		} else {
			int me, power;
			scanf("%d%d", &me, &power);
			setFather(me, power);
		}
	}
}