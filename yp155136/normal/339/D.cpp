#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct Node {
	Node* lc;
	Node* rc;
	int val;
	Node() {
		lc=rc=NULL;
		val=0;
	}
	void pull(int depth) {
		if (depth%2==0) val = (lc->val | rc->val);
		else if (depth%2==1) val = (lc->val ^ rc->val);
	}
};

const int MAX_N = 140000;
int v[MAX_N];

Node* Build(int L,int R,int depth) {
	Node* node= new Node();
	if (L==R) {
		node->val = v[L];
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid,depth-1);
	node->rc=Build(mid+1,R,depth-1);
	node->pull(depth);
//	cout<<L<<"~"<<R<<" : "<<node->val<<endl;
	return node;
}

void modify(Node* node,int L,int R,int pos,int Val,int depth) {
	if (L==R) {
		node->val=Val;
//		cout <<L<<" change to "<<node->val <<endl;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos,Val,depth-1);
	else if (pos>mid) modify(node->rc,mid+1,R,pos,Val,depth-1);
	node->pull(depth);
//	cout<<"node->pull("<<depth<<")\n";
//	cout<<L<<"~"<<R<< " : "<<node->val<<endl;;
}

int query(Node* node,int L,int R,int l,int r) {
	return node->val;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
//		cout << (1<<n) << endl;
		for (int x=1;(1<<n)>=x;x++) scanf("%d",&v[x]);
		Node* root = Build(1,(1<<n),n-1);
		for (int x=0;m>x;x++) {
//			cout<<"x = "<<x<<endl;
			int p,b;
			scanf("%d %d",&p,&b);
			modify(root,1,(1<<n),p,b,n-1);
			printf("%d\n",query(root,1,n,1,n));
		}
	}
}