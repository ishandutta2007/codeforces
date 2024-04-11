#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_T = 1e4 + 4;
const int MAX_NN = 1e6+4;
const int INF = 1e9+7;

#define double long double

struct Node {
	int lc;
	int rc;
	double val;
	double add;
	int depth;

	void give_val(int _lc,int _rc,int _depth) {
		lc=_lc;
		rc=_rc;
		depth=_depth;
		val=0.0;
	}
	
} node[MAX_NN];

void flow(int n) {
	node[1].val+=1.0;
	for (int x=1;60>=x;x++) {
		if (node[x].val>1) {
			double tmp=(node[x].val-1)/2;
			node[x].val=1;
			node[node[x].lc].val+=tmp;
			node[node[x].rc].val+=tmp;
		}
	}
}

int main () {
	int n,t;
	while (scanf("%d %d",&n,&t) != EOF) {
		node[1].give_val(2,3,0);
		int tmp=2;
		int id=2;
		int l=4;
		for (int x=2;1000>=x;x++) {
			for (int i=0;x>i;i++) {
				node[id++].give_val(l,l+1,x);
				l++;
			}
			l++;
		}
		while (t--) {
			flow(n);
//			cout<<"t="<<t<<endl;
		}
		int ans=0;
		for (int x=1;(n*n+n)/2>=x;x++) {
			if (node[x].val==1) ans++;
		}
		printf("%d\n",ans);
	}
}