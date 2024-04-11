#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 5e5 + 6;
const int INF = 1e9+7;

pii query[MAX_N];
int a[MAX_N];
int mp[MAX_N];
int ans[MAX_N];

struct Node {
	Node *lc,*rc;
	int val;
	Node() {
		lc=rc=NULL;
		val=INF;
	}
	void pull() {
		val = min(lc->val,rc->val);
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
	return node;
}

void modify(Node* node,int L,int R,int pos,int val) {
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

int query1(Node* node,int L,int R,int l,int r) {
	if (L>r || l>R) return INF;
	else if (l<=L && R<=r) return node->val;
	int mid=(L+R)>>1;
	return min(query1(node->lc,L,mid,l,r),query1(node->rc,mid+1,R,l,r));
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		vector<int> v;
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			v.push_back(a[x]);
		}
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end()) - v.begin());
		for (int x=1;n>=x;x++) {
			a[x]=lower_bound(v.begin(),v.end(),a[x]) -v.begin() + 1;
		}
		Node* root = Build(1,n);
		memset(mp,-1,sizeof(mp));
		priority_queue<pii,vector<pii>, greater<pii> > pq;
		for (int x=1;m>=x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			query[x] = make_pair(i,j);
			pq.push(make_pair(j,x));
		}
		for (int x=1;n>=x;x++) {
			if (mp[a[x]] != -1) {
				modify(root,1,n,mp[a[x]],x-mp[a[x]]);
			}
			mp[a[x]]=x;
			while (!pq.empty() && pq.top().first == x) {
				pii tmp=pq.top();
				pq.pop();
				int i=tmp.first,j=tmp.second;
				ans[j]=query1(root,1,n,query[j].first,i);
			}
		}
		for (int x=1;m>=x;x++) {
			printf("%d\n",ans[x]==INF?-1:ans[x]);
		}
	}
}