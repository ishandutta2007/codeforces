#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int,int> pii;
const int INF = 1e9 +7;

pii operator+(const pii &p1,const pii &p2) {
	return make_pair(min(p1.first,p2.first),max(p1.second,p2.second));
}

pii ___ = make_pair(INF,-INF);

struct Node {
	Node *lc,*rc;
	pii val;
	Node() {
		lc=rc=NULL;
		val = ___;
	}
	void pull() {
		val = lc->val + rc->val;
	}
};

Node *Build(int L,int R) {
	//the 
	Node* node = new Node();
	if (L==R) {
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

void modify(Node* node,int L,int R,int pos,pii val) {
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

pii query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return ___;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int a[n+2][m+2];
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		for (int i=0;n>=i;i++) {
			a[i][0] = INF;
			a[i][m+1] = -INF;
		}
		for (int i=0;m>=i;i++) {
			a[0][i] = INF;
			a[n+1][i] = -INF;
		}
		Node* root[n+1];
		int mx[n+1][m+1],mn[n+1][m+1];
		memset(mx,0,sizeof(mx));
		memset(mn,0,sizeof(mn));
		deque<pii> dq;
		for (int j=1;m>=j;j++) {
			//
			dq.clear();
			for (int i=n;i>=0;i--) {
				pii _=make_pair(a[i][j],i);
				if(dq.size()>0) {
					if (_ > dq.back()) {
						while (dq.size()) {
							mx[dq[0].second][j] = i+1;
							dq.pop_front();
						}
					}
					
				}
				dq.push_back(_);
			}
			// 
			dq.clear();
			for (int i=1;n+1>=i;i++) {
				pii _=make_pair(a[i][j],i);
//				cout<<"i = "<<i<<endl;
				if(dq.size()>0) {
					if (_ < dq.back()) {
						while (dq.size()) {
							mn[dq[0].second][j] = i-1;
							dq.pop_front();
						}
					}
					
				}
				dq.push_back(_);
			}
		}
		for (int i=1;n>=i;i++) {
			root[i] = Build(1,m);
		}
//		cout<<"mn : \n";
//		for (int i=1;n>=i;i++) {
//			for (int j=1;m>=j;j++) {
//				cout<<mn[i][j]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<"mx : \n";
//		for (int i=1;n>=i;i++) {
//			for (int j=1;m>=j;j++) {
//				cout<<mx[i][j]<<' ';
//			}
//			cout<<endl;
//		}
		
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				modify(root[i],1,m,j,make_pair(mx[i][j],mn[i][j]));
			}
		}
		int k;
		scanf("%d",&k);
		while (k--) {
			int l,r;
			scanf("%d %d",&l,&r);
			pii ret1=query(root[l],1,m,1,m);
			pii ret2=query(root[r],1,m,1,m);
//			cout<<"ret1 = "<<ret1.first<<' '<<ret1.second<<endl;
//			cout<<"ret2 = "<<ret2.first<<" "<<ret2.second<<endl;
			if (ret2.first<=l && ret1.second>=r) puts("Yes");
			else puts("No");
		}
	}
}