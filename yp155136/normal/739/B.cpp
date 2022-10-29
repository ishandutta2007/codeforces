#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;
const LL INF = 1e9+7;

vector<pii> edg[MAX_N];
int a[MAX_N];
int ans[MAX_N];
int n;

struct Node {
	Node *lc;
	Node *rc;
	LL sum;
	LL tag;
	Node() {
		lc=rc=NULL;
		sum=tag=0;
	}
	void pull() {
		sum = lc->sum + rc->sum;
	}
};

Node* Build(int L,int R) {
	Node* node= new Node();
	if (L==R) {
		return node;
	}
	int mid=(L+R)>>1;
	node->lc=Build(L,mid);
	node->rc=Build(mid+1,R);
	return node;
}

void push(Node* node,int L,int R) {
	if (node->tag == 0) return;
	if (L!=R) {
		int mid=(L+R)>>1;
		node->lc->tag += node->tag;
		node->lc->sum += node->tag*(mid-L+1);
		node->rc->tag += node->tag;
		node->rc->sum += node->tag*(R-mid);
	}
	node->tag=0;
}

void modify(Node* node,int L,int R,int l,int r,LL val) {  //segment plus
	if (l>R || L>r) return;
	else if (l<=L && R<=r) {
		node->sum += (R-L+1)*val;
		node->tag += val;
		return;
	}
	push(node,L,R);
	int mid=(L+R)>>1;
	modify(node->lc,L,mid,l,r,val);
	modify(node->rc,mid+1,R,l,r,val);
	node->pull();
}

LL query(Node* node,int L,int R,int l,int r) {
	if (l>R || L>r) return 0;
	else if (l<=L && R<=r) return node->sum;
	push(node,L,R);
	int mid=(L+R)>>1;
	return query(node->lc,L,mid,l,r)+query(node->rc,mid+1,R,l,r);
}

Node *root1,*root2;  //root1-->ans,root2-->val

LL Q(Node* node,int L,int R,LL val) {
	push(node,L,R);
//	cout<<"L = "<<L<<" ~ "<<R<<" = R : sum = "<<node->sum<<" , val = "<<val<<endl;
	if (L==R) {
		if (node->sum <= val) return 1;
		else return 0;
	}
	int mid=(L+R)>>1;
	node->pull();
	if (node->sum <= val) return R-L+1;
	else if (node->rc->sum <= val) return (R-mid)+Q(node->lc,L,mid,val-node->rc->sum);
	else return Q(node->rc,mid+1,R,val);
}

void dfs(int id,int depth) {
//	cout<<"id = "<<id<<" , depth = "<<depth<<" : "<<endl;
	modify(root1,1,n,depth,depth,-query(root1,1,n,depth,depth));
	//count ans id
	if (id!=1) {
		int ret=Q(root2,1,n,a[id]);
//		cout<<"ori ret = "<<ret<<endl;
		ret -= (n-depth+1);
//		cout<<"ret = "<<ret<<endl;
		modify(root1,1,n,depth-ret,depth-1,1);
	}
	for (auto i:edg[id]) {
		modify(root2,1,n,depth,depth,i.second);
		dfs(i.first,depth+1);
		modify(root2,1,n,depth,depth,-i.second);
	}
	ans[id] = query(root1,1,n,depth,depth);
}

int main () {
	while (scanf("%d",&n) != EOF) {
		root1=Build(1,n);
		root2=Build(1,n);
		for (int i=1;n>=i;i++) {
			edg[i].clear();
			scanf("%d",&a[i]);
		}
		for (int i=2;n>=i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(make_pair(i,b));
		}
		dfs(1,1);
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
}