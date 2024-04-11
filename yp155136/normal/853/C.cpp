#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

typedef long long LL;

struct Node {
	Node *lc,*rc;
	LL val;
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
	if (L==R) return node;
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

Node* getNode(Node* old) {
	Node* node = new Node();
	node->lc=old->lc;
	node->rc=old->rc;
	node->val = old->val;
	return node;
}

void modify(Node* node,Node* old,int L,int R,int pos,LL val) {
	if (L==R) {
		node->val += val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos <= mid) {
		node->lc = getNode(old->lc);
		modify(node->lc,old->lc,L,mid,pos,val);
	}
	else {
		node->rc = getNode(old->rc);
		modify(node->rc,old->rc,mid+1,R,pos,val);
	}
	node->pull();
	return;
}

LL query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->val;
	int mid= (L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

const int MAX_N = 2e5 + 6;
int p[MAX_N];
Node* root[MAX_N];

int main () {
	int n,q;
	scanf("%d %d",&n,&q);
	root[0] = Build(1,n);
	for (int i=1;n>=i;i++) {
		scanf("%d",&p[i]);
		root[i] = getNode(root[i-1]);
		modify(root[i],root[i-1],1,n,p[i],1);
	}
	while (q--) {
		int l,d,r,u;
		scanf("%d %d %d %d",&l,&d,&r,&u);
		swap(l,d);
		swap(r,u);
		LL ans=0;
		ans = n*1LL*(n-1)/2;
		LL ll=l-1,rr=n-r;
		ans -= (ll*(ll-1))/2;
		ans -= (rr*(rr-1))/2;
		LL dd=d-1,uu=n-u;
		ans -= (dd*(dd-1))/2;
		ans -= (uu*(uu-1))/2;
		LL ld=query(root[d-1],1,n,1,l-1),rd=query(root[d-1],1,n,r+1,n);
		ans += (ld*(ld-1))/2;
		ans += (rd*(rd-1))/2;
		LL lu=query(root[n],1,n,1,l-1)-query(root[u],1,n,1,l-1);
		LL ru=query(root[n],1,n,r+1,n)-query(root[u],1,n,r+1,n);
		ans += (lu*(lu-1))/2;
		ans += (ru*(ru-1))/2;
		printf("%lld\n",ans);
	}
}