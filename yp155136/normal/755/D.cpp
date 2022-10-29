#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

struct Node {
	Node* lc;
	Node* rc;
	int val;
	Node() {
		lc=rc=NULL;
		val=0;
	}
	void pull() {
		val = lc->val + rc->val;
	}
};

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R){
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

void modify(Node* node,int L,int R,int pos,int val) {
	if (L==R) {
		node->val = val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos,val);
	else modify(node->rc,mid+1,R,pos,val);
	node->pull();
	return;
}

int query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

Node* root;

LL Val(int L,int R,int n) {
	if (R<L) return query(root,1,n,L,n) + query(root,1,n,1,R);
	else return query(root,1,n,L,R);
}

LL f(int a,int n) {
	if (a>n) return a-n;
	else return a;
}

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		if (k>n/2) k=n-k;
		root = Build(1,n);
		modify(root,1,n,1,1);
		LL ans=1;
		LL id=1;
		for (int x=0;n>x;x++) {
			//cout<<"id = "<<id<<endl;
			ans++;
			int nxt=f(id+k,n);
			ans += Val(f(id+1,n),f(nxt-1,n),n);
			//cout<<"value = "<<Val(id,nxt,n)<<endl;
			modify(root,1,n,nxt,2);
			id = nxt;
			if (x!=0) printf(" ");
			printf("%I64d",ans);
		}
		puts("");
	}
}