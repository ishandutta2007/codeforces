#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX_N = 3e5 + 6;
const int MAX_M = 5e5 + 6;

vector<int> edg[MAX_N];
vector<int> S[MAX_N];

int col[MAX_N];
bool used[MAX_N];
bool visit[MAX_N];
int mx_col;

struct Treap {
	Treap *lc,*rc;
	int val;
	int pri;
	int mx;
	Treap(int _val){
		lc=rc=NULL;
		pri=rand();
		val = _val;
		mx = _val;
	}
};

void pull(Treap* t) {
	if (!t) return;
	t->mx = t->val;
	if (t->lc) t->mx = max(t->mx,t->lc->mx);
	if (t->rc) t->mx = max(t->mx,t->rc->mx);
}

Treap* merge(Treap* a,Treap* b){
	if (!a || !b) return a?a:b;
	else if (a->pri > b->pri) {
		a->rc=merge(a->rc,b);
		pull(a);
		return a;
	}
	else {
		b->lc=merge(a,b->lc);
		pull(b);
		return b;
	}
}

void split(Treap* t,int k,Treap* &a,Treap* &b) {
	if (!t) a=b=NULL;
	else if (t->val <= k) {
		a=t;
		split(t->rc,k,a->rc,b);
		pull(a);
	}
	else {
		b=t;
		split(t->lc,k,a,b->lc);
	}
}

int Mx(Treap* t) {
	return t?t->mx:0;
}

void dfs(int id,int p) {
//	cout<<"id = "<<id<<" , p = "<<p<<endl;
	visit[id]=1;
	if (id == p) {
		int idd=0;
		for (int i:S[id]) {
			col[i] = ++idd;
		}
		mx_col = max(mx_col,idd);
	}
	else {
		Treap* painted=NULL;
		vector<int> not_painted;
		int szz=0;
		for (int i:S[id]) {
			//cout<<"i = "<<i<<" , col = "<<col[i]<<endl;
			if (col[i] != 0) {
				int tt=col[i];
				Treap *tl,*tr;
				split(painted,tt-1,tl,painted);
				split(painted,tt,painted,tr);
				painted = merge(tl,merge(new Treap(tt),tr));
				szz++;
			}
			else not_painted.push_back(i);
		}
		mx_col = max(mx_col,szz + (int)not_painted.size());
		if (not_painted.empty());
		else {
			for (int i=mx_col;i>=1;i--) {
				if (Mx(painted) == i) {
					Treap* tl;
					split(painted,i-1,tl,painted);
					painted = merge(tl,NULL);
				}
				else {
					col[not_painted.back()] = i;
					not_painted.pop_back();
					if (not_painted.empty()) break;
				}
			}
		}
		
	}
	for (int i:edg[id]) {
		if (!visit[i]) dfs(i,id);
	}
}

int main () {
	srand(time(NULL));
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;n>=i;i++) {
		int t;
		scanf("%d",&t);
		while (t--) {
			int k;
			scanf("%d",&k);
			S[i].push_back(k);
		}
	}
	for (int i=1;n>i;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		edg[a].push_back(b);
		edg[b].push_back(a);
	}
	int ss=rand()%n+1;
	dfs(ss,ss);
	if (mx_col == 0) {
		mx_col=1;
		for (int i=1;m>=i;i++) {
			col[i] = 1;
		}
	}
	printf("%d\n",mx_col);
	for (int i=1;m>=i;i++) {
		if (i!=1) printf(" ");
		if (col[i] == 0) col[i]=1;
		printf("%d",col[i]);
	}
	puts("");
}