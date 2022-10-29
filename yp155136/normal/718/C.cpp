#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_P = 70;
const int MAX_N = 1e5+6;
const LL mod = 1e9 + 7;

struct _2_1 {
	LL a1,b1;
	void s(LL _a1,LL _b1) {
		a1 = _a1;
		b1 = _b1;
	}
};

struct _2_2 {
	LL a1,a2,b1,b2;
	void s(LL _a1,LL _a2,LL _b1,LL _b2) {
		a1 = _a1;
		a2 = _a2;
		b1 = _b1;
		b2 = _b2;
	}
};

_2_1 operator+(const _2_1 &e1,const _2_1 &e2) {
	_2_1 ret;
	ret.s((e1.a1 + e2.a1)%mod,(e1.b1 + e2.b1)%mod);
	return ret;
}

_2_1 operator*(const _2_2 &e1,const _2_1 &e2) {
	_2_1 ret;
	ret.s((e1.a1 * e2.a1 + e1.a2 * e2.b1)%mod,(e1.b1 * e2.a1 + e1.b2 * e2.b1) % mod);
	return ret;
}

_2_2 operator*(const _2_2 &e1,const _2_2 &e2) {
	_2_2 ret;
	ret.s((e1.a1 * e2.a1 + e1.a2 * e2.b1)%mod,(e1.a1 * e2.a2 + e1.a2 * e2.b2)%mod , 
	(e1.b1 * e2.a1 + e1.b2 * e2.b1)%mod,(e1.b1 * e2.a2 + e1.b2 * e2.b2)%mod);
	return ret;
}

struct Node {
	Node *lc;
	Node *rc;
	_2_1 val;
	_2_2 tag;
	Node() {
		lc=rc=NULL;
		val.s(0,0);
		tag.s(1,0,0,1);
	}
};

_2_1 pull(_2_1 lc,_2_1 rc) {
	return lc + rc;
}

_2_2 a[MAX_P];

void init() {
	a[0].s(1,1,1,0);
	for (int x=1;MAX_P>x;x++) {
		a[x] = a[x-1] * a[x-1];
	}
}

_2_2 g(LL n) {
	_2_2 ret;
	ret.s(1,0,0,1);
	int id=0;
	while (n>0) {
		int t=n%2;
		if (t) ret = a[id] * ret;
		id++;
		n/=2;
	}
	return ret;
}

_2_1 f(LL n) {
	_2_1 ret;
	ret.s(1,0);
	if (n==1) return ret;
	else return g(n-1)*ret;
}

LL v[MAX_N];

Node* Build(int L,int R) {
//	cout<<L<<" ~ "<<R<<endl;
	Node* node = new Node();
	if (L==R) {
		node->val = f(v[L]);
		return node;
	}
	int mid=(L+R)>>1;
	node->lc = Build(L,mid);
	node->rc = Build(mid+1,R);
	node->val = pull(node->lc->val,node->rc->val);
	return node;
}

void push(Node* node,int L,int R) {
	if (L != R) {
		node->rc->tag = node->tag * node->rc->tag;
		node->lc->tag = node->tag * node->lc->tag;
		node->lc->val = node->tag * node->lc->val;
		node->rc->val = node->tag * node->rc->val;
	}
	node->tag.s(1,0,0,1);
}

void modify(Node* node,int L,int R,int l,int r,int val) {
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		node->tag = node->tag * g(val);
		node->val = g(val) * node->val;
		return;
	}
	int mid=(L+R)>>1;
	push(node,L,R);
	modify(node->lc,L,mid,l,r,val);
	modify(node->rc,mid+1,R,l,r,val);
	node->val = pull(node->lc->val,node->rc->val);
	return;
}

_2_1 query(Node* node,int L,int R,int l,int r) {
	_2_1 ret;
	ret.s(0,0);
	if (l>R || L>r) return ret;
	else if (l<=L && R<=r) return node->val;
	push(node,L,R);
	int mid=(L+R)>>1;
	return pull(query(node->lc,L,mid,l,r) , query(node->rc,mid+1,R,l,r));
}

int main () {
	init();
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=1;n>=x;x++) scanf("%I64d",&v[x]);
		Node* root= Build(1,n);
		while (m--) {
			int i,j,k,l;
			scanf("%d %d %d",&i,&j,&k);
			if (i & 1) scanf("%d",&l);
			if (i&1) {
				modify(root,1,n,j,k,l);
			}
			else {
				_2_1 ret = query(root,1,n,j,k);
				printf("%I64d\n",ret.a1);
			}
		}
	}
}

/*

5 4
1 1 2 1 1
2 1 5
1 2 4 2
2 2 4
2 1 5

*/