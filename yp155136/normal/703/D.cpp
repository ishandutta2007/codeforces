#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

const int MAX_N = 1e6 + 4;

struct Q {
	int l;
	int r;
	int q;
	void input(int _q) {
		scanf("%d %d",&l,&r);
		q=_q;
	}
} q[MAX_N];

bool operator<(const Q &n1,const Q &n2) {
	return n1.r < n2.r;
} 

int a[MAX_N];
int pre[MAX_N];
int ans[MAX_N];
map<int,int> last;

struct Node {
	Node* lc;
	Node* rc;
	int val;
	Node() {
		lc=rc=NULL;
		val = 0;
	}
	void pull() {
		val = lc->val ^ rc->val;
	}
};

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) {
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
	return node;
}

void modify(Node* node,int L,int R,int pos,int val) {
	if(L==R) {
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
//	cout<<
	if (L>r || l>R) return 0;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) ^ query(node->rc,mid+1,R,l,r);
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			pre[x] = pre[x-1] ^ a[x];
		}
		int m;
		scanf("%d",&m);
		for (int x=1;m>=x;x++) {
			q[x-1].input(x);
		}
//		for (int x=1;n>=x;x++) cout<<pre[x]<<' ';
		sort(q,q+m);
		Node* root=Build(1,n);
		int nowr=0;
		for (int x=0;m>x;x++) {
			int tmpr=q[x].r;
			for (int y=nowr+1;tmpr>=y;y++) {
				if (last[a[y]] != 0)modify(root,1,n,last[a[y]],0);
				modify(root,1,n,y,a[y]);
				last[a[y]] = y;
			}
			nowr=tmpr;
//			cout << pre[q[x].r] << ' '<<pre[q[x].l - 1] << ' '<< query(root,1,n,q[x].l,q[x].r)<<endl;
			ans[q[x].q] = pre[q[x].r] ^ pre[q[x].l - 1] ^ query(root,1,n,q[x].l,q[x].r);
		}
		for (int x=1;m>=x;x++) {
			printf("%d\n",ans[x]);
		}
	}
}