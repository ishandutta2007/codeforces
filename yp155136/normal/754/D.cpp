#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;
const int MAX_N = 3e5 + 6;
const int INF = 1e9 + 7;

struct Treap {
	Treap *lc,*rc;
	int pri,key;
	int sz;
	Treap(int _key) {
		lc=rc=NULL;
		sz=1;
		pri=rand();
		key = _key;
	}
};

int Sz(Treap* t) {
	return t?t->sz:0;
}

void pull(Treap* t) {
	t->sz = Sz(t->lc) + Sz(t->rc) + 1;
}

Treap* merge(Treap* a,Treap* b) {
	if (!a||!b) return a?a:b;
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
pii a[MAX_N];
int b[MAX_N];
piii c[MAX_N];
bool used[MAX_N];

int Q(Treap* t,int sz) {
	//cout<<"Size of t = "<<Sz(t)<<"  sz  = "<<sz<<endl;
	if (Sz(t->lc)+1==sz) return t->key;
	else if (Sz(t->lc) >= sz) return Q(t->lc,sz);
	else return Q(t->rc,sz-Sz(t->lc)-1);
}

void add(int _key) {
	Treap* tl;
	split(root,_key,tl,root);
	root = merge(merge(tl,new Treap(_key)),root);
}

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		memset(used,0,sizeof(used));
		for (int i=1;n>=i;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			a[i] = make_pair(x,y);
			c[i] = make_pair(a[i],i);
		}
		sort(c+1,c+n+1);
		for (int i=1;n>=i;i++) {
			b[i] = c[i].second;
			a[i] = c[i].first;
		}
		root=NULL;
		int ansL=-INF,ansR=-INF,ans=-1;
		for (int i=1;n>=i;i++) {
			//cout<<"i = "<<i<<endl;
			add(a[i].second);
			if (i>=k) {
				//cout<<"in  root size = "<<Sz(root)<<endl;
				//cout<<"Q = "<<i-k+1<<endl;
				int tmp=Q(root,i-k+1);
				if (tmp-a[i].first > ans) {
					ans = tmp-a[i].first;
					ansL = a[i].first;
					ansR = tmp;
				}
			}
		}
		printf("%d\n",ans+1);
		memset(used,0,sizeof(used));
		int cnt=0;
		for (int i=1;n>=i;i++) {
			if (a[i].first <= ansL && ansR <= a[i].second && cnt<k) {
				used[i]=true;
				printf("%d",b[i]);
				cnt++;
				if (cnt==k) puts("");
				else printf(" ");
			}
		}
		for (int i=1;n>=i;i++) {
			if (cnt<k && !used[i]) {
				printf("%d",b[i]);
				cnt++;
				if (cnt==k) puts("");
				else printf(" ");
			}
		}
	}
}