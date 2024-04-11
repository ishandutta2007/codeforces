#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 4e5 + 6;
const int INF = 1e9+7;

struct Node {
	int sum;
	int mx;
	void f(int _sum,int _mx) {
		sum=_sum;
		mx=_mx;
	}
} node[MAX_N];

vector<int> edg[MAX_N];
int cnt[MAX_N];
bool visit[MAX_N];
int ans[MAX_N];
int n;

struct Treap {
	Treap *lc;
	Treap *rc;
	int key;
	int pri;
	int mx;
	Treap(int _key) {
		lc=rc=NULL;
		key=_key;
		mx=_key;
		pri=rand();
	}
};

int Mx(Treap* t) {
	return t?t->mx:-INF;
}

void pull(Treap* t) {
	t->mx = max(Mx(t->lc) , max(t->key,Mx(t->rc)) );
}

Treap* merge(Treap* a,Treap* b) {
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		a->rc = merge(a->rc,b);
		pull(a);
		return a;
	}
	else {
		b->lc = merge(a,b->lc);
		pull(b);
		return b;
	}
}

void split(Treap* t,int k,Treap* &a,Treap* &b) {
	if (!t) a=b=NULL;
	else if (t->key <= k) {
		a=t;
		split(t->rc,k,a->rc,b);
		pull(a);
	}
	else {
		b=t;
		split(t->lc,k,a,b->lc);
		pull(b);
	}
}

Treap* root;

void add(int x) {
	assert(x<=n);
	cnt[x]++;
	if (cnt[x]==1) {
		Treap *tl,*tr;
		split(root,x-1,tl,root);
		split(root,x,root,tr);
		assert(root==NULL);
		root = new Treap(x);
		root = merge(merge(tl,root),tr);
	}
}

void remove(int x) {
	assert(x<=n);
	cnt[x]--;
	if (cnt[x]==0) {
		Treap *tl,*tr;
		split(root,x-1,tl,root);
		split(root,x,root,tr);
		assert(root!=NULL);
//		delete(root);
		root = merge(tl,tr);
	}
}

int query() {
	return root->mx;
}

int dfs1(int id) {
	int ret=1,mx=0;
	visit[id]=true;
	for (auto i=edg[id].begin();i!=edg[id].end();i++) {
		int tmp=*i;
		if (visit[tmp]==false) {
			int temp=dfs1(tmp);
			ret += temp;
			mx = max(mx,temp);
		}
	}
	node[id].f(ret,mx);
	return ret;
}

void dfs2(int id,int root,int parent) {
	visit[id]=true;
	if (id==root) {
		ans[id]=1;
		for (auto i=edg[id].begin();i!=edg[id].end();i++) {
			int tmp=*i;
			add(node[tmp].sum);
		}
		for (auto i=edg[id].begin();i!=edg[id].end();i++) {
			int tmp=*i;
			if (visit[tmp]==false) {
				remove(node[tmp].sum);
				dfs2(tmp,root,tmp);
				add(node[tmp].sum);
			}
		}
	}
	else  {
		if (max(node[id].mx,n-node[id].sum) <= n/2) ans[id]=1;
		else if (node[parent].sum == n-n/2) ans[id]=1;
		else if (node[id].sum + query() >= n-n/2) ans[id]=1;
		else ans[id]=0;
		for (auto i=edg[id].begin() ;i!=edg[id].end() ; i++) {
			int tmp=*i;
			if (visit[tmp]==false) {
				dfs2(tmp,root,parent);
			}
		}
	}
}

int main () {
	srand(time(NULL));
	while (scanf("%d",&n) != EOF) {
		root=NULL;
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			visit[x]=false;
		}
		for (int x=0;n-1>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			edg[i].push_back(j);
			edg[j].push_back(i);
		}
		dfs1(1);
		for (int x=0;n>=x;x++) {
			visit[x]=false;
		}
		int root;
		for (int x=1;n>=x;x++) {
			if (max(node[x].mx,n-node[x].sum) <= n/2) {
				root=x;
				break;
			}
		}
		dfs1(root);
		for (int x=0;n>=x;x++) {
			visit[x]=false;
		}
		memset(cnt,0,sizeof(cnt));
		dfs2(root,root,root);
		for (int x=1;n>=x;x++) {
			if (x!=1) printf(" ");
			printf("%d",ans[x]);
		}
		puts("");
	}
}