#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
using namespace std;

#define int long long
typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 1e5 + 6;
const LL INF = 1e17 + 7;

LL a[MAX_N];

inline long long  max(int a,int b) {
	return (a<b?b:a);
}

struct Node {
	Node* lc;
	Node* rc;
	LL lmax,rmax,midmax,sum;
	Node () {
		lc=rc=NULL;
	}
	void init(int pos,int val) {
		lmax=rmax=midmax=sum=val;
	}
	void pull() {
		sum=lc->sum+rc->sum;
		if (sum<-INF) sum=-INF;
		lmax = max(lc->lmax, lc->sum + rc->lmax);
		rmax = max(rc->rmax,rc->sum + lc->rmax);
		midmax = max(max(lc->midmax,rc->midmax) , lc->rmax + rc->lmax);
	}
};

int v[MAX_N];

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) {
		node->init(L,v[L]);
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	node->pull();
	return node;
}

LL ans;
int ansst,ansed;
LL f0,f1;
int f0st,f0ed,f1st,f1ed;

void modify(Node* node,int L,int R,int pos,int val) {
	if (L==R) {
		node->lmax=node->rmax=node->midmax=node->sum=val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos,val);
	else modify(node->rc,mid+1,R,pos,val);
	node->pull();
	return;
}

void query(Node* node,int L,int R,int l,int r) {
	if (L>r || l>R) return;
	else if (l<=L && R<=r) {
		f0 = max(node->midmax,f1+node->lmax);
		LL pref1=f1;
		f1 = max(node->rmax, pref1 + node->sum);
		if (f0>ans) {
			ans=f0;
		}
		if (f1>ans) {
			ans=f1;
		}
		return;
	}
	int mid=(L+R)>>1;
	query(node->lc,L,mid,l,r);
	query(node->rc,mid+1,R,l,r);
}

LL ans1[MAX_N];
LL b[MAX_N];

main () {
	int n,q;
	while (scanf("%I64d",&n) != EOF) {
		int ii=-1;
		LL sum=0;
		for (int x=1;n>=x;x++) {
			scanf("%I64d",&a[x]);
			v[x]=-INF;
		}
		Node* root=Build(1,n);
		for (int x=1;n>=x;x++) {
			scanf("%I64d",&b[x]);
		}
		for (int x=n;x>=1;x--) {
			f0=f1=0;
			ans=-INF;
			LL aa=root->lmax,bb=root->rmax,c=root->midmax,d=root->sum;
//			cout<<root->midmax<<endl;
			ans1[x] = max(max(max(aa,bb),max(c,d)),ans );
			modify(root,1,n,b[x],a[b[x]]);
		}
		for (int x=1;n>=x;x++) {
			if (x==n) {
				puts("0");
				break;
			}
			printf("%I64d\n",ans1[x]);
		}
	}
}