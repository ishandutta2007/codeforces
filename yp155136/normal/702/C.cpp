#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 6;
typedef long long LL;

struct Node {
	LL val;
	int type;
	void input(int _type) {
		scanf("%I64d",&val);
		type=_type;
	}
} node[2*MAX_N];

bool operator<(const Node &n1,const Node &n2) {
	return n1.val<n2.val;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=0;n>x;x++) node[x].input(1);
		for (int x=0;m>x;x++) node[n+x].input(2);
		sort(node,node+(n+m));
		int L=-1,R=-1,l,r;
		LL ans=0;
		for (int x=0;n+m>x;x++) {
			if (node[x].type == 2) {
				if (L==-1) {
					L=x;
					ans = node[x].val - node[0].val;
				}
				else if (R==-1) {
					for (int y=L+1;x>y;y++) {
						ans = max(ans,min(node[y].val - node[L].val,node[x].val - node[y].val));
					}
					L=x;
				}
			}
		}
		for (int x=L+1;n+m>x;x++) {
			ans = max(ans,node[x].val - node[L].val);
		}
		printf("%I64d\n",ans);
	}
}