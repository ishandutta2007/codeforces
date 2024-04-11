#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e5 + 6;
const int INF = 1000000300;
int hash_map[MAX_N];
int num[MAX_N];
vector<int> tmp;

struct Node {
	Node* lc;
	Node* rc;
	pii mn;
	pii mx;
	Node() {
		lc=rc=NULL;
		mn=make_pair(INF,0);
		mx=make_pair(-INF,0);
	}
	void pull() {
		mn = min(lc->mn,rc->mn);
		mx = max(lc->mx,rc->mx);
	}
};

Node* Build(int L,int R) {
	Node* node = new Node();
	if (L==R) {
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
		node->mn = make_pair(pos,val);
		node->mx = make_pair(pos,val);
		return;
	}
	int mid=(L+R)>>1;
	if (pos<=mid) modify(node->lc,L,mid,pos,val);
	else modify(node->rc,mid+1,R,pos,val);
	node->pull();
	return;
}

pii tmpL;
pii tmpR;

#define tmpmx tmpL
#define tmpmn tmpR

void query(Node* node,int L,int R,int pos) {
	if (L==R) return;
	int mid=(L+R)>>1;
	if (pos<=mid) {
		tmpmx=min(tmpmx,node->rc->mn);
		query(node->lc,L,mid,pos);
	}
	else {
		tmpmn=max(tmpmn,node->lc->mx);
		query(node->rc,mid+1,R,pos);
	}
	return;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=1;n>=x;x++) {
			scanf("%d",&num[x]);
			tmp.push_back(num[x]);
		}
		sort(tmp.begin(),tmp.end());
		tmp.resize(unique(tmp.begin(),tmp.end()) - tmp.begin());
		for (int x=1;n>=x;x++) {
			int t=num[x];
			num[x] = lower_bound(tmp.begin(),tmp.end(),num[x]) - tmp.begin() + 1;
			hash_map[num[x]] = t;
		}
		Node* root = Build(1,n);
		modify(root,1,n,num[1],1);
		for (int x=2;n>=x;x++) {
//			cout<<"x="<<x<<endl;
//			cout<<"num = "<<num[x]<<endl;
			//do domething
			if (x!=2) printf(" ");
			tmpmn=make_pair(-INF,0);
			tmpmx=make_pair(+INF,0);
			query(root,1,n,num[x]);
//			puts("1");
//			cout<<tmpmn.first<<' '<<tmpmn.second<<endl;
//			cout<<tmpmx.first<<' '<<tmpmx.second<<endl;
			if (tmpmn.second > tmpmx.second) {
				printf("%d",hash_map[tmpmn.first]);
			}
			else {
				printf("%d",hash_map[tmpmx.first]);
			}
//			puts("");
			modify(root,1,n,num[x],x);
		}
		puts("");
	}
}
/*
5
4 2 3 1 6
*/