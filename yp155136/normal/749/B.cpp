#include <iostream>
#include <stdio.h>
#include <utility>
#include <set>
#include <cassert>
using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii &p1,const pii &p2) {
	return make_pair(p1.first+p2.first,p1.second+p2.second);
}

pii operator-(const pii &p1,const pii &p2) {
	return make_pair(p1.first-p2.first,p1.second-p2.second);
}

int main () {
	int a,b,c,d,e,f;
	while (scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f) != EOF) {
		pii x=make_pair(a,b);
		pii y=make_pair(c,d);
		pii z=make_pair(e,f);
		set<pii> ans;
		ans.insert(x+(y-z));
		ans.insert(x-(y-z));
		ans.insert(y+(x-z));
		ans.insert(y-(x-z));
		ans.insert(z+(x-y));
		ans.insert(z-(x-y));
		assert(ans.size() == 3);
		puts("3");
		for (auto i:ans) {
			printf("%d %d\n",i.first,i.second);
		}
	}
}