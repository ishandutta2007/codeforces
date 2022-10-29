#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Treap {
	Treap *lc,*rc;
	int val,sz,pri;
	bool rev;
	Treap(int _val) : lc(NULL),rc(NULL),pri(rand()),sz(1),rev(0),val(_val) {
		
	}
};

int Sz(Treap* t) {
	return t?t->sz:0;
}

void pull(Treap* t) {
	if (!t) return;
	t->sz =Sz(t->lc) + Sz(t->rc) +1;
}

void push(Treap* t) {
	if (t->rev) {
		swap(t->lc,t->rc);
	}
	if (t->lc) {
		t->lc->rev ^= t->rev;
	}
	if (t->rc) {
		t->rc->rev ^= t->rev;
	}
	t->rev = 0;
}

Treap* merge(Treap* a,Treap* b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		push(a);
		a->rc=merge(a->rc,b);
		pull(a);
		return a;
	}
	else {
		push(b);
		b->lc=merge(a,b->lc);
		pull(b);
		return b;
	}
}

void split_by_sz(Treap* t,int k,Treap* &a,Treap* &b) {
	if (!t) a=b=NULL;
	else {
		push(t);
		if (Sz(t->lc) + 1 <= k) {
			a=t;
			split_by_sz(t->rc,k-Sz(t->lc)-1,a->rc,b);
			pull(a);
		}
		else {
			b=t;
			split_by_sz(t->lc,k,a,b->lc);
			pull(b);
		}
	}
}

void pprint(Treap* t) {
	if (!t) return;
	push(t);
	pprint(t->lc);
	cout<<t->val << ' ';
	pprint(t->rc);
}

int main () {
	srand(time(NULL));
	int n,q,m;
	scanf("%d %d %d",&n,&q,&m);
	Treap* root=NULL;
	for (int i=1;n>=i;i++) {
		int x;
		scanf("%d",&x);
		root=merge(root,new Treap(x));
	}
//	cout<<"now "<<" : ";pprint(root);cout<<endl;
	while (q--) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1) {
			Treap *tl,*tr;
			split_by_sz(root,b-1,tl,root);
			split_by_sz(root,(c-b+1),root,tr);
			Treap *tmp;
			split_by_sz(root,Sz(root)-1,root,tmp);
			root=merge(tmp,root);
			root=merge(tl,merge(root,tr));
		}
		else {
			Treap *tl,*tr;
			split_by_sz(root,b-1,tl,root);
			split_by_sz(root,(c-b+1),root,tr);
			root->rev ^= 1;
			root=merge(merge(tl,root),tr);
		}
	}
	while (m--) {
		int x;
		scanf("%d",&x);
		Treap *tl,*tr;
		split_by_sz(root,x-1,tl,root);
		split_by_sz(root,1,root,tr);
		printf("%d",root->val);
		if (m) printf(" ");
		root=merge(merge(tl,root),tr);
	}
	puts("");
}