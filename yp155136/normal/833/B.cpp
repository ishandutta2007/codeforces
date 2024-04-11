#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_K = 52;
const int MAX_N = 35006;

struct Node {
	Node *lc,*rc;
	int mx,tag;
	Node() {
		lc=rc=NULL;
		mx=tag=0;
	}
	void pull() {
		mx = max(lc->mx,rc->mx);
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

void push(Node* node,int L,int R) {
	if (!node) return;
	if (L==R) node->tag =0 ;
	if (node->tag == 0) return;
	node->lc->tag += node->tag;
	node->rc->tag += node->tag;
	node->lc->mx  += node->tag;
	node->rc->mx  += node->tag;
	node->tag =0 ;
	return;
} 

void modify(Node* node,int L,int R,int l,int r,int val) {
	if (L>r ||l>R) return;
	else if (l<=L && R<=r) {
		node->tag += val;
		node->mx  += val;
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
	else if (l<=L && R<=r) return node->mx;
	int mid=(L+R)>>1;
	push(node,L,R);
	return max(query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r));
}

int a[MAX_N];
int pos[MAX_N];
int dp[MAX_K][MAX_N];

int main () {
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;n>=i;i++) {
		scanf("%d",&a[i]);
	}
	for (int i=1;k>=i;i++) {
		Node* root=Build(0,n);
		memset(pos,0,sizeof(pos));
		for (int j=i;n-(k-i)>=j;j++) {
			modify(root,0,n,j-1,j-1,dp[i-1][j-1]);
			if (pos[a[j]] == -1) {
				modify(root,0,n,i-1,j-1,1);
			}
			else {
				modify(root,0,n,pos[a[j]],j-1,1);
			}
			pos[a[j]] = j;
			dp[i][j] = query(root,0,n,0,j-1);
//			cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<endl;
		}
	}
	printf("%d\n",dp[k][n]);
}