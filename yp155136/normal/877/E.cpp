#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;

struct Treap {
	Treap *lc,*rc;
	char val;
	int sum;
	int key;
	short pri;
	Treap(int _val,int _key) {
		lc=rc=NULL;
		val = _val;
		sum = _val;
		key = _key;
		pri = rand();
	}
};

int Sum(Treap* t) {
	return t?t->sum:0;
}

void pull(Treap* t) {
	if (!t) return;
	t->sum = Sum(t->lc) + Sum(t->rc) + t->val;
}

Treap* merge(Treap* a,Treap* b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		a->rc=merge(a->rc,b);
		pull(a);
		return a;
	}
	else {
		b->lc=merge(a,b->lc);
		pull(b);
		return b;
	}
}

void split(Treap* t,int k,Treap* &a,Treap* &b) {
	if (!t) a=b=NULL;
	else if (t->key <= k) {
		a=t;
		split(t->rc,k,a->rc,b);
		pull(a);
	}
	else {
		b=t;
		split(t->lc,k,a,b->lc);
		pull(b);
	}
}

Treap *root,*unroot;

const int MAX_N = 2e5 + 6;
vector<int> edg[MAX_N];

int stamp=0;
int p[2*MAX_N];
int p2[2*MAX_N];
int pin[MAX_N],pout[MAX_N];
int clr[MAX_N];

void dfs(int id) {
	++stamp;
	pin[id] = stamp;
	p[stamp] = clr[id];
	p2[stamp] = 1-clr[id];
//	stamp++;
	for (int i:edg[id]) {
		dfs(i);
	}
	++stamp;
	pout[id] = stamp;
	p[stamp] = 0;
	p2[stamp] = 0;
//	stamp++;
}

int main () {
	srand(time(NULL));
	int n;
	scanf("%d",&n);
	for (int i=2;n>=i;i++) {
		int x;
		scanf("%d",&x);
		edg[x].push_back(i);
	}
	for (int i=1;n>=i;i++) {
		scanf("%d",&clr[i]);
	}
	dfs(1);
	assert(stamp==2*n);
	root = unroot = NULL;
	for (int i=1;stamp>=i;i++) {
//		cout<<"i = "<<i<<" , p = "<<p[i]<<endl;
		root = merge(root,new Treap(p[i],i));
		unroot = merge(unroot,new Treap(p2[i],i));
	}
	int q;
	scanf("%d\n",&q);
	while (q--) {
		char c[6];
		scanf("%s",c);
		int x;
		scanf("%d",&x);
//		cout<<"c = "<<c<<" , x = "<<x<<endl;
		if (c[0] == 'g') {
			Treap *tl,*tr;
//			cout<<"pin = "<<pin[x]<<" , pout = "<<pout[x]<<endl;
			split(root,pin[x]-1,tl,root);
			split(root,pout[x],root,tr);
			int ans=Sum(root);
			root=merge(merge(tl,root),tr);
			printf("%d\n",ans);
		}
		else {
			Treap *tl,*tr,*mid;
			split(root,pin[x]-1,tl,root);
			split(root,pout[x],root,tr);
			Treap *_tl,*_tr,*_mid;
			split(unroot,pin[x]-1,_tl,unroot);
			split(unroot,pout[x],unroot,_tr);
			mid = root;
			_mid = unroot;
			root=merge(tl,merge(_mid,tr));
			unroot=merge(_tl,merge(mid,_tr));
		}
	}
}