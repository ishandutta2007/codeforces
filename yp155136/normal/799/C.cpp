#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 +6 ;

int cc[MAX_N];
int cccc[MAX_N];
int dd[MAX_N];
int dddd[MAX_N];

struct Node {
	Node *lc,*rc;
	int val;
	Node() {
		lc=rc=NULL;
		val=0;
	}
	void pull() {
		val = max(lc->val,rc->val);
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

void modify(Node* node,int L,int R,int pos,int val) {
	if(L==R) {
		node->val = val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos <= mid ) modify(node->lc,L,mid,pos,val);
	else modify(node->rc,mid+1,R,pos,val);
	node->pull();
	return;
}

int query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return max(query(node->lc,L,mid,l,r),query(node->rc,mid+1,R,l,r));
}

int main () {
	int n,c,d;
	while (scanf("%d %d %d",&n,&c,&d) != EOF) {
		int nn=1e5+1;
		memset(cc,0,sizeof(cc));
		memset(cccc,0,sizeof(cccc));
		memset(dd,0,sizeof(dd));
		memset(dddd,0,sizeof(dddd));
		for (int i=1;n>=i;i++) {
			int b,p;
			char ccc;
			scanf("%d %d %c",&b,&p,&ccc);
			if (ccc=='C') {
				if (cc[p] == 0) cc[p] = max(cc[p],b);
				else if (cccc[p] == 0) {
					int mx=max(cc[p],b);
					int mn=min(cc[p],b);
					cc[p]=mx;
					cccc[p]=mn;
				}
				else {
					if (b>cccc[p]) cccc[p]=b;
					if (cccc[p]>cc[p]) swap(cccc[p],cc[p]);
				}
			}
			else {
				if (dd[p] == 0) dd[p] = max(dd[p],b);
				else if (dddd[p] == 0) {
					int mx=max(dd[p],b);
					int mn=min(dd[p],b);
					dd[p]=mx;
					dddd[p]=mn;
				}
				else {
					if (b>dddd[p]) dddd[p]=b;
					if (dddd[p]>dd[p]) swap(dddd[p],dd[p]);
				}
			}
//			cout<<"cc["<<p<<"] = "<<cc[p]<<" , dd["<<p<<"] = "<<dd[p]<<endl;
		}
		int ans=0;
		Node *rootc,*rootd;
		rootc=Build(1,nn);
		rootd=Build(1,nn);
		for (int i=1;nn>=i;i++) {
			modify(rootc,1,nn,i,cc[i]);
		}
		for (int i=1;nn>=i;i++) {
			modify(rootd,1,nn,i,dd[i]);
		}
		for (int i=1;c>=i;i++) {
			if (cc[i] == 0) continue;
			if (query(rootd,1,nn,1,d) != 0) ans = max(ans,cc[i] + query(rootd,1,nn,1,d));
			modify(rootc,1,nn,i,cccc[i]);
			if (query(rootc,1,nn,1,c-i) != 0)ans = max(ans,cc[i] + query(rootc,1,nn,1,c-i));
			modify(rootc,1,nn,i,cc[i]);
		}
		for (int i=1;d>=i;i++) {
			if (dd[i] == 0) continue;
			if (query(rootc,1,nn,1,c) != 0)ans = max(ans,dd[i] + query(rootc,1,nn,1,c));
			modify(rootd,1,nn,i,dddd[i]);
			if (query(rootd,1,nn,1,d-i) != 0)ans = max(ans,dd[i] + query(rootd,1,nn,1,d-i));
			modify(rootd,1,nn,i,dddd[i]);
		}
		printf("%d\n",ans);
	}
}