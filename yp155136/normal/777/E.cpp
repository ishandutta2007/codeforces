#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const LL INF = 1e15 + 7;

struct Treap {
	Treap *lc,*rc;
	LL mx;
	LL key;
	LL pri;
	LL val;
	Treap(LL _key,LL _val) {
		lc=rc=NULL;
		mx = _val;
		val = _val;
		key = _key;
		pri = rand();
	}
};

LL Mx(Treap* t) {
	return t?t->mx:0;
}

void pull(Treap* t) {
	if (!t) return;
	t->mx = max(max(Mx(t->lc),Mx(t->rc)),t->val);
}

Treap* merge(Treap* a,Treap* b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri)  {
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

Treap* root;

struct _ {
	LL a,b,h;
	void __() {
		scanf("%I64d %I64d %I64d",&a,&b,&h);
	}
	void ___() {
		cout<<a<<' '<<b<<' '<<h<<endl;
	}
} ipt[MAX_N];

bool operator<(const _ &p1,const _ &p2) {
	return p1.b > p2.b || p1.b==p2.b && p1.a>p2.a || p1.b==p2.b && p1.a==p2.a && p1.h>p2.h;
}

LL dp[MAX_N];

void add(LL _key,LL _val) {
	Treap* tl;
	split(root,_key,tl,root);
	root = merge(merge(tl,new Treap(_key,_val)),root);
}

LL Q(LL _key) {
	Treap *tl;
	split(root,_key-1,tl,root);
	LL ret = Mx(tl);
	root = merge(tl,root);
	return ret;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		root=NULL;
		for (int i=1;n>=i;i++) {
			ipt[i].__();
		}
		sort(ipt+1,ipt+n+1);
		LL ans=-1;
		for (int i=1;n>=i;i++) {
//			cout<<"i = "<<i<<" : ";
//			ipt[i].___();
			dp[i] = Q(ipt[i].b) + ipt[i].h;
//			cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
			ans = max(ans,dp[i]);
			add(ipt[i].a,dp[i]);
		}
		printf("%I64d\n",ans);
	}
}