#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 + 6;
const int INF = 1e9 + 7;

struct Node {
	Node *lc,*rc;
	int mx;
	int tag;
	Node() {
		lc=rc=NULL;
		tag=0;
		mx=0;
	}
	void pull() {
		mx = max(lc->mx,rc->mx);
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
	return node;
}

void push(Node* node,int L,int R) {
	if (L==R) return;
	if (node->tag != 0) {
		node->lc->mx  += node->tag;
		node->lc->tag += node->tag;
		node->rc->mx  += node->tag;
		node->rc->tag += node->tag;
		node->tag = 0;
	}
}

void modify(Node* node,int L,int R,int l,int r,int delta) {
	if (L>r || l>R) return;
	else if (l<=L && R<=r) {
		node->mx  += delta;
		node->tag += delta;
		return;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	modify(node->lc,L,mid,l,r,delta);
	modify(node->rc,mid+1,R,l,r,delta);
	node->pull();
}

int query(Node* node,int L,int R) {
	if (L==R) {
		if (node->mx <= 0) return 0;
		else return R;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	//cout<<"L = "<<L<<" , R = "<<R<<" , rmx = "<<node->rc->mx<<" , lmx = "<<node->lc->mx<<endl;
	if (node->rc->mx > 0) return query(node->rc,mid+1,R);
	else if (node->lc->mx > 0) return query(node->lc,L,mid);
	else return 0;
}

int a[MAX_N];
int ans[MAX_N];
int p[MAX_N],t[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		Node* root=Build(1,n);
		for (int i=1;n>=i;i++) {
			scanf("%d %d",&p[i],&t[i]);
			if (t[i]) scanf("%d",&a[p[i]]);
			else a[p[i]]=INF;
			if (t[i]) {
				modify(root,1,n,1,p[i],1);
			}
			else {
				modify(root,1,n,1,p[i],-1);
			}
		}
		a[0]=-1;
		for (int i=n;i>=1;i--) {
			//cout<<"query = "<<query(root,1,n)<<endl;;
			ans[i] = a[query(root,1,n)];
			if (t[i]) {
				modify(root,1,n,1,p[i],-1);
				modify(root,1,n,p[i],p[i],-INF);
			}
			else {
				modify(root,1,n,1,p[i],1);
				modify(root,1,n,p[i],p[i],-INF);
			}
		}
		for (int i=1;n>=i;i++) {
			printf("%d\n",ans[i]);
		}
	}
}