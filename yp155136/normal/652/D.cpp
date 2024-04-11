#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;
const int MAX_N = 2e5 + 10;

piii node[MAX_N];
int ans[MAX_N];

struct Treap {
	Treap* lc;
	Treap* rc;
	int pri;
	int key;
	int val;
	Treap(int _key) {
		lc=rc=NULL;
		pri=rand();
		key=_key;
		val = 1;
	}
};

int Val(Treap* t) {
	return t?t->val:0;
}

void pull(Treap *t) {
	t->val = Val(t->lc) + Val(t->rc) + 1;
}

Treap* merge(Treap* a,Treap* b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		a->rc = merge(a->rc,b);
		pull(a);
		return a;
	}
	else {
		b->lc = merge(a,b->lc);
		pull(b);
		return b;
	}
}

void split(Treap* t,int k,Treap* &a,Treap* &b) {
//	cout<<"in split\n";
	if (!t) {
//		cout<<"in1\n";
		a=b=NULL;
	}
	else if (t->key <= k) {
//		cout<<"in2\n";
		a=t;
		split(t->rc,k,a->rc,b);
		if (a) pull(a);
	}
	else {
//		cout<<"in3\n";
		b=t;
		split(t->lc,k,a,b->lc);
		if (b) pull(b);
	}
}

Treap* root;

void add (int k) {
//	cout<<"k="<<k<<endl;
	Treap *tl,*tr;
//	cout<<"in\n";
//	if (!root) cout<<"nothing no root\n";
	split(root,k-1,tl,root);
//	cout<<"in\n";
	split(root,k,root,tr);
//	assert(root==NULL);
//	cout<<"in\n";
	root = merge(merge(tl,new Treap(k)),tr);
//	cout<<"root->val = "<<root->key<<endl;
	pull(root);
}

int query (int R) {
//	cout<<"R = "<<R<<endl;
	Treap *tl;
	split(root,R,tl,root);
	if (tl) pull(tl);
	int ret=Val(tl);
	root = merge(tl,root);
//	cout<<"ret = "<<ret<<endl;
	return ret;
}

void remove(int k) {
//	cout<<"in\n";
	Treap *tl,*tr;
	split(root,k-1,tl,root);
	split(root,k,root,tr);
//	assert(root!=NULL);
	root = merge(tl,tr);
	if (root) pull(root);
}

int main () {
	srand(time(NULL));
	int n;
	while (scanf("%d",&n) != EOF) {
		root=NULL;
		for (int x=0;n>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			node[x]=make_pair(make_pair(i,j),x);
		}
		sort(node,node+n);
//		for (int x=0;n>x;x++) {
//			cout<<node[x].first.first << ' '<<node[x].first.second << ' '<<node[x].second<<endl;
//		}
		for (int x=0;n>x;x++) {
			add((node[x].first).second);
//			cout<<"x="<<x<<endl;
		}
		for (int x=0;n>x;x++) {
			remove((node[x].first).second);
//			cout<<"x="<<x<<endl;
//			cout<<" ~ = "<<node[x].second<<endl;
			ans[node[x].second] = query((node[x].first).second);
		}
		for (int x=0;n>x;x++) {
			printf("%d\n",ans[x]);
		}
	}
}