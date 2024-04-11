#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

const int MAX_N = 5e3 + 6;

int a[MAX_N];
bool good[MAX_N][MAX_N];
int k;

struct Trie {
	Trie *lc,*rc;
	int cnt;
	int val;
	Trie(int _val) {
		cnt=0;
		lc=rc=NULL;
		val = _val;
	}
};

void add(Trie* trie,int start,int end,int now) {
	if (now==start-1) {
		if (a[now+1]==0 && !trie->lc) trie->lc = new Trie(0);
		if (a[now+1]==0) add(trie->lc,start,end,now+1);
		if (a[now+1]==1 && !trie->rc) trie->rc= new Trie(1);
		if (a[now+1]==1) add(trie->rc,start,end,now+1);
	}
	else if (now==end) {
		trie->cnt += good[start][end];
		return;
	}
	else {
		trie->cnt += good[start][now];
		if (a[now+1]==0 && !trie->lc) trie->lc = new Trie(0);
		if (a[now+1]==0) add(trie->lc,start,end,now+1);
		if (a[now+1]==1 && !trie->rc) trie->rc= new Trie(1);
		if (a[now+1]==1) add(trie->rc,start,end,now+1);
	}
}

Trie *root;
string ans;

int tot;
bool ans_get;

void solve(Trie* trie) {
	if (!trie || ans_get) return;
	if (trie->val == -1) {
		solve(trie->lc);
		if (ans_get) return;
		solve(trie->rc);
		return;
	}
	ans += " ";
	ans[ans.size()-1] = trie->val + 'a';
	tot += trie->cnt;
	if (k <= tot) {
		ans_get=1;
		return;
	}
	solve(trie->lc);
	if (ans_get) {
		return;
	}
	solve(trie->rc);
	if (ans_get) {
		return;
	}
	ans.resize(ans.size()-1);
}

int main () {
	string s;
	while (cin >> s) {
		cin >> k;
		int n=0;
		for (auto i:s) {
			a[++n]=i-'a';
		}
		memset(good,0,sizeof(good));
		for (int sz=1;n>=sz;sz++) {
			for(int i=1;n>=i+sz-1;i++) {
				int j=i+sz-1;
				if(sz<=4) {
					good[i][j]=(a[i]==a[j]);
				}
				else {
					good[i][j] = (a[i]==a[j] & good[i+2][j-2]);
				}
			}
		}
		root = new Trie(-1);
		for (int i=1;n>=i;i++) {
			add(root,i,n,i-1);
		}
		tot=0;
		ans_get=0;
		ans="";
		solve(root);
		cout<<ans<<endl;
	}
}