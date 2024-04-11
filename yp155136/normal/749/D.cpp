#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

vector<int> num[MAX_N];
int mx[MAX_N];

struct Node {
	Node *lc,*rc;
	pii val;
	Node() {
		lc=rc=NULL;
		val=make_pair(0,0);
	}
	void pull() {
		val = max(lc->val,rc->val);
	}
};

Node* Build(int L,int R) {
	Node *node= new Node();
	if (L==R) {
		node->val = make_pair(mx[L],L);
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
	return node;
}

void modify(Node* node,int L,int R,int pos,int val ) {
	if (L==R) {
		node->val = make_pair(val,pos);
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos,val);
	else modify(node->rc,mid+1,R,pos,val);
	node->pull();
	return;
}

pii query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return make_pair(0,0);
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return max(query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r));
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			num[i].clear();
			mx[i]=0;
		}
		for (int i=1;n>=i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			num[a].push_back(b);
			mx[a] = b;
		}
		Node *root = Build(1,n);
		int q;
		scanf("%d",&q);
		while (q--) {
			int _;
			scanf("%d",&_);
			vector<int> v;
			for (int i=0;_>i;i++) {
				int __;
				scanf("%d",&__);
				v.push_back(__);
				modify(root,1,n,__,0);
			}
			pii ret=query(root,1,n,1,n);
			if (ret.first == 0) {
				puts("0 0");
			}
			else {
				int _0=ret.first,_1=ret.second;
				modify(root,1,n,_1,0);
				pii ret2=query(root,1,n,1,n);
				printf("%d %d\n",_1,num[_1][(lower_bound(num[_1].begin(),num[_1].end(),ret2.first)-num[_1].begin())]);
				modify(root,1,n,_1,mx[_1]);
			}
			for (int i=0;_>i;i++) {
				int __ = v[i];
				modify(root,1,n,__,mx[__]);
			}
		}
	}
}