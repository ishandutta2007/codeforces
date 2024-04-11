#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;
int p[MAX_N];

pii F(pii p) {
	return make_pair(min(p.first,p.second),max(p.first,p.second));
}

int main () {
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;n>=i;i++) {
		p[i] = i;
	}
	set<pii> st;
	for (int i=1;m>=i;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		st.insert(F({x,y}));
	}
	int cnt=50;
	while (cnt--) {
		random_shuffle(p+1,p+n+1);
		int can=0;
		p[n+1] = p[1];
		for (int i=1;n>=i;i++) {
			if (st.find(F({p[i],p[i+1]})) == st.end()) {
				can++;
			}
		}
		if (can >= m) {
			for (int i=1;n>=i;i++) {
				if (st.find(F({p[i],p[i+1]})) == st.end()) {
					printf("%d %d\n",p[i],p[i+1]);
					m--;
					if (!m) return 0;
				}
			}
		}
	}
	puts("-1");
}