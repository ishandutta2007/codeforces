#include <iostream>
#include <stdio.h>
#include <utility>
#include <set>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

int p[MAX_N];
int a[MAX_N];
int b[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&p[i]);
		}
		set<pii> st[4];
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			st[a[i]].insert(make_pair(p[i],i));
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&b[i]);
			st[b[i]].insert(make_pair(p[i],i));
		}
		int nn;
		scanf("%d",&nn);
		for (int i=1;nn>=i;i++) {
			if (i!=1) printf(" ");
			int c;
			scanf("%d",&c);
			if (st[c].empty()) printf("-1");
			else {
				pii pp=*(st[c].begin());
				st[c].erase(pp);
				for (int j=1;3>=j;j++) {
					pii ppp=make_pair(pp.first,pp.second);
					if (st[j].find(ppp) != st[j].end()) st[j].erase(ppp);
				}
				printf("%d",pp.first);
			}
			puts("");
		}
	}
}