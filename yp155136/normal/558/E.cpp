#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;
const int MAX_M = 26;

int s[MAX_N];

struct Node {
	Node *lc,*rc;
	int sum,tag;
	Node() {
		lc=rc=NULL;
		sum=0;
		tag=-1;
	}
	void pull() {
		sum = lc->sum + rc->sum;
	}
};

Node* Build(int id,int L,int R) {
	Node* node = new Node();
	if (L==R) {
		if (s[L] == id) node->sum = 1;
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(id,L,mid);
	node->rc=Build(id,mid+1,R);
	node->pull();
	return node;
}

void push(Node* node,int L,int R) {
	if (L==R) node->tag=-1;
	if (node->tag == -1) return;
	int mid=(L+R)>>1;
	node->lc->sum = (mid-L+1)*node->tag;
	node->rc->sum = (R-mid)  *node->tag;
	node->lc->tag = node->tag;
	node->rc->tag = node->tag;
	node->tag = -1;
	return;
}

void modify(Node* node,int L,int R,int l,int r,int val) {
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		node->sum = val*(R-L+1);
		node->tag=val;
		return;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	modify(node->lc,L,mid,l,r,val);
	modify(node->rc,mid+1,R,l,r,val);
	node->pull();
	return;
}

int query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->sum;
	push(node,L,R);
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

Node* root[MAX_M];
char c[MAX_N];
int cnt[MAX_N];

int main () {
	int n,q;
	scanf("%d %d",&n,&q);
	getchar();
	scanf("%s",c);
	for (int i=1;n>=i;i++) {
		s[i] = (c[i-1]-'a');
	}
	for (int i=0;MAX_M>i;i++) {
		root[i] = Build(i,1,n);
	}
	while (q --> 0) {
		int l,r,k;
		scanf("%d %d %d",&l,&r,&k);
		memset(cnt,0,sizeof(cnt));
		for (int i=0;MAX_M>i;i++) {
			cnt[i] = query(root[i],1,n,l,r);
			if (cnt[i] > 0)modify(root[i],1,n,l,r,0);
		}
		if (k==1) {
			int now=l;
			for (int i=0;MAX_M>i;i++) {
				if (cnt[i]>0) {
					modify(root[i],1,n,now,now+cnt[i]-1,1);
					now+=cnt[i];
				}
			}
		}
		else if (k==0) {
			int now=l;
			for (int i=MAX_M-1;i>=0;i--) {
				if (cnt[i]>0) {
					modify(root[i],1,n,now,now+cnt[i]-1,1);
					now+=cnt[i];
				}
			}
		}
	}
	for (int i=1;n>=i;i++) {
		for (int j=0;MAX_M>j;j++) {
			if (query(root[j],1,n,i,i)==1) {
				printf("%c",char(j+'a'));
				break;
			}
		}
	}
	puts("");
}