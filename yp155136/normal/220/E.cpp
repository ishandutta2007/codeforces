#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;
const int MAX_P = 2e6 +6;

struct BIT {
	LL data[MAX_N];
	int n;
	void Build(int _n) {
		n=_n;
		memset(data,0,sizeof(data));
	}
	void modify(int x,LL val) {
		for (int i=x;n>=i;i+=(i&(-i))) {
			data[i] += val;
		}
	}
	LL query(int x) {
		LL ret=0;
		for (int i=x;i>0;i-=(i&(-i))) {
			ret += data[i];
		}
		return ret;
	}
} bit;

int a[MAX_N];

struct Node {
	static Node mem[MAX_P];
	Node *lc,*rc;
	int sum;
	Node() {
		lc=rc=NULL;
		sum=0;
	}
	void pull() {
		sum = lc->sum + rc->sum;
	}
} Node::mem[MAX_P],*ptr = Node::mem;

Node *Build(int L,int R) {
	Node* node = new(ptr++)Node;
	if (L==R) return node;
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

Node* getNode(Node* old) {
	Node* node = new(ptr++)Node;
	node->lc=old->lc;
	node->rc=old->rc;
	node->sum = old->sum;
	return node;
}

void modify(Node* node,Node* old,int L,int R,int pos,int val) {
	if (L==R) {
		node->sum += val;
		return;
	}
	int mid=(L+R)>>1;
	if (pos <= mid) {
		node->lc = getNode(old->lc);
		modify(node->lc,old->lc,L,mid,pos,val);
	}
	else {
		node->rc = getNode(old->rc);
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

int main () {
	LL n,k;
	while (scanf("%lld %lld",&n,&k) != EOF) {
		ptr = Node::mem;
		vector<int> v;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			v.push_back(a[i]);
		}
		bit.Build(n);
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		LL tot=0;
		root[0] = Build(1,n);
		for (int i=1;n>=i;i++) {
			a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin()+1;
			tot += (bit.query(n) - bit.query(a[i]));
			bit.modify(a[i],1);
			root[i] = getNode(root[i-1]);
			modify(root[i],root[i-1],1,n,a[i],1);
		}
		if(tot <= k) {
			printf("%lld\n",(n*(n-1)/2));
			continue;
		}
		int R=2;
		LL now=tot;
		LL ans=0;
		for (int L=1;n-1>=L;L++) {
			if (L!=1) {
				now += query(root[L],1,n,a[L]+1,n);
				now += (query(root[n],1,n,1,a[L]-1) -query(root[R-1],1,n,1,a[L]-1));
			}
			while (R<=n && now>k) {
				now -= (query(root[L],1,n,a[R]+1,n));
				now -= (query(root[n],1,n,1,a[R]-1) - query(root[R],1,n,1,a[R]-1));
				R++;
			}
			if (now > k) break;
			ans += (n-R+1);
		}
		printf("%lld\n",ans);
	}
}