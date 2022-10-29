#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 2e5+6;
const int INF=1e9+7;

struct Node {
	Node* lc;
	Node* rc;
	int mx;
	int mn;
	Node() {
		lc=rc=NULL;
		mx=-INF;
		mn=INF;
	}
	void pull() {
		mx=max(lc->mx,rc->mx);
		mn=min(lc->mn,rc->mn);
	}
};

int a[MAX_N];
int b[MAX_N];

Node* Build(int L,int R,int type) {
	Node* node = new Node();
	if (L==R) {
		if (type==1) node->mx=node->mn=a[L];
		else node->mx=node->mn=b[L];
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid,type);
	node->rc=Build(mid+1,R,type);
	node->pull();
	return node;
}

int query_max(Node* node,int L,int R,int l,int r) {
	if (L>r||l>R) return -INF;
	else if (l<=L && R<=r) return node->mx;
	int mid=(L+R)>>1;
	return max(query_max(node->lc,L,mid,l,r),query_max(node->rc,mid+1,R,l,r));
}

int query_min(Node* node,int L,int R,int l,int r) {
	if (L>r||l>R) return INF;
	else if (l<=L && R<=r) return node->mn;
	int mid=(L+R)>>1;
	return min(query_min(node->lc,L,mid,l,r),query_min(node->rc,mid+1,R,l,r));
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) scanf("%d",&a[x]);
		Node* roota=Build(1,n,1);
		for (int x=1;n>=x;x++) scanf("%d",&b[x]);
		Node* rootb=Build(1,n,2);
		long long ans=0;
		for (int x=1;n>=x;x++) {
			if (a[x]>b[x]) continue; //no help XDDD
			else if (a[x]==b[x]) {
				//need to find what i that a[i]>a[x] || b[i]<b[x]
				int ida,idb;
				//find a first
				if (query_max(roota,1,n,x,n) == a[x]) { //all safe
					ida=n;
				}
				else {
					int L=x,R=n;
					while (R-L!=1) {
						int mid=(L+R)>>1;
						if (query_max(roota,1,n,x,mid) == a[x]) L=mid;
						else R=mid;
					}
					ida=L;
				}
				//find b then
				if (query_min(rootb,1,n,x,n) == b[x]) { //all safe
					idb=n;
				}
				else {
					int L=x,R=n;
					while (R-L!=1) {
						int mid=(L+R)>>1;
						if (query_min(rootb,1,n,x,mid) == b[x]) L=mid;
						else R=mid;
					}
					idb=L;
				}
//				cout<<"ida = "<<ida<<" , idb="<<idb<<endl;
				ans+=min(ida-x+1,idb-x+1);
			}
			else if (b[x]>a[x]) {
				//find  XD
				int L=x,R=n;
				if (query_min(rootb,1,n,x,n) - query_max(roota,1,n,x,n) > 0) continue;
				while (R-L!=1) {
					int mid=(L+R)>>1;
					if (query_min(rootb,1,n,x,mid)-query_max(roota,1,n,x,mid) > 0) L=mid;
					else R=mid;
				}
				if (query_min(rootb,1,n,x,R) - query_max(roota,1,n,x,R) < 0) continue;
				else {
					int tmpR=R;
					L=R;
					R=n+1;
					while (R-L!=1) {
						int mid=(L+R)>>1;
						if (query_min(rootb,1,n,x,mid)-query_max(roota,1,n,x,mid) < 0) R=mid;
						else L=mid;
					}
					ans+=L-tmpR+1;
//					cout<<"tmpR="<<tmpR<<" , L="<<L<<endl;
				}
			}
//			cout<<"ans="<<ans<<endl;
		}
		printf("%I64d\n",ans);
	}
}