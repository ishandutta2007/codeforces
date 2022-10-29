#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Val {
	int gcd;
	int num;
	void change(int Gcd,int Num) {
		gcd = Gcd;
		num = Num;
	}
};

Val empty;

bool operator ==(const Val& v1, const Val& v2) {
	return v1.gcd==v2.gcd && v1.num==v2.num;
}

Val PULL(Val a,Val b) {
	if (a==empty) return b;
	else if (b==empty) return a;
	int g1=a.gcd,n1=a.num;
	int g2=b.gcd,n2=b.num;
	int g=__gcd(g1,g2);
	Val val;
	if (g1==g2) {
		val.gcd=g1;
		val.num=n1+n2;
	}
	else if (g1==g) {
		val.gcd=g;
		val.num=n1;
	}
	else if (g2==g) {
		val.gcd=g;
		val.num=n2;
	}
	else {
		val.gcd=g;
		val.num=0;
	}
	return val;
}

struct Node {
	Node* lc;
	Node* rc;
	Val val;
	Node() {
		lc = rc=NULL;
		val.change(1,0);
	}
	void pull() {
		val = PULL(lc->val,rc->val);
	}
};

const int MAX_N = 100005;
int v[MAX_N];

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) {
		node->val.change(v[L],1);
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
	return node;
}

Val query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return empty;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return PULL(query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r));
}

int main () {
	empty.gcd=2147483647;
	empty.num=2147483647;
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) scanf("%d",&v[x]);
		Node* root = Build(1,n);
		int m;
		scanf("%d",&m);
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			printf("%d\n",(j-i+1) -query(root,1,n,i,j).num);
		}
	}
}