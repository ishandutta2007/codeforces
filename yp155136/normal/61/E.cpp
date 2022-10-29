#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 1000006;

int num[MAX_N];
vector<int> v;
long long f[MAX_N];
int b[MAX_N];

struct Node {
	Node* lc;
	Node* rc;
	int val;
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
	if (L==R) {
		node->val = 0;
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
	return node;
}

void modify(Node* node,int L,int R,int pos,int val) {
	if (L==R) {
		node->val+=val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos,val);
	else modify(node->rc,mid+1,R,pos,val);
	node->pull();
	return;
}

int query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r) + query(node->rc,mid+1,R,l,r);
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>x;x++) {
			scanf("%d",&num[x]);
			v.push_back(num[x]);
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		for (int x=0;n>x;x++) {
			num[x]=lower_bound(v.begin(),v.end(),num[x]) - v.begin() + 1;
		}
		memset(f,0,sizeof(f));
		Node* root = Build(1,n);
		for (int x=0;n>x;x++) {
//			cout<<"num["<<x<<"] = "<<num[x]<<endl;
			if (x==0) {
				f[0]=0;
				modify(root,1,n,num[0],1);
			}
			else {
				if (num[x]==n) f[x]=0;
				else {
					f[x]=query(root,1,n,num[x]+1,n);
//					cout<<"query(root,1,n,"<<num[x]+1<<","<<n<<")\n";
					
				}
				modify(root,1,n,num[x],1);
			}
		}
		Node* Root = Build(1,n);
		for (int x=n-1;x>=0;x--) {
			if (x==n-1) {
				b[x]=0;
				modify(Root,1,n,num[x],1);
			}
			else {
				if (num[x]==1) b[x]=0;
				else {
					b[x]=query(Root,1,n,1,num[x]-1);
					
				}
				modify(Root,1,n,num[x],1);
			}
		}
		long long ans=0;
		for (int x=0;n>x;x++) {
//			cout <<"b["<<x<<"] = "<<b[x]<<endl;
//			cout<<"f["<<x<<"] = "<<f[x]<<endl;
			ans += b[x]*f[x];
		}
		printf("%I64d\n",ans);
	}
}

/*
4
5 3 2 1
*/