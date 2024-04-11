#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 2e5 +6;

int a[MAX_N];

struct Node {
	Node *lc,*rc;
	int sum;
	Node() {
		lc=rc=NULL;
		sum=0;
	}
	void pull() {
		sum = lc->sum + rc->sum;
	}
};

Node *Build(int L,int R) {
	Node* node=new Node();
	if (L==R) return node;
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

Node* getNode(Node* old) {
	Node* node=new Node();
	node->lc=old->lc;
	node->rc=old->rc;
	node->sum=old->sum;
	return node;
}

void modify(Node* node,Node* old,int L,int R,int pos,int val) {
	if (L==R) {
		node->sum += val;
		return;
	}
	int mid=(L+R)>>1;
	if(pos <= mid) {
		node->lc=getNode(old->lc);
		modify(node->lc,old->lc,L,mid,pos,val);
	}
	else {
		node->rc=getNode(node->rc);
		modify(node->rc,old->rc,mid+1,R,pos,val);
	}
	node->pull();
	return;
}

int query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->sum;
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

Node* root[MAX_N];
int ans[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		vector<int> v;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		for (int i=1;n>=i;i++) {
			a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin()+1;
		}
		int m=v.size();
		memset(ans,0,sizeof(ans));
		root[0]=Build(1,m);
		for (int i=1;n>=i;i++) {
			root[i] = getNode(root[i-1]);
			modify(root[i],root[i-1],1,m,a[i],1);
		}
		for (int k=1;n-1>=k;k++) {
			for (int v=1;n>=v;v++) {
				int L=k*(v-1)+2,R=k*v+1;
				if (L>n) break;
				R = min(R,n);
				ans[k] += query(root[R],1,m,1,a[v]-1) - query(root[L-1],1,m,1,a[v]-1);
			}
		}
		for (int i=1;n-1>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
}