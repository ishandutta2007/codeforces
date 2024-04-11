#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;
const LL INF = 1e17 + 6;

struct Treap {
    Treap *lc,*rc;
    LL val;
    LL key;
    LL lmax,rmax,midmax,sum;
    int pri;
    Treap(LL _key,LL _val) {
        lc=rc=NULL;
        pri = rand();
        lmax=rmax=midmax=sum=val=_val;
        key = _key;
    }
};

LL Lmax(Treap* t) {
    return t?t->lmax:-INF;
}

LL Rmax(Treap* t) {
    return t?t->rmax:-INF;
}

LL Midmax(Treap* t) {
    return t?t->midmax:-INF;
}

LL Sum(Treap* t) {
    return t?t->sum:0;
}

void pull(Treap* t) {
    t->sum = Sum(t->lc) + Sum(t->rc) + t->val;
    t->lmax = max(max(Lmax(t->lc),Sum(t->lc)+t->val),Sum(t->lc)+t->val+Lmax(t->rc));
    t->rmax = max(max(Rmax(t->rc),Sum(t->rc)+t->val),Sum(t->rc)+t->val+Rmax(t->lc));
    t->midmax = max(max(max(Midmax(t->lc),Midmax(t->rc)),t->val),max(max(Rmax(t->lc)+t->val,Lmax(t->rc)+t->val),Lmax(t->rc)+Rmax(t->lc)+t->val));
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

void split(Treap* t,LL k,Treap* &a,Treap* &b) {
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

LL a[MAX_N];

Treap* root;

void add(int _key,LL _val) {
	Treap *tl;
	split(root,_key-1,tl,root);
	root = merge(tl,merge(new Treap(_key,_val),root));
}

void deleted(int _key) {
	Treap *tl,*tr;
	split(root,_key-1,tl,root);
	split(root,_key,root,tr);
	root = merge(merge(tl,root->lc),merge(root->rc,tr));
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		root=NULL;
		for (int i=1;n>=i;i++) {
			scanf("%lld",&a[i]);
		}
		LL mx=-INF;
		for (int i=1;n>i;i+=2) {
			if (i==1) {
				add(i,abs(a[i+1]-a[i]));
				mx = max(mx,root->midmax);
			}
			else {
				deleted(i-2);
				add(i-2,abs(a[i-2]-a[i-1]) - abs(a[i]-a[i-1]));
				add(i,abs(a[i+1]-a[i]));
				mx = max(mx,root->midmax);
			}
		}
		root=NULL;
		for (int i=2;n>i;i+=2) {
			if (i==2) {
				add(i,abs(a[i+1]-a[i]));
				mx = max(mx,root->midmax);
			}
			else {
				deleted(i-2);
				add(i-2,abs(a[i-2]-a[i-1]) - abs(a[i]-a[i-1]));
				add(i,abs(a[i+1]-a[i]));
				mx = max(mx,root->midmax);
			}
		}
		printf("%lld\n",mx);
	}
}