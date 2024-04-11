#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5+6;
const LL INF = 1e15+6;

int a[MAX_N];

struct Node {
	Node *lc,*rc;
	LL val;
	Node() {
		lc=rc=NULL;
		val = INF;
	}
	void pull() {
		val = min(lc->val,rc->val);
	}
};

Node* Build(int L,int R) {
	Node* node=  new Node();
	if (L==R) {
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

void modify(Node* node,int L,int R,int pos,LL val) {
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

LL query(Node* node,int L,int R,int l,int r) {
	if (L>r || l>R) return INF;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return min(query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r));
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>x;x++) {
			scanf("%d",&a[x]);
		}
		a[n] = n;
		LL ans=0;
		Node* root = Build(1,n);
		modify(root,1,n,n,n);
		for (int i=n-1;i>=1;i--) {
			LL dp = n + query(root,1,n,i+1,a[i]) - i - a[i];
			ans += dp;
			modify(root,1,n,i,dp+i);
		}
		printf("%I64d\n",ans);
	}
}