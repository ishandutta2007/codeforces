#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 3e5 + 4;
const int INF = 1e9+7;

vector<int> edg[MAX_N];
pii node[MAX_N]; //sum,mx
int ans[MAX_N];
int p[MAX_N];
bool visit[MAX_N];

struct Treap {
	Treap* lc;
	Treap* rc;
	pii key;  //n, id
	int pri;
	Treap(int sz,int id) {
		pri=rand();
		key=make_pair(sz,id);
		lc=rc=NULL;
	}
};

Treap* merge(Treap* a,Treap* b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		a->rc = merge(a->rc,b);
		return a;
	}
	else {
		b->lc = merge(a,b->lc);
		return b;
	}
}

void split(Treap* t,pii k,Treap* &a,Treap* &b) {
	if (!t) a=b=NULL;
	else if (t->key <= k) {
		a=t;
		split(t->rc,k,a->rc,b);
	}
	else {
		b=t;
		split(t->lc,k,a,b->lc);
	}
}

Treap* root;
Treap* root2;

void add(int sz,int id) {
	Treap *tl,*tr;
	split(root,make_pair(sz-1,id),tl,root);
	split(root,make_pair(sz,id),root,tr);
	assert(root==NULL);
	root = merge(merge(tl,new Treap(sz,id)),tr);
}

void add2(int sz,int id) {
	Treap *tl,*tr;
	split(root2,make_pair(sz-1,id),tl,root2);
	split(root2,make_pair(sz,id),root2,tr);
	assert(root2==NULL);
	root2 = merge(merge(tl,new Treap(sz,id)),tr);
}

void update(Treap *t,int id,int sz,int mx) {
	Treap* ret;
	pii tmp=t->key;
	if (max(tmp.first - sz,mx) <= tmp.first/2) {
		ans[tmp.second]=id;
	}
	else {
		add2(tmp.first,tmp.second);
	}
	if (t->lc) {
		update(t->lc,id,sz,mx);
	}
	if (t->rc) {
		update(t->rc,id,sz,mx);
	}
	delete t;
}

void query(int sz,int mx,int id) {
	Treap *tl,*tr;
	split(root,make_pair(2*mx-1,-INF),tl,root);
	split(root,make_pair(2*sz,INF),root,tr);
	if (root!=NULL) update(root,id,sz,mx);
	root = merge(tl,merge(root2,tr));
	root2=NULL;
}

int dfs1(int id) {
	visit[id]=true;
	int sum=1;
	int mx=-INF;
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (visit[tmp]==false) {
			int ret=dfs1(tmp);
			sum += ret;
			mx = max(mx,ret);
		}
	}
	node[id]=make_pair(sum,mx);
	return sum;
}

void dfs2(int id) {
	visit[id]=true;
	int sz=node[id].first;
	int mx=node[id].second;
	query(sz,mx,id);
	if (mx == -INF) ans[id]=id;
	else if (mx <= sz/2) ans[id]=id;
	else add(sz,id);
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (visit[tmp]==false) {
			dfs2(tmp);
		}
	}
}

int main () {
	int n,q;
	while (scanf("%d %d",&n,&q) != EOF) {
		for (int x=0;n>=x;x++) {
			ans[x]=-1;
			edg[x].clear();
			visit[x]=false;
		}
		for (int x=2;n>=x;x++) {
			scanf("%d",&p[x]);
			edg[x].push_back(p[x]);
			edg[p[x]].push_back(x);
		}
		dfs1(1);
		for (int x=0;n>=x;x++) {
			visit[x]=false;
		}
		dfs2(1);
		while (q--) {
			int k;
			scanf("%d",&k);
			printf("%d\n",ans[k]);
		}
	}
}